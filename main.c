#include "header.h"

int main() {
    ListKota L;
    CreateListKota(&L);

    int pilihan;
    char nama_kota[50], nama_orang[50];
    addressKota K;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Orang ke Kota\n");
        printf("3. Tampilkan Data Kota dan Orang\n");
        printf("4. Hapus Kota\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                scanf("%s", nama_kota);
                InsertKota(&L, nama_kota);
                printf("Kota '%s' berhasil ditambahkan.\n", nama_kota);
                break;

            case 2:
                printf("Masukkan nama kota: ");
                scanf("%s", nama_kota);
                K = CariKota(L, nama_kota);
                if (K != Nil) {
                    printf("Masukkan nama orang: ");
                    scanf("%s", nama_orang);
                    InsertOrang(K, nama_orang);
                    printf("Orang '%s' berhasil ditambahkan ke kota '%s'.\n", nama_orang, nama_kota);
                } else {
                    printf("Kota '%s' tidak ditemukan.\n", nama_kota);
                }
                break;

            case 3:
                printf("\nData Kota dan Orang:\n");
                PrintKota(L);
                break;

            case 4:
                printf("Masukkan nama kota yang akan dihapus: ");
                scanf("%s", nama_kota);
                DeleteKota(&L, nama_kota);
                printf("Kota '%s' berhasil dihapus.\n", nama_kota);
                break;

            case 5:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}