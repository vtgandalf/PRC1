#ifndef _ANIMAL_H
#define _ANIMAL_H

#define MaxNameLength 25

typedef enum
{
    Cat,
    Dog,
    GuineaPig,
    Parrot,

    Counter,
    Unknown
} SPECIES;

typedef enum
{
    Initialized,
    NotInitialized
} INIT;

typedef struct
{
    char    Name[MaxNameLength];
    SPECIES Species;
    int     Age;
} ANIMAL;

typedef struct
{
    INIT State;
    ANIMAL Animal;

} ANIMAL_PAIR;


char* SpeciesToString(SPECIES species);
SPECIES StringToSpecies(char* string);

#endif
