//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
#include "AST.h"
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


 void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    char workingChar[5];
    char workingCheck[2];
    char workingMemKeys[200];
    bool memoryKeyBool;
    bool assocationBool;
    int letterCounter = 0;


    loadNexFile(fp, &memoryFileSplit);
    int len = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);
    for (int i = 0; i < len; i++) {
        workingChar[0] = memoryFileSplit.mainArray[i];
        if (workingChar == openBraceToken) {
            workingCheck[0] = workingChar[1];
            if (workingCheck == nameToken) {
                // This will need to advance workingChar until another nameToken is hit
                // And then append everything between to workingMemKeys
                workingCheck[0] = workingChar[2];
                // this is the loop that will be doing the letter check.
                // Alphas and alphas length are in AST.h
                // This is also where we get the length of the memory key
                // via letterCounter.
                for (int i = 0; i < alphasLength; i++) {
                    if (workingCheck[i] == alphas[i]) {
                        memoryKeyBool = true;
                        letterCounter++;
                    }
                    else {
                        memoryKeyBool = false;
                    }
                }
                /* letterCounter gets us the length of the Memory Key.
                 From here we can go from the point of one char after the initial
                nametoken add letterCounter and that range will hold the memory key and we can append
                it to a seperate array. */
                workingCheck[0] = workingChar[2];
                // Our memory key from here will be workingCheck + letterCounter
                if (memoryKeyBool == true) {
                    for (int j = 2; j < letterCounter; j++) {
                        workingMemKeys[j] = workingChar[j];
                    }
                }
                memoryKeyBool = false;

                // I'm not sure if workingChar is really what I want to append to yet but it's a work in progress
            }
        }
        int startingPoint = letterCounter + 1;
        workingCheck[0] = workingChar[startingPoint];
        if (workingCheck == openBraceToken)
        {
            startingPoint++;
            workingCheck[0] = workingChar[startingPoint];
        }
        // This will be the association loop; we need to write it to be
        // reusable as many times as necessary.
        if (workingCheck == nameToken)
        {
            startingPoint++;
            workingCheck[0] = workingChar[startingPoint];
            int associationStartIdx = workingCheck[0];
            for (int i = 0; i < alphasLength; i++) {
                if (workingCheck[i] == alphas[i]) {
                    letterCounter++;
                    assocationBool = true;
                }

                else {
                    assocationBool = false;
                }
            } // At this point letterCounter will be sitting at the END of the first associaton.
             // associationStartIdx is the beginning of the association, therefore associationStartIdx
            // through letterCounter is the association.

        }

    }






    }


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



}

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