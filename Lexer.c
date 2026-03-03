//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
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

const char tokens[ROW][COLUMN] = {
    {"{'", "(': )", "@", ";"},
    {"c00"}
};

const char startItemToken = tokens[0][0];
const char endItemToken = tokens[0][1];
const char associator = tokens[0][2];
const char endlineToken = tokens[0][3];
const char checkTokens[20000] = {
    startItemToken, endItemToken, endlineToken, associator,
};



void *loadNexFile(FILE *fp, MemoryFileSplit *split) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(split->mainArray, sizeof(split->mainArray), 1, fp);
   split->mainArray[size] = '\0';

}

void split(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    loadNexFile(fp, &memoryFileSplit);
    int length = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);
    for (int i = 0; i < length; i++) {
        if (i == checkTokens[0]) {


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
    split(fp);
    fclose(fp);
}


int lexMain() {
    catalyst();
    return 0;
};