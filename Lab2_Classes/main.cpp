#include <iostream>
#include <locale>
#include "Tpracownik.h"
#include "Tdzialania.h"
#include "Tstudent.h"

using namespace std;

int main()
{
    setlocale( LC_ALL,"" );

    cout<<"Program pracownik"<<endl;
    Tpracownik pracownik;
    pracownik.wczytaj();
    pracownik.wyswietl();

    cout<<endl<<"Program dzialania"<<endl;
    Tdzialania dzialania;   //obiekt
    dzialania.wczytaj();
    cout<<"Wynik mnozenia: "<<dzialania.iloczyn()<<endl;
    cout<<"Wynik dzielenia: "<<dzialania.iloraz()<<endl;

    cout<<endl<<"Program student"<<endl;
    Tstudent student;
    student.wczytaj();
    student.wyswietl();
    return 0;
}
