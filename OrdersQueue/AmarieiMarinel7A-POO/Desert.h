#pragma once
#include "Ierarhie.h"

class Desert : public Produs
{
protected:
	string producator;
	int cantitate;
public:
	Desert();
	Desert(bool i,string nume, string produc, int cantit);
	void afisare(void);
	virtual void Set(void);
	
	void fafisare(void);
	void fSet(void);

	~Desert() {}
};

class Inghetata : public Desert
{
	string aroma;
	bool conSauPahar;
public:
	Inghetata();
	Inghetata(bool i,string nume, string produc, int cantit, string arom, bool cSp);
	void afisare(void);
	~Inghetata() {}
	void Set(void);

	void fafisare(void);
	void fSet(void);

	friend class Comanda;
};

class Prajitura : public Desert
{
	string ingredient;
public:
	Prajitura();
	Prajitura(bool i,string nume, string produc, int cantit, string ing);
	void afisare(void);
	void Set(void);
	~Prajitura() {}

	void fafisare(void);
	void fSet(void);

	friend class Comanda;
};


