#include "tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


struct Voters* readVoterDataFromFile()
{
    FILE *fp;
    struct Voters* voters_data = (struct Voters*) malloc (sizeof(struct Voters*));
    voters_data->all_voters = NULL;
    voters_data->count = 0;

    int file_exists = 0;

    //TODO if new file, write header
    fp = fopen("voters.txt", "r");

    int row_number = 0;
    int voters = 0;
    if(fp != NULL)
    {
        char * line = NULL;
        size_t len = 0;
        ssize_t read;


        while ((read = getline(&line, &len, fp)) != -1)
        {

            if(row_number > 0 ) //First line is header
            {
                if(voters_data->all_voters == NULL)
                    voters_data->all_voters = malloc(1*sizeof(struct Voter));
                else
                    voters_data->all_voters = realloc(voters_data->all_voters,(voters+1)*sizeof(struct Voter));

                //Split line to Voter struct
                char * token = strtok(line, ",");
                struct Voter voter = {};
                strcpy(voter.SSN, token);
                int element = 1;
                while( token != NULL )
                {
                    //printf( " %s\n", token );
                    token = strtok(NULL, ",");
                    if(element == 1)
                        strcpy(voter.are_code, token);
                    else  if(element == 2)
                        strcpy(voter.firstname, token);
                    else  if(element == 3)
                        strcpy(voter.last_name, token);

                    element++;
                    //fprintf(fp, "%s,%s,%s,%s\n", "SSN", "are_code", "firstname", "last_name");
                }

                voters_data->all_voters[voters] = voter;
                voters_data->count = ++voters;

            }
            row_number++;
        }

        fclose(fp);
        if (line)
            free(line);

    }

    return voters_data;

}

