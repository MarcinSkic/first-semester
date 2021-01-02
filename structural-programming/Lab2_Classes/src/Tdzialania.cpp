#include "Tdzialania.h"
#include <iostream>

using namespace std;

void Tdzialania::wczytaj(){
    cout<<"Podaj liczbê x: ";
    cin>>x;
    cout<<"Podaj liczbê y: ";
    cin>>y;
}
int Tdzialania::iloczyn(){
    return x*y;
}
float Tdzialania::iloraz(){
    if(y == 0){
        cout<<"Nie wolno dzielic przez zero!"<<endl;
        return NULL;
    }
    return (float)x/y;
}
