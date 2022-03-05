#include <iostream>
using namespace std;

int main()
{
  // --- pointer
  int *andi;    // Andi sebagai pointer
  int budi = 5; // Budi bukan pointer, perhatikan perbedaan pada *
  andi = &budi; // Isi dari Andi yaitu alamat Budi

  cout << "Isi alamat memori Andi : " << andi << endl;
  cout << "Isi alamat memori Budi : " << budi << endl;
  cout << "Isi alamat memori Budi : " << *andi << endl;
  cout << "Alamat memori Andi : " << &andi << endl;
  cout << "Alamat memori Budi :" << &budi << endl;

  // --- pointer pada array
  cout << endl << ">> Pointer pada Array" << endl;

  int x[5] = {};
  int *p = 0;
  p = x;

  x[0] = 5;
  x[1] = x[0];
  x[2] = *p + 2;
  x[3] = *(p + 1) - 3;
  x[4] = *(x + 2);

  for (auto i = 0; i < 5; i++)
  {
    cout << "x[" << i << "] = " << x[i] << endl;
  }

  // --- pointer pada C style string
  cout << endl << ">> Pointer pada C Style String" << endl;

  char nama[] = "Andi";
  cout << "Nama awal: " << nama << endl;

  char *ptr;
  ptr = nama;
  *(ptr + 3) = 'y';

  cout << "Nama menjadi: " << nama << endl;
}
