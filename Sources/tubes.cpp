#include <iostream>
#include <string>
#include "tubes.h"

using namespace std;

void showMenu(){

    cout << "-------------------------------------------" << endl;
    cout << "Menu Program:" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tambah Kegiatan Mahasiswa" << endl;
    cout << "3. Hapus Mahasiswa" << endl;
    cout << "4. Hapus Kegiatan Mahasiswa" << endl;
    cout << "5. Tampilkan Semua Mahasiswa dan Kegiatannya" << endl;
    cout << "6. Tampilkan Mahasiswa Paling Aktif" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan Anda: ";

}

void createList(list &L){
    // Menerima input list L dan mendefinisikan L sebagai list kosong
    L.first = nullptr; 
};

adrMahasiswa createMahasiswa(string nama, string nim){
    adrMahasiswa p = new elmMahasiswa; 
    p->info.nama = nama; 
    p->info.nim = nim; 
    p->child = nullptr;
    p->next = nullptr;
    return p; 
}

adrKegiatan createKegiatan(string kegiatan){
    adrKegiatan k = new elmKegiatan; 
    k->info = kegiatan; 
    k->next = nullptr; 
    return k; 
}

adrMahasiswa findMahasiswa(list L, string nama, string nim){
    // menerima input address mahasiswa dan list L
    // Mengembalikan address mahasiswa jika ditemukan dalam list
    // dan return null jika tidak ditemukan
    adrMahasiswa q = L.first;
    while (q){
        if (q->info.nama == nama && q->info.nim == nim) {
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
    } else if (!findMahasiswa(L, p->info.nama, p->info.nim)){
        adrMahasiswa q = L.first; 
        
        while (q->next != nullptr) {
            q = q->next; 
        }
        q->next = p;
    }
}

adrKegiatan findKegiatan(adrMahasiswa p, string kegiatan){
    adrKegiatan q = p->child;
    while (q){
        if (q->info == kegiatan){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void addKegiatan(adrMahasiswa p, string kegiatan){
    adrKegiatan k = createKegiatan(kegiatan);
    if (p->child == nullptr) {
        p->child = k;
    } else {
        adrKegiatan q = p->child;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = k;
    }
}

int hitungKegiatan(adrMahasiswa p){
    int jumlah = 0;
    adrKegiatan q;

    if (p != nullptr) {
        adrKegiatan q = p->child;
        while (q != nullptr) {
            jumlah++;
            q = q->next;
        }
    }
    return jumlah; 
}

void tampilKegiatan(adrMahasiswa p){
    if (p == nullptr){
        cout << "Data mahasiswa tidak ada" << endl; 
    } else {
        cout << "Daftar kegiatan dari " << p->info.nama << ":" << endl;

        adrKegiatan q = p->child; 

        if (q == nullptr) {
            cout << "Data kegiatan mahasiswa tidak ada" << endl;
        } else {
            cout << "- " << q->info << endl;
            q = q->next;  
        }
    }
}

void delMahasiswa(list &L,  adrMahasiswa p, adrMahasiswa &out){
    adrMahasiswa q = L.first;

    if (q){ // if list is not empty
        if (q == p){ // if deletion is the first element
            L.first = p->next;
            out = p;
        } else{
            while (q->next && q->next != p){ //find the element before p
                q = q->next;
            }

            if (q->next){ //if the element p exist
                q->next = p->next;
                out = p;
            }
        }
    }
}


void delKegiatan(adrMahasiswa p, string kegiatan, adrKegiatan &out){
    adrKegiatan q = p->child;

    if (q){
        if (q->info == kegiatan){
            p->child = q->next;
            out = q;
        } else{
            while (q->next && q->next->info != kegiatan)
            {
                q = q->next;
            }
        
            if (q->next){
                q->next = q->next->next;
                out = q->next;
            }
        }
    }
}

void tampilSemuaMahasiswa(list L){
    adrMahasiswa p = L.first;
    if (!p){
        cout << "Data Mahasiswa Kosong" << endl;
    } else {
        while (p) { // Loop utama menelusuri mahasiswa
            cout << "Nama Mahasiswa: " << p->info.nama << endl;
            
            // PERBAIKAN: q harus diatur ulang ke anak (child) mahasiswa saat ini (p)
            adrKegiatan q = p->child; 
            
            cout << "Kegiatan: ";
            if (!q){
                cout << "-";
            } else {
                while (q) { // Loop menelusuri kegiatan mahasiswa p
                    cout << q->info << ", ";
                    q = q->next;
                }
            }
            cout << endl;
            p = p->next; // Pindah ke mahasiswa berikutnya
        }
    }
}

int jumlahKegiatanMahasiswa(adrMahasiswa p){
    adrKegiatan q = p->child;
    int n = 0;

    while (q)
    {
        n = n+1;
        q = q->next;
    }

    return n;
    
}

adrMahasiswa mahasiswaAktif(list L){
    adrMahasiswa p = L.first;
    adrMahasiswa temp = p;
    int mx = -1;
    int n;

    while (p)
    {
        n = jumlahKegiatanMahasiswa(p);
        if (n > mx){
            mx = n;
            temp = p;
        }

        p = p->next;
    }

    return temp;
}


