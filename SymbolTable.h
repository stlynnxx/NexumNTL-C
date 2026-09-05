#ifndef SymbolTable_H
#define SymbolTable_H
#include "Nexum.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 256

extern const char alphas[];
extern const int alphasLength;

struct MemoryKey {
    int x;
    // char associationBank[20];
    struct associatonBank{
        char associationsList[200];
        struct associator {
            struct MemoryKey *associatonBank;

        } associator;

    } associatonBank;

};

// These structs are the buffer for the matrix; only columns need to be expanded.
typedef struct {
    DynamicBuffers *cols;
    size_t count;
    size_t capacity;
} Row;

typedef struct {
    Row row[26];
} Table;
extern char *valuesMatrix[26][14];
extern char *encodedMatrix[26][14];
extern int hexMatrix[40][40];
extern int countsMatrix[26][14];
extern char firsts[40];
extern char secondaries[80];
void seed_table(Table *table);
int row_init(Row *row);
int row_set(Row *row, size_t col, const char *value);


#endif // AST_H