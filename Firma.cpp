#include "Firma.h"

//Výchozí hodnoty firmy.

const std::string defaultICO = "99999999";
const std::string defaultFirma = "bezejmenna";

//Výchozí konstruktor.

Firma::Firma() {
	this->ico = defaultICO;
	this->nazev = defaultFirma;
}

//Konstruktor s parametry.

Firma::Firma(const std::string ico, const std::string nazev) {
	if (!setICO(ico)) {
		this->ico = defaultICO;
	}

	if (!setNazev(nazev)) {
		this->nazev = defaultFirma;
	}
}

//Kopirovací konstruktor.

Firma::Firma(const Firma& f) {
	this->ico = f.getICO();
	this->nazev = f.getNazev();
}

//Funkce pro získání IČA.

std::string Firma::getICO() const {
	return this->ico;
}

//Funkce pro nastavení IČA.

bool Firma::setICO(const std::string ico) {
	if (kontrolaICO(ico)) {
		this->ico = ico;
		return true;
	}

	else {
		return false;
	}
}

//Funkce pro získání názvu firmy.

std::string Firma::getNazev() const {
	return this->nazev;
}

//Funkce pro nastavení názvu firmy.

bool Firma::setNazev(std::string nazev) {
	if (kontrolaNazev(nazev)) {
		this->nazev = nazev;
		return true;
	}

	else {
		return false;
	}
}

//Funkce pro kontrolu platného IČA.

bool Firma::kontrolaICO(const std::string ico) const {
	if (ico.length() != 8) {
		return false;
	}

	for (int i = 0; i < ico.length(); i++) {
		if (std::stoi(ico.substr(i, 1)) < 0 || std::stoi(ico.substr(i, 1)) > 9) {
			return false;
		}
	}

	int zbytek = (11 - ((std::stoi(ico.substr(0, 1)) * 8) + (std::stoi(ico.substr(1, 1)) * 7) + (std::stoi(ico.substr(2, 1)) * 6) + (std::stoi(ico.substr(3, 1)) * 5) + (std::stoi(ico.substr(4, 1)) * 4) + (std::stoi(ico.substr(5, 1)) * 3) + (std::stoi(ico.substr(6, 1)) * 2)) % 11) % 10;

	if (zbytek == std::stoi(ico.substr(7, 1))) {
		return true;
	}
	
	else {
		return false;
	}
}

//Funkce pro kontrolu platného názvu firmy.

bool Firma::kontrolaNazev(const std::string nazev) const {
	if (ico.length() < 3 || ico.length() > 255) {
		return false;
	}
	else
		return true;
}

//Přátelská metoda pro výpis IČA a názvu firmy.

std::ostream& operator<<(std::ostream& os, const Firma& firma) {
	os << "ICO: " << firma.getICO() << " Firma: " << firma.getNazev() << std::endl;
	return os;
}
