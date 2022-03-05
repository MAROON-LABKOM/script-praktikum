/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

using namespace std;

// --- STACK MENGGUNAKAN CLASS ---

class StrukturStack
{
private:
  int *isiStack = NULL;
  int maksimal = 0, jumlah = 0;

public:
  // constructor, dipanggil saat membuat instance baru dari kelas ini
  StrukturStack(int banyaknyaElemen)
  {
    isiStack = new int[maksimal];
    maksimal = banyaknyaElemen;
  }

  // destructor, dipanggil saat instance dihapus
  ~StrukturStack()
  {
    delete[] isiStack;
  }

  // cek apakah stack kosong
  bool IsEmpty()
  {
    return jumlah == 0;
  }

  // cek apakah stack penuh
  bool IsFull()
  {
    return jumlah >= maksimal;
  }

  // cek berapa banyak sisa elemen yang tersedia
  int ItemsRemaining()
  {
    return maksimal - jumlah;
  }

  // cek berapa banyak elemen yang ada di stack
  int Count()
  {
    return jumlah;
  }

  // cek berapa banyak elemen maksimal yang dapat diisi
  int MaximumSize()
  {
    return maksimal;
  }

  // menambahkan elemen ke stack paling atas
  void Push(int nilai)
  {
    if (IsFull())
    {
      cout << "Stack sudah penuh!" << endl;
    }

    jumlah++;
    isiStack[jumlah] = nilai;
  }

  // menghapus elemen dari stack paling atas
  int Pop()
  {
    if (IsEmpty())
    {
      cout << "Stack masih kosong!" << endl;
      return -1;
    }

    auto popItem = isiStack[jumlah];
    isiStack[jumlah] = 0;
    jumlah -= 1;

    return popItem;
  }

  // membersihkan semua elemen pada stack
  void Clear()
  {
    jumlah = 0;
    fill(isiStack, isiStack + maksimal, 0);
    cout << "Stack sudah bersih" << endl;
  }

  // menampilkan isi stack
  void Print()
  {
    if (IsEmpty())
    {
      cout << "Stack masih kosong!" << endl;
      return;
    }

    for (auto i = jumlah; i > 0; i--)
    {
      cout << "[" << isiStack[i] << "]";
    }
  }
};

// --- MAIN APPLICATION ---

int main()
{
  auto mainLoop = true;
  auto pilihan_user = 0;
  StrukturStack contohStack(100);

  while (mainLoop)
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
    {
      if (contohStack.IsEmpty())
      {
        cout << "Stack masih kosong." << endl;
        cout << endl;
        break;
      }

      cout << "Stack sudah terisi " << contohStack.Count() << " elemen" << endl;
      cout << endl;
      break;
    }

    case 2:
    {
      if (contohStack.IsFull())
      {
        cout << "Stack sudah penuh." << endl;
        break;
      }

      cout << "Stack masih sisa " << contohStack.ItemsRemaining() << endl;
      cout << endl;
      break;
    }

    case 3:
    {
      auto input_nilai = 0;
      cout << "Input angka: ";

      cin >> input_nilai;
      contohStack.Push(input_nilai);

      cout << "Data sudah diinputkan " << input_nilai << endl;
      cout << endl;
      break;
    }

    case 4:
    {
      auto pop_nilai = contohStack.Pop();
      cout << "Membuang data " << pop_nilai << endl;
      cout << endl;
      break;
    }

    case 5:
    {
      contohStack.Print();
      cout << endl;
      break;
    }

    case 6:
    {
      contohStack.Clear();
      cout << "Stack dibersihkan" << endl;
      cout << endl;
      break;
    }

    case 7:
    {
      cout << "Bye!";
      mainLoop = false;
      break;
    }

    default:
    {
      cout << "Salah input!" << endl;
      cout << endl;
      break;
    }
    }
  }
}
