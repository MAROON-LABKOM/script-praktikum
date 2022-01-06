/*
    Praktikum Struktur Data
	Laboratorium Komputer
	Universitas Pakuan
	2021
*/
#include <iostream>

using namespace std;

int main()
{
	struct data
	{
		char npm[10]= "", nama[21] = "";
		int kehadiran = 0, tugas = 0, uts = 0, uas = 0;
	};

	int jumlah_mahasiswa = 0;
	cout << "Masukan jumlah mahasiswa: ";
	cin >> jumlah_mahasiswa;

	data Mahasiswa[jumlah_mahasiswa];

	for (size_t i = 0; i < jumlah_mahasiswa; i++)
	{
		cout << "Mahasiswa ke-" << (i + 1) << endl;
		cout << "\tMasukan NPM: ";
		fflush(stdin);
		gets(Mahasiswa[i].npm);
		cout << "\tMasukan nama: ";
		fflush(stdin);
		gets(Mahasiswa[i].nama);
		cout << "\tMasukan nilai kehadiran: ";
		cin >> Mahasiswa[i].kehadiran;
		cout << "\tMasukan nilai tugas: ";
		cin >> Mahasiswa[i].tugas;
		cout << "\tMasukan nilai uts: ";
		cin >> Mahasiswa[i].uts;
		cout << "\tMasukan nilai uas: ";
		cin >> Mahasiswa[i].uas;
	}

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
