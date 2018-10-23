#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

struct Lista
{
	int key;
	double liczba;
	char znak;
	int liczba_elementow = 0;
	Lista * next=NULL;
	Lista * prev=NULL;
	Lista * first = NULL;

	//Funkcja wstawiająca element w odpowiednim miejscu według klucza
	void wstaw(int klucz)
	{
		Lista* nowy;
		nowy = new Lista;  //tworzymy nową strukturę Element

		nowy->key = klucz;
		nowy->liczba = rand();
		nowy->znak = 'T';

		int wartosc = liczba_elementow;

		if (first == NULL) //jezeli lista byla pusta 
		{
			nowy->prev = nowy;
			nowy->next = nowy;
			first = nowy;
			liczba_elementow++;
			return;
		}

		Lista* temp = first; //tymczasowy wskaznik na glowe Listy

		for(int i=0;i<wartosc;i++)
		{
			if (nowy->key == temp->key)
			{
				cout << "BLAD: Element o takim kluczu znajduje sie na liscie" << endl;
				return;
			}
			else if (liczba_elementow == 1)
			{
				if (first->key < nowy->key)
				{
					first->next = nowy;
					first->prev = nowy;
					nowy->prev = first;
					nowy->next = first;
					liczba_elementow++;
					return;
				}
				else
				{
					first->next = nowy;
					first->prev = nowy;
					nowy->prev = first;
					nowy->next = first;
					liczba_elementow++;
					first = nowy;
					return;
				}
			}

			else if (nowy->key > (first->prev)->key)
			{
				nowy->prev = first->prev;
				nowy->next = first;
				(first->prev)->next = nowy;
				first->prev = nowy;
				liczba_elementow++;
				return;
			}

			else if (nowy->key < first->key)
			{
				nowy->prev = first->prev;
				nowy->next = first;
				(first->prev)->next = nowy;
				first->prev = nowy;
				first = nowy;
				liczba_elementow++;
				return;
			}
			else if (nowy->key > temp->key && nowy->key < (temp->next)->key)
			{
				nowy->prev = temp;
				nowy->next = temp->next;
				(temp->next)->prev = nowy;
				temp->next = nowy;
				liczba_elementow++;
				return;
			}
			temp = temp->next;
		}
		return;
	}
	//Funkcja wstawiajaca X elementów do Listy
	void wstaw_wiele(int X)
	{
		int klucz = (rand() % 99900 + 99);
		for (int i = 0; i < X; i++)
		{
			wstaw(klucz);
			klucz = (rand() % 99900 + 99);
		}
		return;
	}
	//Funkcja szukająca podanego elementu
	bool znajdz_element(int klucz)
	{
		Lista* temp = first;
		if (first == NULL)
		{
			cout << "Lista nie zawiera elementow" << endl;
			return false;
		}

		int ilosc = liczba_elementow;
		for (int i = 0; i < ilosc; i++)
		{
			if (temp->key == klucz)
			{
				cout << "\nW Liscie znajduje sie szukany element na pozycji nr " << i + 1 << endl;
				return true;
			}
			else
			{
				temp = temp->prev;
			}

		}
		cout << "\nW liscie nie ma elementu o danej wartosci klucza" << endl;
		return false;
	};
	//Funkcja usuwająca element o podanej wartosci klucza
	void usun_element(int klucz)
	{
		Lista* temp = first;
		if (znajdz_element_bool(klucz) == false)
		{
			cout << "\nW liscie nie znajdue sie podany element" << endl;
			return;
		}
		else if (first == NULL)
		{
			cout << "\n W liscie nie ma elementow" << endl;
		}
		else
		{
			int ilosc = liczba_elementow;
			for (int i = 0; i < ilosc; i++)
			{
				if (temp->key == klucz)
				{
					if (temp == first)
					{
						first->next->prev = first->prev;
						first->prev->next = first->next;
						first = first->next;
						delete temp;
						liczba_elementow--;
						cout << "\nUsunieto element o wartosci klucza " <<klucz<< endl;
						return;
					}
					else
					{
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
						liczba_elementow--;
						cout << "\nUsunieto element o wartosci klucza " << klucz << endl;
						return;
					}
				}
				else
				{
					temp = temp->prev;
				}
			}
		}
	};
	//Funkcja prezentujaca wybrane pierwsze elementy listy
	void wyswietl_klucz_front(int ilosc)
	{
		Lista* temp = first;
		if (first == NULL)
		{
			cout << "\nBLAD WYPISYWANIA : Lista jest pusta" << endl;
			return;
		}
		else if (ilosc > liczba_elementow)
		{
			cout << "\nBLAD WYPISYWANIA : Lista zawiera za malo elementow" << endl;
			return;
		}
		else
		{
			cout << "\nZaczynam wypisywanie wartosci skladowych kluczy pierwszychy " << ilosc << " elementow listy:" << endl;
			for (int i = 0; i < ilosc; i++)
			{
				cout << temp->key << " ";
				temp = temp->next;
			}
			cout << "\n" << endl;
		}
		return;
	}
	//Funkcja  prezentujaca wybrane ostatnie elementy listy
	void wyswietl_klucz_back(int ilosc)
	{
		Lista* temp = first;
		if (first == NULL)
		{
			cout << "\nBLAD WYPISYWANIA : Lista jest pusta" << endl;
			return;
		}
		else if (ilosc > liczba_elementow)
		{
			cout << "\nBLAD WYPISYWANIA : Lista zawiera za malo elementow" << endl;
			return;
		}
		else
		{
			cout << "\nRozpoczynam wypisywanie wartosci kluczowych ostatnich " << ilosc << " elementow listy:" << endl;
			for (int i = 0; i < ilosc; i++)
			{
				cout << temp->prev->key << " ";
				temp = temp->prev;
			}
			cout << "\n" << endl;
		}
		return;
	}
	//Funkcja wypisujaca liczbe elementow w liscie
	void ilosc_elementow()
	{
		cout << "\nLiczba elementow wynosi: " << liczba_elementow << endl;
	}
	//Funkcja usuwajaca wszystkie elementy z listy
	void usun_wszystko()
	{
		int liczba_elementow2 = liczba_elementow;
		Lista* temp = first;
		if (first == NULL)
		{
			cout << "\nLista jest pusta, nie ma co usuwac" << endl;
			return;
		}
		else
		{
			Lista* temp = first;
			for (int i = 0; i < liczba_elementow2 - 1  ; i++)
			{
				first = first->next;
				delete temp;
				temp = first;
				liczba_elementow--;
			}
			delete temp;
			liczba_elementow = liczba_elementow - 1;
			cout << "\nUsunieto wszystkie elementy listy" << endl;
		}
		return;
	}
	//Funkcja znajdz element bez cout
	bool znajdz_element_bool(int klucz)
	{
		Lista* temp = first;
		if (first == NULL)
		{
			return false;
		}

		int ilosc = liczba_elementow;
		for (int i = 0; i < ilosc; i++)
		{
			if (temp->key == klucz)
			{
				return true;
			}
			else
			{
				temp = temp->prev;
			}

		}
		return false;
	};
	};


