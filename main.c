#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_printer.h"

enum states
{
    MainMenu = 0,
};

#define KInvalidInput -10

int getUserInputAsInt();

int main()
{
    int programState = MainMenu;

    while(1)
    {
        switch (programState)
        {
            case MainMenu:
                printMainMenu();
                int userSelection = getUserInputAsInt();
                if(userSelection == KInvalidInput)
                {
                    printf("Invalid input!\n");
                    continue;//Goes to begining of while
                }
                else if(userSelection == 0)
                    return 0;
                break;
        }


    }


    return 0;
}

/* Asks user for a input (numeric), if input non-numeric returns KERROR */
int getUserInputAsInt()
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
