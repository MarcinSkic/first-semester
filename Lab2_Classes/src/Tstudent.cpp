#include "Tstudent.h"
#include <iostream>

using namespace std;

void Tstudent::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj oceny z egzaminow: ";
    cin>>egzaminy[0]>>egzaminy[1]>>egzaminy[2];
}
float Tstudent::obliczSrednia(){
    return (float) (egzaminy[0]+egzaminy[1]+egzaminy[2])/3;
}
void Tstudent::wyswietl(){
    cout<<"Student "<<imie<<" "<<nazwisko<<" ma srednia ocen = "<<obliczSrednia();
}
