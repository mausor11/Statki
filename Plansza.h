#pragma once
#include "Statek.h"
#include <vector>
class Plansza
{
private:
	bool isStatekOnStatek(Statek);
	bool isStatekNearStatek(Statek);
public:
	Plansza();
	char bitmap[30][30];
	char plansza[30][30];
	std::vector<Statek> statkiGracza;
	void pokaKordy();
	void printPlansza(int gracz);
	static void printPlanszaWin(int gracz);
	void printPlanszaPudlo();
	void printPlanszaTrafiony();
	void printPlanszaZatopiony();
	void printHpStatki();
	void insertStatek(Statek,int);
	void insertStatekAI(Statek, int);
	int ifHit(int, int);
	void insertHit(int, int, char);
	static int returnRandomNumber(int minimum, int maksimum);
	
};

