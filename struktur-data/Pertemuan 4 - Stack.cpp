/*
    Praktikum Struktur Data
	Laboratorium Komputer
	Universitas Pakuan
	2021
*/
#include <iostream>

#ifndef JUMLAH_MAKSIMAL_AWAL
#define JUMLAH_MAKSIMAL_AWAL 10
#endif

#ifndef NAMA_STACK
#define NAMA_STACK praktikum
#endif

using namespace std;

struct stack
{
    int data[JUMLAH_MAKSIMAL_AWAL], maksimal = 0, jumlah = 0;
};

stack NAMA_STACK;

bool isEmpty(int max)
{
    if (NAMA_STACK.jumlah == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(int max)
{
    if (NAMA_STACK.jumlah >= max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(int max)
{
    if (isFull(max) == false)
    {
        NAMA_STACK.jumlah += 1;
        cout << "Masukan data: ";
        cin >> NAMA_STACK.data[NAMA_STACK.jumlah];
    }
    else
    {
        cout << "Stack sudah penuh!" << endl;
    }
}

void Pop(int max)
{
    if (isEmpty(max) == false)
    {
        cout << "Membuang data " << NAMA_STACK.data[NAMA_STACK.jumlah] << endl;
        NAMA_STACK.jumlah -= 1;
    }
    else
    {
        cout << "Stack masih kosong!" << endl;
    }
}

void Clear()
{
    NAMA_STACK.jumlah = 0;
    cout << "Stack sudah bersih" << endl;
}

void Print(int max)
{
    if (isEmpty(max) == false)
    {
        for (size_t i = NAMA_STACK.jumlah; i > 0; i--)
        {
            cout << "\t[" << NAMA_STACK.data[i] << "]" << endl;
        }
    }
    else
    {
        cout << "Belum ada data pada stack" << endl;
    }
}

int main()
{
    int pilihan_user = 0, maksimal_isi_stack = 0;

    cout << "Masukan maksimal isi stack: ";
    cin >> maksimal_isi_stack;
    NAMA_STACK.data[maksimal_isi_stack];

    bool isLoop = true;

    while (isLoop == true)
    {

        cout << "Penerapan Stack"
             << "\n1. isEmpty"
             << "\n2. isFull"
             << "\n3. Push"
             << "\n4. Pop"
             << "\n5. Print"
             << "\n6. Clear"
             << "\n7. Quit" << endl;
        cout << "Masukan pilihan: ";
        cin >> pilihan_user;

        switch (pilihan_user)
        {
        case 1:
            if (isEmpty(maksimal_isi_stack) == true)
            {
                cout << "Stack masih kosong." << endl;
            }
            else
            {
                cout << "Stack sudah terisi" << endl;
            }
            cout << endl;
            break;

        case 2:
            if (isFull(maksimal_isi_stack) == true)
            {
                cout << "Stack sudah penuh.";
            }
            else
            {
                cout << "Stack masih sisa " << maksimal_isi_stack - NAMA_STACK.jumlah << endl;
            }
            cout << endl;
            break;

        case 3:
            Push(maksimal_isi_stack);
            cout << endl;
            break;

        case 4:
            Pop(maksimal_isi_stack);
            cout << endl;
            break;

        case 5:
            Print(maksimal_isi_stack);
            cout << endl;
            break;

        case 6:
            Clear();
            cout << endl;
            break;

        case 7:
            cout << "Bye!";
            isLoop = false;
            break;

        default:
            cout << "Salah input!" << endl;
            cout << endl;
            break;
        }
    }
}