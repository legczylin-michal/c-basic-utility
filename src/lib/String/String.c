#include "String.h"

struct cString
{
    size_t _length;
    char *_characters;
};

String new_String(size_t length)
{
    String result = (String)malloc(sizeof(struct cString));

    result->_length = length;
    result->_characters = (char *)malloc(sizeof(char) * (result->_length + 1));
    result->_characters[result->_length] = '\0';

    return result;
}

void del_String(String *self)
{
    if (*self == NULL)
        return;

    free((*self)->_characters);
    free(*self);

    *self = NULL;

    return;
}

String copy_String(String self)
{
    String result = new_String(self->_length);

    for (size_t i = 0; i < result->_length; i++)
        result->_characters[i] = self->_characters[i];

    return result;
}

String str_String(String self)
{
    return copy_String(self);
}

size_t String_GetLength(String self)
{
    return self->_length;
}

char *String_GetCharacters(String self)
{
    return self->_characters;
}

String String_SubString(String self, int start, int length)
{
    size_t _start = start < 0 ? self->_length - ((-start) % self->_length) : start % self->_length;
    int direction = length < 0 ? -1 : 1;
    size_t _length = length < 0 ? -length : length;
    if (direction == 1 && _start + _length > self->_length)
        _length = self->_length - _start;
    else if (direction == -1 && (int)_start - (int)_length < 0)
        _length = _start + 1;

    String result = new_String(_length);

    for (size_t i = 0; i < _length; i++)
        result->_characters[i] = self->_characters[start + direction * i];

    return result;
}

String String_FromInt(int value)
{
    int bufferSize = snprintf(NULL, 0, "%d", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%d", value);

    return result;
}

String String_FromLongInt(long int value)
{
    int bufferSize = snprintf(NULL, 0, "%ld", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%ld", value);

    return result;
}

String String_FromLongLongInt(long long int value)
{
    int bufferSize = snprintf(NULL, 0, "%lld", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%lld", value);

    return result;
}

String String_FromFloat(float value)
{
    int bufferSize = snprintf(NULL, 0, "%f", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%f", value);

    return result;
}

String String_FromDouble(double value)
{
    int bufferSize = snprintf(NULL, 0, "%lf", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%lf", value);

    return result;
}

String String_FromChar(char value)
{
    int bufferSize = snprintf(NULL, 0, "%c", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%c", value);

    return result;
}

String String_FromChars(char *value)
{
    int bufferSize = snprintf(NULL, 0, "%s", value);

    String result = new_String(bufferSize);

    snprintf(result->_characters, bufferSize + 1, "%s", value);

    return result;
}