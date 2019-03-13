#pragma once
#include "Ierarhie.h"
class FelPrincipal : public Produs
{
protected:
	int portii;
public:
	FelPrincipal();
	FelPrincipal(bool i, string num,int p);
	void afisare(void);
	~FelPrincipal() {}
	virtual void Set(void);

	void fafisare(void);
	void fSet(void);
};

class Supa : public FelPrincipal
{
	string ingredient;
public:
	Supa();
	Supa(bool i, string num,int p,string ing);
	~Supa() {}
	virtual void afisare(void);
	virtual void Set(void);
	void fafisare(void);
	void fSet(void);
};

class Friptura : public FelPrincipal
{
	string animal;
	string garnitura;
public:
	Friptura();
	Friptura(bool i, string num,int p,string anim, string garnit);
	virtual void afisare(void);
	~Friptura() {}
	virtual void Set(void);

	void fafisare(void);
	void fSet(void);
};


