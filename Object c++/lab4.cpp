#include<iostream>
#include<string>

using namespace std;

class Samochod {
private:
	string marka;
	string model;
	float cena;

public:

	Samochod(){} //Domyslny
	Samochod(string mar, string mod, float cen) : marka(mar), model(mod), cena(cen) {}	//Sparametryzowany

	void wypisz() {
		cout << "Marka: " << marka << endl;
		cout << "Model: " << model << endl;
		cout << "Cena: " << cena << endl;
	}

	float zwrocCena() {
		return cena;
	}

	string zwrocModel() {
		return model;
	}

	string zwrocMarka() {
		return marka;
	}

};

class Garaz {
private:
	string nazwa;
	Samochod* samochody[15];
	int ilosc=0;
public:
	//Konstruktor wieloargumentowy
	Garaz(string naz, Samochod* tab, int size) {
		if (size <= 15) {
			nazwa = naz;
			cout << "Nazwa garazu: " << nazwa << endl;
			
			for(int i = 0; i < size; i++) {
				samochody[i] = &tab[i];
				ilosc++;
			}
		}
		else {
			cout << "Nie ma na tyle miejsca w garazu" << endl;
		}
	}

	Garaz(string naz, Samochod* tab, Samochod *tab2, int size1, int size2) {
		int pom = size1 + size2;

		if (pom <= 15) {
			nazwa = naz;
			cout << "Nazwa garazu: " << nazwa << endl;

			for (int i = 0; i < size1; i++) {
				samochody[i] = &tab[i];
			}

			for (int i = 2, x=0; i < 5; i++,x++) {
				samochody[i] = &tab2[x];
			}
			ilosc = pom;
		}else {
			cout << "Nie ma na tyle miejsca w garazu" << endl;
		}
	}

	void wartoscAut() {
		float suma = 0;

		for (int i = 0; i < ilosc; i++) {
			suma += samochody[i]->zwrocCena();
		}

		cout << "Wartosc aut:" << suma << endl;
	}

	void wypiszAuta() {
		cout << "Nazwa garazu: " << nazwa << endl;
		cout << "Lista samochodow: " << endl;

		for (int i = 0; i < ilosc; i++) {
			samochody[i]->wypisz();
			cout << endl;
		}
	}

};


int main() {
	//A)
	Samochod tab1[2] = {
		Samochod("marka1", "model1", 123.9),
		Samochod("marka2", "model2", 736.2)
	};

	Samochod tab2[3] = {
		Samochod("marka3", "model3", 1432.9),
		Samochod("marka4", "model4", 67.91),
		Samochod("marka5", "model5", 8371.1)
	};

	for (int i = 0; i < 2; i++) {
		tab1[i].wypisz();
	}

	for (int i = 0; i < 3; i++) {
		tab2[i].wypisz();
	}
	cout << endl;

	//B)
	Garaz garaz1("G1", tab1, 2);
	Garaz garaz2("G2", tab1, tab2, 2, 3);
	cout << endl;

	//C)
	garaz1.wypiszAuta();
	garaz2.wypiszAuta();

	//D)
	garaz1.wartoscAut();
	garaz2.wartoscAut();

	return 0;
}