#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;


class Produs
{
protected:
	string nume;
	bool impachetat;
public:
	Produs();
	Produs(bool i,string num);
	void impachetSet(bool i);
	bool impachetGet();
	void setNume(string num);
	virtual void Set(void) {};
	virtual void afisare(void);

	virtual void fSet(void){}
	virtual void fafisare(void);

	virtual ~Produs() {}
};


class Comanda
{
private:
	static int nr;//nr comanda
	Produs *a[3];// 0-fel principal, 1-desert, 2-bautura
public:
	Comanda();
	Comanda(Produs *x, Produs *y, Produs *z);
	~Comanda();
	void afisare(void);
	void editare(void);
	void setUp(void);

	void fsetUp(void);
	void fafisare(void);


//	void setFelPrinc(void);
//	void setDesert(void);
//	void setBautura(void);
};

