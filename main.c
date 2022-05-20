#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "menu_printer.h"
#include "globals.h"


//int getUserInputAsOneNumber();
void askVoterData(struct Voter* v);
//void getUserInputString(char* char_array, int length, char* what_to_ask);
//void storeVoterDataToFile(struct Voter* v);

int main()
{
    int programState = MainMenu;
    struct Voters* allVoters = NULL;

    allVoters = readVoterDataFromFile();
    while(1)
    {
        switch (programState)
        {
            case MainMenu:
                printMainMenu();
                int userSelection = getUserInputAsOneNumber();
                if(userSelection == KInvalidInput)
                {
                    printf("Invalid input!\n");
                    continue;//Goes to begining of while
                }
                else if(userSelection == RegisterVoter)
                {
                    struct Voter new_voter = {};
                    askVoterData(&new_voter);
                    storeVoterDataToFile(&new_voter);

                    if(allVoters != NULL)
                    {
                        free(allVoters);
                        allVoters = NULL;
                    }


                    allVoters = readVoterDataFromFile();

                }
                else if(userSelection == PrintVoters)
                {
                    for(int i = 0; i < allVoters->count; i++)
                    {
                        printf("Voter %d, SSN: %s\n", i, allVoters->all_voters[i].SSN);
                    }
                }
                else
                    goto end;
                break;
        }


    }

 end:
    if(allVoters != NULL)
    {
        free(allVoters);
        allVoters = NULL;
    }

    return 0;
}


void askVoterData(struct Voter* v)
{
    while(1)
    {

        getUserInputString(v->SSN, SIZEOF_ARRAY(v->SSN), "SSN");
        getUserInputString(v->firstname, SIZEOF_ARRAY(v->firstname), "firstname");
        getUserInputString(v->last_name, SIZEOF_ARRAY(v->last_name), "lastname");
        getUserInputString(v->are_code, SIZEOF_ARRAY(v->are_code), "area_code");

        puts("You did enter");
        printf("SSN: %s\n", v->SSN);
        printf("first name: %s\n", v->firstname);
        printf("lastname: %s\n", v->last_name);
        printf("area code: %s\n", v->are_code);
ask:
        printf("OK (1), do again (0): \n");


        int userSelection = getUserInputAsOneNumber();
        if(userSelection == KInvalidInput)
        {
            printf("Invalid input!\n");
            goto ask;
        }
        else if(userSelection == 1)
        {
            return;
        }
    }


}

