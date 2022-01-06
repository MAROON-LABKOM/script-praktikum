/*
    Praktikum Struktur Data
	Laboratorium Komputer
	Universitas Pakuan
	2021
*/
#include <iostream>

#ifndef BANYAK_ELEMEN
#define BANYAK_ELEMEN 7
#endif

int main()
{
	char praktikum[BANYAK_ELEMEN][BANYAK_ELEMEN] = {{'M', 'A', 'R', 'O', 'O', 'N'}, {'L', 'A', 'B', 'K', 'O', 'M'}};
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << "Dimensi ke-" << (i + 1) << std::endl;
		for (size_t j = 0; j < BANYAK_ELEMEN; j++)
		{
			if (praktikum[i][j])
			{
				std::cout << "\tHuruf " << praktikum[i][j] << " ada pada indeks ke-" << j << std::endl;
			}
		}
	}
	return 0;
}