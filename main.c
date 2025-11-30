#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Jangan kebanyakan pakai pointer

#define MAX_STUDENTS 100 // belum dipelajari
#define KIP_QUOTA 10 // belum dipelajari

struct Student
{
    char nisn[20];
    char name[50];
    char gender[10];
    int kip;
};

// sample data
struct Student students[MAX_STUDENTS] = {
    {"0051234567", "Ahmad Saputra", "Laki-laki", 1},
    {"0052234568", "Siti Rahmawati", "Perempuan", 0},
    {"0053234569", "Budi Santoso", "Laki-laki", 1},
    {"0054234570", "Dewi Anggraini", "Perempuan", 1},
    {"0055234571", "Rizky Ananda", "Laki-laki", 0},
    {"0056234572", "Nadia Putri", "Perempuan", 0},
    {"0057234573", "Fajar Hidayat", "Laki-laki", 1}};

int student_count = 7;
int kip_count = 4;

// Fungsi untuk menampilkan menu
void displayMenu()
{
    printf("\n=== Sistem Manajemen Data Siswa ===\n");
    printf("1. Tambah Data Siswa\n");
    printf("2. Edit Data Siswa\n");
    printf("3. Hapus Data Siswa\n");
    printf("4. Urutkan Data Siswa\n");
    printf("5. Cari Data Siswa\n");
    printf("6. Tampilkan Persentase dan Jumlah Penerima KIP\n");
    printf("7. Ubah Status KIP Siswa\n");
    printf("8. Keluar\n");
    printf("Pilih opsi: ");
}

