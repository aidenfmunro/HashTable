#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    //HashTable ht = {};
    //size_t bucketsQuantity = 5009; // 35265
//
    //CreateHashTable(&ht, bucketsQuantity, letterSumDivLenHash);
//
    //Text text = {};
    //CreateText(&text, "txt/result.txt");
//
    //fillHashTable(&ht, &text);
//
    //printf("%d", countSumSizeOfLists(&ht));
//
    //fillHashData(&ht, "hashres.txt", "ASCII sum divided by length (log)");
//
    //DestroyText(&text);
    //DestroyHashTable(&ht);

    printf("1. %lg\n",
                        calculateLoadFactor(5009, zeroHash, "txt/result.txt"));

    return OK;
}




