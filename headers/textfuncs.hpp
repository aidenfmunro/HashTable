//! @file
//! @author Aiden Munro

#ifndef TEXTFUNCS_H
#define TEXTFUNCS_H

#include <stdlib.h>
#include "utils.hpp"

/**
 * 
 * Line structure that contains a string and the length of the string.
 * 
 */

struct Line
{
    char* string;
    size_t length;
};

/**
 * 
 * Text structure that contains line pointers, buffer, size & amount of lines.
 * 
 */

struct Text 
{
    char*  buffer;
    char* const* lineptrs;
    size_t size,
           numLines;

    Line* lines;
};

char* getLine(Text* text, size_t numLine);

/**
 * 
 * \brief Gets lots of line structures.
 * 
 * @param[in] text - text structure.
 * @param[out] struct Line.   
 * 
 * \return string.
 * 
 */

struct Line* getLines(Text* text);

/**
 * 
 * \brief Creates a text with the chosen sortmode.
 * 
 * @param[in] text - text structure.
 * @param[in] filename - name of file.
 * @param[in] sortmode - sort mode.
 * 
 */

ErrorCode CreateText(Text* text, const char* filename);

/**
 * 
 * \brief Frees memory space.
 * 
 * @param[in] text - text structure.
 * @param[in] filename - name of file.
 * @param[in] sortmode - sort mode.
 * 
 */

ErrorCode DestroyText(Text* text);

/**
 * 
 * \brief Gets the length of the file.
 * 
 * @param[in] filename - name of file.
 * @param[out] length - size of file.
 * 
 * \return size of file.
 * 
 */

size_t getSize(const char* filename);

/**
 * 
 * \brief Gets the amount of lines.
 * 
 * @param[in] filename - name of file.
 * @param[out] lines - amount of lines.
 * 
 * \return size of file.
 * 
 */

size_t countLines(const Text* text);

/**
 * 
 * \brief Buffer parser.
 * 
 * @param[in] text - text structure.
 * @param[in] filename - name of file.
 * @param[out] buffer - parsed buffer.
 * 
 * \return buffer.
 * 
 */

char* parseBuf(Text* text, const char* filename);

char* const* getLinePointers(Text *text);

#endif