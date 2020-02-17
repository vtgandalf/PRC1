#include "animal.h"

char* SpeciesToString(SPECIES species)
{
    switch (species)
    {
    case Cat:
        return "Cat";

    case Dog:
        return "Dog";

    case GuineaPig:
        return "GuineaPig";

    case Parrot:
        return "Parrot";

    case Counter:
    case Unknown:
        break;
    }

    return "Unknown";
}

SPECIES StringToSpecies(char* string)
{
    if (strcmp(string, "Cat") == 0)
        return Cat;

    else if (strcmp(string, "Dog") == 0)
        return Dog;

    else if (strcmp(string, "GuineaPig") == 0)
        return GuineaPig;

    else if (strcmp(string, "Parrot") == 0)
        return Parrot;

    return Unknown;
}