// Fungsi untuk menambah data siswa
void addStudent()
{
    if (student_count >= MAX_STUDENTS)
    {
        printf("Kapasitas siswa penuh!\n");
        return;
    }

    struct Student newStudent;
    printf("Masukkan NISN: ");
    scanf("%s", newStudent.nisn);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", newStudent.name); // Membaca string dengan spasi
    printf("Masukkan Jenis Kelamin (Laki-laki/Perempuan): ");
    scanf("%s", newStudent.gender);
    printf("Status KIP (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &newStudent.kip);

    // Periksa kuota KIP
    if (newStudent.kip == 1 && kip_count >= KIP_QUOTA)
    {
        printf("Kuota KIP penuh! Tidak dapat menambahkan sebagai penerima KIP.\n");
        newStudent.kip = 0;
    }

    students[student_count] = newStudent;
    student_count++;
    if (newStudent.kip == 1)
        kip_count++;
    printf("Data siswa berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan semua data siswa
void displayStudents()
{
    printf("\nDaftar Siswa:\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("%d. NISN: %s, Nama: %s, Gender: %s, KIP: %s\n",
               i + 1, students[i].nisn, students[i].name, students[i].gender,
               students[i].kip ? "Ya" : "Tidak");
    }
}

// Fungsi untuk edit data siswa
void editStudent()
{
    displayStudents();
    int index;
    printf("Masukkan nomor siswa yang ingin diedit: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= student_count)
    {
        printf("Nomor siswa tidak valid!\n");
        return;
    }

    printf("Masukkan NISN baru: ");
    scanf("%s", students[index].nisn);
    printf("Masukkan Nama baru: ");
    scanf(" %[^\n]", students[index].name);
    printf("Masukkan Jenis Kelamin baru (Laki-laki/Perempuan): ");
    scanf("%s", students[index].gender);
    printf("Status KIP baru (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &students[index].kip);

    // Periksa kuota KIP
    if (students[index].kip == 1 && kip_count >= KIP_QUOTA)
    {
        printf("Kuota KIP penuh! Status KIP tidak dapat diubah.\n");
        students[index].kip = 0;
    }

    // Update kip_count
    kip_count = 0;
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].kip)
            kip_count++;
    }

    printf("Data siswa berhasil diubah!\n");
}

// Fungsi untuk hapus data siswa
void deleteStudent()
{
    displayStudents();
    int index;
    printf("Masukkan nomor siswa yang ingin dihapus: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= student_count)
    {
        printf("Nomor siswa tidak valid!\n");
        return;
    }

    if (students[index].kip)
        kip_count--;
    for (int i = index; i < student_count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    student_count--;
    printf("Data siswa berhasil dihapus!\n");
}

// Fungsi compare untuk sorting berdasarkan NISN
int compareNISN(const void *a, const void *b)
{
    return strcmp(((struct Student *)a)->nisn, ((struct Student *)b)->nisn); // belum dipelajar
}

// Fungsi compare untuk sorting berdasarkan Nama
int compareName(const void *a, const void *b)
{
    return strcmp(((struct Student *)a)->name, ((struct Student *)b)->name);
}

// Fungsi compare untuk sorting berdasarkan Status KIP
int compareKIP(const void *a, const void *b)
{
    return ((struct Student *)b)->kip - ((struct Student *)a)->kip; // Ya (1) duluan
}

// Fungsi untuk sorting
void sortStudents()
{
    int choice;
    printf("Urutkan berdasarkan:\n");
    printf("1. NISN\n");
    printf("2. Nama\n");
    printf("3. Status KIP\n");
    printf("Pilih: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        qsort(students, student_count, sizeof(struct Student), compareNISN); // ubah ke bubble/selection sort
        break;
    case 2:
        qsort(students, student_count, sizeof(struct Student), compareName); // ubah ke bubble/selection sort
        break;
    case 3:
        qsort(students, student_count, sizeof(struct Student), compareKIP); // ubah ke bubble/selection sort
        break;
    default:
        printf("Pilihan tidak valid!\n");
        return;
    }
    printf("Data berhasil diurutkan!\n");
    displayStudents();
}

// Fungsi untuk searching
void searchStudent()
{
    int choice;
    printf("Cari berdasarkan:\n");
    printf("1. Nama\n");
    printf("2. NISN\n");
    printf("3. Status KIP\n");
    printf("Pilih: ");
    scanf("%d", &choice);

    char searchStr[50];
    int searchInt;
    int found = 0;

    switch (choice)
    {
    case 1:
        printf("Masukkan Nama: ");
        scanf(" %[^\n]", searchStr);
        for (int i = 0; i < student_count; i++)
        {
            if (strstr(students[i].name, searchStr) != NULL)
            {
                printf("Ditemukan: NISN: %s, Nama: %s, Gender: %s, KIP: %s\n",
                       students[i].nisn, students[i].name, students[i].gender,
                       students[i].kip ? "Ya" : "Tidak");
                found = 1;
            }
        }
        break;
    case 2:
        printf("Masukkan NISN: ");
        scanf("%s", searchStr);
        for (int i = 0; i < student_count; i++)
        {
            if (strcmp(students[i].nisn, searchStr) == 0)
            {
                printf("Ditemukan: NISN: %s, Nama: %s, Gender: %s, KIP: %s\n",
                       students[i].nisn, students[i].name, students[i].gender,
                       students[i].kip ? "Ya" : "Tidak");
                found = 1;
            }
        }
        break;
    case 3:
        printf("Masukkan Status KIP (1 untuk Ya, 0 untuk Tidak): ");
        scanf("%d", &searchInt);
        for (int i = 0; i < student_count; i++)
        {
            if (students[i].kip == searchInt)
            {
                printf("Ditemukan: NISN: %s, Nama: %s, Gender: %s, KIP: %s\n",
                       students[i].nisn, students[i].name, students[i].gender,
                       students[i].kip ? "Ya" : "Tidak");
                found = 1;
            }
        }
        break;
    default:
        printf("Pilihan tidak valid!\n");
        return;
    }

    if (!found)
    {
        printf("Data tidak ditemukan!\n");
    }
}

// Fungsi untuk menampilkan persentase dan jumlah penerima KIP
void displayKIPStats()
{
    printf("Jumlah penerima KIP: %d\n", kip_count);
    if (student_count > 0)
    {
        float percentage = (float)kip_count / student_count * 100;
        printf("Persentase penerima KIP: %.2f%%\n", percentage);
    }
    else
    {
        printf("Tidak ada data siswa.\n");
    }
}

// Fungsi untuk mengubah status KIP
void changeKIPStatus()
{
    displayStudents();
    int index;
    printf("Masukkan nomor siswa yang ingin diubah status KIP-nya: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= student_count)
    {
        printf("Nomor siswa tidak valid!\n");
        return;
    }

    int newStatus;
    printf("Status KIP baru (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &newStatus);

    if (newStatus == 1 && kip_count >= KIP_QUOTA)
    {
        printf("Kuota KIP penuh! Tidak dapat mengubah status.\n");
        return;
    }

    if (students[index].kip != newStatus)
    {
        students[index].kip = newStatus;
        kip_count = 0;
        for (int i = 0; i < student_count; i++)
        {
            if (students[i].kip)
                kip_count++;
        }
        printf("Status KIP berhasil diubah!\n");
    }
    else
    {
        printf("Status sudah sama.\n");
    }
}

int main()

{

    int choice;
    while (1)
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            editStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            sortStudents();
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            displayKIPStats();
            break;
        case 7:
            changeKIPStatus();
            break;
        case 8:
            printf("Keluar dari program.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid!\n");
        }
    }
    return 0;
}


