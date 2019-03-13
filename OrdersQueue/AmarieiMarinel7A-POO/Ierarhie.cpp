#include "Bautura.h"
#include "Desert.h"
#include "FelPrincipal.h"
using namespace std;
Comanda::Comanda()
{
	a[0] = nullptr;
	a[1] = nullptr;
	a[2] = nullptr;
	nr++;
}
Comanda::Comanda(Produs *x, Produs *y, Produs *z)
{
	if (x != nullptr)
	{
		a[0] = new Produs(*x);
	}
	else
	{
		a[0] = nullptr;
	}
	if (y != nullptr)
	{
		a[1] = new Produs(*y);
	}
	else
	{
		a[1]= nullptr;
	}
	if (z != nullptr)
	{
		a[2] = new Produs(*z);
	}
	else
	{
		a[2] = nullptr;
	}
	nr++;
}
Comanda::~Comanda()
{
	if (a[0] != nullptr) { delete a[0]; }
	if (a[1] != nullptr) { delete a[1]; }
	if (a[2] != nullptr) { delete a[2]; }
}
void Comanda::afisare(void)
{
	cout << "Comanda nr " << nr << " :" << endl;
	cout << "---------------------------" << endl;
	cout << "Fel principal: " << endl;
	if (a[0] != nullptr) a[0]->afisare();
	else cout << " - " << endl;
	cout << "\nDesert: " << endl;
	if (a[1] != nullptr) a[1]->afisare();
	else cout << " - " << endl;
	cout << "\nBautura: " << endl;
	if (a[2] != nullptr) a[2]->afisare();
	else cout << " - " << endl;
	cout << "---------------------------" << endl;
}
void Comanda::setUp(void)
{
	cout << "Introducere comanda fel principal?\n1.Nu\n2.Da\nRaspuns: ";
	int ok;
	cin >> ok;
	ok--;
	if (ok)
	{
		ClearScreen();
		if (a[0] != nullptr) delete a[0];
		cout << "Fel principal:\n1.Supa\n2.Friptura\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[0] = new Supa;
		else if (i == 2)a[0] = new Friptura;
		ClearScreen();
		a[0]->Set();
		cout << "Finalizat.";
	}
	else
	{
		a[0] = nullptr;
	}
	cout << "Introducere comanda desert?\n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	ok--;
	if (ok)
	{
		ClearScreen();
		if (a[1] != nullptr) delete a[1];
		cout << "Desert:\n1.Inghetata\n2.Prajitura\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[1] = new Inghetata;
		else if (i == 2)a[1] = new Prajitura;
		ClearScreen();
		a[1]->Set();
		cout << "Finalizat.";
	}
	else
	{
		a[1] = nullptr;
	}
	cout << "Introducere comanda bautura?\n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	ok--;
	if (ok)
	{

		ClearScreen();
		if (a[2] != nullptr) delete a[2];
		cout << "Bautura:\n1.Suc\n2.Sampanie\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[2] = new Suc;
		else if (i == 2)a[2] = new Sampanie;
		ClearScreen();
		a[2]->Set();
		cout << "Finalizat.";
	}
	else
	{
		a[2] = nullptr;
	}
}

void Comanda::editare(void)
{
	int ok; cout << "Editare comanda bautura?\n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	ok--;
	if (ok)
	{
		ClearScreen();
		if (a[0] != nullptr) delete a[0];
		cout << "Bautura:\n1.Supa\n2.Friptura\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[2] = new Supa;
		else if (i == 2)a[2] = new Friptura;
		ClearScreen(); 
		a[0]->Set();
		cout << "Finalizat." << endl;
	}
	cout << "Editare comanda bautura?\n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	ok--;
	if (ok)
	{
		ClearScreen();
		if (a[1] != nullptr) delete a[1];
		cout << "Desert:\n1.Inghetata\n2.Prajitura\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[2] = new Inghetata;
		else if (i == 2)a[2] = new Prajitura;
		ClearScreen();
		a[1]->Set();
		cout << "Finalizat." << endl;
	}
	cout << "Editare comanda bautura?\n1.Nu\n2.Da\nRaspuns: ";
	cin >> ok;
	ok--;
	if (ok)
	{

		ClearScreen();
		if (a[2] != nullptr) delete a[2];
		cout << "Bautura:\n1.Suc\n2.Sampanie\nRaspuns: ";
		int i; cin >> i;
		if (i == 1) a[2] = new Suc;
		else if (i == 2)a[2] = new Sampanie;
		ClearScreen();
		a[2]->Set();
		cout << "Finalizat." << endl;
	}
}

void Comanda::fsetUp(void)
{
	int ok;
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		inFile >> ok;
		ok--;
		if (ok)
		{
			if (a[0] != nullptr) delete a[0];
			int i; inFile >> i;
			if (i == 1) a[0] = new Supa;
			else if (i == 2)a[0] = new Friptura;
			a[0]->fSet();
		}
		else
		{
			a[0] = nullptr;
		}
		inFile >> ok;
		ok--;
		if (ok)
		{
			if (a[1] != nullptr) delete a[1];
			int i; inFile >> i;
			if (i == 1) a[1] = new Inghetata;
			else if (i == 2)a[1] = new Prajitura;
			a[1]->fSet();
		}
		else
		{
			a[1] = nullptr;
		}
		inFile >> ok;
		ok--;
		if (ok)
		{

			if (a[2] != nullptr) delete a[2];
			int i; inFile >> i;
			if (i == 1) a[2] = new Suc;
			else if (i == 2)a[2] = new Sampanie;;
			a[2]->fSet();
		}
		else
		{
			a[2] = nullptr;
		}
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }

}

void Comanda::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt",ios::app);
	if (outFile.is_open()) {
		outFile << "Comanda nr " << nr << " :" << endl;
		outFile << "---------------------------" << endl;
		outFile << "Fel principal: " << endl;
		if (a[0] != nullptr) a[0]->fafisare();
		else outFile << " - " << endl;
		outFile << "\nDesert: " << endl;
		if (a[1] != nullptr) a[1]->fafisare();
		else outFile << " - " << endl;
		outFile << "\nBautura: " << endl;
		if (a[2] != nullptr) a[2]->fafisare();
		else outFile << " - " << endl;
		outFile << "---------------------------" << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}
//////////////////////////////////////////////

Produs::Produs()
{
	nume = '\0';
	impachetat = 0;
}
Produs::Produs(bool imp,string num)
{
	impachetat = imp;
	nume = num;
}
void Produs::impachetSet(bool i)
{
	impachetat = i;
}
bool Produs::impachetGet()
{
	return impachetat;
}

void Produs::afisare(void)
{
	cout << "Denumire produs: " << nume << endl;
	cout << "La pachet: ";
	if (impachetat)cout << "Da"<<endl;
	else cout << "Nu" << endl;
}

void Produs::setNume(string num)
{
	nume = num;
}


void Produs::fafisare()
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open()) {
		outFile << "Denumire produs: " << nume << endl;
		outFile << "La pachet: ";
		if (impachetat)outFile << "Da" << endl;
		else outFile << "Nu" << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}