//
// Created by tomas on 25.04.2022.
//
#include <iostream>
#include <fstream>
#include <string>

#ifndef HASHOWANIE_HASH_H
#define HASHOWANIE_HASH_H
using namespace std;
class Text{
private:                                        //enkapsulacja zmiennych
    string tekst;
    string *wsk_slowa;
    int *wsk_ilosc_powtorzen;
    fstream plik_z_tekstem;                         //zmienna odpowiadajaca za obsluge pliku z tekstem
    int licznik_slow;
    int maksrozmiar;
public:                                         //metody manipulacji zmiennymi
    bool otworz_plik();
    bool zamknij_plik();
    bool skopiuj_zawartosc();
    unsigned int schaszuj_tekst(const string&);
    int znajdz_w_tekscie(const string&);
Text();
};
#endif //HASHOWANIE_HASH_H
