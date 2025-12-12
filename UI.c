#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "method.c" 

struct Login {
    char userName[20];
    char userPass[20];
};


struct Login login[] = {
    {"admin", "admin123"},
    {"jamal", "anakhilang"}
};
int Tubes() {
    char passwordInput[20];
    char userInput[20];

    bool batas_input = true;
    int jumlah_input = 0;

    while (batas_input) {
        printf("\n\n==============================================\n");
        printf("||===========  LOGIN INTERFACE  ============||\n");
        printf("==============================================\n\n");
        printf("Masukan Username: ");
        scanf("%19s", userInput);
        printf("Masukan Password: ");
        scanf("%19s", passwordInput);


        int found = 0;
        for (int i = 0; i < sizeof(login) / sizeof(login[0]); i++) {
            if ((strcmp(userInput, login[i].userName) == 0) && (strcmp(passwordInput, login[i].userPass) == 0)) {
                found = 1;
                break;
            }
        }

        if (found) {
            menu();
        }
        else {
            jumlah_input++;
            printf("\n########################################\n");
            printf("#              LOGIN GAGAL             #\n");
            printf("#     Username / Password salah!       #\n");
            printf("########################################\n\n");

            if (jumlah_input >= 3) {
                printf("\nKesempatan habis, silahkan jalankan aplikasi lagi.\n");
                batas_input = false;
            }
        }
    }

    return 0;
}
