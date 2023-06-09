#pragma once
#include "Plansza.h"

class Gra
{
private:
	Plansza planszaA;
	Plansza planszaB;
	Plansza planszaAgame;
	Plansza planszaBgame;
	int ileStatkow;
	int ileZatopionychA = 0;
	int ileZatopionychB = 0;
	bool checkIfNotZatopiony(Statek);
	int ifZatopiony(int,int);
	void strzal(int gracz);
	void strzalAI(int gracz);

public:
	Gra(Plansza, Plansza, int ileStatkow);
	void printAllInformation();
	void officialGamePvP();
	void officialGamePvC();
	void officialGameCvC();

};

