/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

using namespace std;

struct Node {
  string nama;
  Node* next;
};

void print(Node* head) {
  while (head != NULL) {
    cout << head->nama << "->";
    head = head->next;
  }

  cout << endl << endl;
}

int main() {
  cout << " >>> CONTOH LINKED LIST <<<" << endl << endl;

  Node* node1 = NULL;
  Node* node2 = NULL;
  Node* node3 = NULL;

  // Membuat 3 node
  node1 = new Node();
  node2 = new Node();
  node3 = new Node();

  // Menginputkan nilai ke dalam node
  node1->nama = "Fahmi";
  node2->nama = "Noor";
  node3->nama = "Fiqri";

  // Sambungkan node-node
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  // --- menampilkan linked list awal
  cout << "Linked List Awal" << endl;
  print(node1);

  // --- menambahkan elemen pada akhir linked list
  Node* node4 = new Node();
  node4->nama = "Fauzan";
  node3->next = node4;

  cout << "Menambahkan elemen pada akhir linked list" << endl;
  print(node1);

  // --- menambahkan elemen pada awal linked list
  Node* node0 = new Node();
  node0->nama = "Adam";
  node0->next = node1;

  cout << "Menambahkan elemen pada awal linked list" << endl;
  print(node0);

  // --- menambahkan elemen setelah elemen kedua pada linked list
  Node* node12 = new Node();
  node12->nama = "Reyhan";
  node12->next = node2;
  node1->next = node12;

  cout << "Menambahkan elemen pada awal linked list" << endl;
  print(node0);

  // -- mengambil elemen ke-i pada linked list
  cout << "Mengambil elemen ke-2 pada linked list" << endl;

  string nilai_dicari;
  Node* nodeDicari = node0;
  for (auto i = 0; i < 1; i++) {
    nodeDicari = nodeDicari->next;
  };

  cout << nodeDicari->nama << endl << endl;

  // --- menghapus elemen pada akhir linked list
  node3->next = NULL;

  cout << "Menghapus elemen pada akhir linked list" << endl;
  print(node0);

  return 0;
}
