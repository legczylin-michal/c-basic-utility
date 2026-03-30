mkdir .\bin
mkdir .\bin\shared
mkdir .\bin\static

mkdir .\bin\static\lib
gcc -c .\src\lib\String\String.c -o .\bin\static\lib\String.o
gcc -c .\src\lib\List\List.c -o .\bin\static\lib\List.o
gcc -c .\src\lib\Matrix\Matrix.c -o .\bin\static\lib\Matrix.o
ar -rcs .\bin\static\libbasic.a .\bin\static\lib\*.o

mkdir .\bin\static\tests

gcc .\src\tests\test_String.c -Lbin\static -lbasic -o .\bin\static\tests\test_String.exe
gcc .\src\tests\test_List.c -Lbin\static -lbasic -o .\bin\static\tests\test_List.exe
gcc .\src\tests\test_Matrix.c -Lbin\static -lbasic -o .\bin\static\tests\test_Matrix.exe
gcc .\src\main\main.c -Lbin\static -lbasic -o .\bin\static\main.exe