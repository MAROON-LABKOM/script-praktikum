/*
    Praktikum Struktur Data
	Laboratorium Komputer
	Universitas Pakuan
	2021
*/
#include <iostream>

using namespace std;

void Print(unsigned int arr[], int length)
{
    cout << "Data:" << endl
         << "\t";
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(unsigned int arr[], int length)
{
    int data_iteration = 0, temporary_data1 = 0, temporary_data2 = 0;
    for (size_t i = 0; i < length - 1; i++)
    {
        data_iteration = i;
        temporary_data1 = arr[i];
        for (size_t j = i + 1; j < length; j++)
        {
            if (temporary_data1 > arr[j])
            {
                data_iteration = j;
                temporary_data1 = arr[j];
            }
        }
        temporary_data2 = arr[i];
        arr[i] = arr[data_iteration];
        arr[data_iteration] = temporary_data2;
    }
}

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

    Print(data, jumlah_data);

    SelectionSort(data, jumlah_data);

    Print(data, jumlah_data);

    return 0;
}