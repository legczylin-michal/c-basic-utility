#include <stdio.h>

#include "../lib/String/String.h"

int main(int argc, char const *argv[])
{
    String str1 = str("World, hello!");

    printf("original: '%s'", String_GetCharacters(str1));
    printf("\n");
    printf("from 0 length 10: '%s'", String_GetCharacters(String_SubString(str1, 0, 10)));
    printf("\n");
    printf("from 0 length 100: '%s'", String_GetCharacters(String_SubString(str1, 0, 100)));
    printf("\n");
    printf("from 2 length 2: '%s'", String_GetCharacters(String_SubString(str1, 2, 2)));
    printf("\n");
    printf("from 2 length -2: '%s'", String_GetCharacters(String_SubString(str1, 2, -2)));
    printf("\n");
    printf("from 2 length -20: '%s'", String_GetCharacters(String_SubString(str1, 2, -20)));
    printf("\n");
    printf("from -5 length 2: '%s'", String_GetCharacters(String_SubString(str1, -5, 2)));
    printf("\n");
    printf("from -1 length -20: '%s'", String_GetCharacters(String_SubString(str1, -1, -20)));
    printf("\n");
    printf("from 5 length 0: '%s'", String_GetCharacters(String_SubString(str1, 5, 0)));
    printf("\n");
    printf("from 5 length -1: '%s'", String_GetCharacters(String_SubString(str1, 5, -1)));
    printf("\n");
    printf("from 5 length 1: '%s'", String_GetCharacters(String_SubString(str1, 5, 1)));
    printf("\n");
    printf("from 5 length -2: '%s'", String_GetCharacters(String_SubString(str1, 5, -2)));
    printf("\n");
    printf("from 5 length 2: '%s'", String_GetCharacters(String_SubString(str1, 5, 2)));
    printf("\n");
    String str2 = str("My name is John.");
    String str3 = String_Concatenate(str1, str2);
    printf("concatenated string: '%s' + '%s' = '%s'", String_GetCharacters(str1), String_GetCharacters(str2), String_GetCharacters(str3));
    printf("\n");
    String_Append(str1, str1);
    printf("original: '%s'", String_GetCharacters(str1));

    printf("\nCOMPILED SUCCESSFULLY\n");

    return 0;
}