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

    int choice = -1;
    while (choice != 0)
    {
        showMenu();
        cin >> choice;
        if (choice == 1){
            // Tambah Mahasiswa
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            addMahasiswa(L, createMahasiswa(nama, nim));
        } else if (choice == 2){
            // Tambah Kegiatan Mahasiswa
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            p = findMahasiswa(L, nama, nim);
            cout << "Masukkan kegiatan mahasiswa: ";
            cin >> kegiatan;
            addKegiatan(p, kegiatan);
        } else if (choice == 3){
            // Hapus Mahasiswa
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            p = findMahasiswa(L, nama, nim);
            delMahasiswa(L, p, q);
        } else if (choice == 4){
            // Hapus Kegiatan Mahasiswa
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            p = findMahasiswa(L, nama, nim);
            delKegiatan(p, kegiatan, k);
        } else if (choice == 5){
            // Tampilkan Semua Mahasiswa dan Kegiatannya
            tampilSemuaMahasiswa(L);
        } else if (choice == 6){
            // Tampilkan Mahasiswa Paling Aktif
            p = mahasiswaAktif(L);
            if (p != nullptr){
                cout << "Mahasiswa paling aktif adalah " << p->info.nama << " dengan " << jumlahKegiatanMahasiswa(p) << " kegiatan." << endl;
            } else {
                cout << "Data mahasiswa kosong." << endl;
            }
        } else if (choice == 0){
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    

    return 0;
}