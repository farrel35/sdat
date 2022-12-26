#include <iostream>

using namespace std;

void tukar(int *x,int *y);

int main()
{
    int x,y;
    cout << "Masukan nilai ke-1 = ";
    cin >> x;
    cout << "Masukan nilai ke-2 = ";
    cin >> y;
    tukar(&x,&y);
    cout << endl;
    cout << "//Setelah ditukar//" << endl;
    cout << "Nilai ke-1 = ";
    cout << x << endl;
    cout << "Nilai ke-2 = ";
    cout << y << endl;
    return 0;
}

void tukar(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
