#include "hashtable.hpp"

// Aiden: maybe use uint64_t for size? (or use size_t everywhere?)

ErrorCode CreateHashTable (HashTable* ht, size_t bucketsQuantity, hashFunction_t hashFunction)
{
    AssertSoft(ht, NULL_PTR);

    SafeCalloc(temp, List, bucketsQuantity, NO_MEMORY_AVAILABLE);

    ht->size = bucketsQuantity;

    ht->lists = temp;

    for (int i = 0; i < bucketsQuantity; i++)
    {
        CreateList(&ht->lists[i]);
    }

    ht->hashFunction = hashFunction;

    return OK;
}

ErrorCode DestroyHashTable (HashTable* ht)
{
    AssertSoft(ht, NONE_EXISTING);

    for (int i = 0; i < ht->size; i++)
    {
        DestroyList(&ht->lists[i]);
    }

    free(ht->lists);

    ht->size = 0;

    ht->hashFunction = NULL;

    return OK;
}

ErrorCode findElement (HashTable* ht, size_t listIndex, Elem_t elem)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(elem, NULL_PTR);
    AssertSoft(listIndex < ht->size, INDEX_OUT_OF_RANGE);

    for (int elemIndex = 0; elemIndex < ht->lists[listIndex].size; elemIndex++)
    {
        if (! strcmp(elem, ht->lists[listIndex].ptr[elemIndex].value))
        {
            ht->lists[listIndex].ptr[elemIndex].count += 1;

            return FOUND;
        }
    }

    return NOT_FOUND;
}

ErrorCode fillWithWordLengthHash (HashTable* ht, Text* text)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(text, NULL_PTR);

    for (int i = 0; i < text->numLines; i++)
    {
        uint64_t listIndex = ht->hashFunction(&text->lines[i].length, ht->size); // fix this

        if (findElement(ht, listIndex, text->lines[i].string) == NOT_FOUND)
        {
            PushBack(&ht->lists[listIndex], text->lines[i].string);
        } 
    }

    return OK;
}

ErrorCode fillWithZeroHash (HashTable* ht, Text* text)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(text, NULL_PTR);

    for (int i = 0; i < text->numLines; i++)
    {
        uint64_t listIndex = ht->hashFunction("", ht->size); // fix this

        if (findElement(ht, listIndex, text->lines[i].string) == NOT_FOUND)
        {
            PushBack(&ht->lists[listIndex], text->lines[i].string);
        } 
    }

    return OK;
}

ErrorCode fillWithFirstLetterHash (HashTable* ht, Text* text)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(text, NULL_PTR);

    for (int i = 0; i < text->numLines; i++)
    {
        uint64_t listIndex = ht->hashFunction(text->lines[i].string, ht->size); // fix this

        if (findElement(ht, listIndex, text->lines[i].string) == NOT_FOUND)
        {
            PushBack(&ht->lists[listIndex], text->lines[i].string);
        } 
    }

    return OK;
}

ErrorCode fillWithLetterSumHash (HashTable* ht, Text* text)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(text, NULL_PTR);

    for (int i = 0; i < text->numLines; i++)
    {
        uint64_t listIndex = ht->hashFunction(text->lines[i].string, ht->size); // fix this

        if (findElement(ht, listIndex, text->lines[i].string) == NOT_FOUND)
        {
            PushBack(&ht->lists[listIndex], text->lines[i].string);
        } 
    }

    return OK;
}

ErrorCode fillWithLetterSumDivLenHash (HashTable* ht, Text* text)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(text, NULL_PTR);

    for (int i = 0; i < text->numLines; i++)

    uint64_t listIndex = ht->hashFunction(text->lines[i].string, ht->size);

     for (int i = 0; i < text->numLines; i++)
    {
        uint64_t listIndex = ht->hashFunction(text->lines[i].string, ht->size); // fix this

        if (findElement(ht, listIndex, text->lines[i].string) == NOT_FOUND)
        {
            PushBack(&ht->lists[listIndex], text->lines[i].string);
        } 
    }

    return OK;
}

ErrorCode fillHashData (HashTable* ht, const char* outputFileName, const char* hashName)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(outputFileName, NULL_PTR);
    AssertSoft(hashName, NULL_PTR);

    myOpen(outputFileName, "w", outputFile);

    fprintf(outputFile, "%s\n", hashName);

    for (int i = 0; i < ht->size; i++)
    {
        for (int j = 0; j < ht->lists[i].size; j++)
        {
            fprintf(outputFile, "%d\n", i);
        }
    }

    myClose(outputFile);

    return OK;
}
