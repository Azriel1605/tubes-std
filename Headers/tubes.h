#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <string>

using namespace std; 

struct elmMahasiswa;
struct elmKegiatan;
typedef elmMahasiswa *adrMahasiswa;
typedef elmKegiatan *adrKegiatan;


typedef mahasiswa infotype;

struct mahasiswa {
    string nama; 
    int nim; 
};

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

#endif;