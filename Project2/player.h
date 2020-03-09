#pragma once
#include"plywa.h"
class player {
private:
	bool rozkladaniestatek;
	bool rozkladaniestateczek;
	bool rozkladaniedestroyer;
	int nrgracza;
	int zycie;
	bool tura;
public:

	player(bool rozkladaniestatek, bool rozkladaniestateczek, bool rozkladaniedestroyer, int nrgracza, bool tura) : rozkladaniestatek(rozkladaniestatek), rozkladaniestateczek(rozkladaniestateczek), rozkladaniedestroyer(rozkladaniedestroyer), nrgracza(nrgracza), tura(tura) {};
	bool getrozkladaniestatek() const { return rozkladaniestatek; }
	void setrozkladaniestatek(bool rozkladaniestatek) { this->rozkladaniestatek = rozkladaniestatek; }
	bool getrozkladaniedestroyer() const { return rozkladaniedestroyer; }
	void setrozkladaniedestroyer(bool rozkladaniedestroyer) { this->rozkladaniedestroyer = rozkladaniedestroyer; }
	bool getrozkladaniestateczek() const { return rozkladaniestateczek; }
	void setrozkladaniestateczek(bool rozkladaniestateczek) { this->rozkladaniestateczek = rozkladaniestateczek; }
	bool gettura() const { return tura; }
	void settura(int tura) { this->tura = tura; }
	int getnrgracza()const { return nrgracza; }
	void setnrgracza(int nrgracza) { this->nrgracza = nrgracza; }

	
};

