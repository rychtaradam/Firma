#include "Firma.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	Firma f1;
	Firma f2("47813121", "Stredni skola prumyslova a umelecka, Opava");
	Firma f3(f2);

	cout << "Objekt o1 vytvoreny vychozim konstruktorem: " << endl
		<< f1 << endl;

	cout << "Objekt o2 vytvoreny konstruktorem s parametry: " << endl
		<< f2 << endl;

	cout << "Objekt o3 vytvoreny kopirovacim konstruktorem: " << endl
		<< f3 << endl;


	return 0;
}