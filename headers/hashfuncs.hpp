#ifndef HASHFUNCS_HPP
#define HAHFUNCS_HPP

#include "inttypes.h"
#include "stddef.h"
#include "stdlib.h"

uint64_t zeroHash (const void* memory, size_t htSize);

uint64_t firstLetterHash (const void* memory, size_t htSize);

uint64_t wordLengthHash (const void* memory, size_t htSize);

uint64_t letterSumHash (const void* memory, size_t htSize);


#endif