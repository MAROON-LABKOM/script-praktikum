/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/
#include <iostream>

using namespace std;

// --- STACK ---

int isiStack[100];
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

void Push()
{
  if (IsFull())
  {
    cout << "Stack sudah penuh!" << endl;
    return;
  }

  auto input_nilai = 0;
  cout << "Masukan data: ";
  cin >> input_nilai;

  jumlah += 1;
  isiStack[jumlah] = input_nilai;
  cout << "Data sudah diinputkan " << input_nilai << endl;
}

void Pop()
{
  if (IsEmpty())
  {
    cout << "Stack masih kosong!" << endl;
    return;
  }

  auto popItem = isiStack[jumlah];
  isiStack[jumlah] = 0;
  jumlah -= 1;

  cout << "Membuang data " << popItem << endl;
}

void Clear()
{
  jumlah = 0;
  cout << "Stack sudah bersih" << endl;
}

void Print()
{
  if (IsEmpty())
  {
    cout << "Belum ada data pada stack" << endl;
    return;
  }

  for (auto i = jumlah; i > 0; i--)
  {
    cout << "\t[" << isiStack[i] << "]";
  }
}

// --- MAIN APPLICATION ---

int main()
{
  auto pilihan_user = 0;
  auto isLoop = true;

  while (isLoop)
  {
    cout << "Penerapan Stack"
         << "\n1. IsEmpty"
         << "\n2. IsFull"
         << "\n3. Push"
         << "\n4. Pop"
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
        cout << "Stack masih kosong." << endl;
        cout << endl;
        break;
      }

      cout << "Stack sudah terisi " << Count() << "elemen" << endl;
      cout << endl;
      break;

    case 2:
      if (IsFull())
      {
        cout << "Stack sudah penuh.";
        cout << endl;
        break;
      }

      cout << "Stack masih sisa " << ItemsRemaining() << " elemen" << endl;
      cout << endl;
      break;

    case 3:
      Push();
      cout << endl;
      break;

    case 4:
      Pop();
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
      cout << "Bye!";
      isLoop = false;
      break;

    default:
      cout << "Salah input!" << endl;
      cout << endl;
      break;
    }
  }
}
