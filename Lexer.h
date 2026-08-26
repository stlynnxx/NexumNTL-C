//
// Created by steviexx on 2/28/26.
//

#ifndef NEXUMNTL_LEXER_H
#define NEXUMNTL_LEXER_H
#include <stddef.h>

void lRun();
#define MAX_ASSOC 200
#define MAX_ASSOC_LEN 200
#define ROW 20
#define COLUMN 20
typedef struct {
    char *data;
    size_t len;
    size_t cap;
} DynamicBuffers;

typedef struct {
    DynamicBuffers mainArray;
    // We may end up coming back in here and creating a second array to handle nexcode passes
} MemoryFileLoad;

typedef struct {
    DynamicBuffers memoryKey;
    int assocationCount;
    DynamicBuffers associations;
    DynamicBuffers workingAssociators;
    int tracker;
} Breakdown;

#endif //NEXUMNTL_LEXER_H