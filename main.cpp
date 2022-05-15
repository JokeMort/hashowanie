
#include "hash.h"
using namespace std;
int main() {                                                            //przykładowa implementacja
    Text ksiazka;                                                       //utworzenie obiektu do ktorego ida dane - wazne
    bool prawa = true;                                                  //zmienna dla petli, przyklad
    string input;                                                       //zmienna do sprawdzenia czy ma wyjsc z petli, przyklad
    string tekst;                                                       //zmienna zawierajaca tekst ktorego obecnosc jest sprawdzana - wazna
    while (prawa){                                                      //petla - pzrzyklad
        cin >> tekst;                                                   //wpisanie tekstu
        int wynik = ksiazka.znajdz_w_tekscie(tekst);                    //wyszukanie w tekscie czy slowo sie tam znajduje - krytyczne
        if (wynik == 0){                                                //jesli funkcja powyzej zwraca -1 to nie ma takiego slowa
            cout << "nie znaleziono wpisu\n";
        }
        else{                                                           //inne wartosci oznaczaja obecnosc slowa w tekscie
            cout << "znaleziono slowo: '" << tekst << "' lacznie: " << wynik << " razy\n";
        }
        tekst.clear();                                                  //wyczyszczenie stringa, przyklad
        cout << "Wpisz 1 by wyjsc, dowolny inny by kontynuowac\n";
        cin >> input;
        if (input == "1") {
            prawa = false;                                              //wyjscie z petli
        }
    }
    return 0;
}
