#include "animal_shelter.h"

int main (void)
{
    printf ("PRC assignment 'Animal Shelter' (version april 2019)\n");
    ANIMAL_PAIR animalPairs[MaxAnimalPairArraySize];
    FillWithEmptyPairs(animalPairs);

    int choice = -1;
    while (choice != 0)
    {
        printf ("\nMENU\n====\n");
        printf ("1: Show Animals \n");
        printf ("2: Add Animal \n");
        printf ("3: Remove Animal \n");
        printf ("4: Find Animal by name \n");
        printf ("0: quit \n");

        scanf ("%d", &choice);

        char name[MaxNameLength];
        switch (choice)
        {
            case 1: //Show Animals
                printf ("show Animals\n");
                ShowAnimals(animalPairs);
                break;
            case 2: //Add Animal
                printf ("add Animal\n");
                getchar(); // Consume extra char aka '\n'
                ANIMAL animal = FetchAnimalFromConsole();
                AddAnimal(&animal, animalPairs);
                break;
            case 3: //Remove Animal
                printf ("remove Animal\n");
                getchar(); // Consume extra char aka '\n'
                RequestSomethingFromConsole(name, "Name: ");
                RemoveAnimal(name, animalPairs);
                break;
            case 4://find by name
                printf ("find by name\n");
                getchar(); // Consume extra char aka '\n'
                RequestSomethingFromConsole(name, "Name: ");
                FindByName(name, animalPairs);
                break;
            case 0:
                break;
            default:
                printf ("ERROR: invalid choice: %d\n", choice);
                break;
		}
	}
    return 0;
}