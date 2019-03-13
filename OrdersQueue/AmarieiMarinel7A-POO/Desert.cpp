#include "Desert.h"
Desert::Desert()
{
	producator = '\0';
	cantitate = 0;
}
Desert::Desert(bool i, string nume, string produc, int cantit) :Produs(i, nume)
{
	producator = produc;
	cantitate = cantit;
}
void Desert::afisare(void)
{
	Produs::afisare();
	cout << "Producator: " << producator << endl;
	cout << "Cantitate: " << cantitate << " ml." << endl;
}
void Desert::Set()
{
	int ok;
	cout << "La pachet? \n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	impachetat = ok - 1;
	ClearScreen();
	cout << "Cantitate: \n1.330ml\n2.500ml\n3.1L\n";
	cin >> ok;
	switch (ok)
	{
	case 1: cantitate = 330; break;
	case 2: cantitate = 500; break;
	case 3: cantitate = 1000; break;
	default: break;
	}
}

void Desert::fafisare(void)
{

	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open()) {
		Produs::fafisare();
		outFile << "Producator: " << producator << endl;
		outFile << "Cantitate: " << cantitate << " ml." << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Desert::fSet(void)
{

	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		int ok;
		inFile >> ok;
		impachetat = ok - 1;
		inFile >> ok;
		switch (ok)
		{
		case 1: cantitate = 330; break;
		case 2: cantitate = 500; break;
		case 3: cantitate = 1000; break;
		default: break;
		}
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}
//////////////////////////

Inghetata::Inghetata()
{
	aroma = '\0';
	conSauPahar = 0;
}
Inghetata::Inghetata(bool i, string nume, string produc, int cantit, string arom, bool cSp) : Desert(i, nume, produc, cantit)
{
	aroma = arom;
	conSauPahar = cSp;
}
void Inghetata::afisare(void)
{
	Desert::afisare();
	cout << "Aroma: " << aroma << endl;
	cout << "Ambalaj: ";
	if (conSauPahar) cout << "Con" << endl;
	else cout << "Pahar" << endl;
}
void Inghetata::Set()
{
	cout << "Introducere inghetata: " << endl;
	Desert::Set();
	ClearScreen();
	nume = "Inghetata";
	cout << "Producator: \n1.BlueIce\n2.Nestle\n3.BettyIce\n4.Destiny\n9.Altul\n";
	int ok; cin >> ok;
	switch (ok)
	{
	case 1:producator = "BlueIce"; break;
	case 2: producator = "Nestle"; break;
	case 3: producator = "BettyIce"; break;
	case 4: producator = "Destiny"; break;
	case 9: cout << "Raspuns: "; cin >> producator; break;
	default: break;
	}
	ClearScreen();
	cout << "Aroma: \n1.Vanilie\n2.Ciocolata\n3.Caramel\n4.Capsuni\n5.Cocos\n9.Altul\n";
	 cin >> ok;
	switch (ok)
	{
	case 1: aroma = "Vanilie"; break;
	case 2: aroma = "Ciocolata"; break;
	case 3: aroma = "Caramel"; break;
	case 4: aroma = "Capsuni"; break;
	case 5: aroma = "Cocos"; break;
	case 9: cout << "Raspuns: "; cin >> aroma; break;
	default: break;
	}
	ClearScreen();
	cout << "Ambalaj: \n1.Con\n2.Pahar";
	cin >> ok;
	conSauPahar = ok - 1;
	ClearScreen();
}

void Inghetata::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open()) {
		Desert::fafisare();
		outFile << "Aroma: " << aroma << endl;
		outFile << "Ambalaj: ";
		if (conSauPahar) outFile << "Con" << endl;
		else outFile << "Pahar" << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Inghetata::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		Desert::fSet();
		nume = "Inghetata";
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1:producator = "BlueIce"; break;
		case 2: producator = "Nestle"; break;
		case 3: producator = "BettyIce"; break;
		case 4: producator = "Destiny"; break;
		case 9: inFile >> producator; break;
		default: break;
		}
		inFile >> ok;
		switch (ok)
		{
		case 1: aroma = "Vanilie"; break;
		case 2: aroma = "Ciocolata"; break;
		case 3: aroma = "Caramel"; break;
		case 4: aroma = "Capsuni"; break;
		case 5: aroma = "Cocos"; break;
		case 9: inFile >> aroma; break;
		default: break;
		}
		inFile >> ok;
		conSauPahar = ok - 1;
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

/////////////////////
Prajitura::Prajitura()
{
	ingredient = '\0';
}
Prajitura::Prajitura(bool i, string nume, string produc, int cantit, string ing) : Desert(i, nume, produc, cantit)
{
	ingredient = ing;
}

void Prajitura::afisare(void)
{
	Desert::afisare();
	cout << "Ingredient prajitura: " << ingredient << endl;
}
void Prajitura::Set(void)
{
	cout << "Introducere prajitura: ";
	Desert::Set();
	ClearScreen();
	nume = "Prajitura";
	cout << "Producator: \n1.DrOetker\n2.Oreo\n3.Milka\n4.Snickers\n9.Altul\n";
	int ok; cin >> ok;
	switch (ok)
	{
	case 1:producator = "DrOetker"; break;
	case 2: producator = "Oreo"; break;
	case 3: producator = "Milka"; break;
	case 4: producator = "Snickers"; break;
	case 9: cout << "Raspuns: "; cin >> producator; break;
	default: break;
	}
	ClearScreen();
	cout << "Ingredient prajitura: \n1.Lapte\n2.Ciocolata\n3.Caramel\n4.Cocos\n9.Altul\n";
	cin >> ok;
	switch (ok)
	{
	case 1: ingredient = "Lapte"; break;
	case 2: ingredient = "Ciocolata"; break;
	case 3: ingredient = "Caramel"; break;
	case 4: ingredient = "Cocos"; break;
	case 9 :cout << "Raspuns: "; cin >> producator; break;
	default: break;
	}
	ClearScreen();
}

void Prajitura::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open()) {
		Desert::fafisare();
		outFile<< "Ingredient prajitura: " << ingredient << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Prajitura::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		Desert::fSet();
		nume = "Prajitura";
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1:producator = "DrOetker"; break;
		case 2: producator = "Oreo"; break;
		case 3: producator = "Milka"; break;
		case 4: producator = "Snickers"; break;
		case 9: inFile >> producator; break;
		default: break;
		}
		inFile >> ok;
		switch (ok)
		{
		case 1: ingredient = "Lapte"; break;
		case 2: ingredient = "Ciocolata"; break;
		case 3: ingredient = "Caramel"; break;
		case 4: ingredient = "Cocos"; break;
		case 9:inFile >> producator; break;
		default: break;
		}

		inFile.close();

	}
	else { cout << "Fisier invalid."; Pause(); }
}