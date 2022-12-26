//Nama    : Farrel Ardian
//Nim     : A11.2021.13437
//Kel     : A11.4317
#include <iostream>
using namespace std;

struct Pln{
    //data
    string nama;
    int noplg;
    int tagihan;

    //pointer
    Pln *next;
};

Pln *Baru, *cur, *head, *tail, *bantu, *before, *del, *baru;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}
int jumlahData(){
    cur=head;
    int jumlah = 0;
    while(cur != 0){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}
void cetak(){
    cout << "Jumlah data ada :" << jumlahData() << endl;
       if(head==NULL)
    {
        cout << "\nData Kosong";
    }
    else
    {
        bantu=head;
        while(bantu!=NULL)
        {
            cout << "nama     : " << bantu->nama << endl;
            cout << "noplg    : " << bantu->noplg << endl;
            cout << "Tagihan     : " << bantu->tagihan << endl<<endl;
            bantu=bantu->next;
        }
    }
}

void create(string nama, int noplg, int tagihan){
    Pln *baru;
    baru = new Pln ();
    baru->nama=nama;
    baru->noplg=noplg;
    baru->tagihan=tagihan;
    baru->next= head->next;
    head=baru;
}

void tambahBelakang(string nama, int noplg, int tagihan){
    Pln *baru;
    baru = new Pln();

    baru -> nama=nama;
    baru -> noplg=noplg;
    baru -> tagihan=tagihan;
    baru -> next = NULL;

    if(isEmpty()){
        head = tail = baru;
    }
    else {
        tail->next= baru;
        tail = baru;
    }
}

void tambahDepan(string nama, int noplg, int tagihan){
    Pln *baru;
    baru = new Pln();
    baru -> nama=nama;
    baru -> noplg=noplg;
    baru -> tagihan=tagihan;
    baru -> next = NULL;


    if(isEmpty()){
        head = tail = baru;
        tail -> next =NULL;
    }
    else {
        baru->next= head;
        head = baru;
    }
}

void tambahTengah(string nama, int noplg, int tagihan, int pos){
     if(pos < 1 || pos>jumlahData()){
        cout << "Di luar jangkauan" << endl;
    }else if(pos == 1 || pos == jumlahData()){
        cout << "Bukan posisi tengah" << endl;
    }else {
    Pln *baru;
    baru = new Pln();

    baru -> nama=nama;
    baru -> noplg=noplg;
    baru -> tagihan=tagihan;

    cur = head;
    int i = 1;
    while (i < pos-1){
    cur = cur->next;
    i++;
   }

   baru->next = cur->next;
   cur->next = baru;
}
}
void hapusDepan(){
    del=head;
    head=head->next;
    delete del;
}

void hapusBelakang(){
    del=tail;
    cur=head;
    while(cur ->next != tail){
        cur =cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void hapusTengah(int pos){
    if(pos < 1 || pos>jumlahData()){
        cout << "Di luar jangkauan" << endl;
    }else if(pos == 1 || pos == jumlahData()){
        cout << "Bukan posisi tengah" << endl;
    }else {
        int i=1;
        cur = head;
        while (i <= pos){
        if(i == pos-1){
        before=cur;
        }
        if (i == pos){
        del = cur;
        }
        cur =cur->next;
        i++;
    }
    before->next=cur;
    delete del;
    }
}

void menu(int pil){
    string nama;
    int noplg;
    int tagihan;
    int pos;
    switch(pil){
        case 1:cout << "\nnama   : ";
                cin >> nama;
                cout << "noplg    : ";
                cin >> noplg;
                cout << "Tagihan     : ";
                cin >>tagihan;
            create(nama,noplg,tagihan);
                break;
        case 2: cout << "\nnama   : ";
                cin >> nama;
                cout << "noplg    : ";
                cin >> noplg;
                cout << "Tagihan     : ";
                cin >>tagihan;
                tambahDepan(nama,noplg,tagihan);
                break;
        case 3: cout << "\nnama   : ";
                cin >> nama;
                cout << "noplg    : ";
                cin >> noplg;
                cout << "Tagihan     : ";
                cin >>tagihan;
                tambahBelakang(nama,noplg,tagihan);
                break;
        case 4: cout << "\nnama   : ";
                cin >> nama;
                cout << "noplg    : ";
                cin >> noplg;
                cout << "Tagihan     : ";
                cin >>tagihan;
                cout << "Posisi ke :";
                cin >> pos;
                tambahTengah(nama,noplg,tagihan,pos);
                break;
        case 5: hapusDepan();
                break;
        case 6: hapusBelakang();
                break;
        case 7: cout << "Hapus Posisi ke :";
                cin >> pos;
                hapusTengah(pos);
                break;
        case 8: cetak();
                break;
        case 0: break;
        default: cout << "pilihan tidak ditemukan." << endl; break;
    }
}

int main(){
    int pilih;
    do{
        cout << "[1] Create" << "\n";
        cout << "[2] Tambah Depan" << "\n";
        cout << "[3] Tambah Belakang" << "\n";
        cout << "[4] Tambah Tengah" << "\n";
        cout << "[5] Hapus Depan" << "\n";
        cout << "[6] Hapus Belakang" << "\n";
        cout << "[7] Hapus Tengah" << "\n";
        cout << "[8] Cetak" << "\n";
        cout << "[0] Exit" << "\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilih;
        menu(pilih);
    }while(pilih != 0);
    return 0;
}
