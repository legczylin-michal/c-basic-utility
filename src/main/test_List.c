#include <stdio.h>

#include "../lib/String/String.h"
#include "../lib/List/List.h"

int main(int argc, char const *argv[])
{
    String exampleString = str("retrotmrot");

    List list1 = String_Split(exampleString, str(""));
    for (size_t i = 0; i < List_GetSize(list1); i++)
        printf("'%s' ", String_GetCharacters((String)List_Get(list1, i)));

    printf("\n");

    List list2 = String_Split(exampleString, str("r"));
    for (size_t i = 0; i < List_GetSize(list2); i++)
        printf("'%s' ", String_GetCharacters((String)List_Get(list2, i)));

    printf("\n");

    List list3 = String_Split(exampleString, str("ro"));
    for (size_t i = 0; i < List_GetSize(list3); i++)
        printf("'%s' ", String_GetCharacters((String)List_Get(list3, i)));

    printf("\n");

    List list4 = String_Split(exampleString, str("rot"));
    for (size_t i = 0; i < List_GetSize(list4); i++)
        printf("'%s' ", String_GetCharacters((String)List_Get(list4, i)));

    printf("\n");

    printf("\nCOMPILED SUCCESSFULLY\n");

    return 0;
}