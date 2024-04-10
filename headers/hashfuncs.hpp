#ifndef HASHFUNCS_HPP
#define HAHFUNCS_HPP

#include "inttypes.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

uint64_t zeroHash            (const void* seed, size_t htSize);
    
uint64_t firstLetterHash     (const void* seed, size_t htSize);
    
uint64_t wordLengthHash      (const void* seed, size_t htSize);
    
uint64_t letterSumHash       (const void* seed, size_t htSize);

uint64_t letterSumDivLenHash (const void* seed, size_t htSize);

uint64_t rotateRightHash     (const void* seed, size_t htSize);

uint64_t rotateLeftHash      (const void* seed, size_t htSize);

#endif