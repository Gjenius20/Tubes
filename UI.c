
#include <stdio.h>
#include <string.h>
#include "method.c"

struct Login
{
    char userName[10];
    char userPass[10];
};


// Daftar User / Admin
struct Login login[] = { {"admin47", "admin123"}, {"jamal", "anakhilang"} };

int Tubes()
{

    char passwordInput[10];
    char userInput[10];

    printf("\nMenu Login\n");
    printf("Masukan Username: ");
    scanf(" %s", userInput);
    printf("Masukan Pasword: ");
    scanf(" %s", passwordInput);

    // temp pencarian
    int found = 0;
    for (int i = 0; i < sizeof(login) / sizeof(login[0]); i++)
    {
        if ((strcmp(userInput, login[i].userName) == 0) && (strcmp(passwordInput, login[i].userPass) == 0))
        {
            found = 1;
        }
    }
    if (found)
    {
        menu();
    }
    else
        printf("\nLogin Gagal\n");
};
