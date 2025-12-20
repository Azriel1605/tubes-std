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

#endif;