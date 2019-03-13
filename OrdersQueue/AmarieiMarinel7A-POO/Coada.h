#pragma once
#include "Ierarhie.h"
typedef Comanda* Data;
class Nod {
	Nod *next;
	Data data;
public:
	Nod();
	Nod(Data x);
	Nod(const Nod& sursa);
	~Nod();
	friend class Coada;
};

class Coada {
	Nod* first; // capul cozii
	Nod* last; // ultimul element din coada
public:
	Coada();
	~Coada();
	bool IsEmpty();
	void Put(Data element); // pune un element la sfarsitul cozii
	Data Get(); //detaseaza si returneaza un element din capul cozii
	Data Front();

};