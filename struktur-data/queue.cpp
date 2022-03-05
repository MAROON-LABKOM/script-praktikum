/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

using namespace std;

// --- QUEUE ---

int isiQueue[100];
const int maksimal = 100;
int jumlah = 0;

bool IsEmpty()
{
  return jumlah == 0;
}

bool IsFull()
{
  return jumlah >= maksimal;
}

int ItemsRemaining()
{
  return maksimal - jumlah;
}

int Count()
{
  return jumlah;
}

int MaximumSize()
{
  return maksimal;
}

void Enqueue()
{
  if (IsFull())
  {
    cout << "Queue sudah penuh!" << endl;
    return;
  }

  auto input_nilai = 0;
  cout << "Masukan data: ";
  cin >> input_nilai;

  jumlah += 1;
  isiQueue[jumlah] = input_nilai;
  cout << "Data sudah diinputkan " << input_nilai << endl;
}

void Dequeue()
{
  if (IsEmpty())
  {
    cout << "Queue masih kosong!" << endl;
    return;
  }

  cout << "Membuang data " << isiQueue[1] << endl;
  for (auto i = 1; i <= jumlah; i++)
  {
    isiQueue[i] = isiQueue[i + 1];
  }

  jumlah -= 1;
}

void Clear()
{
  jumlah = 0;
  cout << "Queue sudah bersih" << endl;
}

void Print()
{
  if (IsEmpty())
  {
    cout << "Queue masih kosong!" << endl;
    return;
  }

  cout << "\t";
  for (size_t i = 1; i <= jumlah; i++)
  {
    cout << "[" << isiQueue[i] << "]";
  }
}

int main()
{
  auto pilihan_user = 0;
  auto isLoop = true;

  while (isLoop)
  {
    cout << "Penerapan Queue"
         << "\n1. IsEmpty"
         << "\n2. IsFull"
         << "\n3. Enqueue"
         << "\n4. Dequeue"
         << "\n5. Print"
         << "\n6. Clear"
         << "\n7. Quit" << endl;
    cout << "Masukan pilihan: ";
    cin >> pilihan_user;

    switch (pilihan_user)
    {
    case 1:
      if (IsEmpty())
      {
        cout << "Queue masih kosong." << endl;
        cout << endl;
        break;
      }

      cout << "Queue sudah terisi " << Count() << " elemen" << endl;
      cout << endl;
      break;

    case 2:
      if (IsFull())
      {
        cout << "Queue sudah penuh." << endl;
        cout << endl;
        break;
      }

      cout << "Queue masih sisa " << ItemsRemaining() << " elemen" << endl;
      cout << endl;
      break;

    case 3:
      Enqueue();
      cout << endl;
      break;

    case 4:
      Dequeue();
      cout << endl;
      break;

    case 5:
      Print();
      cout << endl;
      break;

    case 6:
      Clear();
      cout << endl;
      break;

    case 7:
      isLoop = false;
      cout << "Bye!" << endl;
      break;

    default:
      cout << "Salah input!" << endl;
      cout << endl;
      break;
    }
  }
}
