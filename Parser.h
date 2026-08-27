//
// Created by steviexx on 3/31/26.
//

#ifndef NEXUMNTL_PARSER_H
#include <stddef.h>
#define NEXUMNTL_PARSER_H

int prun();
typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} DynamicBuffers;

typedef struct {
    DynamicBuffers assoc;
    DynamicBuffers associators;
    DynamicBuffers memKey;
} Export;

typedef struct {
    DynamicBuffers assocScratch;
    DynamicBuffers associatorScratch;
    DynamicBuffers memKeyScratch;
} builder;

#endif //NEXUMNTL_PARSER_H