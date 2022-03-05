/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>
#include <limits>

using namespace std;

struct BiodataMahasiswa
{
  string npm;
  string nama;
  int kehadiran = 0, tugas = 0, uts = 0, uas = 0;
};

int main()
{
  int jumlah_mahasiswa = 0;
  cout << "Masukan jumlah mahasiswa: ";
  cin >> jumlah_mahasiswa;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // ingat kenapa perlu clear buffer?

  BiodataMahasiswa Mahasiswa[jumlah_mahasiswa];

  for (size_t i = 0; i < jumlah_mahasiswa; i++)
  {
    cout << "Mahasiswa ke-" << (i + 1) << endl;
    cout << "\tMasukan NPM: ";
    getline(cin, Mahasiswa[i].npm);
    cout << "\tMasukan nama: ";
    getline(cin, Mahasiswa[i].nama);
    cout << "\tMasukan nilai kehadiran: ";
    cin >> Mahasiswa[i].kehadiran;
    cout << "\tMasukan nilai tugas: ";
    cin >> Mahasiswa[i].tugas;
    cout << "\tMasukan nilai uts: ";
    cin >> Mahasiswa[i].uts;
    cout << "\tMasukan nilai uas: ";
    cin >> Mahasiswa[i].uas;
  }

  cout << endl << " >> DATA NILAI MAHASISWA <<" << endl;
  for (size_t i = 0; i < jumlah_mahasiswa; i++)
  {
    cout << "Mahasiswa ke-" << (i + 1)
         << "\n\tNPM		: " << Mahasiswa[i].npm
         << "\n\tNama		: " << Mahasiswa[i].nama
         << "\n\tKehadiran	: " << Mahasiswa[i].kehadiran
         << "\n\tTugas		: " << Mahasiswa[i].tugas
         << "\n\tUTS		: " << Mahasiswa[i].uts
         << "\n\tUAS		: " << Mahasiswa[i].uas << endl;
  }

  return 0;
}
