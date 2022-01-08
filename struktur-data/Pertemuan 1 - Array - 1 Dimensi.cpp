/*
    Praktikum Struktur Data
	Laboratorium Komputer
	Universitas Pakuan
	2021
*/
#include <iostream>

int main()
{
	char praktikum[] = "LABKOM";
	std::cout << praktikum << std::endl;
	for (size_t i = 0; i < sizeof(praktikum); i++)
	{
		if (praktikum[i])
		{
			std::cout << "Huruf " << praktikum[i] << " ada pada indeks ke-" << i << std::endl;
		}
	}
	return 0;
}