#pragma once
#include <string>
#include <iostream>


class Firma {
public:
	Firma();
	Firma(const std::string, const std::string);
	Firma(const Firma&);

	std::string getICO()const;
	bool setICO(const std::string);
	std::string getNazev()const;
	bool setNazev(const std::string);

private:
	std::string ico;
	std::string nazev;

	bool kontrolaICO(const std::string)const;
	bool kontrolaNazev(const std::string)const;

};

