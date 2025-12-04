#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SISWA 100

struct Siswa
{
    char NISN[15];
    char nama[50];
    char jenisKelamin[15];
    char alamat[100];
    char kelas[10];
    char namaWali[50];   
    bool statusKIP;
};

struct Siswa siswa[MAX_SISWA] = {
    {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", "Jl. Sudirman", "10A", "Pak Ahmad", true},
    {"0012345679", "Abdullah Koswara", "Laki-laki", "Jl. Thamrin", "10B", "Pak Budi", false},
    {"0012345680", "Budi Kapal Laut", "Laki-laki", "Jl. Malioboro", "10A", "Pak Joko", false},
    {"0012345681", "Dewi Angel", "Perempuan", "Jl. Malioboro", "10B", "Bu Siti", true},
    {"0012345682", "Rama Rama", "Laki-laki", "Jl. Sudirman", "10A", "Pak Dedi", false},
    {"0012345683", "Nina Bobo", "Perempuan", "Jl. Thamrin", "10B", "Bu Rina", true},
    {"0012345684", "Fajar Kopling", "Laki-laki", "Jl. Malioboro", "10A", "Pak Agus", false}
};

int jumlah_siswa = 7;

void tukarSiswa(struct Siswa *a, struct Siswa *b)
{
    struct Siswa temp = *a;
    *a = *b;
    *b = temp;
}


void sortBerdasarkanKelas()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
            if (strcmp(siswa[j].kelas, siswa[j + 1].kelas) > 0 ||
               (strcmp(siswa[j].kelas, siswa[j + 1].kelas) == 0 &&
                strcmp(siswa[j].nama, siswa[j + 1].nama) > 0))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
}


void daftarSiswa()
{
    printf("\n==============================================================================================\n");
    printf("| No | NISN       | Nama                 | JK         | Kelas | Wali            | KIP |\n");
    printf("==============================================================================================\n");

    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("| %-2d | %-10s | %-20s | %-10s | %-5s | %-15s | %-3s |\n",
               i + 1,
               siswa[i].NISN,
               siswa[i].nama,
               siswa[i].jenisKelamin,
               siswa[i].kelas,
               siswa[i].namaWali,
               siswa[i].statusKIP ? "Ya" : "No");
    }

    printf("==============================================================================================\n");
}


void cariBerdasarkanKelas()
{
    char kelas[10];
    printf("Masukkan kelas yang dicari: ");
    scanf(" %[^\n]", kelas);

    bool ditemukan = false;

    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (strcmp(siswa[i].kelas, kelas) == 0)
        {
            printf("%s | %s | %s\n",
                   siswa[i].nama,
                   siswa[i].NISN,
                   siswa[i].namaWali);
            ditemukan = true;
        }
    }

    if (!ditemukan)
        printf("Tidak ada siswa di kelas tersebut.\n");
}


void tambahSiswa()
{
    if (jumlah_siswa >= MAX_SISWA)
    {
        printf("Data penuh!\n");
        return;
    }

    struct Siswa s;

    printf("NISN: ");
    scanf(" %[^\n]", s.NISN);

    printf("Nama: ");
    scanf(" %[^\n]", s.nama);

    printf("Jenis Kelamin: ");
    scanf(" %[^\n]", s.jenisKelamin);

    printf("Alamat: ");
    scanf(" %[^\n]", s.alamat);

    printf("Kelas: ");
    scanf(" %[^\n]", s.kelas);

    printf("Nama Wali: ");
    scanf(" %[^\n]", s.namaWali);

    int kip;
    printf("Status KIP (1/0): ");
    scanf("%d", &kip);
    s.statusKIP = kip == 1;

    siswa[jumlah_siswa++] = s;
    printf("Siswa berhasil ditambah.\n");
}

void menu()
{
    int opsi;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Daftar Siswa\n");
        printf("2. Tambah Siswa\n");
        printf("3. Urutkan Berdasarkan Kelas\n");
        printf("4. Cari Berdasarkan Kelas\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &opsi);

        switch (opsi)
        {
        case 1: daftarSiswa(); break;
        case 2: tambahSiswa(); break;
        case 3: sortBerdasarkanKelas(); daftarSiswa(); break;
        case 4: cariBerdasarkanKelas(); break;
        case 5: return;
        default: printf("Pilihan tidak valid!\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}
