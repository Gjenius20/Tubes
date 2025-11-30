#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Siswa
{
    char NISN[11];
    char nama[50];
    char jenisKelamin[15];
    bool statusKIP;
};

// jumlah siswa awal (contoh untuk presentasi)
struct Siswa siswa[] = {
    {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", true},
    {"0012345679", "Abdullah Koswara", "Laki-laki", false},
    {"0012345680", "Budi Kapal Laut", "Laki-laki", false},
    {"0012345681", "Dewi Angel", "Perempuan", true},
    {"0012345682", "Rama Rama", "Laki-laki", false},
    {"0012345683", "Nina Bobo", "Perempuan", true},
    {"0012345684", "Fajar Kopling", "Laki-laki", false} };

// menghitung banyak jumlah daftar siswa yang tersimpan.
int jumlah_siswa = sizeof(siswa) / sizeof(siswa[0]);

// fungsi menukar index siswa untuk sorting.
void tukarSiswa(struct Siswa* a, struct Siswa* b)
{
    struct Siswa temp = *a;
    *a = *b;
    *b = temp;
}

// fungsi sorting menggunakan bubble-sort berdasarkan NISN.
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

// fungsi sorting menggunakan bubble-sort berdasarkan Nama.
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

// fungsi sorting menggunakan bubble-sort berdasarkan KIP.
void sortBerdasarkanKIP()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {
            if (siswa[j].statusKIP > siswa[j + 1].statusKIP)
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

// fungsi opsi dalam mengurutkan siswa.
void urutkanSiswa()
{
    int opsi;
    printf("\nUrutkan berdasarkan:\n");
    printf("1. NISN\n");
    printf("2. Nama\n");
    printf("3. Status KIP\n");
    printf("Pilih: ");
    scanf("%d", &opsi);

    switch (opsi)
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
        printf("Berhasil diurutkan berdasarkan Status KIP.\n");
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

// fungsi menampilkan daftar siswa yang tersimpan (tanpa sorting).
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

// fungsi menampilkan daftar siswa yang menerima bantuan KIP.
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

// fungsi menambah siswa kedalam data.
void tambahSiswa()
{
    if (jumlah_siswa >= MAX_SISWA)
    {
        printf("Data siswa penuh!\n");
        return;
    }

    struct Siswa siswaBaru;

    printf("Masukkan NISN: ");
    scanf(" %[^\n]", siswaBaru.NISN);

    printf("Masukkan nama: ");
    scanf(" %[^\n]", siswaBaru.nama);

    // nanti diganti dengan kondisi (malas input capital nya)
    printf("Masukkan jenis kelamin (Laki-laki/Perempuan): ");
    scanf(" %[^\n]", siswaBaru.jenisKelamin);

    int kip;
    printf("Status KIP (1 = Ya, 0 = Tidak): ");
    scanf("%d", &kip);
    siswaBaru.statusKIP = (kip == 1);

    siswa[jumlah_siswa] = siswaBaru;
    jumlah_siswa++;

    printf("Siswa berhasil ditambahkan.\n");
}

void cariSiswa()
{

    for (int i = 0; i < jumlah_siswa; i++)
    {
    }


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

    // Perhitungan persentase dengan bilangan pecahan
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
            printf("Fungsi cari siswa belum tersedia.\n");
            break;
        case 2:
            tambahSiswa();
            break;
        case 3:
            printf("Fungsi edit siswa belum tersedia.\n");
            break;
        case 4:
            printf("Hapus siswa\n");
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
