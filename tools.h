#ifndef TOOLS_H
#define TOOLS_H

#include "globals.h"

void getUserInputString(char* char_array, int length, char* what_to_ask);
int getUserInputAsOneNumber();
void storeVoterDataToFile(struct Voter* v);
struct Voters* readVoterDataFromFile();

#endif // TOOLS_H
