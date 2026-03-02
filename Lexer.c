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
    char pull[4] = {memoryFileSplit.mainArray[0], memoryFileSplit.mainArray[1]};
    switch (pull[0]) {
        case checkTokens[0]:
            printf("startItemToken");
            break;
        case checkTokens[1]:
            printf("endItemToken");
            break;
        case checkTokens[2]:
            printf("associator");
            break;
        case checkTokens[3]:
            printf("endlineToken");
            break;
        default:
            printf("unknownToken");
            break;
    }


}

// The open function will serve to open the file and append
// to memory.
void open() {
    FILE *fp = fopen("Testing2.nex", "a");
    if (fp == NULL) {
        printf("Unable to open existing .nex file, creating"
                        "new file instance.\n");
        fopen("Testing2.nex", "w");
        if (fp != NULL) {
            printf("Successfully created new .nex file.\n");
        }
    }
    split(fp);
}


int lexMain() {
    char splits[2000];
    open();



    return 0;
};