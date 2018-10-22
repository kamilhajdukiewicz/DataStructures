#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;
int ilosc{ 0 };
unsigned int odwiedzone_pre{ 0 };
unsigned int odwiedzone_in{ 0 };
unsigned int odwiedzone_post{ 0 };

struct wezel		//struktura wezla
{
	int klucz{ NULL };
	wezel * lewy{ NULL };
	wezel * prawy{ NULL };
	char znak[10];
};
//dziala
void puste_drzewo(struct wezel *root) //inicjacja pustego drzewa
{
	root = NULL;
}
//dziala
void insert(wezel *root, int klucz)
{
	int i = 0;
	int czy_klucz = klucz;
	wezel * temp1;
	temp1 = new wezel;
	if (klucz < 0)
	{
		klucz = klucz*(-1);
	} //wartosc bezwględna z klucza
	temp1->lewy = NULL;
	temp1->prawy = NULL;

	wezel * temp2;
	temp2 = root;

	if (root->klucz == NULL)
	{
		root->klucz = czy_klucz;
		root->lewy = NULL;
		root->prawy = NULL;
		{
			while (klucz != 0)          //przypisane wartosci klucza do chara;
			{
				char znakk = klucz % 10;
				klucz = klucz / 10;
				root->znak[i] = 48 + znakk;
				i++;
			}
			for (int j = 0; j < i / 2; j++) //odwrocenie tablicy
			{
				if (czy_klucz < 0)  //dopisanie '-' kiedy wartosc ujemna
				{
					char temp = root->znak[i - j - 1];
					root->znak[i - j - 1] = root->znak[j];
					root->znak[j] = temp;
					root->znak[i] = 45;
				}
				else
				{
					char temp = root->znak[i - j - 1];
					root->znak[i - j - 1] = root->znak[j];
					root->znak[j] = temp;
				}
			}
			while (czy_klucz < 0) //przerzucenie '-' na pooczatek tablicy
			{
				char temp = root->znak[i];
				for (int z = i; z > 0; z--)
					root->znak[z] = root->znak[z - 1];
				root->znak[0] = temp;
				czy_klucz = czy_klucz*(-1);
				i++;
			}
		/*	for (int z = 0; z < i; z++)
			{
				cout << root->znak[z];
			}
			cout << "\n" << endl;*/
		}
		return;
	}
	else
	{
		while (true)
		{
			if (klucz < temp2->klucz)
			{
				if (temp2->lewy == NULL)
				{
					temp1->klucz = klucz;
					{
						while (klucz != 0)          //przypisane wartosci klucza do chara;
						{
							char znakk = klucz % 10;
							klucz = klucz / 10;
							temp1->znak[i] = 48 + znakk;
							i++;
						}
						for (int j = 0; j < i / 2; j++) //odwrocenie tablicy
						{
							if (czy_klucz < 0)  //dopisanie '-' kiedy wartosc ujemna
							{
								char temp = temp1->znak[i - j - 1];
								temp1->znak[i - j - 1] = temp1->znak[j];
								temp1->znak[j] = temp;
								temp1->znak[i] = 45;
							}
							else
							{
								char temp = temp1->znak[i - j - 1];
								temp1->znak[i - j - 1] = temp1->znak[j];
								temp1->znak[j] = temp;
							}
						}
						while (czy_klucz < 0) //przerzucenie '-' na pooczatek tablicy
						{
							char temp = temp1->znak[i];
							for (int z = i; z > 0; z--)
								temp1->znak[z] = temp1->znak[z - 1];
							temp1->znak[0] = temp;
							czy_klucz = czy_klucz*(-1);
							i++;
						}
					  /*for (int z = 0; z < i; z++)
						{
							cout << temp1->znak[z];
						}
						cout << "\n" << endl;*/
					}
					temp2->lewy = temp1;
					break;
				}
				else
				{
					temp2 = temp2->lewy;
				}
			}
			else if (klucz == temp2->klucz)
			{
				cout << "\nBlad, taki klucz = "<<klucz<<" juz istnieje\n" << endl;
				ilosc--;
				return;
			}
			else
			{
				if (temp2->prawy == NULL)
				{
					temp1->klucz = klucz;
					{
						while (klucz != 0)          //przypisane wartosci klucza do chara;
						{
							char znakk = klucz % 10;
							klucz = klucz / 10;
							temp1->znak[i] = 48 + znakk;
							i++;
						}
						for (int j = 0; j < i / 2; j++) //odwrocenie tablicy
						{
							if (czy_klucz < 0)  //dopisanie '-' kiedy wartosc ujemna
							{
								char temp = temp1->znak[i - j - 1];
								temp1->znak[i - j - 1] = temp1->znak[j];
								temp1->znak[j] = temp;
								temp1->znak[i] = 45;
							}
							else
							{
								char temp = temp1->znak[i - j - 1];
								temp1->znak[i - j - 1] = temp1->znak[j];
								temp1->znak[j] = temp;
							}
						}
						while (czy_klucz < 0) //przerzucenie '-' na pooczatek tablicy
						{
							char temp = temp1->znak[i];
							for (int z = i; z > 0; z--)
								temp1->znak[z] = temp1->znak[z - 1];
							temp1->znak[0] = temp;
							czy_klucz = czy_klucz*(-1);
							i++;
						}
						/*for (int z = 0; z < i; z++)
						{
							cout << temp1->znak[z];
						}
						cout << "\n" << endl;*/
					}
					temp2->prawy = temp1;
					break;
				}
				else
				{
					temp2 = temp2->prawy;
				}
			}
		}
	}
}
//dziala
void wstawianie_wielu(struct wezel * root, int ilosc)
{
	int klucz = (rand() % 20000 - 10000);
	for (int i = 0; i < ilosc; i++)
	{
		insert(root, klucz);
		klucz = (rand() % 20000 - 10000);

	}
	return;
}
//dziala
bool szukanie(struct wezel * root, int klucz)
{
	wezel * temp2;
	temp2 = root;

	if (klucz == temp2->klucz)
	{
		cout << "\n\nSzukany element jest rootem\n" << endl;
		return true;
	}

	while (true)
	{
		if (klucz < temp2->klucz)
		{
			if (temp2->lewy == NULL)
			{
				cout << "\nNie ma takiego elementu\n" << endl;
				return false;
			}
			else
			{
				temp2 = temp2->lewy;
			}
		}
		else if (klucz == temp2->klucz)
		{
			cout << "\nZnaleziono taki klucz = "<<klucz<<"\n" << endl;
			return true;
		}
		else
		{
			if (temp2->prawy == NULL)
			{
				cout << "\nNie ma takiego elementu\n" << endl;
				return false;
			}
			else
			{
				temp2 = temp2->prawy;
			}
		}
	}

}
//dziala
void usuwanie(struct wezel * root, int klucz)
{
	wezel * parent, *ptr, *preparent, *child, *grandchild;
	parent = NULL;
	ptr = root;
	while ((ptr != NULL) && (klucz != ptr->klucz))
	{
		parent = ptr;
		if (ptr->klucz < klucz)
		{
			ptr = ptr->prawy;
		}
		else
		{
			ptr = ptr->lewy;
		}
	}
	if (ptr == NULL)
	{
		cout << "\n\nBrak wezla o podanym kluczu\n" << endl;
		return;
	}
	if ((ptr->prawy == NULL) && (ptr->lewy == NULL))
	{
		if (ptr == root)
		{
			root = NULL;
			return;
		}
		if (parent->prawy == ptr)
		{
			parent->prawy = NULL;
		}
		else
		{
			parent->lewy = NULL;
		}
		return;
	}
	if (ptr->prawy == NULL)
	{
		if (ptr == root)
		{
			root = ptr->lewy;
		}
		else if (parent->prawy == ptr)
		{
			parent->prawy = ptr->lewy;
		}
		else
		{
			parent->lewy = ptr->lewy;
		}
		return;
	}
	if (ptr->lewy == NULL)
	{
		if (ptr == root)
		{
			root = ptr->prawy;
		}
		else if (parent->prawy == ptr)
		{
			parent->prawy = ptr->prawy;
		}
		else
		{
			parent->lewy = ptr->prawy;
		}
		return;
	}

	preparent = ptr;
	child = ptr->lewy;
	while (child->prawy != NULL)
	{
		preparent = child;
		child = child->prawy;
	}
	if (child == ptr->lewy)
	{
		if (ptr == root)
		{
			root = ptr->lewy;
		}
		else if (parent->prawy == ptr)
		{
			parent->prawy = child;
		}
		else
		{
			parent->lewy = child;
		}
		return;
	}

	grandchild = child->lewy;
	if (preparent->prawy == child)
	{
		preparent->prawy = grandchild;
	}
	else
	{
		preparent->lewy = grandchild;
	}

	child->lewy = ptr->lewy;
	if (ptr == root)
	{
		root = child;
	}
	else if (parent->prawy == ptr)
	{
		parent->prawy = child;
	}
	else
	{
		parent->lewy = child;
	}
	return;
};
//dziala
void wyswietl_preorder(struct wezel * root)
{
	if (root == NULL)
	{
		return;
	}
	cout << " " << root->klucz;
	odwiedzone_pre++;
	wyswietl_preorder(root->lewy);
	wyswietl_preorder(root->prawy);
	//cout << "Odwiedzono " << odwiedzone_pre << " wezlow" << endl;

}
//dziala
void wyswietl_inorder(struct wezel * root)
{
	if (root == NULL)
	{
		return;
	}
	odwiedzone_in++;
	wyswietl_inorder(root->lewy);
	cout << " " << root->klucz;
	wyswietl_inorder(root->prawy);
}
//dziala
void wyswietl_postorder(struct wezel * root)
{
	if (root == NULL)
	{
		return;
	}
	odwiedzone_post++;
	wyswietl_postorder(root->lewy);
	wyswietl_postorder(root->prawy);
	cout << " " << root->klucz;
}

