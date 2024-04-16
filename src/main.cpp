#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 5009; // 35265

    CreateHashTable(&ht, bucketsQuantity, rotateRightHash);

    Text text = {};
    CreateText(&text, "txt/result.txt");

    fillHashTable(&ht, &text);

    printf("%d", countSumSizeOfLists(&ht));

    fillHashData(&ht, "hashres.txt", "test for work ror");

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}





