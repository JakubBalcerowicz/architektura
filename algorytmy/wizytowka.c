// implementacja wizytownika w postaci listy jednokierunkowej
// dane sortowane sa alfabetycznie wg nazwiska
// www.algorytm.org
 
#include<iostream>
using namespace std;
#include<string>
 
struct Wizytowka // struktura reprezentujaca pojedyncza wizytowke
{
string imie;
string nazwisko;
int numer_telefonu;
Wizytowka *nastepny; // wskaznik na nastepny element na liscie
 
Wizytowka() // konstruktor - wywolywany przy tworzeniu obiektu
{
// wczytujemy dane
cout << "Podaj imie: ";
cin >> imie;
cout << "Podaj nazwisko: ";
cin >> nazwisko;
cout << "Podaj numer telefonu (bez zera na poczatku): ";
cin >> numer_telefonu;
// wskazniki ustawiamy na NULL
nastepny = NULL;
}
 
void wypisz()
{
cout << "Imie: " << imie << "\tNazwisko: " << nazwisko << "\tNumer telefonu: " << numer_telefonu << endl;
}
};
 
void dodaj_wizytowke(Wizytowka **korzen)
{
Wizytowka *nowa = new Wizytowka; // utworzenie nowej wizytowki
Wizytowka *pomoc = (*korzen), *pomoc1 = NULL; // wskazniki pomocnicze posluza do poruszania sie po liscie
 
while (pomoc != NULL && (pomoc->nazwisko).compare(nowa->nazwisko) == -1) // dopoki nie wyszlismy za liste i nazwisko na liscie jest przed nowym nazwiskiem poruszamy sie dalej
{
pomoc1 = pomoc; // pomoc1 zawsze wskazuje poprzednika pomoc
pomoc = pomoc->nastepny;
}
 
if (pomoc != NULL && (pomoc->nazwisko).compare(nowa->nazwisko) == 0) // wizytowka z podanym nazwiskiem juz istanieje
{
cout << "Wizytowka " << nowa->nazwisko << " juz istanieje w wizytowniku\n";
delete nowa; // usuniecie obiektu
}
else if ((*korzen) == NULL || (pomoc == (*korzen) && (pomoc->nazwisko).compare(nowa->nazwisko) == 1)) // nowy element bedzie korzeniem listy
{
nowa->nastepny = (*korzen);
(*korzen) = nowa;
}
else // dodajemy wizytowke w srodku lub na koncu listy
{
pomoc1->nastepny = nowa;
nowa->nastepny = pomoc;
}
}
 
void wyszukaj_wizytowke(Wizytowka *korzen, string a)
{
while(korzen != NULL && (korzen->nazwisko).compare(a) != 0) // dopoki nie znajdziemy wizytowki z podanym nazwiskiem lub nie przeszukamy calego wizytownika
korzen = korzen->nastepny;
 
if (korzen == NULL)
cout << "Nie ma wizytowki " << a << endl;
else
korzen->wypisz();
}
 
void wypisz_wizytownik(Wizytowka *korzen)
{
cout << "Zawartosc wizytownika:\n";
 
while(korzen != NULL)
{
korzen->wypisz(); // wypisanie wizytowki
korzen = korzen->nastepny; // przejscie na kolejny element
}
}
 
bool usun_wizytowke(Wizytowka **korzen, string a)
{
if ((*korzen) == NULL) // lista jest pusta
return false;
Wizytowka *pomoc = (*korzen), *pomoc1 = NULL; // wskazniki pomocnicze posluza do poruszania sie po liscie
 
while(pomoc != NULL && (pomoc->nazwisko).compare(a) != 0) // dopoki nie znajdziemy wizytowki z podanym nazwiskiem lub nie przeszukamy calego wizytownika
{
pomoc1 = pomoc;
pomoc = pomoc->nastepny;
}
 
if (pomoc == NULL) // wyszlismy za liste - nie ma takiego nazwiska na liscie
return false;
else if (pomoc == (*korzen)) // usuwamy koniec
{
(*korzen) = (*korzen)->nastepny;
delete pomoc;
}
else // usuwamy z srodka lub konca listy
{
pomoc1->nastepny = pomoc->nastepny;
delete pomoc;
}
return true;
}
 
int main()
{
char instrukcja;
string nazwisko;
Wizytowka *korzen = NULL; // korzen listy - wskaznik na pierwszy element
cout << "MENU - mozliwe operacje na wizytowniku\n"
<< "d - dodanie wizytowki\n"
<< "s - wyszukanie wizytowki\n"
<< "w - wypisanie wszystkich wizytowek\n"
<< "u - usuniecie wizytowki\n"
<< "Ctrl+Z - koniec programu\n";
 
while (cin >> instrukcja)
{
switch (instrukcja)
{
case 'd':
dodaj_wizytowke(&korzen);
break;
case 's':
cout << "Podaj nazwisko: ";
cin >> nazwisko;
wyszukaj_wizytowke(korzen, nazwisko);
break;
case 'w':
wypisz_wizytownik(korzen);
break;
case 'u':
cout << "Podaj nazwisko: ";
cin >> nazwisko;
if (!usun_wizytowke(&korzen, nazwisko))
cout << "Nie odnaleziono wizytowki z podanym nazwiskiem" << endl;
else
cout << "Wizytowka z podanym nazwiskiem zostala usunieta" << endl;
break;
default:
cout << "Musisz wybrac jedna z opcji: d - dodawanie, s - wyszukiwanie, w - wypisanie zawartosci lub u - usuwanie\n";
break;
}
}
 
return 0;
}
