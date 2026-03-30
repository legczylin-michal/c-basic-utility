#ifndef _STRING_H_
#define _STRING_H_

#include "../types.h"

String new_String(size_t length);
void del_String(String *self);
String copy_String(String self);
String str_String(String self);

size_t String_GetLength(String self);
char *String_GetCharacters(String self);

void String_Append(String self, String other);

String String_SubString(String self, int start, int length);
List String_Split(String target, String delimiter);
String String_Concatenate(String left, String right);

String String_FromInt(int value);
String String_FromLongInt(long int value);
String String_FromLongLongInt(long long int value);
String String_FromFloat(float value);
String String_FromDouble(double value);
String String_FromChar(char value);
String String_FromChars(char *value);

#define str(X) _Generic((X),                        \
    int: String_FromInt,                            \
    unsigned int: String_FromInt,                   \
    long int: String_FromLongInt,                   \
    unsigned long int: String_FromLongInt,          \
    long long int: String_FromLongLongInt,          \
    unsigned long long int: String_FromLongLongInt, \
    float: String_FromFloat,                        \
    double: String_FromDouble,                      \
    char: String_FromChar,                          \
    const char: String_FromChar,                    \
    char *: String_FromChars,                       \
    const char *: String_FromChars)(X)

#endif // !_STRING_H_