#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_printer.h"
#include "globals.h"


int getUserInputAsOneNumber();
void getVoterData(struct Voter* v);
void getUserInputString(char* char_array, int length, char* what_to_ask);
void storeVoterDataToFile(struct Voter* v);

int main()
{
    int programState = MainMenu;

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
                    getVoterData(&new_voter);
                    storeVoterDataToFile(&new_voter);
                }
                else
                    return 0;
                break;
        }


    }


    return 0;
}

void storeVoterDataToFile(struct Voter* v)
{
    FILE *fp;

    int file_exists = 0;

    //TODO if new file, write header
    fp = fopen("voters.txt", "r");

    if(fp != NULL)
    {
        file_exists = 1;
        fclose(fp);
    }

    fp = fopen("voters.txt", "a+");
    if(file_exists == 0)
        fprintf(fp, "%s,%s,%s,%s\n", "SSN", "are_code", "firstname", "last_name");

    fprintf(fp, "%s,%s,%s,%s\n", v->SSN, v->are_code, v->firstname, v->last_name);
    fclose(fp);
}

void getVoterData(struct Voter* v)
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

void getUserInputString(char* char_array, int length, char* what_to_ask)
{
    printf("Please enter voters %s\n", what_to_ask);
    fgets(char_array,length,stdin);
    char_array[strcspn(char_array, "\n")] = 0;
}
/* Asks user for a input (numeric), if input non-numeric returns KERROR */
int getUserInputAsOneNumber()
{
    int repeat = 1;
    char buff[10] = {0};
    fgets(buff,10,stdin);
    buff[strcspn(buff, "\n")] = 0; /* removing newline character from the buffer */

    if(strlen(buff) > 1)
        return KInvalidInput;

    char chr = buff[0];

    int value = KInvalidInput;

    if ((chr >= '0') && (chr <= '9'))
        value = chr - '0';

    return value;

}
