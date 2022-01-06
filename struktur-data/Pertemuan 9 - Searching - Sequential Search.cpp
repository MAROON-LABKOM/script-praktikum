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
    int jumlah_data = 0;
    cout << "Masukan jumlah data: ";
    cin >> jumlah_data;

    unsigned int data[jumlah_data];

    cout << "Masukan data: " << endl;
    for (size_t i = 0; i < jumlah_data; i++)
    {
        cout << "\tke-" << (i + 1) << " : ";
        cin >> data[i];
    }

    int cari_data = 0;
    cout << "Data yang dicari: ";
    cin >> cari_data;

    int jumlah_ditemukan = 0;

    for (size_t i = 0; i < jumlah_data; i++)
    {
        if (data[i] == cari_data)
        {
            jumlah_ditemukan += 1;
            cout << "Data ditemukan pada indeks ke-" << i << " (data ke-" << (i + 1) << ")" << endl;
        }
    }

    if (jumlah_ditemukan > 0)
    {
        cout << "Jumlah data ditemukan: " << jumlah_ditemukan << endl;
    }
    else
    {
        cout << "Tidak dapat menemukan data" << endl;
    }

    return 0;
}