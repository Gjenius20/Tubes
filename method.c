#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SISWA 100

struct Siswa
{
    char NISN[15]; // Diubah dari int NISN[15] menjadi char NISN[15] untuk konsistensi sebagai string
    char nama[50];
    char jenisKelamin[15];
    bool statusKIP;
};

struct Siswa siswa[MAX_SISWA] = {
    {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", true},
    {"0012345679", "Abdullah Koswara", "Laki-laki", false},
    {"0012345680", "Budi Kapal Laut", "Laki-laki", false},
    {"0012345681", "Dewi Angel", "Perempuan", true},
    {"0012345682", "Rama Rama", "Laki-laki", false},
    {"0012345683", "Nina Bobo", "Perempuan", true},
    {"0012345684", "Fajar Kopling", "Laki-laki", false}};

int jumlah_siswa = 7; // jumlah siswa awal (contoh untuk presentasi)

void tukarSiswa(struct Siswa *a, struct Siswa *b)
{
    struct Siswa temp = *a;
    *a = *b;
    *b = temp;
}

void sortBerdasarkanNISN()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {
            if (strcmp(siswa[j].NISN, siswa[j + 1].NISN) > 0)
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

void sortBerdasarkanNama()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {
            if (strcmp(siswa[j].nama, siswa[j + 1].nama) > 0)
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

void sortBerdasarkanKIP()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {
            // Untuk descending: true (1) duluan, false (0) belakangan
            if (siswa[j].statusKIP < siswa[j + 1].statusKIP) // Diubah agar true duluan
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

void urutkanSiswa()
{
    int pilihan;
    printf("\nUrutkan berdasarkan:\n");
    printf("1. NISN\n");
    printf("2. Nama\n");
    printf("3. Status KIP\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    while (getchar() != '\n')
        ;

    switch (pilihan)
    {
    case 1:
        sortBerdasarkanNISN();
        printf("Berhasil diurutkan berdasarkan NISN.\n");
        break;
    case 2:
        sortBerdasarkanNama();
        printf("Berhasil diurutkan berdasarkan Nama.\n");
        break;
    case 3:
        sortBerdasarkanKIP();
        printf("Berhasil diurutkan berdasarkan Status KIP (descending).\n");
        break;
    default:
        printf("Pilihan tidak valid!\n");
        return;
    }

    printf("\n=== Hasil Urutan Siswa ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("%-3d. %-20s | NISN: %-20s | JK: %-20s | KIP: %-20s\n",
               i + 1,
               siswa[i].nama,
               siswa[i].NISN,
               siswa[i].jenisKelamin,
               siswa[i].statusKIP ? "Ya" : "Tidak");
    }
}

void daftarSiswa()
{
    printf("\n=== Daftar Siswa ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("%-3d. %-20s | NISN: %-20s | JK: %-20s | KIP: %-20s\n",
               i + 1,
               siswa[i].nama,
               siswa[i].NISN,
               siswa[i].jenisKelamin,
               siswa[i].statusKIP ? "Ya" : "Tidak");
    }
}

void daftarKIP()
{
    printf("\n=== Daftar Penerima KIP ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (siswa[i].statusKIP)
            printf("%-3d. %-20s | NISN: %-20s | JK: %-20s\n",
                   i + 1,
                   siswa[i].nama,
                   siswa[i].NISN,
                   siswa[i].jenisKelamin);
    }
}

void tambahSiswa()
{
    bool lanjut = true;

    while (lanjut)
    {
        struct Siswa siswaBaru;

        char jenisKelaminInput;
        int statusKipInput;
        int opsi;

        printf("Masukkan NISN: ");
        scanf(" %[^\n]", siswaBaru.NISN);
        if (strlen(siswaBaru.NISN) != 10)
        {
            printf("\nNISN Harus berisi 10 digit angka.\n");
            continue;
        }

        printf("Masukkan nama: ");
        scanf(" %[^\n]", siswaBaru.nama);
        printf("Masukkan jenis kelamin (L/P): ");
        scanf(" %c", &jenisKelaminInput);

        if (jenisKelaminInput == 'L' || jenisKelaminInput == 'l')
        {
            strcpy(siswaBaru.jenisKelamin, "Laki-laki");
        }
        else if (jenisKelaminInput == 'P' || jenisKelaminInput == 'p')
        {
            strcpy(siswaBaru.jenisKelamin, "Perempuan");
        }
        else
        {
            printf("Masukkan input yang valid.\n");
            continue;
        }

        printf("Status KIP (1 = Ya, 0 = Tidak): ");
        scanf("%d", &statusKipInput);
        siswaBaru.statusKIP = (statusKipInput == 1);

        siswa[jumlah_siswa] = siswaBaru;
        jumlah_siswa++;

        printf("\nApakah anda ingin lanjut mengisi?\n");
        printf("(1 = Ya, 0 = Tidak):");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            printf("\nLanjut Mengisi\n");
            break;
        case 0:
            printf("Siswa berhasil ditambahkan.\n");
            lanjut = false;
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
        }
    }
}

void cariSiswa()
{
    int pilihan;
    printf("\nCari berdasarkan:\n");
    printf("1. NISN\n");
    printf("2. Nama\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    while (getchar() != '\n')
        ;

    char cari[50];
    bool ditemukan = false;

    switch (pilihan)
    {
    case 1:
        printf("Masukkan NISN: ");
        scanf(" %[^\n]", cari);
        for (int i = 0; i < jumlah_siswa; i++)
        {
            if (strcmp(siswa[i].NISN, cari) == 0)
            {
                printf("Ditemukan: %-20s | NISN: %-20s | JK: %-20s | KIP: %-20s\n",
                       siswa[i].nama, siswa[i].NISN, siswa[i].jenisKelamin,
                       siswa[i].statusKIP ? "Ya" : "Tidak");
                ditemukan = true;
            }
        }
        break;
    case 2:
        printf("Masukkan Nama: ");
        scanf(" %[^\n]", cari);
        for (int i = 0; i < jumlah_siswa; i++)
        {
            if (strstr(siswa[i].nama, cari) != NULL)
            {
                printf("Ditemukan: %-20s | NISN: %-20s | JK: %-20s | KIP: %-20s\n",
                       siswa[i].nama, siswa[i].NISN, siswa[i].jenisKelamin,
                       siswa[i].statusKIP ? "Ya" : "Tidak");
                ditemukan = true;
            }
        }
        break;
    default:
        printf("Pilihan tidak valid!\n");
        return;
    }

    if (!ditemukan)
        printf("Siswa tidak ditemukan.\n");
}

void editSiswa()
{
    char nisn[15];
    printf("Masukkan NISN siswa yang ingin diedit: ");
    scanf(" %[^\n]", nisn);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (strcmp(siswa[i].NISN, nisn) == 0)
        {
            ditemukan = true;
            printf("Data siswa ditemukan. Masukkan data baru:\n");

            printf("Masukkan nama baru: ");
            scanf(" %[^\n]", siswa[i].nama);

            char jenisKelaminInput;
            printf("Masukkan jenis kelamin baru (L/P): ");
            scanf(" %c", &jenisKelaminInput);
            if (jenisKelaminInput == 'L' || jenisKelaminInput == 'l')
            {
                strcpy(siswa[i].jenisKelamin, "Laki-laki");
            }
            else if (jenisKelaminInput == 'P' || jenisKelaminInput == 'p')
            {
                strcpy(siswa[i].jenisKelamin, "Perempuan");
            }
            else
            {
                printf("Input tidak valid, jenis kelamin tidak diubah.\n");
            }

            int statusKipInput;
            printf("Status KIP baru (1 = Ya, 0 = Tidak): ");
            scanf("%d", &statusKipInput);
            siswa[i].statusKIP = (statusKipInput == 1);

            printf("Data siswa berhasil diedit.\n");
            break;
        }
    }

    if (!ditemukan)
        printf("Siswa dengan NISN %s tidak ditemukan.\n", nisn);
}

void hapusSiswa()
{
    char nisn[15];
    printf("Masukkan NISN siswa yang ingin dihapus: ");
    scanf(" %[^\n]", nisn);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (strcmp(siswa[i].NISN, nisn) == 0)
        {
            ditemukan = true;
            for (int j = i; j < jumlah_siswa - 1; j++)
            {
                siswa[j] = siswa[j + 1];
            }
            jumlah_siswa--;
            printf("Siswa dengan NISN %s berhasil dihapus.\n", nisn);
            break;
        }
    }

    if (!ditemukan)
        printf("Siswa dengan NISN %s tidak ditemukan.\n", nisn);
}

void presentasePenerimaKIP()
{
    if (jumlah_siswa == 0)
    {
        printf("Data siswa kosong.\n");
        return;
    }

    int jumlahKIP = 0;
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (siswa[i].statusKIP)
            jumlahKIP++;
    }

    float persentase = (jumlahKIP * 100.0) / jumlah_siswa;

    printf("\nJumlah siswa: %d\n", jumlah_siswa);
    printf("Jumlah penerima KIP: %d\n", jumlahKIP);
    printf("Persentase penerima KIP: %.2f%%\n", persentase);
}

void menu()
{
    bool lanjut = true;

    while (lanjut)
    {
        int opsi;
        printf("\n===============================\n");
        printf("      MENU UTAMA PROGRAM      \n");
        printf("===============================\n");
        printf("1. Cari siswa\n");
        printf("2. Menambah siswa\n");
        printf("3. Edit siswa\n");
        printf("4. Hapus siswa\n");
        printf("5. Daftar siswa\n");
        printf("6. Urutkan siswa\n");
        printf("7. Daftar penerima KIP\n");
        printf("8. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1:
            cariSiswa();
            break;
        case 2:
            tambahSiswa();
            break;
        case 3:
            editSiswa();
            break;
        case 4:
            hapusSiswa();
            break;
        case 5:
            daftarSiswa();
            break;
        case 6:
            urutkanSiswa();
            break;
        case 7:
            daftarKIP();
            presentasePenerimaKIP();
            break;
        case 8:
            lanjut = false;
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    }
}
