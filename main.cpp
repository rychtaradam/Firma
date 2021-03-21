#include "Firma.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	Firma f1;
	Firma f2("47813121", "Stredni skola prumyslova a umelecka, Opava");
	Firma f3(f2);

	cout << "Objekt f1 vytvoreny vychozim konstruktorem " << endl
		<< "------------------------------------------" << endl
		<< f1 << endl;

	cout << "Objekt f2 vytvoreny konstruktorem s parametry " << endl
		<< "---------------------------------------------" << endl
		<< f2 << endl;

	cout << "Objekt f3 vytvoreny kopirovacim konstruktorem " << endl
		<< "---------------------------------------------" << endl
		<< f3 << endl;

	int konec;
	do {
		cout << "Zadej 8-mistne ICO: ";
		std::string ico;
		std::getline(cin, ico);

		cout << "Zadej nazev firmy (3 az 255 znaku): ";
		std::string nazevFirmy;
		std::getline(cin, nazevFirmy);

		if (f1.setICO(ico) && f1.setNazev(nazevFirmy)) {
			cout << "Objekt f1 po zmene" << endl
				<< "------------------" << endl
				<< f1 << endl;
		}

		else {
			cout << endl;
			cout << "Chybne ICO nebo nazev firmy" << endl;
			cout << endl;
		}

		cout << endl;

		Firma f4(f1);

		cout << "Objekt f4 po zmene f4 = f1" << endl
			<< "--------------------------" << endl
			<< f4 << endl;

		if (f1.getICO() == f4.getICO() && f1.getNazev() == f4.getNazev()) {
			cout << "Objekty f1 a f4 jsou shodne." << endl;
		}

		else {
			cout << "Objekty f1 a f4 nejsou shodne." << endl;
		}

		cout << endl;

		cout << "Pro zadani dalsi firmy zadej 1: ";
		cin >> konec;

		cout << endl;

	} while (konec == 1);

	return 0;
}