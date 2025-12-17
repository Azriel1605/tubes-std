#include <iostream>
#include <string>
#include "tubes.h"

using namespace std;

void createList(list &L){
    // Menerima input list L dan mendefinisikan L sebagai list kosong
    L.first = nullptr; 
};

adrMahasiswa createMahasiswa(string nama, string nim){
    adrMahasiswa p = new elmMahasiswa; 
    p->info.nama = nama; 
    p->info.nim = nim; 
    p->child = nullptr;
    return p; 
}

adrMahasiswa findMahasiswa(list L, adrMahasiswa p){
    // menerima input address mahasiswa dan list L
    // Mengembalikan address mahasiswa jika ditemukan dalam list
    // dan return null jika tidak ditemukan
    adrMahasiswa q = L.first;
    while (q){
        if (q->info.nama == p->info.nama && q->info.nim == p->info.nim) {
            return q; 
        }
        q = q->next; 
     }
     return nullptr;     
}

void addMahasiswa(list &L, adrMahasiswa p){
    // Menerima input address mahasiswa dan List L yang mungkin kosong;
    // Melakukan cek jika mahasiswa sudah terdaftar
    // Menambahkan mahasiswa baru pada list paling akhir
    if (!L.first){
        L.first = p;
    } else if (!findMahasiswa(L, p)){
        adrMahasiswa q = L.first; 
        
        while (q->next != nullptr) {
            q = q->next; 
        }
        q->next = p; 
    }
}

adrKegiatan findKegiatan(adrMahasiswa p, string kegiatan){
    adrKegiatan q = p->child;
}

void addKegiatan(adrMahasiswa p, string kegiatan){
    adrKegiatan q = p->child;
    while (q->next)
    {
        q = q->next;
    }

    q->info = kegiatan;
}

