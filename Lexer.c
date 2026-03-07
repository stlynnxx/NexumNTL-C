//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ASSOC 50
#define MAX_ASSOC_LEN 200
#define ROW 20
#define COLUMN 20
#define STARTLINETOKEN "{"
#define STARTITEMTOKEN "'"
#define ENDLINETOKEN "}"
#define ASSOCIATOR "@"
typedef struct {
    char mainArray[2000];
    char splitArray[MAX_ASSOC][MAX_ASSOC_LEN];
} MemoryFileSplit;
typedef struct {} Add;
typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[MAX_ASSOC][MAX_ASSOC_LEN];
} Breakdown;





void *loadNexFile(FILE *fp, MemoryFileSplit *split) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(split->mainArray, sizeof(split->mainArray), 1, fp);
   split->mainArray[size] = '\0';

}
void associations(char wC[50]) {

}

void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    char fileArray[5];
    char workingCheck[2];
    char wC[50];
    char workingMemKeys[200];
    bool memoryKeyBool;
    bool assocationBool;
    int tracker = 0;
    int nameTokenPoint;
    int letterCounter = 0;


    loadNexFile(fp, &memoryFileSplit);
    int len = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);

    for (int i = 0; i < sizeof(memoryFileSplit.mainArray); i++) {
        /* Here the first char of memfilesplit.mainarray is loaded into workingChar[0]
          letterCounter is also sitting at 0 */
        fileArray[0] = memoryFileSplit.mainArray[i];
        // Don't forget that fileArray is the entirety of the file at this moment
        wC[0] = fileArray[0];
        if (wC == openBraceToken) {
            /* If we are thinking of wC as a 'selector' moving across the file
            Char by Char then this next line advances the selector */
            wC[0] = fileArray[1];
            tracker++;
            /* We won't exactly be needing tracker at this moment but it's still good to
             * keep it updated */
            if (wC == nameToken) {
                // This will need to advance workingChar until another nameToken is hit
                // And then append everything between to workingMemKeys
                wC[0] = fileArray[2];
                tracker++;
                nameTokenPoint = tracker;
                // this is the loop that will be doing the letter check.
                // Alphas and alphas length are in AST.h
                // This is also where we get the length of the memory key
                // via letterCounter.
                for (int i = 0; i < alphasLength; i++) {
                    // I'm not super convinced that this is exactly how I
                    // want to handle letter checking for real as it seems
                    // prone to unwanted results/unnecessary loops.
                    // But also maybe I'm overthinking it
                    if (wC[i] != alphas[i]) {
                        memoryKeyBool = false;
                    }
                    if (workingCheck[i] == alphas[i]) {
                        memoryKeyBool = true;
                        workingMemKeys[i] = fileArray[i];
                        letterCounter++;
                        tracker++;
                    }
                }
                /* letterCounter gets us the length of the Memory Key.
                 From here we can go from the point of one char after the initial
                nametoken (namePointToken is that exact index)
                and add letterCounter and that range will hold the memory key and we can append
                it to a seperate array.
                if nameTokenPoint = 5 and letterCounter = 6, then 5-11 is our MemoryKeyRange

                */
                // If we're thinking of tracker as a sort of mirror for the imagined selector of
                // fileArray then this statement moves tracker onto the first char after the last letter of
                // the memory key, which means it should return a name token.
                tracker++;
                wC[0] = fileArray[tracker];
                if (wC == nameToken) {
                    tracker++;
                    wC[0] = fileArray[tracker];
                }
                if (wC == comma) {
                    tracker++;
                    tracker++;
                    wC[0] = fileArray[tracker];
                }


                // this is the start of the association loop. I've already started
                // a function to move all of this into but I'm feeling it out here first
                // and then moving it all to the function


            if (wC == nameToken) {
                //This is where we will begin associator logic. We need to keep
                // in mind that it needs to be repeatable.
                associations(wC);

            }
            // I'm not sure if workingChar is really what I want to append to yet but it's a work in progress
        }
    }
    letterCounter = 0;
    wC[0] = fileArray[tracker];
    if (wC == nameToken)
    {
        tracker++;
        wC[0] = fileArray[tracker];
    }

    for (int i = 0; i < alphasLength; i++) {
        // This is the same loop I'm using above with the bool swapped out
        if (wC[i] != alphas[i]) {
            assocationBool = false;
        }
        if (workingCheck[i] == alphas[i]) {
            assocationBool = true;
            workingMemKeys[i] = fileArray[i];
            letterCounter++;
            tracker++;
        }
    // we will need a demlimiter to tell the association loop when to end
}








    /* What I'm trying to do here essentially is go through what's loaded into the array
    char by char and take different actions based on what it is.
    I just don't quite know how i'm going to do this yet.

    So.

    If workingChar == startBraceToken - Append to working memory, append to
    previousChars[], read Next Char
    if workingChar == nameToken && previousChar == startBraceToken
    {
        Append to working Memory
        (So working memory at this point will hold startBraceToken, nameToken)
        Update previousChars[]
    }
    if previousChar == startNameToken && workingMemory[0] == startBraceToken
    {
        Read chars and APPEND to previousChars[]
        until workingChar == nameToken
        if workingChars[2] AFTER second nameToken == ": " {
        chars between nameTokens = MemoryKey}
        advance working char
    }
    if workingChar == startBraceToken {
            Append to previousChar and advance workingChar
            if workingChar == nameToken
            {
                Advance workingChar
                if workingChar == Associator
                associatorBool = True
                Read chars and APPEND to previousChars[]
                until working char == nameToken
                if workingChar AFTER second nameToken == "," OR "}"
                {
                    chars between nameTokens = Association
                    if working char AFTER second nameToken == "," {
                    Repeat Associator
                    Process to this point
                    }
                    if working char AFTER second nameToken == endBraceToken
                    {
                        Advance working char +1
                        if working char +1 == endLineToken
                        {
                            Go to next line
                        }
                    }

                }
                if new line char[1] == startBraceToken
                {
                Repeat Process
                }
                if new line char[1] == endFileToken
                {
                    End Lexing
                }
            }
        }

        There's a rough pseudo outline of the Lexing Process.
    */





// The open function will serve to open the file and append
// to memory.
void catalyst() {

    FILE *fp = fopen("Testing2.nex", "r");
    crawler(fp);
    fclose(fp);
}


int lexMain() {
    printf("%s", openBraceToken);


    catalyst();
    return 0;
};