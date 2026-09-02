#ifndef AST_H
#define AST_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 256


# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7
# define I 8
# define J 9
# define K 10
# define L 11
# define M 12
# define N 13
# define O 14
# define P 15
# define Q 16
# define R 17
# define S 18
# define T 19
# define U 20
# define V 21
# define W 22
# define X 23
# define Y 24
# define Z 25

typedef enum {
    OPENBRACE = '{',
    CLOSEBRACE = '}',
    SEMICOLON = ';',
    NAMETOKEN = '\'',
    COMMA = ',',
    ASSOCIATOR = '@',
    LINEDELMITER = '\n',
    ENDOFFILE = '0',
    COLON = ':',
    SPACE = ' ',
    } Symbols;



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
    char *data;
    size_t length;
    size_t capacity;
} MatrixBuffers;

typedef struct {
    MatrixBuffers *cols;
    size_t count;
    size_t capacity;
} Row;

typedef struct {
    Row row[26];
} Table;


int row_init(Row *row)
{
    row->cols = calloc(16, sizeof(MatrixBuffers));
    if (!row->cols) return -1;
    row->count    = 0;
    row->capacity = 16;
    return 0;
}
// This is for setting the row size
int row_set(Row *row, size_t col, const char *value) {
    if (col >= row->capacity) {
        size_t new_capacity = row->capacity * 2;
        MatrixBuffers *tmp = realloc(row->cols, sizeof(MatrixBuffers) * new_capacity);
        if (!tmp) return (-1);
            memset(row->cols, 0, sizeof(MatrixBuffers) * new_capacity);
        row->cols = tmp;
        row->capacity = new_capacity;
    }
    if (col >= row->count)
        row->count = col + 1;
    MatrixBuffers *cell = &row->cols[col];
    if (cell->data) free(cell->data);
    size_t len = strlen(value);
    cell-> data = malloc(len + 1);
    if (!cell->data) return (-1);
    memcpy(cell->data, value, len + 1);
    cell->length = cell->capacity = len;
    return 0;
}
char *encoded_matrix[26][14] = {
    {"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AX", "A11", "NULL"}, // A
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // B
    {"C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "NULL", "NULL", "NULL", "NULL"}, // C
    {"D0", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // D
    {"E0", "E1", "E2", "E3", "E4", "E5", "E6", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // E
    {"F0", "F1", "F2", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // F
    {"G0", "G1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // G
    {"H0", "H1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // H
    {"I0", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "NULL", "NULL"}, // I
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // J
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // K
    {"L0", "L1", "L2", "L3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // L
    {"M0", "M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "MX", "M11"}, // M
    {"N0", "N1", "N2", "N3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // N
    {"O0", "O1", "O2", "O3", "O4", "O5", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // O
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // P
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // Q
    {"R0", "R1", "R2", "R3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // R
    {"S0", "S1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // S
    {"T0", "T1", "T2", "T3", "T4", "T5", "T6", "T7", "T8", "T9", "NULL", "NULL"}, // T
    {"U0", "U1", "U2", "U3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // U
    {"V0", "V1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // V
    {"W0", "W1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // W
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // X
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // Y
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"} // Z

};


// The matrix sizes are placeholders
char *valuesMatrix[26][400] = {
    {"Able", "Al", "As", "At", "Ance", "ance", "And", "Ante", "ante", "Anti", "anti", "NULL"}, // A, 0
{"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // B, 1
{"Cede", "cede", "Cess", "cess", "Circum", "circum", "Clude", "clude", "NULL", "NULL", "NULL", "NULL"}, // C, 2
{"Dict", "NULL", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // D ,3
{"Ed", "ed", "Er", "er", "En", "en", "NULL","NULL","NULL","NULL","NULL","NULL"}, // E, 4
{"For_", "Form", "form", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // F, 5
{"Gress", "gress", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // G
{"He", "he", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // H
{"In", "in", "Ing", "ing", "Is", "is", "Inter", "inter", "Intra", "intra", "NULL","NULL"}, // I
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // J
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // K
{"Less", "less", "Ly", "ly","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // L
{"Magni", "magni", "Mark", "mark", "Ment", "ment", "Micro", "micro", "Milli", "milli", "Multi", "multi"}, // M
{"Ness", "ness", "Nd", "nd", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // N
{"Of", "of", "On", "on", "Or", "or", "NULL","NULL","NULL","NULL","NULL","NULL"}, // O
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // P
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // Q
{"Re", "re", "Retro", "retro","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // R
{"Super", "super","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // S
{"Th", "th", "That", "that", "The", "the", "Tion", "tion", "To","to", "NULL","NULL"}, // T
{"Un", "un", "Under", "under", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // U
{"Vert", "vert","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // V
{"With", "with", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // W
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // X
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // Y
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"} // Z
};
size_t valuesSize = sizeof(valuesMatrix) / sizeof(valuesMatrix[0][0]);


int hex_matrix[40][40] = {
    {0x15},

};

int counts_matrix[20][20] = {
    {4,2,2,2,4,4,3,4,4,4,4,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {4,4,4,4,6,6,5,5,0,0,0,0},
    {4,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,0,0,0,0,0,0},
    {4,4,4,0,0,0,0,0,0,0,0,0},
    {5,5,0,0,0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,0,0,0,0,0},
    {2,2,3,3,2,2,5,5,5,5,0,0},
    {4,4,2,2,0,0,0,0,0,0,0,0},
    {5,5,4,4,4,4,5,5,5,5,5,5},
    {4,4,2,2,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,0,0,0,0,0,0},
    {2,2,5,5,0,0,0,0,0,0,0,0},
    {5,5,0,0,0,0,0,0,0,0,0,0},
    {2,2,4,4,3,3,4,4,2,2,0,0},
    {2,2,5,5,0,0,0,0,0,0,0,0},
    {4,4,0,0,0,0,0,0,0,0,0,0},
    {4,4,0,0,0,0,0,0,0,0,0,0}
};

int counts[] = {
    4,2,2,2,4,3,4,4,4,4,6,5,4,2,2,2,4,4,5,2,2,3,5,5,2,4,4,2,5,4,
    4,5,5,5,4,2
};
/*
size_t uppersSize = sizeof(*upperKeys) / sizeof(*upperKeys[0]);
size_t lowersSize = sizeof(*lowerKeys) / sizeof(*lowerKeys[0]);
size_t countsSize = sizeof(*counts) / sizeof(counts[0]);
*/


// We should resize this later
extern const char firsts[40] = {'t','i','a','o','e','r','l','m','f','n', 'u'};
extern const char secondaries[80] = {
    'b', 'c', 'd', 'g', 'h', 'j', 'k', 'p', 'q', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};


#endif // AST_H