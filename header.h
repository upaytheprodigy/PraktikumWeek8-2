#ifndef header_H
#define header_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define MAX_NAMA 30

typedef char infotype[MAX_NAMA];
typedef struct tElmtOrang *addressOrang;
typedef struct tElmtKota *addressKota;

// Struktur untuk orang
typedef struct tElmtOrang {
    infotype nama;
    addressOrang NextOrang;
} ElmtOrang;

// Struktur untuk kota
typedef struct tElmtKota {
    infotype kota;
    addressOrang FirstOrang;
    addressKota NextKota;
} ElmtKota;

// Linear list untuk kota
typedef struct {
    addressKota FirstKota;
} ListKota;

// Fungsi dan prosedur
void CreateListKota(ListKota *L);
addressKota AlokasiKota(infotype nama_kota);
addressOrang AlokasiOrang(infotype nama_orang);
void InsertKota(ListKota *L, infotype nama_kota);
void InsertOrang(addressKota K, infotype nama_orang);
void PrintKota(ListKota L);
void PrintOrang(addressKota K);
addressKota CariKota(ListKota L, char *nama_kota);
void DeleteOrang(addressKota K);
void DeleteKota(ListKota *L, char *nama_kota);

#endif