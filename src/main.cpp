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
        PushBack(&ht.lists[ht.hashFunction(&text.lines[i].length, ht.size)], text.lines[i].string); 
    }

    FILE* fp = fopen("hashres.txt", "w");

    for (int i = 0; i < ht.size; i++)
    {
        for (int j = 0; j < ht.lists[i].size; j++)
        {
            fprintf(fp, "%d\n", i);
        }
    }

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}