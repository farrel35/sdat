#include <iostream>
#include <math.h>

using namespace std;

float pembagian(float x,float y);
int main()
{
    float x,y,hasil;

    cout << "Masukan nilai ke-1 = ";
    cin >> x;
    cout << "Masukan nilai ke-2 = ";
    cin >> y;

    hasil = pembagian(x,y);

    cout << "Hasil pembagian = " << hasil << endl;
    return 0;
}

float pembagian(float x,float y){
    if(y == 0){
        return INFINITY;
    }else{
        return x/y;
    }
}

