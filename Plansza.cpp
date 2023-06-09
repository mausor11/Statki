#include "Plansza.h"

#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

Plansza::Plansza() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			plansza[i][j] = '*';
			bitmap[i][j] = '*';
		}
	}
}
void Plansza::pokaKordy()
{
	for (vector<Statek>::iterator itr = statkiGracza.begin(); itr != statkiGracza.end(); itr++) {
		isStatekNearStatek(*itr);
	}
}
void Plansza::printPlansza(int gracz) {
	system("cls");
	cout << "************************* GRACZ "<< gracz <<" **************************" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << plansza[i][j] << "|";
		}
		cout << endl;
	}
	cout << "************************* GRACZ " << gracz << " **************************" << endl;
}
void Plansza::printPlanszaWin(int gracz) {
	system("cls");
	switch (gracz) {
	case 1:
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************              WYGRAL            **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************              GRACZ             **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************             PIERWSZY           **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		exit(0);
		break;
	case 2:
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************              WYGRAL            **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************              GRACZ             **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************              DRUGI             **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "**************                                **************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		cout << "************************************************************" << endl;
		exit(0);
		break;

	}
}

void Plansza::printPlanszaPudlo()
{
	system("cls");
	cout << "************************** PUDLO! **************************" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << plansza[i][j] << "|";
		}
		cout << endl;
	}
	cout << "************************** PUDLO! **************************" << endl;
}

void Plansza::printPlanszaTrafiony()
{
	system("cls");
	cout << "************************ TRAFIONY! *************************" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << plansza[i][j] << "|";
		}
		cout << endl;
	}
	cout << "************************ TRAFIONY! *************************" << endl;
}

void Plansza::printPlanszaZatopiony()
{
	system("cls");
	cout << "************************ ZATOPIONY! ************************" << endl;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << plansza[i][j] << "|";
		}
		cout << endl;
	}
	cout << "************************ ZATOPIONY! ************************" << endl;
}

void Plansza::printHpStatki()
{
	cout << "Twoje statki: " << endl;
	for (int i = 0; i < statkiGracza.size(); i++) {
		if (statkiGracza[i].zatopiony == false) {
			cout << "Statek " << i + 1 << ", HP: " << statkiGracza[i].health << "/" << statkiGracza[i].dlugosc << endl;

		}
		else {
			cout << "Statek " << i + 1 << ", zatopiony" << endl;
		}
	}
}

bool Plansza::isStatekOnStatek(Statek statek)
{
	for (int i = 0; i < statek.dlugosc; i++) {
		if (plansza[statek.y_cor[i]][statek.x_cor[i]] == '2' || plansza[statek.y_cor[i]][statek.x_cor[i]] == '3' || plansza[statek.y_cor[i]][statek.x_cor[i]] == '3' || plansza[statek.y_cor[i]][statek.x_cor[i]] == '4' || plansza[statek.y_cor[i]][statek.x_cor[i]] == '5') {
			return true;
		}
	}
	return false;
}
//do naprawy
bool Plansza::isStatekNearStatek(Statek statek)
{
	int size = statek.dlugosc;
	int rotation = statek.rotation;
	switch (rotation) {
	case 0: //pionowo
		if (statek.x_cor[0] > 0 && statek.x_cor[0] < 30 && statek.y_cor[0] > 0 && statek.y_cor[0] < 30) { //default
			int xL = statek.x_cor[0] - 1;
			int y = statek.y_cor[0] - 1;
			int xP = statek.x_cor[0] + 1;
			if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
				return true;
			}
			y++;
			for (int i = 0; i < statek.dlugosc; i++) {
				if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
					return true;
				}
				y++;
			}
			if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
				return true;
			}
			
		}
		else if (statek.x_cor[0] == 0) { //lewa strona
			if (statek.y_cor[0] == 0) { //lewy-gorny rog
				int xP = statek.x_cor[0] + 1;
				int y = statek.y_cor[0];
				
				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xP] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xP] != '*') {
					return true;
				}
			}
			else if (statek.y_cor[0] == 29) { //lewy-dolny rog
				int xP = statek.x_cor[0] + 1;
				int y = statek.y_cor[0] - statek.dlugosc - 1;
				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xP] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xP] != '*') {
					return true;
				}
			}
			else { //default max lewo
				int xP = statek.x_cor[0] + 1;
				int y = statek.y_cor[0] - 1;

				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xP] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xP] != '*') {
					return true;
				}
			}
		}
		else if (statek.x_cor[0] == 29) { //prawa strona
			if (statek.y_cor[0] == 0) { //prawy-gorny rog
				int xL = statek.x_cor[0] - 1;
				int y = statek.y_cor[0];

				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xL] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xL] != '*') {
					return true;
				}
			}
			else if (statek.y_cor[0] == 29) { //prawy-dolny rog
				int xL = statek.x_cor[0] - 1;
				int y = statek.y_cor[0] - statek.dlugosc - 1;
				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xL] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xL] != '*') {
					return true;
				}
			}
			else { //default max prawo
				int xL = statek.x_cor[0] - 1;
				int y = statek.y_cor[0] - 1;

				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[y][xL] != '*') {
						return true;
					}
					y++;
				}
				if (plansza[y][xL] != '*') {
					return true;
				}
			}
		}
		else if (statek.y_cor[0] == 0) { //gora strona
			int xL = statek.x_cor[0] - 1;
			int y = statek.y_cor[0];
			int xP = statek.x_cor[0] + 1;
			for (int i = 0; i < statek.dlugosc; i++) {
				if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
					return true;
				}
				y++;
			}
			if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
				return true;
			}
		}
		else if (statek.y_cor[0] == 29) {
			int xL = statek.x_cor[0] - 1;
			int y = statek.y_cor[0] - statek.dlugosc - 1;
			int xP = statek.x_cor[0] + 1;
			for (int i = 0; i < statek.dlugosc; i++) {
				if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
					return true;
				}
				y++;
			}
			if (plansza[y][xL] != '*' || plansza[y][xP] != '*') {
				return true;
			}
		}
		break;
	case 1: //poziomo
		if (statek.x_cor[0] > 0 && statek.x_cor[0] < 30 && statek.y_cor[0] > 0 && statek.y_cor[0] < 30) { //default
			int yL = statek.y_cor[0] - 1;
			int yP = statek.y_cor[0] + 1;
			int x = statek.x_cor[0] - 1;
			if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
				return true;
			}
			x++;
			for (int i = 0; i < statek.dlugosc; i++) {
				if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
					return true;
				}
				x++;
			}
			if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
				return true;
			}

		}
		else if (statek.x_cor[0] == 0) { //lewa strona
				int yL = statek.y_cor[0] - 1;
				int yP = statek.y_cor[0] - 1;
				int x = statek.x_cor[0];

				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
						return true;
					}
					x++;
				}
				if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
					return true;
				}
		}
		else if (statek.x_cor[0] == 29) { //prawa strona
				int yL = statek.y_cor[0] - 1;
				int yP = statek.y_cor[0] + 1;
				int x = statek.x_cor[0] - statek.dlugosc - 1;
				if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
					return true;
				}
				x++;
				for (int i = 0; i < statek.dlugosc; i++) {
					if (plansza[yL][x] != '*' || plansza[yP][x] != '*') {
						return true;
					}
					x++;
				}
				
		}
		
}
	return false;
}


