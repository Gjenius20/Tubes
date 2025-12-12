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
    {"0012345678", "Dafa Dhiyaul Haq", "Laki-laki", "Jl. Sudirman No. 1", "10A", "Ahmad", true},
    {"0012345679", "Abdullah Koswara", "Laki-laki", "Jl. Thamrin No. 2", "10B", "Koswara", false},
    {"0012345680", "Budi Kapal Laut", "Laki-laki", "Jl. Malioboro No. 3", "10A", "Kapal Laud", false},
    {"0012345681", "Dewi Angel", "Perempuan", "Jl. Malioboro No. 4", "10B", "Angela", true},
    {"0012345682", "Rama Rama", "Laki-laki", "Jl. Sudirman No. 5", "10A", "Rama Rama", false},
    {"0012345683", "Nina Bobo", "Perempuan", "Jl. Thamrin No. 6", "10B", "Bobo", true},
    {"0012345684", "Fajar Kopling", "Laki-laki", "Jl. Malioboro No. 7", "10A", "Asep Knalpot", false}};

int jumlah_siswa = 7; // jumlah siswa awal (contoh untuk presentasi)

bool isValidNISN(const char *nisn, int excludeIndex)
{
    if (strlen(nisn) != 10)
        return false;
    // Cek tiap karakter apakah digit
    for (int i = 0; i < 10; i++)
    {
        if (nisn[i] < '0' || nisn[i] > '9')
            return false;
    }

    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (i != excludeIndex && strcmp(siswa[i].NISN, nisn) == 0)
            return false;
    }
    return true;
}

void tukarSiswa(struct Siswa *a, struct Siswa *b)
{
    struct Siswa temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort asccending/decending
void sortNISN(bool ascending)
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
            if ((ascending && strcmp(siswa[j].NISN, siswa[j + 1].NISN) > 0) ||
                (!ascending && strcmp(siswa[j].NISN, siswa[j + 1].NISN) < 0))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
}

void sortNama(bool ascending)
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
            if ((ascending && strcmp(siswa[j].nama, siswa[j + 1].nama) > 0) ||
                (!ascending && strcmp(siswa[j].nama, siswa[j + 1].nama) < 0))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
}

void sortKIP(bool ascending)
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
            if ((ascending && siswa[j].statusKIP > siswa[j + 1].statusKIP) ||
                (!ascending && siswa[j].statusKIP < siswa[j + 1].statusKIP))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
}

void sortKelasNama(bool ascending)
{
    for (int i = 0; i < jumlah_siswa - 1; i++)
        for (int j = 0; j < jumlah_siswa - i - 1; j++)
        {
            int cmpKelas = strcmp(siswa[j].kelas, siswa[j + 1].kelas);
            if ((ascending && (cmpKelas > 0 || (cmpKelas == 0 && strcmp(siswa[j].nama, siswa[j + 1].nama) > 0))) ||
                (!ascending && (cmpKelas < 0 || (cmpKelas == 0 && strcmp(siswa[j].nama, siswa[j + 1].nama) < 0))))
                tukarSiswa(&siswa[j], &siswa[j + 1]);
        }
}

// Sub-menu memilih urutan secara langsung
bool pilihUrutan()
{
    int order;
    printf("\nPilih urutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan: ");
    scanf(" %d", &order);

    if (order == 1)
        return true;
    if (order == 2)
        return false;

    printf("Pilihan tidak valid! Default ascending.\n");
    return true;
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
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    int opsi;
    printf("\nPilih urutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan: ");
    scanf("%d", &opsi);

    bool ascending = (opsi == 1) ? true : false;

    switch (pilihan)
    {
    case 1:
        sortNISN(ascending);
        break;

    case 2:
        sortNama(ascending);
        break;
    case 3:
        sortKIP(ascending);
        break;
    case 4:
        sortKelasNama(ascending);
        break;

    default:
        // default ketika pilihan tidak valid
        printf("Pilihan tidak valid!\n");
        return;
    }

    printf("\n+-----+----------------------+--------+--------+\n");
    printf("| No  | Nama                 | Kelas  | KIP    |\n");
    printf("+-----+----------------------+--------+--------+\n");

    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("| %-4d | %-22s | %-6s | %-9s |\n",
               i + 1,
               siswa[i].nama,
               siswa[i].kelas,
               siswa[i].statusKIP ? "Ya" : "Tidak");
    }

    printf("+-----+----------------------+--------+--------+\n");
}

