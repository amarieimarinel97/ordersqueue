#include "Bautura.h"

Bautura::Bautura()
{
	producator = '\0';
	aciditate = 0;
	cantitate = 0;
}

Bautura::Bautura(bool imp,string num, string prod, bool acid, int cantit) : Produs(imp,num)
{
	producator = prod;
	aciditate = acid;
	cantitate = cantit;
}
void Bautura::afisare(void)
{
	Produs::afisare();
	cout << "Producator: " << producator;
	if (aciditate) cout << " (cu acid)." << endl;
	else cout << " (fara acid)." << endl;
	cout << "Cantitate: " << cantitate << "ml." << endl;
}
void Bautura::Set(void)
{
	cout << "La pachet? \n1.Nu\n2.Da\n";
	int ok; cin >> ok;
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

void Bautura::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		Produs::fafisare();
		outFile << "Producator: " << producator;
		if (aciditate) outFile << " (cu acid)." << endl;
		else outFile << " (fara acid)." << endl;
		outFile << "Cantitate: " << cantitate << "ml." << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Bautura::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		int ok; inFile >> ok;
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
	else {cout << "Fisier invalid."; Pause();}
}

////////////////////////////
Suc::Suc() {
	zahar = 0;
}
Suc::Suc(bool imp,string num, string prod, bool acid, int cantit, bool zah) :Bautura(imp,num, prod, acid, cantit)
{
	zahar = zah;
}
void Suc::afisare(void)
{
	Bautura::afisare();
	if (!zahar) cout << "Fara zahar." << endl;
}
void Suc::Set(void)
{
	cout << "Introducere suc: " << endl;
	cout << "Producator: \n1.Coca-Cola\n2.Fanta\n3.Cappy\n4.Nestea\n9.Altul\n";
	int ok; cin >> ok;
	switch (ok)
	{
	case 1:producator = "Coca-Cola"; break;
	case 2: producator = "Fanta"; break;
	case 3: producator = "Cappy"; break;
	case 4: producator = "Nestea"; break;
	case 9: cout << "Raspuns: "; cin >> producator; break;
	default: break;
	}
	ClearScreen();
	nume = "Suc";
	Bautura::Set();
	ClearScreen();
	cout << "Aciditate:\n1.Fara acid\n2.Cu acid\n";
	cin >> ok;
	aciditate = ok - 1;
	ClearScreen();
	cout << "Zahar: \n1.Fara zahar\n2.Normal\n";
	cin >> ok;
	zahar = ok - 1;
	ClearScreen();
}
void Suc::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		Bautura::fafisare();
		if (!zahar) outFile << "Fara zahar." << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Suc::fSet(void){

	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1:producator = "Coca-Cola"; break;
		case 2: producator = "Fanta"; break;
		case 3: producator = "Cappy"; break;
		case 4: producator = "Nestea"; break;
		case 9:  inFile >> producator; break;
		default: break;
		}
		nume = "Suc";
		Bautura::fSet();
		inFile >> ok;
		aciditate = ok - 1;
		inFile >> ok;
		zahar = ok - 1;
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }

}

//////////////////////////////////
Sampanie::Sampanie()
{
	alcool = 0;
}
Sampanie::Sampanie(bool imp, string num, string prod, bool acid, int cantit, bool alc) :Bautura(imp, num, prod, acid, cantit)
{
	alcool = alc;
}
void Sampanie::afisare(void)
{
	Bautura::afisare();
	if (!alcool) cout << "Non-alcoolica." << endl;
}
void Sampanie::Set(void)
{
	cout << "Introducere sampanie: " << endl;
	cout << "Producator: \n1.Moet\n2.Cliquot\n3.Taittinger\n9.Altul\n";
	int ok; cin >> ok;
	switch (ok)
	{
	case 1:producator = "Moet"; break;
	case 2: producator = "Cliquot"; break;
	case 3: producator = "Taittinger"; break;
	case 9: cout << "Raspuns: "; cin >> producator; break;
	default: break;
	}
	ClearScreen();
	nume = "Sampanie";
	Bautura::Set();
	ClearScreen();
	cout << "Alcool: \n1.Non-alcoolica\n2.Cu alcool\n";
	cin >> ok;
	alcool = ok - 1;
	ClearScreen();
}

void Sampanie::fafisare(void)
{

	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		Bautura::fafisare();
		if (!alcool) outFile << "Non-alcoolica." << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Sampanie::fSet(void)
{

	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1:producator = "Moet"; break;
		case 2: producator = "Cliquot"; break;
		case 3: producator = "Taittinger"; break;
		case 9: inFile >> producator; break;
		default: break; 
		}
		nume = "Sampanie";
		Bautura::fSet();
		inFile >> ok;
		alcool = ok - 1;
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }

}