#include "FelPrincipal.h"
FelPrincipal::FelPrincipal()
{
	portii = 0;
}
FelPrincipal::FelPrincipal(bool i, string num, int p) :Produs(i, num)
{
	portii = p;
}
void FelPrincipal::afisare(void)
{
	Produs::afisare();
	cout << "Portii: " << portii << endl;
}
void FelPrincipal::Set(void)
{
	cout << "La pachet? \n1.Nu\n2.Da\nRaspuns: ";
	int x; cin >> x;
	impachetat = x - 1;
	ClearScreen();
	cout << "Numar portii: ";
	cin >> portii;
}

void FelPrincipal::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		Produs::fafisare();
		outFile << "Portii: " << portii << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void FelPrincipal::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		int x;inFile >> x;
		impachetat = x - 1;
		inFile >> portii;
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}
//////////////////////////////////
Supa::Supa()
{
	ingredient = '\0';
}
Supa::Supa(bool i, string num, int p, string ing) :FelPrincipal(i, num, p)
{
	ingredient = ing;
}
void Supa::afisare()
{
	FelPrincipal::afisare();
	cout << "Ingredient supa: " << ingredient << endl;
}
void Supa::Set(void)
{
	cout << "Introducere supa: " << endl;
	nume = "Supa";
	FelPrincipal::Set();
	ClearScreen();
	cout << "Tip supa: \n1.Pui\n2.Galuste\n3.Burta\n4.Legume\n9.Altul\n";
	int ok; cin >> ok;
	switch(ok)
	{
	case 1: ingredient = "Pui";
		break;
	case 2: ingredient = "Galuste";
		break;
	case 3: ingredient = "Burta";
		break;
	case 4: ingredient = "Legume";
		break;
	case 9:
		cout << "Raspuns: ";
		cin >> ingredient;
		break;
	default: break;
	}
	ClearScreen();
}

void Supa::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		FelPrincipal::fafisare();
		outFile << "Ingredient supa: " << ingredient << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Supa::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		nume = "Supa";
		FelPrincipal::fSet();
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1: ingredient = "Pui";
			break;
		case 2: ingredient = "Galuste";
			break;
		case 3: ingredient = "Burta";
			break;
		case 4: ingredient = "Legume";
			break;
		case 9:
			inFile >> ingredient;
			break;
		default: break;
		}

		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }

}

/////////////////////////////////
Friptura::Friptura()
{
	animal = '\0';
	garnitura = '\0';
}
Friptura::Friptura(bool i, string num, int p, string anim, string garnit) : FelPrincipal(i, num, p)
{
	animal = anim;
	garnitura = garnit;
}
void Friptura::afisare()
{
	FelPrincipal::afisare();
	cout << "Carne friptura: " << animal << endl;
	cout << "Garnitura: " << garnitura << endl;
}
void Friptura::Set()
{
	cout << "Introducere friptura: " << endl;
	nume = "Friptura";
	FelPrincipal::Set();
	ClearScreen();
	cout << "Carne friptura: \n1.Pui\n2.Porc\n3.Vita\n9.Altul\n";
	int ok; cin >> ok;
	switch(ok)
	{
	case 1:animal = "Pui"; break;
	case 2: animal = "Porc"; break;
	case 3:animal = "Vita"; break;
	case 9: cout << "Raspuns: "; cin >> animal; break;
	default: break;
	}
	ClearScreen();
	cout << "Garnitura: \n1.Cartofi\n2.Wedges\n3.Chips\n9.Altul\n";
	cin >> ok;
	switch (ok)
	{
	case 1: garnitura = "Cartofi"; break;
	case 2: garnitura = "Wedges"; break;
	case 3: garnitura = "Chips"; break;
	case 9: cout << "Raspuns: "; cin >> garnitura; break;
	default: break;
	}
	ClearScreen();
}

void Friptura::fafisare(void)
{
	ofstream outFile;
	outFile.open("outData.txt", ios::app);
	if (outFile.is_open())
	{
		FelPrincipal::fafisare();
		outFile << "Carne friptura: " << animal << endl;
		outFile << "Garnitura: " << garnitura << endl;
		outFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }
}

void Friptura::fSet(void)
{
	ifstream inFile;
	inFile.open("InData.txt");
	if (inFile.is_open())
	{
		nume = "Friptura";
		FelPrincipal::fSet();
		int ok; inFile >> ok;
		switch (ok)
		{
		case 1:animal = "Pui"; break;
		case 2: animal = "Porc"; break;
		case 3:animal = "Vita"; break;
		case 9: inFile >> animal; break;
		default: break;
		}
		inFile >> ok;
		switch (ok)
		{
		case 1: garnitura = "Cartofi"; break;
		case 2: garnitura = "Wedges"; break;
		case 3: garnitura = "Chips"; break;
		case 9: inFile >> garnitura; break;
		default: break;
		}
		inFile.close();
	}
	else { cout << "Fisier invalid."; Pause(); }


}