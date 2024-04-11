#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 5009; // 35265

    CreateHashTable(&ht, bucketsQuantity, letterSumDivLenHash);

    Text text = {};
    CreateText(&text, "txt/result.txt");

    fillHashTable(&ht, &text);

    printf("%d", countSumSizeOfLists(&ht));

    fillHashData(&ht, "hashres.txt", "ASCII sum divided by length (log)");

    DestroyText(&text);
    DestroyHashTable(&ht);

    //printf("1. %llu\n"
    //       "2. %llu\n"
    //       "3. %llu\n"
    //       "4. %llu\n"
    //       "5. %llu\n"
    //       "6. %llu\n"
    //       "7. %llu\n"
    //       "8. %llu\n", calculateLoadFactor(809, zeroHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, firstLetterHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, wordLengthHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, letterSumDivLenHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, letterSumHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, rotateRightHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, rotateLeftHash, "txt/result.txt"),
    //                    calculateLoadFactor(809, FNVHash, "txt/result.txt"));

    return OK;
}




