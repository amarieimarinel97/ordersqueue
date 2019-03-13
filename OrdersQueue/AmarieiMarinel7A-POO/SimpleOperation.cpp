#include <iostream>
#include "Globals.h"
#include "Bautura.h"
#include "Desert.h"
#include "FelPrincipal.h"
#include "SimpleOperation.h"
#include "Coada.h"
using namespace std;
extern Coada q;
Write::Write(char *name):Operation(name){}

void Write::ExecuteOperation(void)
{
	Comanda* c = new Comanda;
	c->setUp();
	q.Put(c);
	cout << "Comanda inregistrata." << endl;
	Pause();
}

Read::Read(char *name):Operation(name){}

void Read::ExecuteOperation(void)
{
	Comanda *c = nullptr;
	c = (q.Get());
	if (c != nullptr) {
		c->afisare();
	}
	else { cout << "Nu mai exista comenzi neservite.\n"; }

	Pause();
}

FileWrite::FileWrite(char *name):Operation(name){}

void FileWrite::ExecuteOperation(void)
{
	Comanda *c = nullptr;
	c = (q.Get());
	if (c != nullptr) {
		c->fafisare();
		cout << "Comanda inscrisa in fisier cu succes. \n";
	}
	else { cout << "Nu mai exista comenzi neservite.\n"; }

	cout<<" Doriti afisarea fisierului ce contine comenzile inregistrate ? \n1.Nu\n2.Da\nRaspuns: ";
	int i; cin >> i; i--;
	if(i)
	{
		string line;
		ifstream file;
		file.open("outData.txt");
		if (file.is_open())
		{
			while (getline(file, line))
			{
				cout << line << endl;
			}
			file.close();
		}
		else
		{
			cout << "Fisier invalid." <<endl;
		}
		Pause();
	}
	
}

FileRead::FileRead(char *name):Operation(name){}

void FileRead::ExecuteOperation(void)
{
	Comanda *c = new Comanda;
	c->fsetUp(); 
	cout << "Comanda citita din fisier: " << endl;
	c->afisare();
	Pause();
}


CheckFile::CheckFile(char *name):Operation(name){}

void CheckFile::ExecuteOperation(void)
{
	string line;
	ifstream file;
	file.open("outData.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
		file.close();
	}
	else
	{
		cout << "Fisier invalid." << endl;
	}
	Pause();
}

EraseFile::EraseFile(char *name):Operation(name){}

void EraseFile::ExecuteOperation(void)
{
	ofstream file("outData.txt",ios::trunc);
	if (file.is_open())
	{
		file << " \b";
		cout << "Fisier gol.";
		file.close();
	}
	else
	{
		cout << "Fisier invalid." << endl;
	}
	Pause();

}
