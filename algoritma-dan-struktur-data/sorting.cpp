/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <algorithm>
#include <iostream>

using namespace std;

void Print(int arr[], int length)
{
  cout << "Input data: " << endl;
  for (auto i = 0; i < length; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void BubbleSort(int arr[], int length)
{
  int temp = 0;
  for (auto i = 0; i < length - 1; i++)
  {
    for (auto j = 0; j < length - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }

    cout << "Iterasi ke-" << i + 1 << ": ";
    Print(arr, length);
  }
}

void SelectionSort(int arr[], int length)
{
  int matchIndex = 0, tempData1 = 0, tempData2 = 0;
  for (auto i = 0; i < length - 1; i++)
  {
    matchIndex = i;
    tempData1 = arr[i];
    for (auto j = i + 1; j < length; j++)
    {
      if (tempData1 > arr[j])
      {
        matchIndex = j;
        tempData1 = arr[j];
      }
    }

    tempData2 = arr[i];
    arr[i] = arr[matchIndex];
    arr[matchIndex] = tempData2;

    cout << "Iterasi ke-" << i + 1 << ": ";
    Print(arr, length);
  }
}

int main()
{
  int jumlahData = 0;
  cout << "Masukan jumlah data: ";
  cin >> jumlahData;

  int kumpulanData[jumlahData];

  cout << "Masukan data: " << endl;
  for (auto i = 0; i < jumlahData; i++)
  {
    cout << "\tke-" << (i + 1) << " : ";
    cin >> kumpulanData[i];
  }

  // cetak input data
  Print(kumpulanData, jumlahData);

  cout << endl << ">>> Metode Bubble Sort" << endl << endl;
  int copyKumpulanData1[jumlahData];
  std::copy(kumpulanData, kumpulanData + jumlahData, copyKumpulanData1);
  BubbleSort(copyKumpulanData1, jumlahData);

  cout << endl << ">>> Metode Selection Sort" << endl << endl;
  int copyKumpulanData2[jumlahData];
  std::copy(kumpulanData, kumpulanData + jumlahData, copyKumpulanData2);
  SelectionSort(copyKumpulanData2, jumlahData);

  return 0;
}
