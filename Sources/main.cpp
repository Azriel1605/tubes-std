#include <iostream>
#include <string>
#include "tubes.h"

using namespace std;

int main(){
    list L;
    adrMahasiswa p, q;
    adrKegiatan k;
    string nama, nim, kegiatan;
    
    createList(L);
    
    nama = "Alfa"; nim = "001";
    p = createMahasiswa(nama, nim);
    addMahasiswa(L, p);
    addKegiatan(p, "Himpunan Mahasiswa");
    
    addKegiatan(p, "GDGoC");
    addKegiatan(p, "Event Organizer");
    addKegiatan(p, "Workshop");
    
    nama = "Omega"; nim = "002";
    p = createMahasiswa(nama, nim);
    addMahasiswa(L, p);
    addKegiatan(p, "Kompetisi ONMIPA");
    addKegiatan(p, "Pengabdian Masyarakat");
    addKegiatan(p, "Event Organizer");
    
    nama = "Theta"; nim = "003";
    p = createMahasiswa(nama, nim);
    addMahasiswa(L, p);
    addKegiatan(p, "Himpunan Mahasiswa");
    addKegiatan(p, "GDGoC");
    addKegiatan(p, "Event Organizer");
    addKegiatan(p, "Workshop");
    addKegiatan(p, "Competitive Programming");
    addKegiatan(p, "Digital Bussiness Competition");
    addKegiatan(p, "Seminar");
    addKegiatan(p, "Kepanitiaan");
    
    tampilSemuaMahasiswa(L);
    cout << endl;

    p = findMahasiswa(L, "Theta", "003");
    delKegiatan(p, "Workshop", k);
    cout << "Setelah menghapus kegiatan Workshop dari Theta:" << endl;
    tampilSemuaMahasiswa(L);
    cout << endl;

    cout << "Hapus Mahasiswa Omega beserta kegiatannya:" << endl;
    p = findMahasiswa(L, "Omega", "002");
    delMahasiswa(L, p, q);
    tampilSemuaMahasiswa(L);
    cout << endl;

    cout << "Mahasiswa Paling Aktif:" << endl;
    p = mahasiswaAktif(L);
    if (p){
        cout << "Nama: " << p->info.nama << ", NIM: " << p->info.nim << ", Jumlah Kegiatan: " << hitungKegiatan(p) << endl;
    } else {
        cout << "Data Mahasiswa Kosong" << endl;
    }

    


    
    
    

    return 0;
}