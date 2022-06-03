//
// Created by tomas on 25.04.2022.
//
#include "hash.h"
using namespace std;
bool Text::otworz_plik() {                                     //funkcja otwierajaca plik
    plik_z_tekstem.open("tekst.txt", ios::in);        //"test.txt" to nazwa pliku w folderze cmake-build-debug - podmienic nazwe w razie potrzeby
    if(plik_z_tekstem.is_open()){
        return true;
    }
    else{
        return false;
    }
}
bool Text::zamknij_plik() {                                   //funkcja zamykajaca plik
    plik_z_tekstem.close();
    if(!plik_z_tekstem.is_open()){
        return true;
    }
    else{
        return false;
    }
}
bool Text::skopiuj_zawartosc() {
    char znak_badany;
    int ilosc_liter = 0;
    if (plik_z_tekstem.is_open()) {                          //sprawdzenie czy plik jest otwarty
        while (plik_z_tekstem) {                             //badanie pliku az do konca
            znak_badany = plik_z_tekstem.get();              //pobieranie znakow jeden po drugim
            if ((znak_badany >= 48 && znak_badany <= 58) || (znak_badany >= 41 && znak_badany <= 90) || (znak_badany >= 96 && znak_badany <= 122)) {
                tekst += znak_badany;
                ilosc_liter++;                               //pobieranie liter do slowa
            }
            if (znak_badany < 48 || (znak_badany > 57 && znak_badany <  65) || (znak_badany > 90 &&  znak_badany < 96) || znak_badany > 122)  {//oddzielanie slow
                int lewy_kursor, prawy_kursor;
                for (lewy_kursor = 0; lewy_kursor < ilosc_liter; lewy_kursor++) {
                    for (prawy_kursor = 0; prawy_kursor < ilosc_liter; prawy_kursor++) {
                        string kopia;
                        for (int n = lewy_kursor; n <=prawy_kursor; n++){
                            kopia += tekst[n];
                        }
                        unsigned int pozycja = schaszuj_tekst(kopia);        //pobranie miejsca do wpisania slowa
                        unsigned int start = pozycja, licznik_prob_wpisania = 0;                              //zapisanie miejsca poczatku proby zapisu
                        bool pravda = true;                                        //warunek petli
                        while (pravda) {
                            if (*(wsk_slowa+pozycja) == kopia) {
                                *(wsk_ilosc_powtorzen+pozycja) = *(wsk_ilosc_powtorzen+pozycja) + 1;
                                pravda = false;
                            }
                            if ((wsk_slowa+pozycja)->empty()) {                          //sprawdzenie czy pozycja jest pusta
                                *(wsk_slowa+pozycja) = kopia;                            //zapisanie slowa w pozycji
                                *(wsk_ilosc_powtorzen+pozycja) = 1;
                                pravda = false;                                    //wyjscie z petli
                            } else {
                                pozycja++;
                                licznik_prob_wpisania++;
                                if (pozycja == maksrozmiar) {                                 //zapetlenie miejsc do wpisania, jedynym ograniczeniem jest pojemnosc funkcji
                                    pozycja = 0;
                                } else {
                                    if (licznik_prob_wpisania > maksrozmiar) {
                                        return false;                              //sprawdzenie czy nie doszlo do przepelnienia tabeli
                                    }
                                }
                            }
                        }
                        licznik_slow++;                                            //zliczanie slow
                    }
                }
                tekst.clear();                                                     //wyczyszczenie stringa do ktorego sa zapisywane litery
                ilosc_liter = 0;
            }
        }
        return true;                                                               //zwracane przy udanym wpisaniu
    } else {
        return false;                                                              //zwracane jesli plik nie zostal najpierw otwarty
    }
}
unsigned int Text::schaszuj_tekst(const string& slowo) {                           //hashowanie frazy
hash<string> komenda;
return komenda(slowo)%maksrozmiar;                                              //zwracany jest wynik modulo przez rozmiar tablicy
}

int Text::znajdz_w_tekscie(const string& badany_tekst){                            //funkcja sprawdząca czy szukane slowo jest w tekscie
        unsigned int pozycja = schaszuj_tekst(badany_tekst);                     //pobranie hashu slowa
        int n;
        for (n = 0; n < maksrozmiar; n++) {                                              //sprawdzenie wszystkich pozycji zaczynajac od najbardziej
            if (pozycja >= maksrozmiar) {                                              //zapetlenie sprawdzania
                pozycja = 0;
            }
            if (*(wsk_slowa+pozycja) == badany_tekst) {
                int ilosc = *(wsk_ilosc_powtorzen+pozycja+n);
                return ilosc;
            }
            pozycja++;
    }
    return 0;
}
Text::Text() {
    maksrozmiar = 73000;
    string slowa[maksrozmiar];
    int ilosc_powtorzen[maksrozmiar];
    wsk_slowa = &slowa[0];
    wsk_ilosc_powtorzen = &ilosc_powtorzen[0];
    otworz_plik();                                                                 //skopiowanie zawartosci   - wazne
    /*if ( !skopiuj_zawartosc()){                                                  //awaryjne zamkniecie pliku - przydatne
        cout << "Blad programu" << endl;                        //skomentowane poniewaz mielismy usunac couty
    }*/
    skopiuj_zawartosc();
    zamknij_plik();
licznik_slow = 0;                                                                 //konstruktor
}