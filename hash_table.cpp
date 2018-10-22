#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <math.h>

using namespace std;


struct hasht
{
	int key;
};

hasht * tab = new hasht[997];

void pusta()
{
	for (int i = 0; i < 997; i++)
	{
		tab[i].key = 0;
	}
}

bool wstaw_lin(int klucz )
{
	int val = ((klucz % 1000) + (int)pow(2, (klucz % 10)) + 1) % 997;
	while (true)
	{
		if (tab[val].key == 0)
		{
			tab[val].key = klucz;
			return true;
		}
		else if (tab[val].key == klucz)
		{
			cout << "Taki element jest juz w strukturze" << endl;
			return false;
		}
		else if (tab[val].key != 0)
		{
			val = val + 1;
			if (val == 997)
				val = 0;
		}
	}
}
bool wstaw_mie(int klucz)
{
	int i = 1;
	int val = ((klucz % 1000) + (int)pow(2, (klucz % 10)) + 1) % 997;
	int val2 = (3 * klucz) % 19 + 1;
	while (true)
	{
		if (tab[val].key == 0)
		{
			tab[val].key = klucz;
			return true;
		}
		else if (tab[val].key == klucz)
		{
			cout << "Taki element jest juz w strukturze" << endl;
			return false;
		}
		else if (tab[val].key != 0)
		{
			val = val + i * val2;
			i++;
			if (val >= 997)
				val = 0;
		}
	}
}

void wstaw_wiele_lin(int ilosc)
{
	srand(time(NULL));
	int klucz;
	for (int i = 0; i < ilosc; i++)
	{
		klucz = rand() % 20000 + 20001;
		bool a = wstaw_lin(klucz);
		if (a == false)
			i--;
	}
}
void wstaw_wiele_mie(int ilosc)
{
	srand(time(NULL));
	int klucz;
	for (int i = 0; i < ilosc; i++)
	{
		klucz = rand() % 20000 + 20001;
		bool a = wstaw_mie(klucz);
		if (a == false)
			i--;
	}
}

int szukanie(int klucz)
{
	for (int i = 0; i < 997; i++)
	{
		if (tab[i].key == klucz)
		{
			cout << "Znaleziono element na pozycji tab [ " << i << " ]" << endl;
			return i;
		}
	}
	cout << "Nie znaleziono elementu o wart klucza : " << klucz << endl;
	return -1;
}
int szukanie_2(int klucz)
{
	for (int i = 0; i < 997; i++)
	{
		if (tab[i].key == klucz)
		{
			//cout << "Znaleziono element na pozycji tab [ " << i << " ]" << endl;
			return i;
		}
	}
	//cout << "Nie znaleziono elementu o wart klucza : " << klucz << endl;
	return -1;
}
void usuwanie(int klucz)
{
	int a = szukanie_2(klucz);
	if (a != -1)
	{
		tab[a].key = -1;
	}
	else
	{
		cout << "Element nie istnieje i nie mozna go usunac" << endl;
		return;
	}
}
void wypisz(int x, int y)
{
	for (int i = x; i < y; i++)
	{
		cout << "Tab[" << i << "].key = " << tab[i].key << "\n";
	}
	return;
}

int main()
{
	int ilosc, switcher,j;
	int k1, k2, k3, k4;
	clock_t start, stop;
	double czas;
	srand(time(NULL));

	fstream dane;
	dane.open("inlab06.txt", ios::in);

	if (dane.good() == true)
	{
		while (!dane.eof())
		{
			dane >> ilosc >> k1 >> k2 >> k3 >> k4;
		}
		dane.close();
	}
	else cout << "Nie mozna otworzyc podanego pliku" << endl;
	switcher = 1;
	switch (switcher)
	{
	case 0:
		start = clock();
		pusta();
		usuwanie(k1);
		wstaw_lin(k1);
		wypisz(0, 100);
		wstaw_wiele_lin(ilosc);
		for(int i=0;i<997;i++)
		{
			if(tab[i].key>0)
			j++;
		}
		wypisz(0, 100);
		wstaw_lin(k2);
		wstaw_lin(k3);
		wstaw_lin(k4);
		wypisz(0, 100);
		wypisz(500, 600);
		usuwanie(k3);
		usuwanie(k4);
		wypisz(0, 100);
		wypisz(500, 600);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		cout << "\nCzas wykonania programu stosujac mechanizm kolizji adresowanie liniowe wynosi " << czas << endl;
		break;
	case 1:
		start = clock();
		pusta();
		usuwanie(k1);
		wstaw_mie(k1);
		wypisz(0, 100);
		wstaw_wiele_mie(ilosc);
		for(int i=0;i<997;i++)
		{
			if(tab[i].key>0)
			j++;
		}
		wypisz(0, 100);
		wstaw_mie(k2);
		wstaw_mie(k3);
		wstaw_mie(k4);
		wypisz(0, 100);
		wypisz(500, 600);
		usuwanie(k3);
		usuwanie(k4);
		wypisz(0, 100);
		wypisz(500, 600);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		cout << "\nCzas wykonania programu stosujac mechanizm kolizji mieszanie podwojne wynosi " << czas << endl;
		break;
	}
	cout<<j;
	getchar();
	return 0;
}
