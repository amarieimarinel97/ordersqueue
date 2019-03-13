#include<iostream>
#include "Globals.h"
#include "Menu.h"
#include "SimpleOperation.h"
#include "Coada.h"
#include "Ierarhie.h"
#include "Bautura.h"
#include "FelPrincipal.h"
#include "Desert.h"

using namespace std;
int Comanda::nr = 0;
Coada q;
int main(void)
{
	Menu *meniu = new Menu("Meniu Principal");
	meniu->AddItem(new Write("Introduceti o comanda noua")); // foloseste coada.Put
	meniu->AddItem(new Read("Extrage urmatoarea comanda")); // foloseste coada.Get + afisare pe ecran
	meniu->AddItem(new FileWrite("Extrage si scrie urmatoarea comanda in fisier")); //coada.Get + scriere in fisier
	meniu->AddItem(new FileRead("Citeste o comanda salvata in fisier")); // nu foloseste coada.Get, citeste din fisierul predefinit InData.txt
	meniu->AddItem(new CheckFile("Afiseaza toate comenzile din fisier")); // afiseaza din fisierul outData.txt
	meniu->AddItem(new EraseFile("Goleste fisierul de comenzi")); // goleste outData.txt
	meniu->Execute();
	delete meniu;
	cout << endl << endl << "Sfarsit." << endl;
//	Pause();
	return 0;
}
