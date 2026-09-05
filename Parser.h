//
// Created by steviexx on 3/31/26.
//

#ifndef PARSER_H
#include "Nexum.h"
#include <stddef.h>
#define PARSER_H

int prun();


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