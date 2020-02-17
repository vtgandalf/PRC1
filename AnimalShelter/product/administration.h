#ifndef _ADMINISTRATION_H
#define _ADMINISTRATION_H

#include "animal.h"

#define MaxAnimalPairArraySize 3

int AddAnimal(ANIMAL *animalPtr, ANIMAL_PAIR animalArray[]);
int RemoveAnimal(char name[], ANIMAL_PAIR animalArray[]);
int FindByName(char name[], ANIMAL_PAIR animalArray[]);

void ShowAnimals(ANIMAL_PAIR animalPairArray[]);
ANIMAL FetchAnimalFromConsole();
char* FetchStringFromConsole(char* string);
char* RequestSomethingFromConsole(char* string, char* message);
void FillWithEmptyPairs(ANIMAL_PAIR pairs[]);

// fgets but without '/n'
char *fgetstr(char *string, int n, FILE *stream);

#endif
