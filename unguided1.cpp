#include <iostream>
using namespace std;

struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL;

void insertFront(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

void insertBack(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMiddle(string nama, int usia, int posisi)
{
    if (posisi <= 1 || head == NULL)
    {
        insertFront(nama, usia);
        return;
    }

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;

    Node *temp = head;
    for (int i = 1; i < posisi - 1 && temp != NULL; ++i)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Posisi diluar range." << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->nama << "\t" << temp->usia << endl;
        temp = temp->next;
    }
}

int main()
{
    string Namamu;
    int Usiamu;

    cout << "Masukan nama anda: ";
    getline(cin, Namamu);
    cout << "Masukkan usia anda: ";
    cin >> Usiamu;

    insertFront(Namamu, Usiamu);

    cout << "Masukkan nama dan usia siswa lain: (Masukkan 'exit' untuk berhenti)" << endl;
    while (true)
    {
        string nama;
        int usia;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama);
        if (nama == "exit")
            break;

        cout << "Usia: ";
        cin >> usia;

        insertBack(nama, usia);
    }

    cout << "\nDaftar Siswa:\n";
    displayList();

    return 0;
}
