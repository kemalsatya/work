// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int status_utama = 1; // 0 = berakhir,1 = berjalan, 2 = selesai
    int status_tahapan = 1;
    /*  status_tahapan == 1; mengambil input nama
        status_tahapan == 2; mengambil input no anggota
        status_tahapan == 3; membeli / meminjam
        status_tahapan == 4; mengambil input jumlah buku
        status_tahapan == 5; mengambil input no isbn tiap buku
        status_tahapan == 6; memeriksa adanya voucher dan menghitung total harga
    */

    // Informasi buku sesuai dengan index nya, index 0 di satu array berhubungan dengan array lain sebagai property dari buku
    int array_no_isbn[4] = {1111, 2222, 3333, 4444};
    char array_judul_buku[4][20] = {"'aku'", "'seorang'", "'kapten'", "'baja hitam'"};
    int array_harga_beli[4] = {1500, 2500, 3500, 4500};
    int array_harga_pinjam[4] = {1000, 2000, 3000, 4000};

    // Index dari array-array di atas tidak berpengaruh dengan array_voucher
    int array_voucher[4] = {10, 25, 50, 75};

    // menghitung panjang array yang digunakan
    int panjang_array_no_isbn = sizeof(array_no_isbn) / sizeof(array_no_isbn[0]);
    int panjang_array_voucher = sizeof(array_voucher) / sizeof(array_voucher[0]);
    int panjang_array_judul_buku = sizeof(array_judul_buku) / sizeof(array_judul_buku[0]);

    // Variabel penting
    int cek_isbn = 0;
    int cek_voucher;

    // Variabel untuk struk
    char struk_nama[50];
    int struk_no_anggota;
    int beli_atau_pinjam;
    int struk_jumlah_buku;
    //--------- ai ------------
    int *struk_no_isbn;
    char(*struk_judul_buku)[20];
    //-------------------------
    int harga_sementara = 0;
    float struk_total_harga = 0;
    float struk_voucher;
    float diskon_voucher;

    while (status_utama == 1) // Program dimulai
    {
        while (status_tahapan == 1)
        {
            int tahap_satu = 0;
            printf("\nTahap-1\n");
            printf("1. Masukan nama\n2. Batal\n[Pilih 1/2]\n== ");
            scanf("%d", &tahap_satu);

            //--------------------------------- ai -------------------------------------------
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            } // menghapus newline tersisa dari scanf terkakhir

            switch (tahap_satu)
            {
            case 1:
                printf("Nama = ");
                // scanf("%s", &struk_nama);
                fgets(struk_nama, sizeof(struk_nama), stdin);

                size_t len = strlen(struk_nama);            // Mencari panjang string
                if (len > 0 && struk_nama[len - 1] == '\n') // Periksa karakter terakhir
                {
                    struk_nama[len - 1] = '\0'; // Ganti dengan null
                }

                // Menghapus karakter newline di awal string jika ada
                if (struk_nama[0] == '\n')
                {
                    memmove(struk_nama, struk_nama + 1, len); // memindah string ke kiri 1 langkah
                }
                //----------------------------------------------------------------------------------------

                status_tahapan++;
                break;
            case 2:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("Tidak ada di pilihan\n");
                break;
            }
        }
        while (status_tahapan == 2)
        {
            int tahap_dua = 0;
            printf("\nTahap-2\n");
            printf("1. Masukan no anggota\n2. Kembali\n3. Batal\n[Pilih 1/2/3]\n== ");
            scanf("%d", &tahap_dua);
            switch (tahap_dua)
            {
            case 1:
                printf("No anggota = ");
                scanf("%d", &struk_no_anggota);
                status_tahapan++;
                break;
            case 2:
                status_tahapan--;
                break;
            case 3:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("Tidak ada di opsi");
                break;
            }
        }
        while (status_tahapan == 3)
        {
            int tahap_tiga = 0;
            printf("\nTahap-3");
            printf("\n1. Apakah kamu mau membeli buku?\n2. Apakah kamu mau meminjam buku?\n3. kembali\n4. Batal\n== ");
            scanf("%d", &tahap_tiga);
            switch (tahap_tiga)
            {
            case 1:
                beli_atau_pinjam = 1;
                status_tahapan++;
                break;
            case 2:
                beli_atau_pinjam = 2;
                status_tahapan++;
                break;
            case 3:
                status_tahapan--;
                break;
            case 4:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("\nTidak ada di opsi");
                break;
            }
        }
        while (status_tahapan == 4)
        {
            int tahap_empat = 0;
            printf("\nTahap-4");
            if (beli_atau_pinjam == 1) // membeli
            {
                printf("\n1. Kamu ingin membeli berapa buku?\n2. Kembali\n3. Batal\n[Pilih 1/2/3]\n== ");
            }
            else if (beli_atau_pinjam == 2) // meminjam
            {
                printf("\n1. Kamu ingin meminjam berapa buku?\n2. Kembali\n3. Batal\n[Pilih 1/2/3]\n== ");
            }
            scanf("%d", &tahap_empat);

            switch (tahap_empat)
            {
            case 1:
                printf("Masukan jumlah buku = ");
                scanf("%d", &struk_jumlah_buku);
                //-------------------- ai --------------------------
                struk_no_isbn = malloc(struk_jumlah_buku * sizeof(int));                  // Alokasi dinamis
                struk_judul_buku = malloc(struk_jumlah_buku * sizeof(*struk_judul_buku)); // Alokasi dinamis
                //-------------------- ai --------------------------
                status_tahapan++;
                break;
            case 2:
                status_tahapan--;
                break;
            case 3:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("\nTidak ada di opsi");
                break;
            }
        }
        while (status_tahapan == 5)
        {
            printf("\nTahap-5");
            int tahap_lima = 0;
            printf("\n1. Masukan no isbn\n2. Kembali\n3. Batal\n[Pilih 1/2/3]\n== ");
            scanf("%d", &tahap_lima);
            switch (tahap_lima)
            {
            case 1:
                printf("\nKumpulan isbn =\n");
                for (int j = 0; j < panjang_array_no_isbn; j++)
                {
                    printf("%d\n", array_no_isbn[j]);
                }

                for (int i = 0; i < struk_jumlah_buku;)
                {
                    if (i != struk_jumlah_buku - 1)
                    {
                        printf("Masukan no isbn buku ke-%d = ", i + 1);
                    }
                    else
                    {
                        printf("Masukan no isbn buku terakhir = ");
                    }
                    scanf("%d", &cek_isbn);

                    // Di sini akan mengecek apakah isbn terdaftar atau tidak, apabila terdaftar maka akan masuk ke struk
                    int cek_status_isbn = 0;
                    int index_isbn;
                    for (int k = 0; k < panjang_array_no_isbn; k++)
                    {
                        if (cek_isbn == array_no_isbn[k])
                        {
                            cek_status_isbn += 1;
                            index_isbn = k;
                            break;
                        }
                    }
                    if (cek_status_isbn == 1)
                    {
                        struk_no_isbn[i] = array_no_isbn[index_isbn];
                        // Proses harga
                        // Setelah isbn terverifikasi, menjumlahkan harga-harga dari buku ke variabel sementara sebelum dihitung voucher
                        if (beli_atau_pinjam == 1)
                        {
                            harga_sementara += array_harga_beli[index_isbn];
                        }
                        else if (beli_atau_pinjam == 2)
                        {
                            harga_sementara += array_harga_pinjam[index_isbn];
                        }
                        // masukan struk_judul
                        // Setelah isbn terverifikasi, memasukan judul-judul buku ke dalam array buku yang akan ditampilkan di struk
                        strcpy(struk_judul_buku[i], array_judul_buku[index_isbn]);
                        i++;
                    }
                    else
                    {
                        printf("No isbn tidak tersedia..\n");
                    }
                }
                status_tahapan++;
                break;
            case 2:
                status_tahapan--;
                break;
            case 3:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("Pilihan tidak tersedia");
                break;
            }
        }
        while (status_tahapan == 6)
        {
            printf("\nTahap-6");
            int tahap_enam = 0;
            printf("\n1. Punya voucher?\n2. Tidak ada voucher\n3. Kembali\n4. Batal\n[Pilih 1/2/3/4]\n== ");
            scanf("%d", &tahap_enam);
            int cek_status_voucher = 0;
            int index_voucher;

            switch (tahap_enam)
            {
            case 1:
                // Apabila punya voucher, menginput voucher dan memeriksa apakah voucher terdaftar
                // Voucher tidak berbentuk angka desimal
                printf("Masukan angka voucher = ");
                scanf("%d", &cek_voucher);
                for (int i = 0; i < panjang_array_voucher; i++)
                {
                    if (cek_voucher == array_voucher[i])
                    {
                        cek_status_voucher += 1;
                        index_voucher = i;
                    }
                }
                if (cek_status_voucher == 1) // apabila voucher terverifikasi maka menghitung harga-harga buku dengan voucher
                {
                    struk_voucher = cek_voucher; // tampilan 10
                    diskon_voucher = (float)cek_voucher / 100;
                    struk_total_harga = (float)harga_sementara * (1 - diskon_voucher);
                    status_utama = 2;
                    status_tahapan = 0;
                }
                break;
            case 2:
                status_utama = 2;
                status_tahapan = 0;
                diskon_voucher = 0;
                struk_total_harga = (float)harga_sementara * (1 - diskon_voucher);
                break;
            case 3:
                status_tahapan--;
                break;
            case 4:
                status_utama = 0;
                status_tahapan = 0;
                break;
            default:
                printf("Tidak ada di opsi");
                break;
            }
        }
    } // akhir status_utama 1

    if (status_utama == 0){
        printf("\nProgram dibatalkan...");
    }

    if (status_utama == 2)
    {
        //
        printf("\n========== STRUK ==========");
        printf("\nNama = %s", struk_nama);
        printf("\nNo anggota = %d", struk_no_anggota);
        if (beli_atau_pinjam == 1)
        {
            printf("\nJumlah buku yang dibeli = ");
        }
        else if (beli_atau_pinjam == 2)
        {
            printf("\nJumlah buku yang dipinjam = ");
        }
        printf("%d buku", struk_jumlah_buku);
        printf("\nBuku :\n");
        for (int i = 0; i < struk_jumlah_buku; i++)
        {
            printf("\t%d %s\n", struk_no_isbn[i], struk_judul_buku[i]);
        }
        printf("Total harga = Rp%.2f\n\n", struk_total_harga);
        printf("========== TERIMA KASIH ==========\n\n");
    }
    //-------------------- ai ------------------
    // menghapus alokasi memori yang telah digunakan agar tidak mengalami kebocoran memori dan penurunan performa
    free(struk_no_isbn);
    free(struk_judul_buku);
    //------------------------------------------

    return 0;
}
