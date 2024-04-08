#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 4096;

    CreateHashTable(&ht, bucketsQuantity, wordLengthHash);

    Text text = {};
    CreateText(&text, "result.txt");

    for (int i = 0; i < text.numLines; i++)
    {
        uint64_t listIndex = ht.hashFunction(&text.lines[i].length, ht.size);

        findElement(&ht, listIndex, text.lines[i].string); 
    }

    FILE* fp = fopen("hashres.txt", "w");

    for (int i = 0; i < ht.size; i++)
    {
        for (int j = 0; j < ht.lists[i].size; j++)
        {
            fprintf(fp, "%d\n", i - 1);
        }
    }

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}