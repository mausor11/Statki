#include "Gra.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void Gra::strzal(int gracz)
{
	int x, y;
	switch (gracz) {
	case 1:
		system("cls");
		planszaAgame.printPlansza(gracz);
		planszaA.printHpStatki();
		cout << "Podaj koordynaty strzalu: " << endl;
		cout << "x: ";
		cin >> x;
		while (x < 0 || x > 30) {
			system("cls");
			planszaAgame.printPlansza(gracz);
			planszaA.printHpStatki();
			cout << "Niepoprawna wspolrzedna x!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: ";
			cin >> x;
		}
		cout << "y: ";
		cin >> y;
		while (y < 0 || y > 30) {
			system("cls");
			planszaAgame.printPlansza(gracz);
			planszaA.printHpStatki();
			cout << "Niepoprawna wspolrzedna y!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: " << x << endl;
			cout << "y: ";
			cin >> y;
		}
		if (planszaB.ifHit(x, y) == 0) {
			planszaAgame.insertHit(x, y, 'o');
			planszaAgame.printPlanszaPudlo();
			planszaA.printHpStatki();
			Sleep(2000);
		}
		//todo:
			// - dodac bitmape z samymi indexami statkow -> trafiony -1 health, gdy 0 to zatopiony
		else {
			system("cls");
			planszaAgame.insertHit(x, y, 'X');
			int index = planszaB.bitmap[y][x] - '0';
			planszaB.statkiGracza[index].health--;
			if (checkIfNotZatopiony(planszaB.statkiGracza[index])) {
				if (ifZatopiony(1, index) == 1) {
					system("cls");
					Plansza::printPlanszaWin(1);
					exit(0);
				}
				planszaAgame.printPlanszaZatopiony();
				planszaA.printHpStatki();
			}
			else {
				planszaAgame.printPlanszaTrafiony();
				planszaA.printHpStatki();
			}
			Sleep(2000);
		}
		break;
	case 2:
		system("cls");
		planszaBgame.printPlansza(gracz);
		planszaB.printHpStatki();
		cout << "Podaj koordynaty strzalu: " << endl;
		cout << "x: ";
		cin >> x;
		while (x < 0 || x > 30) {
			system("cls");
			planszaBgame.printPlansza(gracz);
			planszaB.printHpStatki();
			cout << "Niepoprawna wspolrzedna x!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: ";
			cin >> x;
		}
		cout << "y: ";
		cin >> y;
		while (y < 0 || y > 30) {
			system("cls");
			planszaBgame.printPlansza(gracz);
			planszaB.printHpStatki();
			cout << "Niepoprawna wspolrzedna y!" << endl;
			cout << "* x = <0;29>" << endl;
			cout << "* y = <0;29>" << endl;
			cout << "x: " << x << endl;
			cout << "y: ";
			cin >> y;
		}
		if (planszaA.ifHit(x, y) == 0) {
			planszaBgame.insertHit(x, y, 'o');
			planszaBgame.printPlanszaPudlo();
			planszaB.printHpStatki();
			Sleep(2000);
		}
		else {
			system("cls");
			planszaBgame.insertHit(x, y, 'X');
			int index = planszaA.bitmap[y][x] - '0';
			planszaA.statkiGracza[index].health--;
			if (checkIfNotZatopiony(planszaA.statkiGracza[index])) {
				if (ifZatopiony(2, index) == 1) {
					system("cls");
					Plansza::printPlanszaWin(1);
					exit(0);
				}
				planszaBgame.printPlanszaZatopiony();
				planszaB.printHpStatki();
			}
			else {
				planszaBgame.printPlanszaTrafiony();
				planszaB.printHpStatki();
			}
			Sleep(2000);
		}

		break;

	}

}

