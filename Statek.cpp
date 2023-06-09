#include "Statek.h"
#include "Plansza.h"

#include <vector>
#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

void Statek::printInfo()
{
	cout << "Dlugosc: " << dlugosc << endl;
	cout << "Rotacja: " << rotation << endl;
	for (int i = 0; i < dlugosc; i++) {
		cout << x_cor[i] << " " << y_cor[i] << endl;
	}
}

Statek::Statek()
	:zatopiony(false)
{
	setSize();
	setRotation();
	setCoordinates();
}
Statek::Statek(int i)
	:zatopiony(false)
{
	dlugosc = Plansza::returnRandomNumber(2, 5);
	health = dlugosc;
	rotation = Plansza::returnRandomNumber(0, 1);
	setCoordinatesAI();

}
void Statek::setSize()
{
	cout << "Podaj dlugosc statku: " << endl;
	cin >> dlugosc;
	while (dlugosc < 2 || dlugosc > 5) {
		system("cls");
		cout << "Minimalna dlugosc: 2, maksymalna dlugosc: 5" << endl;
		cin >> dlugosc;
	}
	health = dlugosc;
}
void Statek::setRotation()
{
	int tmp;
	cout << "Podaj rotacje statku: " << endl;
	cout << "1. Pionowa" << endl;
	cout << "2. Pozioma" << endl;
	cin >> tmp;
	while (tmp < 1 || tmp > 2) {
		system("cls");
		cout << "Niepoprawny format odpowiedzi!" << endl;
		cout << "1. Pionowa" << endl;
		cout << "2. Pozioma" << endl;
		cin >> tmp;
	}
	rotation = tmp - 1;
}

void Statek::setCoordinates()
{
	int x = 0, y = 0;
	cout << "Dlugosc statku: " << dlugosc << endl;
	switch (rotation) {
	case 0:
		cout << "Rotacja: pionowa " << endl;
		cout << endl;
		cout << "Wybierz wspolrzedne poczatku statku (x,y)" << endl;
		cout << "Statek budowany jest w sposob: (x,y) -> (x,y+1) -> ..." << endl;
		cout << "Dostepny wybor wspolrzednych:" << endl;
		cout << "* x = <0;29>" << endl;
		cout << "* y = <0;" << 30 - dlugosc << ">" << endl;
		cout << "x: ";
		cin >> x;
		while (x < 0 || x > 29) {
			system("cls");
			cout << "Niepoprawna wspolrzedna x!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;" << 30 - dlugosc << ">" << endl;
			cout << "x: ";
			cin >> x;
		}
		cout << "y: ";
		cin >> y;
		while (y < 0 || y > 30 - dlugosc) {
			system("cls");
			cout << "Niepoprawna wspolrzedna y!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;" << 30 - dlugosc << ">" << endl;
			cout << "x: " << x << endl;
			cout << "y: ";
			cin >> y;
		}
		for (int i = 0; i < dlugosc; i++) {
			x_cor.push_back(x);
			y_cor.push_back(y);
			y++;
		}
		break;
	case 1:
		
		cout << "Rotacja: pozioma " << endl;
		cout << endl;
		cout << "Wybierz wspolrzedne poczatku statku (x,y)" << endl;
		cout << "Statek budowany jest w sposob: (x,y) -> (x+1,y+) -> ..." << endl;
		cout << "Dostepny wybor wspolrzednych:" << endl;
		cout << "* x = <0;" << 30 - dlugosc << ">" << endl;
		cout << "* y = <0;29>" << endl;
		cout << "x: ";
		cin >> x;
		while (x < 0 || x > 30 - dlugosc) {
			system("cls");
			cout << "Niepoprawna wspolrzedna x!" << endl;
			cout << "* x = <0;" << 30 - dlugosc << ">" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: ";
			cin >> x;
		}
		cout << "y: ";
		cin >> y;
		while (y < 0 || y > 29) {
			system("cls");
			cout << "Niepoprawna wspolrzedna y!" << endl;
			cout << "* x = <0;" << 30 - dlugosc << ">" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: " << x << endl;
			cout << "y: ";
			cin >> y;
		}
		for (int i = 0; i < dlugosc; i++) {
			x_cor.push_back(x);
			y_cor.push_back(y);
			x++;
		}
		break;
	}
}
void Statek::setCoordinatesAI()
{
	int x = 0, y = 0;
	switch (rotation) {
	case 0:
		x = Plansza::returnRandomNumber(0, 29);
		y = Plansza::returnRandomNumber(0, 30 - dlugosc);
		for (int i = 0; i < dlugosc; i++) {
			x_cor.push_back(x);
			y_cor.push_back(y);
			y++;
		}
		break;
	case 1:
		x = Plansza::returnRandomNumber(0, 30 - dlugosc);
		y = Plansza::returnRandomNumber(0, 29);
		for (int i = 0; i < dlugosc; i++) {
			x_cor.push_back(x);
			y_cor.push_back(y);
			x++;
		}
		break;
	}
}

