//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ASSOC 50
#define MAX_ASSOC_LEN 200

typedef struct {} MemoryFileSplit;
typedef struct {} Add;
typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[MAX_ASSOC][MAX_ASSOC_LEN];
} Breakdown;

// The open function will serve to open the file and append
// to memory.
void open() {}

int lexMain() {
    char splits[2000];
    open();



    return 0;
}