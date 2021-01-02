#ifndef TPRACOWNIK_H
#define TPRACOWNIK_H

struct data{

    int dzien;  //pola
    int miesiac;
    int rok;

};

class Tpracownik{   //class
private:
    char imie [20];//pola|atrybuty
    char nazwisko [20];
    int liczbaGodzin;
    float stawkaZaGodzine;
    data dataZatrudnienia;
public:
    void wczytaj();//metody
    float placa();
    void wyswietl();
};

#endif // TPRACOWNIK_H
