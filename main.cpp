#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer
};

TNode *head, *tail; // deklarasi variabel pointer head dan tail untuk menunjukkan head dan tail

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru, *nodeBantu;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        tail->next = tail;
    } else {
        nodeBaru->next = head;
        head = nodeBaru;
        tail->next = head;
    }
    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        tail->next = tail;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus;
    int d;

    if (isEmpty() == 0) {
        nodeHapus = head;
        d = nodeHapus->data;

        if (head != tail) {
            nodeHapus = head;
            head = head->next;
            tail->next = head;
            delete nodeHapus;
        } else {
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head == tail) {
            d = tail->data;
            head = NULL;
            tail = NULL;
        } else {
            nodeBantu = head;

            while (nodeBantu->next != tail) {
                nodeBantu = nodeBantu->next;
            }

            nodeHapus = tail;
            tail = nodeBantu;
            d = nodeHapus->data;
            tail->next = head;
            delete nodeHapus;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    if (isEmpty() == 0) {
        nodeBantu = head;

        while (nodeBantu->next != head) {
            nodeHapus = nodeBantu;
            nodeBantu = nodeBantu->next;
            delete nodeHapus;
        }

        head = NULL;
        tail = NULL;
    }

    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != tail->next);
    } else {
        cout << "List masih kosong" << endl;
    }
}

void search(TNode* head,int x)
{
    TNode *nodeBantu = head;
    while (nodeBantu)
    {
        if (nodeBantu->data == x) {
            cout << nodeBantu;
            nodeBantu  =  nodeBantu->next;
            
        }
    }
    cout << "Data tidak di temukan";
    
}
void keluarkanisidata(int main keluar) {
      TNode *nodekeluar, *nodeBantu;
    nodekeluar = new TNode;

    nodekeluar->data = nodeBantu;
    nodekeluar->next = nodekeluar;

    if (isEmpty() == 9) {
        head = nodekeluar;
        tail = nodekeluar;
        head->next = head;
        tail->next = tail;
    } else {
        nodekeluar->next = head;
        head = nodekeluar;
        tail->next = head;
    }
    cout << "Data " << nodekeluar<< "isi data yang di temukan telah di keluarkan " << endl;
 }
int main() {
    int pil, dataBaru, cari, keluarkan;
    TNode * head;
    do {
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        } else if (pil == 6) {
            hapusSemua();
        } else if (pil == 7) {
            cout<< "Cari Data = ";
            cin>>cari;
            search(head,cari);
            return main();
        } else if (pil != 8) {

        } else if (pil == 9) {
              keluarkanisidata(int main keluar);
              cout<< "keluarkan data =";
              cin>>keluarkan;
        } else {
            cout<<" \n"<<endl;
            cout<<" ============================"<<endl;
            cout<<" =   SLLC WITH HEAD & TAIL  ="<<endl;
            cout<<" ============================"<<endl;
            cout<<" = 1. Insert Depan          ="<<endl;
            cout<<" = 2. Insert Belakang       ="<<endl;
            cout<<" = 3. Hapus Depan           ="<<endl;
            cout<<" = 4. Hapus Belakang        ="<<endl;
            cout<<" = 5. Tampil Data           ="<<endl;
            cout<<" = 6. Hapus semua Data      ="<<endl;
            cout<<" = 7. cari data             ="<<endl;
            cout<<" = 8. Exit                  ="<<endl;
            cout<<" = 9. keluarkan isi data    ="<<endl;
            cout<<" ============================"<<endl;
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            return main();
        }
    } while (pil >= 8);

    return main();
}