int main()
{
	wezel *root = new wezel;
	clock_t start, stop;
	double czas;
	srand(time(NULL));
	int ilosc, k1, k2, k3, k4;

	fstream plik;
	plik.open("inlab03.txt", ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			plik >> ilosc >> k1 >> k2 >> k3 >> k4;
		}
		plik.close();
	}
	else
	{
		cout << "Nie ma takiego pliku" << endl;
		getchar();
		return 0;
	}
	start = clock();

	puste_drzewo(root);
	usuwanie(root, k1);
	insert(root, k1);
	wstawianie_wielu(root, ilosc);
	cout << "\n \nWyswietlanie InOrder: \n\n";
	wyswietl_inorder(root);
	cout << "\n";
	cout << "\n \nWyswietlanie PreOrder: \n\n";
	wyswietl_preorder(root);
	insert(root, k2);
	cout << "\n \nWyswietlanie InOrder: \n\n";
	wyswietl_inorder(root);
	insert(root, k3);
	insert(root, k4);
	usuwanie(root, k1);
	cout << "\n \nWyswietlanie PreOrder: \n\n";
	wyswietl_preorder(root);
	szukanie(root, k1);
	usuwanie(root, k2);
	cout << "\n \nWyswietlanie InOrder: \n\n";
	wyswietl_inorder(root);
	usuwanie(root, k3);
	usuwanie(root, k4);

	stop = clock();

	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "\nCzas wykonania programu wynosi " << czas << endl;
	getchar();
	return 0;

}
