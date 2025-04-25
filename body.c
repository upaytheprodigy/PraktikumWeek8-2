#include "header.h"


void CreateListKota(ListKota *L) {
    L->FirstKota = Nil;
}

addressKota AlokasiKota(infotype nama_kota) {
    addressKota P = (addressKota)malloc(sizeof(ElmtKota));
    if (P != Nil) {
        strcpy(P->kota, nama_kota);
        P->FirstOrang = Nil;
        P->NextKota = Nil;
    }
    return P;
}

addressOrang AlokasiOrang(infotype nama_orang) {
    addressOrang P = (addressOrang)malloc(sizeof(ElmtOrang));
    if (P != Nil) {
        strcpy(P->nama, nama_orang);
        P->NextOrang = Nil;
    }
    return P;
}


void InsertKota(ListKota *L, infotype nama_kota) {
    addressKota P = AlokasiKota(nama_kota);
    if (P != Nil) {
        P->NextKota = L->FirstKota;
        L->FirstKota = P;
    }
}

// Menambahkan orang ke kota
void InsertOrang(addressKota K, infotype nama_orang) {
    addressOrang P = AlokasiOrang(nama_orang);
    if (P != Nil) {
        P->NextOrang = K->FirstOrang;
        K->FirstOrang = P;
    }
}

// Mencari kota berdasarkan nama
addressKota CariKota(ListKota L, char *nama_kota) {
    addressKota P = L.FirstKota;
    while (P != Nil) {
        if (strcmp(P->kota, nama_kota) == 0) {
            return P;
        }
        P = P->NextKota;
    }
    return Nil;
}

// Menampilkan daftar kota dan orang di dalamnya
void PrintKota(ListKota L) {
    addressKota P = L.FirstKota;
    while (P != Nil) {
        printf("Kota: %s\n", P->kota);
        PrintOrang(P);
        P = P->NextKota;
    }
}

// Menampilkan daftar orang di kota tertentu
void PrintOrang(addressKota K) {
    addressOrang P = K->FirstOrang;
    if (P == Nil) {
        printf("  Daftar orang kosong.\n");
    } else {
        while (P != Nil) {
            printf("  - %s\n", P->nama);
            P = P->NextOrang;
        }
    }
}

// Menghapus semua orang dari kota
void DeleteOrang(addressKota K) {
    addressOrang P = K->FirstOrang;
    while (P != Nil) {
        addressOrang Temp = P;
        P = P->NextOrang;
        free(Temp);
    }
    K->FirstOrang = Nil;
}

// Menghapus kota dari list kota
void DeleteKota(ListKota *L, char *nama_kota) {
    addressKota P = L->FirstKota, Prev = Nil;
    while (P != Nil && strcmp(P->kota, nama_kota) != 0) {
        Prev = P;
        P = P->NextKota;
    }
    if (P != Nil) {
        if (Prev == Nil) {
            L->FirstKota = P->NextKota;
        } else {
            Prev->NextKota = P->NextKota;
        }
        DeleteOrang(P);
        free(P);
    }
}