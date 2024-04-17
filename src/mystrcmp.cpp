#include "mystrcmp.h"

int mystrcmp (const char* s1, const char* s2)
{
    __m256i s1_ = _mm256_loadu_epi8(s1);
    __m256i s2_ = _mm256_loadu_epi8(s2);

    __mmask32 cmp = _mm256_cmp_epi8_mask(s1_, s2_, _MM_CMPINT_EQ);

    return cmp == ~(uint64_t(0)); 
}