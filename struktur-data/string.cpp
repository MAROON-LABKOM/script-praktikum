/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>
#include <limits>
#include <string.h> // C-style string

using namespace std;

void c_style_string()
{
  // Metode inisialisasi C string
  // 1. menggunakan tipe data char pointer dengan inisialisasi menggunakan kutip dua
  char *kata1 = "labkom";

  // 2. menggunakan sintaks array C++
  // char* kata2[6] = {};

  // 3. menggunakan keyword new dan sintaks array C++
  // char* kata2 = new char[6];

  // 4. menggunakan fungsi malloc untuk mengalokasikan memori
  // malloc = mengalokasikan sejumlah bytes dan mengembalikan alamat pointer
  //          [sizeof(char) = 1 byte] x [panjang kata pada kata1 = 6] = 6 bytes
  //          jadi fungsi di bawah ini akan mengalokasikan 6 bytes atau sejumlah 6 karakter.
  // memset = mengisi sejumlah bytes dengan sebuah nilai tertentu, pada kasus ini dengan angka 0
  //          jadi semua elemen array akan memiliki nilai 0 atau "NULL terminator" pada tabel ASCII.
  char *kata2 = (char *)malloc(sizeof(char) * 6);
  memset(kata2, 0, sizeof(char) * strlen(kata1));

  // Menampilkan C-string menggunakan operator << pada cout
  cout << ">> Variabel dan nilai awal" << endl;
  cout << "kata1 = " << kata1 << endl;
  cout << "kata2 = " << kata2 << endl;

  // Menyalin C-string dari kata1 ke kata2 menggunakan fungsi strcpy
  // Referensi: https://en.cppreference.com/w/c/string/byte/strcpy
  cout << ">> Menyalin nilai kata1 ke kata2" << endl;
  strcpy(kata2, kata1);
  cout << "kata1 = " << kata1 << endl;
  cout << "kata2 = " << kata2 << endl;

  // Menggabungkan kata1 dan kata2 ke kata2 menggunakan fungsi strcat
  // Referensi: https://en.cppreference.com/w/c/string/byte/strcat
  cout << ">> Menambahkan nilai kata1 ke kata2" << endl;
  strcat(kata2, kata1);
  cout << "kata1 = " << kata1 << endl;
  cout << "kata2 = " << kata2 << endl;

  // Menghitung panjangnya C-string menggunakan fungsi strlen
  // Referensi: https://en.cppreference.com/w/c/string/byte/strlen
  cout << ">> Menghitung jumlah karakter dari kata1 dan kata2" << endl;
  cout << "kata1 = " << strlen(kata1) << endl;
  cout << "kata2 = " << strlen(kata2) << endl;

  // Membandingkan dua C-string, apakah kedua C-string sama atau tidak menggunakan fungsi strcmp
  // Referensi: https://en.cppreference.com/w/c/string/byte/strcmp
  cout << ">> Apakah kata1 dan kata2 identik sama? (sensitive-case alias harus identik)" << endl;
  if (strcmp(kata1, kata2) == 0)
  {
    cout << "Kedua variabel memiliki nilai yang identik sama" << endl;
  }
  else
  {
    cout << "Kedua variabel memiliki nilai yang tidak sama" << endl;
  }

  // Mengambil input dari user menggunakan fungsi cin
  // 1. Menggunakan cin dan operator >> (naive)
  cout << ">> Mengambil input dari console - cara 1" << endl;
  char input_kalimat1[100];
  cin >> input_kalimat1;
  cout << input_kalimat1 << endl;

  // Pada cara 1, apabila Anda menginputkan teks dengan pemisah berupa spasi/tab/enter,
  // maka teks yang akan diambil hanya bagian pertama sebelum karakter pemisah tersebut.
  // Hal ini terjadi karena pada penggunaan operator >> untuk mengambil input, karakter
  // tersebut ("whitespace") dianggap sebagai pemisah, sehingga karakter setelah pemisah
  // akan disimpan pada "buffer", sehingga saat Anda memanggil kembali "cin >>" setelah
  // menginputkan teks, maka teks yang sudah diinputkan sebelumnya yang akan diambil,
  // bukan teks yang baru Anda inputkan.
  // Referensi: https://en.cppreference.com/w/cpp/io/basic_istream/operator_gtgt

  // Karena Anda sudah mengetahui bahwa apabila teks yang Anda inputkan mengandung spasi
  // menggunakan kode di atas akan disimpan pada buffer, maka buffer harus dibersihkan.
  // Hal ini untuk mencegah pemanggilan fungsi pada cin agar tidak menggunakan data lama.
  // Referensi: https://stackoverflow.com/a/34518907/5561144
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // 2. Menggunakan cin.getline
  cout << ">> Mengambil input dari console - cara 2" << endl;
  char *input_kalimat2 = new char[100];
  cin.getline(input_kalimat2, 100); // parameter: buffer, length
  cout << input_kalimat2 << endl;

  // Pada cara 2 ini, fungsi getline akan membaca input sebanyak maksimum jumlah karakter
  // pada parameter kedua dan akan berhenti saat user menekan Enter. Fungsi ini juga
  // akan tetap menyimpan karakter spasi karena pemisah pada fungsi ini adalah Enter.
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/getline
}

void cpp_style_string()
{
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string

  // Metode inisialisasi C++ string
  // Menggunakan tipe data std::string dan kutip dua
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/operator%3D
  string kata1 = "labkom";
  string kata2 = "maroon";

  // Menampilkan string menggunakan operator << pada cout
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/operator_ltltgtgt
  cout << ">> Variabel dan nilai awal" << endl;
  cout << "kata1 = " << kata1 << endl;
  cout << "kata2 = " << kata2 << endl;

  // Menggabungkan dua string
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B
  cout << ">> Menggabungkan dua string" << endl;
  string kalimat1 = kata1 + " " + kata2;
  cout << kalimat1 << endl;

  // Menghitung panjangnya string
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/size
  cout << ">> Menghitung jumlah karakter dari kata1 dan kata2" << endl;
  cout << "kata1 = " << kata1.length() << endl;
  cout << "kata2 = " << kata2.length() << endl;

  // Membandingkan dua string, apakah kedua string sama atau tidak
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/operator_cmp
  cout << ">> Apakah kata1 dan kata2 identik sama? (sensitive-case alias harus identik)" << endl;
  if (kata1 == kata2)
  {
    cout << "Kedua variabel memiliki nilai yang identik sama" << endl;
  }
  else
  {
    cout << "Kedua variabel memiliki nilai yang tidak sama" << endl;
  }

  // Mengambil input dari user menggunakan fungsi cin
  // 1. Menggunakan cin dan operator >> (naive)
  cout << ">> Mengambil input dari console - cara 1" << endl;
  string input_kalimat1;
  cin >> input_kalimat1;
  cout << input_kalimat1 << endl;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // 2. Menggunakan std::getline
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/getline
  cout << ">> Mengambil input dari console - cara 2" << endl;
  string input_kalimat2;
  getline(cin, input_kalimat2); // parameter: stream, buffer
  cout << input_kalimat2 << endl;

  // PERHATIAN
  // cin.getline dan std::getline adalah dua fungsi yang berbeda!

  // Memotong string
  // Referensi: https://en.cppreference.com/w/cpp/string/basic_string/substr
  cout << ">> Memotong string" << endl;
  cout << kata1.substr(0, 3) << endl;
  // ambil 3 karakter dimulai dari karakter pertama
}

int main()
{
  cout << "C style string" << endl;
  c_style_string();

  cout << endl << "C++ style string" << endl;
  cpp_style_string();

  return 0;
}
