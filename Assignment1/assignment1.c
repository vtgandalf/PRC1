#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ass.h"

void PrintingFunction(int a)
{
    char string[a];
    for (int i = 0; i < a; i++)
    {
        printf("%i.\t", i);
        string[i] = '*';
        string[i+1] = '\0';
        printf("%s\n", string);
    }
}

int main(int argc, char **argv)
{
    printf("argc: %i\n\n", argc);
    if (argc < 2)
    {
        printf("Please add a prameter\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        int arg = atoi(argv[i]);
        printf("parsed argument %i\n", arg);
        PrintingFunction(arg);
        printf("\n");
    }
    kek();
}