#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "administration.h"
#include "animal.h"

void ShowAnimals(ANIMAL_PAIR animalPairArray[])
{
    int i = 0;
    for (; i < MaxAnimalPairArraySize; i++)
    {
        if (animalPairArray[i].State == NotInitialized)
            break;

        printf("\t%i. name: %s, species: %s, age: %i\n"
               , i
               , animalPairArray[i].Animal.Name
               , SpeciesToString(animalPairArray[i].Animal.Species)
               , animalPairArray[i].Animal.Age);
    }
    if (i == 0)
        printf("There are no animals to be shown.\n");
}

int AddAnimal(ANIMAL *animalPtr, ANIMAL_PAIR animalPairArray[])
{
    // Iterate through the pair array
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // If the element has not been Initialized
        // there is room to add the animal
        if (animalPairArray[i].State == NotInitialized)
        {
            INIT state = Initialized;
            ANIMAL_PAIR pair = {.State = state, .Animal = *animalPtr};
            animalPairArray[i] = pair;
            return 0;
        }
        // Otherwise check if the element exists
        // If it does do not attept to add it.
        else if (strcmp(animalPairArray[i].Animal.Name, animalPtr->Name) == 0 &&
                 animalPairArray[i].Animal.Species == animalPtr->Species &&
                 animalPairArray[i].Animal.Age == animalPtr->Age)
        {
            printf("Can not add the animal.\nReason: It has already been registered\n");
            return -2;
        }
    }

    // At this point the array is obviously full
    // with initialized ANIMAL elements
    printf("Can not add the animal.\nReason: There is no more space.\n");
    return -1;
}

int RemoveAnimal(char name[], ANIMAL_PAIR animalArray[])
{
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // Basic checks
        if (animalArray[i].State == NotInitialized)
            break;

        if (strcmp(animalArray[i].Animal.Name, name) != 0)
            continue;

        // Set the element as not initialized aka empty
        animalArray[i].State = NotInitialized;

        // If this is not the last element
        // copy the following aka sorting
        for (int p = i; p < MaxAnimalPairArraySize; p++)
        {
            if (p < MaxAnimalPairArraySize - 1)
            {
                animalArray[p] = animalArray[p+1];
                continue;
            }
            // If it's the last element set it to NotInitialized
            animalArray[p].State = NotInitialized;
        }

        printf("Animal was successfully removed.\n");
        return 0;
    }

    printf("Animal not removed. No such animal found.\n");
    return -1;
}

int FindByName(char name[], ANIMAL_PAIR animalArray[])
{
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // Basic checks
        if (animalArray[i].State == NotInitialized)
            break;

        if (strcmp(animalArray[i].Animal.Name, name) != 0)
            continue;

        // At this point we are sure this is the animal we are
        // looking for
        printf("\t%i. name: %s, species: %s, age: %i\n"
               , i
               , animalArray[i].Animal.Name
               , SpeciesToString(animalArray[i].Animal.Species)
               , animalArray[i].Animal.Age);
        return 0;
    }
    // If the animal hasn't been found
    printf("Animal not found.\n");
    return -1;
}

ANIMAL FetchAnimalFromConsole()
{
    char name [MaxNameLength];
    char species [MaxNameLength];
    char age [MaxNameLength];

    // Get the name
    printf("Please add the details of the animal.\n");
    RequestSomethingFromConsole(name, "Name: ");

    // Get the species
    printf("Possible species: ");
    for (int i = Cat; i < Counter; i++)
    {
        printf("%s, ", SpeciesToString((SPECIES)i));
    }
    printf("...\n");
    RequestSomethingFromConsole(species, "Species: ");

    // Get the age
    RequestSomethingFromConsole(age, "Age: ");

    // Create and return the animal
    ANIMAL animal = {.Species = StringToSpecies(species), .Age = atoi(age)};
    strncpy(animal.Name, name, sizeof(animal.Name) - 1);
    // printf("ANIMAL: name: %s, species: %s, age: %i\n", animal.Name, SpeciesToString(animal.Species), atoi(age));
    return animal;
}

char* FetchStringFromConsole(char* string)
{
    fgetstr(string, MaxNameLength, stdin);
    return string;
}

char* RequestSomethingFromConsole(char* string, char* message)
{
    printf("%s\n", message);
    return FetchStringFromConsole(string);
}

void FillWithEmptyPairs(ANIMAL_PAIR pairs[])
{
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        INIT state = NotInitialized;
        ANIMAL animal = {"", Unknown, 0};
        ANIMAL_PAIR pair = {.State = state, .Animal = animal};
        pairs[i] = pair;
    }
}

char *fgetstr(char *string, int n, FILE *stream)
{
	char *result;
	result = fgets(string, n, stream);
	if(!result)
		return(result);

	if(string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = 0;

	return(string);
}