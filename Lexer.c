//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
#include "AST.h"
#include <stdio.h>
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
                // Alphas and alphas length are in AST.c
                for (int i = 0; i < alphasLength; i++) {

                }
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