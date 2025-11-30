
#include <stdio.h>
#include <string.h>
#include "method.c"

struct Login
{
    char userName[10];
    char userPass[10];
};

int Tubes()
{
    // Daftar User / Admin
    struct Login log[] = {{"admin", "admin123"}, {"jamal", "anakhilang"}};

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
        bool keluar = true;
        int opsi = 0;

        do
        {
            menu();

            printf("Masukkan pilihan: ");
            scanf("%d", &opsi);

            switch (opsi)
            {
            case 1:
                printf("1. Cari siswa\n");
                break;

            case 2:
                printf("2. Menambah siswa\n");
                break;

            case 3:
                printf("3. Edit siswa\n");
                break;

            case 4:
                printf("4. Daftar siswa\n");
                break;

            case 5:
                printf("5. Daftar penerima KIP\n");
                break;

            case 6:
                printf("Keluar...\n");
                keluar = false;
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
            }

        } while (keluar);
    }
    else
        printf("\nLogin Gagal\n");
};
