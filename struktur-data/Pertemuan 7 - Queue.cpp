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

#ifndef NAMA_QUEUE
#define NAMA_QUEUE praktikum
#endif

using namespace std;

struct queue
{
    int data[JUMLAH_MAKSIMAL_AWAL], maksimal = 0, jumlah = 0;
};

queue NAMA_QUEUE;

bool isEmpty(int max)
{
    if (NAMA_QUEUE.jumlah == 0)
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
    if (NAMA_QUEUE.jumlah >= max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EnQueue(int max)
{
    if (isFull(max) == false)
    {
        NAMA_QUEUE.jumlah += 1;
        cout << "Masukan data: ";
        cin >> NAMA_QUEUE.data[NAMA_QUEUE.jumlah];
    }
    else
    {
        cout << "Queue sudah penuh!" << endl;
    }
}

void DeQueue(int max)
{
    if (isEmpty(max) == false)
    {
        //cout << "Membuang data " << NAMA_QUEUE.data[NAMA_QUEUE.jumlah] << endl;
        //NAMA_QUEUE.jumlah -= 1;
        cout << "Membuang data " << NAMA_QUEUE.data[1] << endl;
        for (size_t i = 1; i <= NAMA_QUEUE.jumlah; i++)
        {
            NAMA_QUEUE.data[i] = NAMA_QUEUE.data[i + 1];
        }
        NAMA_QUEUE.jumlah -= 1;
    }
    else
    {
        cout << "Queue masih kosong!" << endl;
    }
}

void Clear()
{
    NAMA_QUEUE.jumlah = 0;
    cout << "Queue sudah bersih" << endl;
}

void Print(int max)
{
    if (isEmpty(max) == false)
    {
        cout << "\t";
        for (size_t i = 1; i <= NAMA_QUEUE.jumlah; i++)
        {
            cout << "[" << NAMA_QUEUE.data[i] << "]";
        }
    }
    else
    {
        cout << "Belum ada data pada queue" << endl;
    }
}

int main()
{
    int pilihan_user = 0, maksimal_isi_queue = 0;

    cout << "Masukan maksimal isi queue: ";
    cin >> maksimal_isi_queue;
    NAMA_QUEUE.data[maksimal_isi_queue];

    bool isLoop = true;

    while (isLoop == true)
    {

        cout << "Penerapan Queue"
             << "\n1. isEmpty"
             << "\n2. isFull"
             << "\n3. EnQueue"
             << "\n4. DeQueue"
             << "\n5. Print"
             << "\n6. Clear"
             << "\n7. Quit" << endl;
        cout << "Masukan pilihan: ";
        cin >> pilihan_user;

        switch (pilihan_user)
        {
        case 1:
            if (isEmpty(maksimal_isi_queue) == true)
            {
                cout << "Queue masih kosong." << endl;
            }
            else
            {
                cout << "Queue sudah terisi" << endl;
            }
            cout << endl;
            break;

        case 2:
            if (isFull(maksimal_isi_queue) == true)
            {
                cout << "Queue sudah penuh.";
            }
            else
            {
                cout << "Queue masih sisa " << maksimal_isi_queue - NAMA_QUEUE.jumlah << endl;
            }
            cout << endl;
            break;

        case 3:
            EnQueue(maksimal_isi_queue);
            cout << endl;
            break;

        case 4:
            DeQueue(maksimal_isi_queue);
            cout << endl;
            break;

        case 5:
            Print(maksimal_isi_queue);
            cout << endl;
            break;

        case 6:
            Clear();
            cout << endl;
            break;

        case 7:
            isLoop = false;
            cout << "Bye!" << endl;
            break;

        default:
            cout << "Salah input!" << endl;
            cout << endl;
            break;
        }
    }
}