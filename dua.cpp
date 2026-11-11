#include <iostream>
using namespace std;

struct Node {
    string nama;
    int skor;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

bool isEmpty() {
    return head == nullptr;
}

void tambahAwal(int nilai) {
    Node* baru = new Node;

    baru->skor = nilai;
    baru->next = head;
    head = baru;

    if (tail == nullptr) {
        tail = baru;
    }
}

void tambahAkhir(int nilai) {
    Node* baru = new Node;
    baru->skor = nilai;
    baru->next = nullptr;

    if (isEmpty()) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    cout << "skor berhasil ditambahkan di akhir.\n";
}
void tampilkan() {
    if (isEmpty()) {
        cout << "Linked List masih kosong.\n";
        return;
    }

    Node* bantu = head;
    cout << "Isi Linked List: ";

    while (bantu != nullptr) {
        cout << bantu->skor << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}

void hapusAwal() {
    if (isEmpty()) {
        cout << "Linked List kosong, tidak ada skor yang dihapus.\n";
        return;
    }

    Node* hapus = head;
    head = head->next;
    delete hapus;

    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Node pertama berhasil dihapus.\n";
}


void hapusAkhir() {
    if (isEmpty()) {
        cout << "Linked List kosong.\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* bantu = head;
        while (bantu->next != tail) {
            bantu = bantu->next;
        }
        delete tail;

        tail = bantu;
        tail->next = nullptr;
    }
    cout << "Node terakhir berhasil dihapus.\n";
}

void hapusNilai(int nilai) {
    if (isEmpty()) {
        cout << "Linked List kosong.\n";
        return;
    }

    Node* bantu = head;
    Node* sebelum = nullptr;

    while (bantu != nullptr && bantu->skor != nilai) {
        sebelum = bantu;
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "skor tidak ditemukan.\n";
        return;
    }

    if (bantu == head) {
        head = head->next;
    } else {
        sebelum->next = bantu->next;
    }

    if (bantu == tail) {
        tail = sebelum;
    }

    delete bantu;
    cout << "skor berhasil dihapus.\n";
}


void hapusPosisi(int posisi) {
    if (isEmpty()) {
        cout << "Linked List kosong.\n";
        return;
    }

    if (posisi < 1) {
        cout << "Posisi tidak valid.\n";
        return;
    }

    if (posisi == 1) {
        hapusAwal();
        return;
    }

    Node* bantu = head;

    for (int i = 1; i < posisi - 1 && bantu != nullptr; i++) {
        bantu = bantu->next;
    }

    if (bantu == nullptr || bantu->next == nullptr) {
        cout << "Posisi tidak ditemukan.\n";
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;

    if (hapus == tail) {
        tail = bantu;
    }

    delete hapus;
    cout << "Node pada posisi " << posisi << " berhasil dihapus.\n";
}


void hitungNode() {
    int jumlah = 0;

    Node* bantu = head;

    while (bantu != nullptr) {
        jumlah++;
        bantu = bantu->next;
    }
    cout << "Jumlah node: " << jumlah << endl;
}

void cariSkor(int nilai) {
    Node* bantu = head;
    int posisi = 1;

    while (bantu != nullptr) {
        if (bantu->skor == nilai) {
            cout << "skor ditemukan pada posisi "
                 << posisi << endl;
            return;
        }
        bantu = bantu->next;
        posisi++;
    }
    cout << "skor tidak ditemukan.\n";
}


void bersihkanList() {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }

    tail = nullptr;
    cout << "Seluruh Linked List berhasil dibersihkan.\n";
}

int main() {
    int pilihan;
    int nilai;
    int posisi;

    do {
        cout << "\n===== MENU LINKED LIST =====\n";
        cout << "1. Tambah skor di awal \n";
        cout << "2. Tambah skor di akhir\n";
        cout << "3. Hapus skor pertama\n";
        cout << "4. Tampilkan skor\n";

        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                tampilkan();
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
    return 0;
}