#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 

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
    {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", "Jl. Sudirman No. 1", "10A", "Ahmad Dhiyaul", true},
    {"0012345679", "Abdullah Koswara", "Laki-laki", "Jl. Thamrin No. 2", "10B", "Koswara Abdullah", false},
    {"0012345680", "Budi Kapal Laut", "Laki-laki", "Jl. Malioboro No. 3", "10A", "Kapal Budi", false},
    {"0012345681", "Dewi Angel", "Perempuan", "Jl. Malioboro No. 4", "10B", "Angel Dewi", true},
    {"0012345682", "Rama Rama", "Laki-laki", "Jl. Sudirman No. 5", "10A", "Rama Rama Sr.", false},
    {"0012345683", "Nina Bobo", "Perempuan", "Jl. Thamrin No. 6", "10B", "Bobo Nina", true},
    {"0012345684", "Fajar Kopling", "Laki-laki", "Jl. Malioboro No. 7", "10A", "Kopling Fajar", false} };

int jumlah_siswa = 7;

// 
bool isValidNISN(const char* nisn, int excludeIndex)
{   
    if (strlen(nisn) != 10)
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(nisn[i])) 
            return false;
    }

    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (i != excludeIndex && strcmp(siswa[i].NISN, nisn) == 0)
            return false;
    }
    return true;
}

// metode swap untuk struct
void tukarSiswa(struct Siswa* a, struct Siswa* b)
{
    struct Siswa temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort berdasarkan nisn
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

// bubble sort berdasarkan nama
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

// bubble sort berdasarkan status KIP
void sortBerdasarkanKIP()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {

            if (siswa[j].statusKIP < siswa[j + 1].statusKIP)
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

// bubble sort berdasarkan kelas dan nama
void sortBerdasarkanKelasDanNama()
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
    {
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {

            // inisiasi strcmp, untuk membancdingkan kelas siswa
            int cmpKelas = strcmp(siswa[j].kelas, siswa[j + 1].kelas);
            // membuat kondisi, ketika siswa semua siswa di kelas yang sama telah di urutkan secara alfabetis, maka akan dilanjut dengan kelas selanjutnya,
            if (cmpKelas > 0 || (cmpKelas == 0 && strcmp(siswa[j].nama, siswa[j + 1].nama) > 0))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
    }
}

// sub menu untuk urutan siswa
void urutkanSiswa()
{
    int pilihan;
    printf("\nUrutkan berdasarkan:\n");
    printf("1. NISN\n");
    printf("2. Nama\n");
    printf("3. Status KIP\n");
    printf("4. Kelas dan Nama\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    while (getchar() != '\n')
        ;

    switch (pilihan)
    {
    case 1:
        // inisiasi sorting berdasarkan NISN
        sortBerdasarkanNISN();
        printf("Berhasil diurutkan berdasarkan NISN.\n");
        break;

    case 2:
        // inisiasi sorting berdasarkan Nama
        sortBerdasarkanNama();
        printf("Berhasil diurutkan berdasarkan Nama.\n");
        break;
    case 3:
        // inisiasi sorting berdasarkan Status-KIP
        sortBerdasarkanKIP();
        printf("Berhasil diurutkan berdasarkan Status KIP (descending).\n");
        break;

    case 4:
        // inisiasi sorting berdasarkan Kelas dan Nama
        sortBerdasarkanKelasDanNama();
        printf("Berhasil diurutkan berdasarkan Kelas dan Nama.\n");
        break;

    default:
        // default ketika pilihan tidak valid
        printf("Pilihan tidak valid!\n");
        return;
    }

    // output hasil urutan sorting berdasarkan opsi yang dipilih
    printf("\n=== Hasil Urutan Siswa ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("%-3d. %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s | KIP: %-20s\n",
            i + 1,
            siswa[i].nama,
            siswa[i].NISN,
            siswa[i].jenisKelamin,
            siswa[i].alamat,
            siswa[i].kelas,
            siswa[i].namaWali,
            siswa[i].statusKIP ? "Ya" : "Tidak");
    }
}

// menampilkan seluruh data siswa yang tersimpan
void daftarSiswa()
{
    printf("\n=== Daftar Siswa ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("%-3d. %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s | KIP: %-20s\n",
            i + 1,
            siswa[i].nama,
            siswa[i].NISN,
            siswa[i].jenisKelamin,
            siswa[i].alamat,
            siswa[i].kelas,
            siswa[i].namaWali,
            siswa[i].statusKIP ? "Ya" : "Tidak");
    }
}


// menampilkan seluruh siswa yang berstatus KIP
void daftarKIP()
{
    printf("\n=== Daftar Penerima KIP ===\n");
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (siswa[i].statusKIP)
            printf("%-3d. %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s\n",
                i + 1,
                siswa[i].nama,
                siswa[i].NISN,
                siswa[i].jenisKelamin,
                siswa[i].alamat,
                siswa[i].kelas,
                siswa[i].namaWali);
    }
}

// fungsi menambah siswa pada array of record/struct
void tambahSiswa()
{
    // inisisasi kondisi loop.
    bool lanjut = true;

    // Loop
    while (lanjut)
    {
        // inisiasi struct siswa baru
        struct Siswa siswaBaru;

        char jenisKelaminInput;
        int statusKipInput;

        // membuat variable opsi untuk, memastikan user ingin menambahkan lagi siswa. 
        int opsi;

        printf("Masukkan NISN: ");
        scanf(" %[^\n]", siswaBaru.NISN);
        if (!isValidNISN(siswaBaru.NISN, -1))
        {
            printf("\nNISN harus berisi 10 digit angka dan unik.\n");
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

        printf("Masukkan alamat: ");
        scanf(" %[^\n]", siswaBaru.alamat);
        printf("Masukkan kelas: ");
        scanf(" %[^\n]", siswaBaru.kelas);
        printf("Masukkan nama wali/orang tua (kepala keluarga): ");
        scanf(" %[^\n]", siswaBaru.namaWali);

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
    printf("3. Kelas\n");
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
                printf("Ditemukan: %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s | KIP: %-20s\n",
                    siswa[i].nama, siswa[i].NISN, siswa[i].jenisKelamin,
                    siswa[i].alamat, siswa[i].kelas, siswa[i].namaWali,
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
                printf("Ditemukan: %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s | KIP: %-20s\n",
                    siswa[i].nama, siswa[i].NISN, siswa[i].jenisKelamin,
                    siswa[i].alamat, siswa[i].kelas, siswa[i].namaWali,
                    siswa[i].statusKIP ? "Ya" : "Tidak");
                ditemukan = true;
            }
        }
        break;
    case 3:
        printf("Masukkan Kelas: ");
        scanf(" %[^\n]", cari);
        for (int i = 0; i < jumlah_siswa; i++)
        {
            if (strcmp(siswa[i].kelas, cari) == 0)
            {
                printf("Ditemukan: %-20s | NISN: %-20s | JK: %-20s | Alamat: %-30s | Kelas: %-10s | Wali: %-20s | KIP: %-20s\n",
                    siswa[i].nama, siswa[i].NISN, siswa[i].jenisKelamin,
                    siswa[i].alamat, siswa[i].kelas, siswa[i].namaWali,
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

            printf("Masukkan alamat baru: ");
            scanf(" %[^\n]", siswa[i].alamat);
            printf("Masukkan kelas baru: ");
            scanf(" %[^\n]", siswa[i].kelas);
            printf("Masukkan nama wali/orang tua baru (kepala keluarga): ");
            scanf(" %[^\n]", siswa[i].namaWali);

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