#include "Firma.h"

const std::string defaultICO = "99999999";
const std::string defaultFirma = "bezejmenna";

Firma::Firma() {
	this->ico = defaultICO;
	this->nazev = defaultFirma;
}

Firma::Firma(const std::string ico, const std::string nazev) {
	if (!setICO(ico)) {
		this->ico = defaultICO;
	}

	if (!setNazev(nazev)) {
		this->nazev = defaultFirma;
	}
}

Firma::Firma(const Firma& f) {
	this->ico = f.getICO();
	this->nazev = f.getNazev();
}

std::string Firma::getICO() const {
	return this->ico;
}

bool Firma::setICO(const std::string ico) {
	if (kontrolaICO(ico)) {
		this->ico = ico;
		return true;
	}

	else {
		return false;
	}
}

std::string Firma::getNazev() const {
	return this->ico;
}

bool Firma::setNazev(const std::string nazev) {
	if (kontrolaNazev(nazev)) {
		this->nazev = nazev;
		return true;
	}

	else {
		return false;
	}
}

bool Firma::kontrolaICO(const std::string ico) const {
	if (ico.length() != 8) {
		return false;
	}

	int zbytek = 0;

	for (int i = 0; i < ico.length() - 1; i++) {
		zbytek = std::stoi(ico.substr(i)) * (ico.length() + 1 - i);
	}

	zbytek = (11 - (zbytek % 11)) % 10;

	if (zbytek == std::stoi(ico.substr(7))) {
		return true;
	}

	else {
		return false;
	}
}

bool Firma::kontrolaNazev(const std::string nazev) const {
	if (ico.length() < 3 || ico.length() > 255) {
		return false;
	}
	else
		return true;
}

std::ostream& operator<<(std::ostream& os, const Firma& firma) {
	os << "ICO: " << firma.getICO() << " Firma: " << firma.getNazev() << std::endl;
	return os;
}
