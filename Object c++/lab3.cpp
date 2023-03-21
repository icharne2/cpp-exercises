#include<iostream>
#include<string>

using namespace std;

namespace Biblioteczka {
	class Ksiazka {
	private:
		string tytul;
		string autor;
		int rok_wydania;
		static int licznik;

	public:
		//Konstruktor domyslny
		Ksiazka() {
			cout << "Ksiazka zostala utworzona" << endl;
			licznik++;
		}

		//Konstruktor sparametyrzowany
		Ksiazka(string t, string a, int r) : tytul(t), autor(a), rok_wydania(r) {
			licznik++;
		}

		void zmienTytul(string tyt) {
			this->tytul = tyt;
		}

		void zmienAutora(string aut) {
			this->autor = aut;
		}

		void zmienRok(int rok) {
			this->rok_wydania = rok;
		}

		bool czyXXwiek() {	//	czy ksiazka byla w XX wieku
			if (this->rok_wydania >= 1900 && (this->rok_wydania < 2000)) {
				return true;
			}
			else {
				return false;
			}
		}

		int pokazRok() {
			return rok_wydania;
		}

		void wyswietl() {
			cout << "Tytul: " << tytul << endl;
			cout << "Autor: " << autor << endl;
			cout << "Rok wydania: " << rok_wydania << endl;
		}

		//Do edycji licznika

		static int getLicznik() {
			return licznik;
		}

		static void setLicznik(int nowyLicznik) {
			licznik = nowyLicznik;
		}
	};

	int Ksiazka::licznik = 0;
}

void sortowanieRok(Biblioteczka::Ksiazka tab[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (tab[j - 1].pokazRok() < tab[j].pokazRok())
				swap(tab[j - 1], tab[j]);
}

int main() {
	//A)
	Biblioteczka:: Ksiazka ksiazka_1;

	ksiazka_1.zmienAutora("Maly ksiaze");
	ksiazka_1.zmienTytul("Antoine de Saint-Exupery");
	ksiazka_1.zmienRok(1943);

	Biblioteczka::Ksiazka ksiazki[4] = {
		Biblioteczka::Ksiazka("W pustyni i w puszczy", "Henryk Sienkiewicz", 1912),
		Biblioteczka::Ksiazka("Pan Tadeusz", "Adam Mickiewicz", 1834),
		Biblioteczka::Ksiazka("Lalka", "Boleslaw Prus", 1890),
		Biblioteczka::Ksiazka("Ferdydurke", "Witold Gombrowicz", 1937)
	};

	cout << endl;

	//B)
	for (int i = 0; i < 4; i++) {
		if (ksiazki[i].czyXXwiek()) {
			cout << "Ksiazka wydana w XXw." << endl;
		}
		else {
			cout << "Ksiazka NIE wydana w XXw." << endl;
		}
	}
	cout << endl;

	//C)
	//sortowanie malejace
	sortowanieRok(ksiazki, 4);

	//Wyswietlenie tablicy ksiazek
	for (int i = 0; i < 4; i++) {
		ksiazki[i].wyswietl();
	}
	cout << endl;

	//D)
	//Ksiazka::setLicznik(4); //Ndpisanie licznika

	cout << "Ksiazki w systemie: " << Biblioteczka::Ksiazka::getLicznik() << endl;	//Wyswietlenie licznika

	system("pause");
	return 0;
}