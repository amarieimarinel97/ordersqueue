#pragma once
#include <iostream>
#include "Coada.h"
using namespace std;
Nod::Nod()
{
	next = nullptr;
}
Nod::~Nod()
{
	if (next != nullptr) delete next;
}
Nod::Nod(Data x)
{
	next = nullptr;
	data = x;
}
Nod::Nod(const Nod& sursa) // de verif
{
	this->data = sursa.data;
	this->next = sursa.next;
}
//////////////////////////////////

Coada::Coada()
{
	first = nullptr;
	last = nullptr;
}
Coada::~Coada()
{
	if (first != nullptr) {
		if (first->next != nullptr)
		{
			delete first->next;
		}
		delete first;
	}
	if (last != nullptr) {
		if (last->next != nullptr)
		{
			delete last->next;
		}
		delete last;
	}
}
bool Coada::IsEmpty()
{
	return (first == nullptr);
}
void Coada::Put(Data element)
{
	Nod* p;
	try {
		p = new Nod;
	}
	catch (exception e) {return;}
	p->data = element;
	if (last != nullptr)
	{
		last->next = p;
	}
	else
	{
		first = p;
	}
	last = p;
}
Data Coada::Get()
{
	if (IsEmpty()) return nullptr;
	Data aux = first->data;
	first = first->next;
	if (first == nullptr)
	{
		last = nullptr;
	}
	return aux;
}
Data Coada::Front()
{
	if (IsEmpty()) return false;
	return first->data;
}