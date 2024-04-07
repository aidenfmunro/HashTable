//! @file
//! @author Aiden Munro

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include "textfuncs.hpp"

ErrorCode CreateText(Text* text, const char* filename)
{
    AssertSoft(text, NULL_PTR);
    AssertSoft(filename, NULL_PTR);

    text->size     = getSize(filename);
    text->buffer   = parseBuf(text, filename);
    text->numLines = countLines(text);
    text->lineptrs = getLinePointers(text);
    text->lines    = getLines(text);

    return OK;
}

ErrorCode DestroyText(Text* text)
{
    AssertSoft(text, NULL_PTR);

    free((void*)text->lineptrs);
    free((void*)text->buffer);
    free((void*)text->lines);

    return OK;
}

char* const* getLinePointers(Text *text)
{
    AssertSoft(text, NULL);

    char** lineptrs = (char**)calloc(text->numLines, sizeof(char*));
    
    *lineptrs = text->buffer;

    char* textptr = strchr(text->buffer, '\n');

    while (textptr != NULL)
    {
        *textptr = '\0'; // \n -> \0
        lineptrs++;
        *lineptrs = textptr + 1;
        textptr = strchr(textptr + 1, '\n'); 
    }

    lineptrs -= (text->numLines - 1);

    return (char* const*)lineptrs;
}

char* parseBuf(Text* text, const char* filename)
{   
    AssertSoft(text, NULL);
    AssertSoft(filename, NULL);

    FILE* fp = fopen(filename, "rb");

    char* buffer = (char*)calloc(text->size + 1, sizeof(char));
    fread(buffer, sizeof(char), text->size, fp);
    buffer[text->size] = '\0';
  
    fclose(fp);

    return buffer;
}

size_t getSize(const char* filename)
{
    AssertSoft(filename, NULL_PTR);

    struct stat stats = {};
    stat(filename, &stats);

    return stats.st_size / sizeof(char);
}

size_t countLines(const Text* text)
{
    AssertSoft(text, NULL_PTR);

    size_t lines = 1;

    for (size_t i = 0; i < text->size; i++)
        if (text->buffer[i] == '\n')
            lines++;

    return lines;
}

char* getLine(Text* text, size_t numLine)
{
    AssertSoft(numLine < text->numLines, NULL);

    return text->lines[numLine].string;
}

Line* getLines(Text* text)
{
    AssertSoft(text, NULL);

    Line* lines = (struct Line*)calloc(text->numLines, sizeof(Line));

    for (size_t i = 0; i < text->numLines; i++)
    {
        lines[i].length = strlen(text->lineptrs[i]);
        lines[i].string = text->lineptrs[i];
    }
    
    return lines;
}