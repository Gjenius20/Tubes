
# include <stdio.h>
# include <string.h>
# include "method.c"

struct Login {
    char userName[10];
    char userPass[10];
};


int Tubes() {
    // Daftar User / Admin
    struct Login log[] = { {"admin", "admin123"}, {"jamal", "anakhilang"} };

    char password[10];
    char user[10];

    printf("\nMenu Login\n");
    printf("Masukan Username: ");
    scanf(" %s", user);
    printf("Masukan Pasword: ");
    scanf(" %s", password);


    // temp pencarian
    int found = 0;
    for (int i = 0; i < sizeof(log) / sizeof(log[0]); i++)
    {
        if ((strcmp(user, log[i].userName) == 0) && (strcmp(password, log[i].userPass) == 0))
        {
            found = 1;
        }
    }

    if (found)
    {
        printf("\nLogin Berhasil\n");
    }
    else
        printf("\nLogin Gagal\n");

};

