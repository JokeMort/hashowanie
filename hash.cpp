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
    string wers, slowo;
    int ilosc_liter = 0, dlugosc_tekstu;
    if (!plik_z_tekstem.good()){
        return false;
    }
    while (plik_z_tekstem.good()){
        getline(plik_z_tekstem, wers);
        tekst_badany += wers;
        tekst_badany += " ";
    }
    zamknij_plik();
    dlugosc_tekstu = tekst_badany.length();
    for(int m = 0; m < dlugosc_tekstu; m++) {                          //sprawdzenie czy plik jest otwarty
        znak_badany = tekst_badany[m];              //pobieranie znakow jeden po drugim
        if ((znak_badany >= 48 && znak_badany <= 58) || (znak_badany >= 41 && znak_badany <= 90) || (znak_badany >= 96 && znak_badany <= 122)) {
            slowo += znak_badany;
            ilosc_liter++;                               //pobieranie liter do slowa
        }
        if (znak_badany < 48 || (znak_badany > 57 && znak_badany <  65) || (znak_badany > 90 &&  znak_badany < 96) || znak_badany > 122)  {//oddzielanie slow
            int lewy_kursor, prawy_kursor;
            for (lewy_kursor = 0; lewy_kursor < ilosc_liter; lewy_kursor++) {
                for (prawy_kursor = 0; prawy_kursor < ilosc_liter; prawy_kursor++) {
                    string kopia;
                    string nazwa_pliku, zawartosc;
                    int liczba_wystapien;
                    for (int n = lewy_kursor; n <=prawy_kursor; n++){
                        kopia += slowo[n];
                    }
                    nazwa_pliku = "schaszowane\\";
                    nazwa_pliku += slowo;
                    nazwa_pliku += ".txt";
                    plik_z_tekstem.open(nazwa_pliku, ios::in);
                    if (plik_z_tekstem.is_open()) {
                        getline(plik_z_tekstem, zawartosc);
                        liczba_wystapien = przetworz_na_liczbe(zawartosc);
                        plik_z_tekstem.close();
                    }
                    else {
                        liczba_wystapien = 0;
                    }
                    plik_z_tekstem.open(nazwa_pliku, ios::out);
                    plik_z_tekstem << liczba_wystapien + 1;
                    plik_z_tekstem.close();
                    licznik_slow++;                                            //zliczanie slow
                    }
                }
                slowo.clear();                                                     //wyczyszczenie stringa do ktorego sa zapisywane litery
                ilosc_liter = 0;
            }
        }
        return true;                                                               //zwracane przy udanym wpisaniu
}
int Text::przetworz_na_liczbe(string jeszcze_nie_liczba) {
    if (jeszcze_nie_liczba == ""){
        return 0;
    }
    int dlugosc = jeszcze_nie_liczba.length();
    int teraz_juz_liczba = 0;
    for (int n = 0; n < dlugosc; n++){
        teraz_juz_liczba = 10*teraz_juz_liczba + jeszcze_nie_liczba[n] - 48;
    }
    return teraz_juz_liczba;
}
unsigned int Text::schaszuj_tekst(const string& slowo) {                           //hashowanie frazy
hash<string> komenda;
return komenda(slowo)%maksrozmiar;                                              //zwracany jest wynik modulo przez rozmiar tablicy
}

int Text::znajdz_w_tekscie(const string& badany_tekst){                            //funkcja sprawdząca czy szukane slowo jest w tekscie
    string nazwa_pliku;
    string zawartosc;
    nazwa_pliku = "schaszowane\\";
    nazwa_pliku += badany_tekst;
    nazwa_pliku += ".txt";
    plik_z_tekstem.open(nazwa_pliku, ios::in);
    if (!plik_z_tekstem.is_open()){
        return 0;
    }
    getline(plik_z_tekstem, zawartosc);
    plik_z_tekstem.close();
    int ilosc = przetworz_na_liczbe(zawartosc);
        return ilosc;
}
Text::Text() {
    maksrozmiar = 73000;
    if (rmdir("schaszowane") != 0){
        cout << "Nie udalo sie usunac folderu\n";
    }
    mkdir("schaszowane");
    otworz_plik();                                                                 //skopiowanie zawartosci   - wazne
    /*if ( !skopiuj_zawartosc()){                                                  //awaryjne zamkniecie pliku - przydatne
        cout << "Blad programu" << endl;                        //skomentowane poniewaz mielismy usunac couty
    }*/
    skopiuj_zawartosc();
    zamknij_plik();
    licznik_slow = 0;                                                                 //konstruktor
    cout << "zakonczono inicjalizacje\n";
}