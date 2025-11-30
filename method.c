# include <stdio.h>
# include <stdbool.h>

// struct daftar siswa
typedef struct Siswa {
    char NISN[20];
    char nama[50];
    char jenisKelamin[15];
    bool statusKIP; // true/false
};





// Daftar siswa
void daftarSiswa(struct Siswa dataSiswa[], int banyakSiswa) {
    for (int i = 0; i < banyakSiswa; i++)
    {
        /* code */
    }

}

// Daftar siswa yang menerima bantuan KIP
void daftarKIP(struct Siswa datasiswa[], int banyakSiswa) {
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
void pencarianNama(struct Siswa dataSiswa[], int banyakSiswa) {
}


// Menambah daftar nama siswa
void menambahSiswa() {



}

// Mengedit data siswa yang sudah ada
void mengeditSiswa() {

}

struct Siswa dataSiswa[7] = {
{"0012345678", "Dafa Dhiyaul Haq",   "Laki-laki",  true},
{"0012345679", "Abdullah Koswara",    "Laki-laki",  false},
{"0012345680", "Budi Kapal Laut",   "Laki-laki",  false},
{"0012345681", "Dewi Angel",   "Perempuan",  true},
{"0012345682", "Rama Rama",    "Laki-laki",  false},
{"0012345683", "Nina Bobo",    "Perempuan",  true},
{"0012345684", "Fajar Kopling",  "Laki-laki",  false}
};


// int main() {



//     daftarKIP(dataSiswa, 7);




// }