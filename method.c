#include <stdio.h>
#include <stdbool.h>

// struct daftar siswa

struct Siswa
{
    int NISN[10];
    char nama[50];
    char jenisKelamin[15];
    bool statusKIP; // true/false
};

// void buatTabel()
// {
//     printf("");
// }

// mengurutkan nisn/nama
void urutkanSiswa() {}

// Daftar siswa
void daftarSiswa(struct Siswa dataSiswa[], int banyakSiswa)
{
    for (int i = 0; i < banyakSiswa; i++)
    {

        printf("%d %s\n", i + 1, datasiswa[i].nama);
    }
}

// Daftar siswa yang menerima bantuan KIP
void daftarKIP(struct Siswa datasiswa[], int banyakSiswa)
{
    printf("Daftar siswa yang menerima bantuan KIP");
    for (int i = 0; i < banyakSiswa; i++)
    {
        if (datasiswa[i].statusKIP)
        {
            printf("%s\n", datasiswa[i].nama);
        }
    }
};

// Pencarian nama / Nisn / Kelamin Siswa
void pencarianNama(struct Siswa dataSiswa[], int banyakSiswa)
{
}

// Menambah daftar nama siswa
void menambahSiswa()
{
}

// Mengedit data siswa yang sudah ada
void mengeditSiswa()
{
}
void menghapusSiswa()
{
}

// struct Siswa dataSiswa[] = {
//     {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", true},
//     {"0012345679", "Abdullah Koswara", "Laki-laki", false},
//     {"0012345680", "Budi Kapal Laut", "Laki-laki", false},
//     {"0012345681", "Dewi Angel", "Perempuan", true},
//     {"0012345682", "Rama Rama", "Laki-laki", false},
//     {"0012345683", "Nina Bobo", "Perempuan", true},
//     {"0012345684", "Fajar Kopling", "Laki-laki", false}};

// int main() {
//     daftarKIP(dataSiswa, 7);
// }

void menu()
{
    printf("\n===============================\n");
    printf(" Selamat datang di daftar menu \n");
    printf("===============================\n");
    printf("Pilih salah satu opsi dibawah:\n");
    printf("1. Cari siswa\n");
    printf("2. Menambah siswa\n");
    printf("3. Edit siswa\n");
    printf("4. Daftar siswa\n");
    printf("5. Daftar penerima KIP\n");
    printf("===============================\n");
    printf("Pilih menu: ");
}