void Plansza::insertStatek(Statek statek, int index)
{
	system("cls");
	if (isStatekOnStatek(statek)) {
		cout << "Statek nachodzi na inny statek!" << endl;
		Statek statek_poprawa;
		while (isStatekOnStatek(statek_poprawa)) {
			cout << "Statek nachodzi na inny statek!" << endl;
			Statek statek_poprawa;
		}
		statkiGracza.push_back(statek_poprawa);
		for (int i = 0; i < statek_poprawa.dlugosc; i++) {
			plansza[statek_poprawa.y_cor[i]][statek_poprawa.x_cor[i]] = '0' + statek_poprawa.dlugosc;
		}
	}
	else if (isStatekNearStatek(statek)) {
		cout << "Odleglosc miedzy statkami conajmniej 1 kratka!" << endl;
		Statek statek_poprawa;
		while (isStatekNearStatek(statek_poprawa)) {
			cout << "Odleglosc miedzy statkami conajmniej 1 kratka!" << endl;
			Statek statek_poprawa;
		}
		statkiGracza.push_back(statek_poprawa);
		for (int i = 0; i < statek_poprawa.dlugosc; i++) {
			plansza[statek_poprawa.y_cor[i]][statek_poprawa.x_cor[i]] = '0' + statek_poprawa.dlugosc;
		}
	}
	else {
		statkiGracza.push_back(statek);
		for (int i = 0; i < statek.dlugosc; i++) {
			plansza[statek.y_cor[i]][statek.x_cor[i]] = '0' + statek.dlugosc;
			bitmap[statek.y_cor[i]][statek.x_cor[i]] = '0' + index;
		}
	}
	
}
void Plansza::insertStatekAI(Statek statek, int index) {
	if (isStatekOnStatek(statek)) {
		Statek statek_poprawa(1);
		while (isStatekOnStatek(statek_poprawa)) {
			Statek statek_poprawa(1);
		}
		statkiGracza.push_back(statek_poprawa);
		for (int i = 0; i < statek_poprawa.dlugosc; i++) {
			plansza[statek_poprawa.y_cor[i]][statek_poprawa.x_cor[i]] = '0' + statek_poprawa.dlugosc;
		}
	}
	else if (isStatekNearStatek(statek)) {
		Statek statek_poprawa(1);
		while (isStatekNearStatek(statek_poprawa)) {
			Statek statek_poprawa(1);
		}
		statkiGracza.push_back(statek_poprawa);
		for (int i = 0; i < statek_poprawa.dlugosc; i++) {
			plansza[statek_poprawa.y_cor[i]][statek_poprawa.x_cor[i]] = '0' + statek_poprawa.dlugosc;
		}
	}
	else {
		statkiGracza.push_back(statek);
		for (int i = 0; i < statek.dlugosc; i++) {
			plansza[statek.y_cor[i]][statek.x_cor[i]] = '0' + statek.dlugosc;
			bitmap[statek.y_cor[i]][statek.x_cor[i]] = '0' + index;
		}
	}
}

int Plansza::ifHit(int x, int y)
{
	if (plansza[y][x] == '*') {
		return 0;
	}
	else if (plansza[y][x] == 'X') {
		return -1;
	}
	else {
		return 1;
	}
}

void Plansza::insertHit(int x, int y, char sign)
{
	plansza[y][x] = sign;
}

int Plansza::returnRandomNumber(int minimum, int maksimum) {
	return rand() % (maksimum - minimum + 1) + minimum;
}