void Gra::strzalAI(int gracz) {
	int x, y;
	switch (gracz) {
	case 1:
		system("cls");
		planszaAgame.printPlansza(gracz);
		planszaA.printHpStatki();
		Sleep(3000);
		x = Plansza::returnRandomNumber(0, 29);
		y = Plansza::returnRandomNumber(0, 29);
		
		if (planszaB.ifHit(x, y) == 0) {
			planszaAgame.insertHit(x, y, 'o');
			planszaAgame.printPlanszaPudlo();
			planszaA.printHpStatki();
			Sleep(2000);
		}
		else {
			system("cls");
			planszaAgame.insertHit(x, y, 'X');
			int index = planszaB.bitmap[y][x] - '0';
			planszaB.statkiGracza[index].health--;
			if (checkIfNotZatopiony(planszaB.statkiGracza[index])) {
				if (ifZatopiony(1, index) == 1) {
					system("cls");
					Plansza::printPlanszaWin(1);
					exit(0);
				}
				planszaAgame.printPlanszaZatopiony();
				planszaA.printHpStatki();
			}
			else {
				planszaAgame.printPlanszaTrafiony();
				planszaA.printHpStatki();
			}
			Sleep(2000);
		}
		break;
	case 2:
		system("cls");
		planszaBgame.printPlansza(gracz);
		planszaB.printHpStatki();
		Sleep(3000);
		x = Plansza::returnRandomNumber(0, 29);
		y = Plansza::returnRandomNumber(0, 29);

		if (planszaA.ifHit(x, y) == 0) {
			planszaBgame.insertHit(x, y, 'o');
			planszaBgame.printPlanszaPudlo();
			planszaB.printHpStatki();
			Sleep(2000);
		}
		else {
			system("cls");
			planszaBgame.insertHit(x, y, 'X');
			int index = planszaA.bitmap[y][x] - '0';
			planszaA.statkiGracza[index].health--;
			if (checkIfNotZatopiony(planszaA.statkiGracza[index])) {
				if (ifZatopiony(2, index) == 1) {
					system("cls");
					Plansza::printPlanszaWin(1);
					exit(0);
				}
				planszaBgame.printPlanszaZatopiony();
				planszaB.printHpStatki();
			}
			else {
				planszaBgame.printPlanszaTrafiony();
				planszaB.printHpStatki();
			}
			Sleep(2000);
		}

		break;

	}

}

void Gra::officialGamePvP()
{
	int gracz = 1;
	while (true) {
		strzal(gracz);
		gracz++;
		strzal(gracz);
		gracz--;
	}
}
void Gra::officialGamePvC()
{
	int gracz = 1;
	while (true) {
		strzal(gracz);
		gracz++;
		strzalAI(gracz);
		gracz--;
	}
}
void Gra::officialGameCvC()
{
	int gracz = 1;
	while (true) {
		strzalAI(gracz);
		gracz++;
		strzalAI(gracz);
		gracz--;
	}
}

bool Gra::checkIfNotZatopiony(Statek statek)
{
	if (statek.health == 0) {
		return true;
	}
	else {
		return false;
	}
}
int Gra::ifZatopiony(int gracz, int index)
{
	switch (gracz) {
	case 1:
		for (int i = 0; i < planszaB.statkiGracza[index].dlugosc; i++) {
			planszaAgame.plansza[planszaB.statkiGracza[index].y_cor[i]][planszaB.statkiGracza[index].x_cor[i]] = '0' + planszaB.statkiGracza[index].dlugosc;
		}
		planszaB.statkiGracza[index].zatopiony = true;
		ileZatopionychB++;
		if (planszaB.statkiGracza.size() == ileZatopionychB) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case 2:
		for (int i = 0; i < planszaA.statkiGracza[index].dlugosc; i++) {
			planszaBgame.plansza[planszaA.statkiGracza[index].y_cor[i]][planszaA.statkiGracza[index].x_cor[i]] = '0' + planszaA.statkiGracza[index].dlugosc;
		}
		planszaA.statkiGracza[index].zatopiony = true;
		ileZatopionychA++;
		if (planszaA.statkiGracza.size() == ileZatopionychA) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	}
	return 0;
}
Gra::Gra(Plansza planszaA, Plansza planszaB, int ileStatkow)
	:planszaA(planszaA)
	,planszaB(planszaB)
	,ileStatkow(ileStatkow)
{}

void Gra::printAllInformation()
{
	cout << "Ile statkow: " << ileStatkow << endl;
	cout << "A" << endl;
	for (int i = 0; i < ileStatkow; i++) {
		cout << "Statek " << i + 1 << endl;
		planszaA.statkiGracza[i].printInfo();
	}
	cout << "B" << endl;
	for (int i = 0; i < ileStatkow; i++) {
		cout << "Statek " << i + 1 << endl;
		planszaB.statkiGracza[i].printInfo();
	}
}
