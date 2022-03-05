#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // --- menulis ke file
  cout << ">>> Menulis ke File" << endl;
  ofstream file_keluaran;
  file_keluaran.open("a.txt");

  cout << "sedang merekam.. " << endl;
  file_keluaran << "Haloo " << endl;
  file_keluaran << "INI ADALAH SAYA" << endl;
  file_keluaran << "KRISNA" << endl;
  file_keluaran.close();

  // --- membaca dari file
  cout << endl << ">>> Membaca dari File" << endl;

  string line;
  ifstream file_input;
  file_input.open("a.txt");

  cout << "Membaca isi file latihan.txt" << endl;
  while (file_input)
  {
    getline(file_input, line);
    cout << line << endl;
  }
}
