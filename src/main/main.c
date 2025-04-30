#include <stdio.h>

#include "../lib/String/String.h"

int main(int argc, char const *argv[])
{
    String str1 = str("World, hello!");

    printf("%s\n", String_GetCharacters(String_SubString(str1, 0, 10)));
    printf("%s\n", String_GetCharacters(String_SubString(str1, 0, 100)));
    printf("%s\n", String_GetCharacters(String_SubString(str1, 2, 2)));
    printf("%s\n", String_GetCharacters(String_SubString(str1, 2, -2)));
    printf("%s\n", String_GetCharacters(String_SubString(str1, 2, -20)));
    printf("%s\n", String_GetCharacters(String_SubString(str1, -1, -20)));

    printf("\nCOMPILED SUCCESSFULLY\n");

    return 0;
}