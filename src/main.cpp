#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 64;

    CreateHashTable(&ht, bucketsQuantity, firstLetterHash);

    Text text = {};
    CreateText(&text, "result.txt");

    for (int i = 0; i < text.numLines; i++)
    {
        printf("%s %d\n", text.lineptrs[i], ht.hashFunction(text.lineptrs[i], ht.size));


        // PushBack(&ht.lists[ht.hashFunction(text.lineptrs[i], ht.size)], text.lineptrs[i]); 
    }

    FILE* fp = fopen("hashres.txt", "w");

    for (int j = 0; j < ht.size; j++)
    {
        fprintf(fp, "%d\n", ht.lists[j].size);
    }

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}