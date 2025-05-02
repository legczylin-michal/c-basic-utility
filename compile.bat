mkdir .\bin
mkdir .\bin\shared
mkdir .\bin\static

mkdir .\bin\static\lib
gcc -c .\src\lib\String\String.c -o .\bin\static\lib\String.o
gcc -c .\src\lib\List\List.c -o .\bin\static\lib\List.o
ar -rcs .\bin\static\libbasic.a .\bin\static\lib\*.o

gcc .\src\main\test_String.c -Lbin\static -lbasic -o .\bin\static\test_String.exe
gcc .\src\main\test_List.c -Lbin\static -lbasic -o .\bin\static\test_List.exe
gcc .\src\main\main.c -Lbin\static -lbasic -o .\bin\static\main.exe