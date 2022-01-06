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

void BubbleSort(unsigned int arr[], int length)
{
    int temporary = 0;
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temporary = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temporary;
            }
        }
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

    BubbleSort(data, jumlah_data);

    Print(data, jumlah_data);

    return 0;
}