void daftarSiswa()
{
    printf("\n+----------------------------------------------------+\n");
    printf("|                   DAFTAR SISWA                     |\n");
    printf("+------+------------------------+--------+-----------+\n");
    printf("| No   | Nama                   | Kelas  | KIP       |\n");
    printf("+------+------------------------+--------+-----------+\n");

    for (int i = 0; i < jumlah_siswa; i++)
    {
        printf("| %-4d | %-22s | %-6s | %-9s |\n",
               i + 1,
               siswa[i].nama,
               siswa[i].kelas,
               siswa[i].statusKIP ? "Ya" : "Tidak");
    }

    printf("+------+------------------------+--------+-----------+\n");
}
// menampilkan seluruh siswa yang berstatus KIP
void daftarKIP()
{
    printf("\n+----------------------------------------------------+\n");
    printf("|                 DAFTAR PENERIMA KIP                |\n");
    printf("+------+------------------------+--------+-----------+\n");
    printf("| No   | Nama                   | Kelas  | KIP       |\n");
    printf("+------+------------------------+--------+-----------+\n");

    int no = 1;
    for (int i = 0; i < jumlah_siswa; i++)
    {
        if (siswa[i].statusKIP)
        {
            printf("| %-4d | %-22s | %-6s | %-9s |\n",
                   no++,
                   siswa[i].nama,
                   siswa[i].kelas,
                   "Ya");
        }
    }

    printf("+------+------------------------+--------+-----------+\n");
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
                printf("\n+---------------------------------------------------------------+\n");
                printf("|                         DATA SISWA                            |\n");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Field", "Data");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Nama", siswa[i].nama);
                printf("| %-20s | %-38s |\n", "NISN", siswa[i].NISN);
                printf("| %-20s | %-38s |\n", "Jenis Kelamin", siswa[i].jenisKelamin);
                printf("| %-20s | %-38s |\n", "Alamat", siswa[i].alamat);
                printf("| %-20s | %-38s |\n", "Kelas", siswa[i].kelas);
                printf("| %-20s | %-38s |\n", "Wali", siswa[i].namaWali);
                printf("| %-20s | %-38s |\n", "KIP", siswa[i].statusKIP ? "Ya" : "Tidak");
                printf("+----------------------+----------------------------------------+\n");
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
                printf("\n+---------------------------------------------------------------+\n");
                printf("|                         DATA SISWA                            |\n");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Field", "Data");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Nama", siswa[i].nama);
                printf("| %-20s | %-38s |\n", "NISN", siswa[i].NISN);
                printf("| %-20s | %-38s |\n", "Jenis Kelamin", siswa[i].jenisKelamin);
                printf("| %-20s | %-38s |\n", "Alamat", siswa[i].alamat);
                printf("| %-20s | %-38s |\n", "Kelas", siswa[i].kelas);
                printf("| %-20s | %-38s |\n", "Wali", siswa[i].namaWali);
                printf("| %-20s | %-38s |\n", "KIP", siswa[i].statusKIP ? "Ya" : "Tidak");
                printf("+----------------------+----------------------------------------+\n");
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
                printf("\n+---------------------------------------------------------------+\n");
                printf("|                         DATA SISWA                            |\n");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Field", "Data");
                printf("+----------------------+----------------------------------------+\n");
                printf("| %-20s | %-38s |\n", "Nama", siswa[i].nama);
                printf("| %-20s | %-38s |\n", "NISN", siswa[i].NISN);
                printf("| %-20s | %-38s |\n", "Jenis Kelamin", siswa[i].jenisKelamin);
                printf("| %-20s | %-38s |\n", "Alamat", siswa[i].alamat);
                printf("| %-20s | %-38s |\n", "Kelas", siswa[i].kelas);
                printf("| %-20s | %-38s |\n", "Wali", siswa[i].namaWali);
                printf("| %-20s | %-38s |\n", "KIP", siswa[i].statusKIP ? "Ya" : "Tidak");
                printf("+----------------------+----------------------------------------+\n");
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
        printf("\n|===========================================|\n");
        printf("|            MENU UTAMA PROGRAM             |\n");
        printf("|===========================================|\n");
        printf("|  No  |              Pilihan               |\n");
        printf("|-------------------------------------------|\n");
        printf("|   1  | Cari siswa                         |\n");
        printf("|   2  | Menambah siswa                     |\n");
        printf("|   3  | Edit siswa                         |\n");
        printf("|   4  | Hapus siswa                        |\n");
        printf("|   5  | Daftar siswa                       |\n");
        printf("|   6  | Urutkan siswa                      |\n");
        printf("|   7  | Daftar penerima KIP                |\n");
        printf("|   8  | Keluar                             |\n");
        printf("+-------------------------------------------+\n");
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