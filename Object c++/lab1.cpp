#include <iostream>

using namespace std;

int* tablice(int* tab, int size) {
	int* wynik = new int[size];

	for (int i = 0; i < size; i++) {	
		wynik[i] = (tab[i]) * 2;
	}

	return wynik;
}

struct Batonik {
	string marka;
	float waga;
	int kalorie;
};

int main() {
	//Punkt a
	int tablica_a[100];

	//Zapelnienie tablicy
	for (int i = 0; i < 100; i++) {
		tablica_a[i] = i;
		//cout << tablica_a[i] << endl;	//Wyswietlenie
	}

	if (tablica_a[9] % 2 == 0) {	//9 poniewaz tablica jest od 0
		cout << "Dziesiaty element tablicy jest podzielny przez 2" << endl;
	}
	else {
		cout << "Dziesiaty element nie jest podzielny przez 2 :<" << endl;
	}

	int* tab_wsk = &tablica_a[10];	// 10 bo tablica jest od 0
	cout << "Wartosc wskaznika wynosi: " << *tab_wsk << endl;

	//Punkt b
	int tablica_b[] = { 1, 6, -7, 3 };

	//Wypisanie - sprawdzenie
	cout << "Nowa tablica:" << endl;
	int* nowa = tablice(tablica_a, 4);

	for (int i = 0; i < 4; i++) {
		cout << nowa[i] << " ";
	}
	cout << endl;

	//Punkt c

	struct Batonik snack = { "Bounty", 57, 278 };

	cout << "Marka: " << snack.marka << endl;
	cout << "Waga: " << snack.waga << endl;
	cout << "Kalorie: " << snack.kalorie << endl;

	system("pause");
	return 0;
}