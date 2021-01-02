#ifndef TSTUDENT_H
#define TSTUDENT_H


class Tstudent
{
    private:
        char imie[20];
        char nazwisko[20];
        float egzaminy[3];
    public:
        void wczytaj();
        float obliczSrednia();
};

#endif // TSTUDENT_H
