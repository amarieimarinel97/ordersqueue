#pragma once
#include "Ierarhie.h"

class Bautura : public Produs
{
protected:
	string producator;
	bool aciditate; 
	int cantitate;
public:
	Bautura();
	Bautura(bool imp,string num,string prod, bool acid, int cantit);
	~Bautura(){}
	virtual void Set(void);
	virtual void afisare(void);

	virtual void fSet(void);
	virtual void fafisare(void);
};

class Suc : public Bautura
{
	bool zahar;
public:
	Suc();
	Suc(bool imp,string num,string prod, bool acid, int cantit, bool zahar);
	~Suc(){}
	void Set(void);
	void afisare(void);

	void fSet(void);
	void fafisare(void);

	friend class Comanda;
};

class Sampanie : public Bautura
{
	bool alcool;
public:
	Sampanie();
	Sampanie(bool imp,string num, string prod, bool acid, int cantit, bool alc);
	~Sampanie() {}
	void Set(void);
	void afisare(void);

	void fSet(void);
	void fafisare(void);


	friend class Comanda;
};