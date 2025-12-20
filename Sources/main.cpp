#include <iostream>
#include <string>
#include "tubes.h"

using namespace std;

int main(){
    list L;
    adrMahasiswa p;
    adrKegiatan k;
    string nama, nim, kegiatan;
    
    createList(L);

    nama = "Alfa"; nim = "001";
    createMahasiswa(nama, nim);
    p  = findMahasiswa(L, nama, nim);
    addKegiatan(p, "Himpunan Mahasiswa");
    addKegiatan(p, "GDGoC");
    addKegiatan(p, "Event Organizer");
    addKegiatan(p, "Workshop");

    
    nama = "Omega"; nim = "002";
    createMahasiswa(nama, nim);
    p  = findMahasiswa(L, nama, nim);
    addKegiatan(p, "Kompetisi ONMIPA");
    addKegiatan(p, "Pengabdian Masyarakat");
    addKegiatan(p, "Event Organizer");

    nama = "Theta"; nim = "003";
    createMahasiswa(nama, nim);
    p  = findMahasiswa(L, nama, nim);
    addKegiatan(p, "Himpunan Mahasiswa");
    addKegiatan(p, "GDGoC");
    addKegiatan(p, "Event Organizer");
    addKegiatan(p, "Workshop");
    addKegiatan(p, "Competitive Programming");
    addKegiatan(p, "Digital Bussiness Competition");
    addKegiatan(p, "Seminar");
    addKegiatan(p, "Kepanitiaan");

    tampilSemuaMahasiswa(L);
    



    return 0;
}