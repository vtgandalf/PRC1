#include <string.h>
#include "unity.h"
#include "administration.h"

void append(char s[], char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_AddAnimal(void)
{
    printf("\ntest_AddAnimal\n");
    printf("--------------\n");

    // Create an empty array of ANIMAL_PAIR
    ANIMAL_PAIR pairs[MaxAnimalPairArraySize];
    FillWithEmptyPairs(pairs);

    // Init general fields of animal
    char name[MaxNameLength];
    SPECIES species = Dog;
    int age = 10;
    ANIMAL animal = {.Species = species,
                     .Age = age};

    // Fill in the array with animals
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // Create an a pair to add
        strcpy(name, "animal_");
        char n = i + '0';
        append(name, n);
        strcpy(animal.Name, name);

        // Add the animal to the array
        TEST_ASSERT_EQUAL(0, AddAnimal(&animal, pairs));
        printf("Animals:\n");
        ShowAnimals(pairs);

        // Check if the animal in the array has the
        // correct properties
        TEST_ASSERT_EQUAL(Initialized,
                        pairs[i].State);
        TEST_ASSERT_EQUAL(0,
                        strcmp(pairs[i].Animal.Name,
                                name));
        TEST_ASSERT_EQUAL(species,
                        pairs[i].Animal.Species);
        TEST_ASSERT_EQUAL(age,
                        pairs[i].Animal.Age);

        // Try to add the same animal again
        TEST_ASSERT_EQUAL(-2, AddAnimal(&animal, pairs));
    }

    // Try to add another one even though
    // the array is full
    strcpy(animal.Name, "to be rejected");
    TEST_ASSERT_EQUAL(-1, AddAnimal(&animal, pairs));
}

void test_RemoveAnimal(void)
{
    printf("\ntest_RemoveAnimal\n");
    printf("----------------\n");

    // Create an empty array of ANIMAL_PAIR
    ANIMAL_PAIR pairs[MaxAnimalPairArraySize];
    FillWithEmptyPairs(pairs);

    // Init general fields of animal
    char name[MaxNameLength];
    SPECIES species = Dog;
    int age = 10;
    ANIMAL animal = {.Species = species,
                     .Age = age};

    // Fill in the array with animals
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // Create an a pair to add
        strcpy(name, "animal_");
        char n = i + '0';
        append(name, n);
        strcpy(animal.Name, name);

        // Add the animal to the array
        AddAnimal(&animal, pairs);
    }
    printf("Animals:\n");
    ShowAnimals(pairs);

    // Remove the first animal
    TEST_ASSERT_EQUAL(0, RemoveAnimal("animal_0", pairs));
    printf("Animals:\n");
    ShowAnimals(pairs);

    // Assert that the rest of the elements of the
    // array are as they should
    for (int i = 0; i < MaxAnimalPairArraySize; i++)
    {
        // Every other element but the last one
        if (i < MaxAnimalPairArraySize - 1)
        {
            // Generate the correct name;
            strcpy(name, "animal_");
            char n =  i + 1 + '0';
            append(name, n);

            // Check properties
            TEST_ASSERT_EQUAL(pairs[i].State, Initialized);
            TEST_ASSERT_EQUAL(0, strcmp(pairs[i].Animal.Name, name));
            TEST_ASSERT_EQUAL(pairs[i].Animal.Species, species);
            TEST_ASSERT_EQUAL(pairs[i].Animal.Age, age);
            continue;
        }

        // If its the last element it should
        // be NotInitialized
        TEST_ASSERT_EQUAL(pairs[i].State, NotInitialized);
    }

    // Try to remove an animal which has not been recorded
    strcpy(name, "invalid name");
    TEST_ASSERT_EQUAL(-1, RemoveAnimal(name, pairs));
}

void test_FindByName(void)
{
    printf("\ntest_FindByName\n");
    printf("---------------\n");

    // Create an empty array of ANIMAL_PAIR
    ANIMAL_PAIR pairs[MaxAnimalPairArraySize];
    FillWithEmptyPairs(pairs);

    // Create an animal and add it to the list
    char name[MaxNameLength];
    SPECIES species = Dog;
    int age = 10;
    ANIMAL animal = {.Species = species,
                     .Age = age};
    strcpy(name, "animal");
    strcpy(animal.Name, name);
    AddAnimal(&animal, pairs);

    // Find the animal
    TEST_ASSERT_EQUAL(0, FindByName(name, pairs));

    // Try to find animal with incorrect name
    TEST_ASSERT_EQUAL(-1, FindByName("to be rejected", pairs));
}

int main (void)
{
    UnityBegin();

    RUN_TEST(test_AddAnimal, 1);
    RUN_TEST(test_RemoveAnimal, 2);
    RUN_TEST(test_FindByName, 3);

    return UnityEnd();
}
