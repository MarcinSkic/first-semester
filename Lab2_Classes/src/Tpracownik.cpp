#include "Tpracownik.h"
#include <iostream>

using namespace std;

void Tpracownik::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj liczb� godzin: ";
    cin>>liczbaGodzin;
    cout<<"Podaj stawk� za godzin�: ";
    cin>>stawkaZaGodzine;
    cout<<"Podaj date zatrudnienia (dd/mm/yyyy): ";
    cin>>dataZatrudnienia.dzien>>dataZatrudnienia.miesiac>>dataZatrudnienia.rok;
}
float Tpracownik::placa(){
    return liczbaGodzin*stawkaZaGodzine;
}
void Tpracownik::wyswietl(){
    cout<<imie<<" "<<nazwisko<<" zatrudniony "<<dataZatrudnienia.dzien<<"/"<<dataZatrudnienia.miesiac<<"/"<<dataZatrudnienia.rok<<" zarobi: "<<placa()<<endl;
}
