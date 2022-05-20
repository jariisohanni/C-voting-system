#ifndef GLOBALS_H
#define GLOBALS_H

enum states
{
    MainMenu = 1000,
    RegisterVoter = 1,
    PrintVoters = 2,
};

struct Voter
{
    char SSN[11];
    char firstname[30];
    char last_name[50];
    char are_code[5];

};

struct Voters
{
    struct Voter* all_voters;
    int count;

};
#define KInvalidInput -10

#define SIZEOF_ARRAY( arr ) sizeof( arr ) / sizeof( arr[0] )

#endif // GLOBALS_H
