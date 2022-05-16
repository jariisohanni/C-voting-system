#include <stdio.h>

#include "globals.h"

void printMainMenu()
{
    printf("Main Menu\n");
    printf("%d: Register a voter...........\n", RegisterVoter);
    printf("%d: Search for a voter.........\n", PrintVoters);
    printf("%d: Register a candidate.......\n", 3);
    printf("%d: Register vote by voter.....\n", 4);
    printf("%d: Calculate votes ...........\n", 5);
    printf("%d: Exit ......................\n", 0);
    printf("Make your selection: ");

}

