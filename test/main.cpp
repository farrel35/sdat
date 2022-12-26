#include <iostream>
#define MAX 8
using namespace std;
//
//struct Stack{
//    int top = -1, data[MAX];
//}tumpukan;
//
//bool IsEmpty(){
//    return tumpukan.top = -1;
//}
//
//bool IsFull(){
//    return tumpukan.top = MAX - 1;
//}
//
//void push(int data){
//    tumpukan.top++;
//    tumpukan.data[tumpukan.top] = data;
//    cout << "Data '" << tumpukan.data[tumpukan.top] << "' masuk ke stack" << endl << endl;
//}
//
//void pop(){
//    cout << "Data '" << tumpukan.data[tumpukan.top] << "' keluar dari stack" << endl << endl;
//    tumpukan.top--;
//}
//
//void print(){
//    for(int i = 0; i <= tumpukan.top; i++){
//        cout << tumpukan.data[i];
//    }
//    cout << endl << endl;
//}

struct Antrian{
    int data[MAX], head, tail;
}antre;

void create(){
    antre.head=antre.tail=-1;
}
bool isEmpty(){
    return antre.tail==-1;
}
bool isFull(){
    return antre.tail==MAX-1;
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
        cout    <<  data    <<  " dimasukkan ke antrian"    <<  endl;
    }
    else if(isFull()){
        cout    <<  "Data Penuh,tidak dapat menambah data"  <<  endl;
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
        cout    <<  data    <<  " dimasukkan ke antrian"    <<  endl;
    }

}

void dequeue(){
    for(int i=antre.head;i<antre.tail;i++){
        antre.data[i] = antre.data[i+1];
    }
    antre.tail--;
}

void print(){
    if(!isEmpty()){
        for(int i=antre.head;i<=antre.tail;i++){
            cout    <<  antre.data[i]   <<  " ";
        }
        cout << endl;
    }

    cout << endl;
}
int main()
{
    create();
//    int pilihan,data;
//    do {
//        print();
//		cout << "1. Push Data (Input)\n"
//			 << "2. Pop Data (Hapus)\n"
//			 << "3. Print (Cetak)\n"
//			 << "0. Exit\n\n"
//			 << "Masukkan Pilihan: ";
//			 cin >> pilihan;
//		switch (pilihan) {
//		case 1:
//		    cout << "Masukan data = ";
//		    cin >> data;
//			push(data);
//			break;
//		case 2:
//			pop();
//			break;
//		case 3:
//			print();
//			break;
//		default:
//		    cout << "Pilihan tidak tersedia" << endl;
//			break;
//		}
//	} while (pilihan != 0);
    int pilihan,data;
    do {
        print();
		cout << "1. Enqueue\n"
			 << "2. Dequeue\n"
			 << "3. Print (Cetak)\n"
			 << "0. Exit\n\n"
			 << "Masukkan Pilihan: ";
			 cin >> pilihan;
		switch (pilihan) {
		case 1:
		    cout << "Masukan data = ";
		    cin >> data;
			enqueue(data);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			print();
			break;
		default:
		    cout << "Pilihan tidak tersedia" << endl;
			break;
		}
	} while (pilihan != 0);
    return 0;
}
