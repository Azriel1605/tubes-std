#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <string>

using namespace std; 

struct elmMahasiswa;
struct elmKegiatan;
typedef elmMahasiswa *adrMahasiswa;
typedef elmKegiatan *adrKegiatan;

struct mahasiswa {
    string nama; 
    string nim; 
};

typedef mahasiswa infotype;

struct elmMahasiswa {
    adrMahasiswa next;
    adrKegiatan child;
    infotype info;
};

struct list {
    adrMahasiswa first; 
};

struct elmKegiatan {
    adrKegiatan next; 
    string info; 
};

void showMenu();
void createList(list &L);
adrMahasiswa createMahasiswa(string nama, string nim);
adrKegiatan createKegiatan(string kegiatan);
adrMahasiswa findMahasiswa(list L, string nama, string nim);
void addMahasiswa(list &L, adrMahasiswa p);
adrKegiatan findKegiatan(adrMahasiswa p, string kegiatan);
void addKegiatan(adrMahasiswa p, string kegiatan);
int hitungKegiatan(adrMahasiswa p);
void tampilKegiatan(adrMahasiswa p);
void delMahasiswa(list &L,  adrMahasiswa p, adrMahasiswa &out);
void delKegiatan(adrMahasiswa p, string kegiatan, adrKegiatan &out);
void tampilSemuaMahasiswa(list L);
int jumlahKegiatanMahasiswa(adrMahasiswa p);
adrMahasiswa mahasiswaAktif(list L);


#endif