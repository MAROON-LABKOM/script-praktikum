#include <iostream>
using namespace std;

// pembuatan fungsi garis()
void garis()
{
  cout << "----------------------" << endl;
}

double perkalian(int a, int b)
{
  return a * b;
}

void tambahReference(int &x)
{
  x = x + 2;
}

void tambahPointer(int* x)
{
  *x = *x + 2;
}

// program utama
int main()
{
  // fungsi tanpa nilai balik
  garis();
  cout << "UNIVERSITAS PAKUAN BOGOR" << endl;
  garis();

  // memanggil fungsi dengan parameter
  cout << endl << ">>> Fungsi dengan parameter" << endl;

  int x = 0, y = 0;
  cout << "masukan nilai x = ";
  cin >> x;
  cout << "masukan nilai y = ";
  cin >> y;

  auto hasil = perkalian(x, y);
  cout << "hasil perkalianya = ";
  cout << x << " x " << y << " = " << hasil << endl;

  // memanggil fungsi dengan parameter reference/pointer
  cout << endl << ">>> Fungsi dengan parameter reference & pointer" << endl;

  int z = 0;
  cout << "Masukan nilai z = ";
  cin >> z;

  cout << "z awal = " << z << endl;
  tambahReference(z);
  cout << "z setelah ditambah = " << z << endl;
  tambahPointer(&z);
  cout << "z setelah ditambah (pointer) = " << z << endl;
}
