/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

void array_1d()
{
  int praktikum[] = {1, 2, 3, 4, 5};

  for (size_t i = 0; i < sizeof(praktikum) / sizeof(int); i++)
  {
    if (praktikum[i])
    {
      std::cout << "Huruf " << praktikum[i] << " ada pada indeks ke-" << i << std::endl;
    }
  }
}

void array_2d()
{
  const int BANYAK_ELEMEN = 6;
  char praktikum[BANYAK_ELEMEN][BANYAK_ELEMEN] = {{'M', 'A', 'R', 'O', 'O', 'N'}, {'L', 'A', 'B', 'K', 'O', 'M'}};

  for (size_t i = 0; i < 2; i++)
  {
    std::cout << "Dimensi ke-" << (i + 1) << std::endl;
    for (size_t j = 0; j < BANYAK_ELEMEN; j++)
    {
      std::cout << "\tHuruf " << praktikum[i][j] << " ada pada indeks ke-" << j << std::endl;
    }
  }
}

int main()
{
  std::cout << "Array 1 dimensi" << std::endl;
  array_1d();

  std::cout << "Array 2 dimensi" << std::endl;
  array_2d();

  return 0;
}