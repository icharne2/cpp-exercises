#include <iostream>
#include<string>

using namespace std;

class Pasazer {
private:
	string imie;
	string nazwisko;
	int wiek;

public:
	//Pasazer(string im, string naz, int w): imie(im), nazwisko(naz), wiek(w) {}	//Konstruktor

	void ustawImie(string imie) {
		this->imie = imie;
	}
	void ustawNazwisko(string nazwisko) {
		this->nazwisko = nazwisko;
	}

	void ustawWiek(int wiek) {
		this->wiek = wiek;
	}

	string pobierzNazwisko() {
		return nazwisko;
	}

	void wypisz() {
		cout << "Imie: " << imie << "\nNazwisko: " << nazwisko << "\nWiek: " << wiek << endl;
	}

};

class Autokar:Pasazer {
private:
	string miejsce_docelowe;
	const int liczbaMiejsc = 15;
	Pasazer* pasazerowie[15];	//Przekaznie tablicy z funkcji powyzej

public:
	void wypisz() {
		cout << "Miejsce docelowe: " << miejsce_docelowe << "\nLiczba miejsc: " << liczbaMiejsc << endl;
		cout << "Lista pasazerow: " << endl;
		for (int i = 0; i < liczbaMiejsc; i++) {
			pasazerowie[i]->wypisz();
		}
	}

	void zmienWiek(int person, int wiek) {
		pasazerowie[person]->ustawWiek(wiek);
	}

	void dodajPazazerow(string cel, Pasazer* tablica_osob) {
		this->miejsce_docelowe = cel;

		for (int i = 0; i < liczbaMiejsc; i++) {
			this->pasazerowie[i] = &tablica_osob[i];
		}
	}

};

int main() {
	Pasazer p1;

	//A) ustawienie danych dla pasazera uzywajac akcesorow:
	p1.ustawImie("Jan");
	p1.ustawNazwisko("Kowalski");
	p1.ustawWiek(35);

	//A) Wypisanie nazwiska pasa¿era przy u¿yciu akcesora
	cout << "Nazwisko pasazera: " << p1.pobierzNazwisko() << endl;

	//B) Utworzenie tablicy dynamicznej obiektów klasy Pasazer o iloœci elementów równej 200
	Pasazer* tablicaPasazerow = new Pasazer[200];

	for (int i = 0; i < 200; i++) {
		Pasazer p;
		p.ustawImie("Imie_" + to_string(i));
		p.ustawNazwisko("Nazwisko_" + to_string(i));
		p.ustawWiek(i + 20);
		tablicaPasazerow[i] = p;
	}

	//wypisanie tablicy:
	/* 
	for (int i = 0; i < 200; i++) {
		tablicaPasazerow[i].wypisz();
	}
	*/

	//C) Utworzenie obiektu klasy Autokar i przypisanie mu miejsca docelowego oraz listy pasa¿erów
	Autokar autokar_1;
	autokar_1.dodajPazazerow("Krakow", tablicaPasazerow);

	//D) Zmieñ wiek dowolnego pasa¿era z autokaru u¿ywaj¹c metody zmienWiek(). Wyœwietl dane autokaru wraz z list¹ pasa¿erów
	autokar_1.zmienWiek(1, 2);

	//Wypisanie
	autokar_1.wypisz();

	system("pause");
	return 0;
}