int main()
{
	int ilosc_losowana;
	int k1, k2, k3, k4, k5;
	clock_t start, stop;
	double czas;
	srand(time(NULL));

	fstream dane;
	dane.open("inlab02.txt", ios::in);

	if (dane.good() == true)
	{
		while (!dane.eof())
		{
			dane >> ilosc_losowana >> k1 >> k2 >> k3 >> k4 >> k5;
		}
		dane.close();
	}
	else cout << "Nie mozna otworzyc podanego pliku"<<endl;

	start = clock();

	Lista nowaLista;
	nowaLista.znajdz_element(k1);
	nowaLista.wstaw_wiele(ilosc_losowana);
	nowaLista.ilosc_elementow();
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.wstaw(k2);
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.wstaw(k3);
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.wstaw(k4);
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.wstaw(k5);
	nowaLista.usun_element(k3);
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.usun_element(k2);
	nowaLista.wyswietl_klucz_front(20);
	nowaLista.usun_element(k5);
	nowaLista.ilosc_elementow();
	nowaLista.znajdz_element(k5);
	nowaLista.wyswietl_klucz_back(11);
	nowaLista.usun_wszystko();
	nowaLista.wyswietl_klucz_back(11);
	nowaLista.ilosc_elementow();

	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "\nCzas wykonania programu wynosi " << czas << endl;
	getchar();
    return 0;
}
