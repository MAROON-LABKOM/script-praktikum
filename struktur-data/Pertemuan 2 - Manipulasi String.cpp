#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char kata1[13] = {'L', 'A', 'B', 'K', 'O', 'M'},
		kata2[13];
	
	cout << "Variabel dan nilai awal" << endl;
	cout << "kata1 = " << kata1 
		<< "\nkata2 = " << kata2 << endl;
	
	cout << "Menyalin nilai kata1 ke kata2" << endl;
	strcpy(kata2, kata1);
	cout << "kata1 = " << kata1 
		<< "\nkata2 = " << kata2 << endl;
	
	cout << "Menambahkan nilai kata1 ke kata2" << endl;
	strcat(kata2, kata1);
	cout << "kata1 = " << kata1 
		<< "\nkata2 = " << kata2 << endl;
	
	cout << "Menghitung jumlah karakter dari kata1 dan kata2" << endl;
	cout << "kata1 = " << strlen(kata1) 
		<< "\nkata2 = " << strlen(kata2) << endl;
	
	cout << "Mengubah kata1 dan kata2 dari huruf besar ke huruf kecil" << endl;
	cout << "kata1 = " << strlwr(kata1) 
		<< "\nkata2 = " << strlwr(kata2) << endl;
	
	cout << "Mengubah kata1 dan kata2 dari huruf besar ke huruf kecil" << endl;
	cout << "kata1 = " << strupr(kata1) 
		<< "\nkata2 = " << strupr(kata2) << endl;
	
	cout << "Apakah kata1 dan kata2 identik sama? (sensitive-case alias harus identik)" << endl;
	if (strcmp(kata1, kata2) == 0)
	{
		cout << "Kedua variabel memiliki nilai yang identik sama" << endl;
	}
	else
	{
		cout << "Kedua variabel memiliki nilai yang tidak sama" << endl;
	}
	
	return 0;
}
