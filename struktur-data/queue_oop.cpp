/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

using namespace std;

// --- QUEUE MENGGUNAKAN CLASS ---

class StrukturQueue
{
private:
  int *isiQueue = NULL;
  int maksimal = 0;
  int jumlah = 0;

public:
  StrukturQueue(const int banyaknyaElemen)
  {
    maksimal = banyaknyaElemen;
    isiQueue = new int[maksimal];
  }

  ~StrukturQueue()
  {
    delete[] isiQueue;
  }

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

  void Enqueue(int nilai)
  {
    if (IsFull())
    {
      cout << "Queue sudah penuh!" << endl;
      return;
    }

    jumlah += 1;
    isiQueue[jumlah] = nilai;
    cout << "Data sudah diinputkan " << nilai << endl;
  }

  int Dequeue()
  {
    if (IsEmpty())
    {
      cout << "Queue masih kosong!" << endl;
      return -1;
    }

    auto dequeued = isiQueue[1];
    for (auto i = 1; i <= jumlah; i++)
    {
      isiQueue[i] = isiQueue[i + 1];
    }

    jumlah -= 1;
    return dequeued;
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
    for (auto i = 1; i <= jumlah; i++)
    {
      cout << "[" << isiQueue[i] << "]";
    }
  }
};

// --- MAIN APPLICATION ---

int main()
{
  auto mainLoop = true;
  auto pilihan_user = 0;
  StrukturQueue contohQueue(100);

  while (mainLoop)
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
    {
      if (contohQueue.IsEmpty())
      {
        cout << "Queue masih kosong." << endl;
        cout << endl;
        break;
      }

      cout << "Queue sudah terisi " << contohQueue.Count() << " elemen" << endl;
      cout << endl;
      break;
    }

    case 2:
    {
      if (contohQueue.IsFull())
      {
        cout << "Queue sudah penuh." << endl;
        break;
      }

      cout << "Queue masih sisa " << contohQueue.ItemsRemaining() << endl;
      cout << endl;
      break;
    }

    case 3:
    {
      auto input_nilai = 0;
      cout << "Input angka: ";

      cin >> input_nilai;
      contohQueue.Enqueue(input_nilai);

      cout << "Data sudah diinputkan " << input_nilai << endl;
      cout << endl;
      break;
    }

    case 4:
    {
      auto dequeued = contohQueue.Dequeue();
      cout << "Membuang data " << dequeued << endl;
      cout << endl;
      break;
    }

    case 5:
    {
      contohQueue.Print();
      cout << endl;
      break;
    }

    case 6:
    {
      contohQueue.Clear();
      cout << "Queue dibersihkan" << endl;
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
