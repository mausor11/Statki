#include "Plansza.h"
#include "Statek.h"

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Gra.h"

using namespace std;
int menuScreen();
void zasadyScreen();
void instrukcjaScreen();
int trybyGrySreen();
int howMany();
Plansza planszaA;
Plansza planszaB;

int main()
{
	int ileStatkow = 0;
	int wybor = menuScreen();
	int tryb = 0;
	switch (wybor) 
	{
	case -1:
		system("cls");
		cout << "Do zobaczenia!" << endl;
		return 0;
	case 1:
		tryb = trybyGrySreen();
		ileStatkow = howMany();
		break;
	default:
		break;
	}
	if (tryb == 1) {
		system("cls");
		int gracz = 1;
		planszaA.printPlansza(gracz);
		for (int i = 0; i < ileStatkow; i++) {
			Statek s1;
			planszaA.insertStatek(s1, i);
			planszaA.printPlansza(gracz);
		}
		Sleep(1000);
		system("cls");
		gracz++;
		planszaB.printPlansza(gracz);
		for (int i = 0; i < ileStatkow; i++) {
			Statek s1;
			planszaB.insertStatek(s1, i);
			planszaB.printPlansza(gracz);
		}
		Sleep(1000);
		Gra gra(planszaA, planszaB, ileStatkow);
		gra.officialGamePvP();
		return 0;
	}
	else if (tryb == 2) {
		system("cls");
		int gracz = 1;
		planszaA.printPlansza(gracz);
		for (int i = 0; i < ileStatkow; i++) {
			Statek s1;
			planszaA.insertStatek(s1, i);
			planszaA.printPlansza(gracz);
		}
		Sleep(1000);
		system("cls");
		gracz++;
		for (int i = 0; i < ileStatkow; i++) {

			Statek s1(1);
			planszaB.insertStatekAI(s1, i);
		}
		Gra gra(planszaA, planszaB, ileStatkow);
		gra.officialGamePvC();
		return 0;
	}
	else if (tryb == 3) {
		system("cls");
		int gracz = 1;
		planszaA.printPlansza(gracz);
		for (int i = 0; i < ileStatkow; i++) {
			Statek s1(1);
			planszaA.insertStatekAI(s1, i);
		}
		planszaA.printPlansza(gracz);
		Sleep(2000);
		system("cls");
		gracz++;
		for (int i = 0; i < ileStatkow; i++) {

			Statek s1(1);
			planszaB.insertStatekAI(s1, i);
		}
		planszaB.printPlansza(gracz);
		Sleep(2000);
		Gra gra(planszaA, planszaB, ileStatkow);
		gra.officialGameCvC();
		return 0;
	}
	else {
		system("cls");
		return 0;
	}
	
	
}

int menuScreen() {
	int wybor;
	system("cls");
	cout << "*****************************************" << endl;
	cout << "    .--. .-----. .--. .-----..-..-..-.   " << endl;
	cout << "   : .--'`-. .-': .; :`-. .-': :' ;: :   " << endl;
	cout << "   `. `.   : :  :    :  : :  :   ' : :   " << endl;
	cout << "    _`, :  : :  : :: :  : :  : :.`.: :   " << endl;
	cout << "   `.__.'  :_;  :_;:_;  :_;  :_;:_;:_;   " << endl;
	cout << "*****************************************" << endl;
	cout << "               1. Graj					  " << endl;
	cout << "               2. Zasady" << endl;
	cout << "               3. Instrukcja" << endl;
	cout << "               4. Wyjscie" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	cout << "Wybierz opcje: ";
	cin >> wybor;
	if (wybor == 2) {
		zasadyScreen();
	}
	else if (wybor == 3) {
		instrukcjaScreen();
	}
	else if (wybor == 4) {
		return -1;
	}
	else if (wybor == 1) {
		return 1;
	}
	else {
		menuScreen();
	}
}

int trybyGrySreen() {
	int wybor;
	system("cls");
	cout << "*****************************************" << endl;
	cout << "    .--. .-----. .--. .-----..-..-..-.   " << endl;
	cout << "   : .--'`-. .-': .; :`-. .-': :' ;: :   " << endl;
	cout << "   `. `.   : :  :    :  : :  :   ' : :   " << endl;
	cout << "    _`, :  : :  : :: :  : :  : :.`.: :   " << endl;
	cout << "   `.__.'  :_;  :_;:_;  :_;  :_;:_;:_;   " << endl;
	cout << "*****************************************" << endl;
	cout << "               1. PvP					  " << endl;
	cout << "               2. PvC" << endl;
	cout << "               3. CvC" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	cout << "Wybierz opcje: ";
	cin >> wybor;
	return wybor;
}

void zasadyScreen() {
	int klawisz;
	system("cls");
	cout << "**************** ZASADY *****************" << endl;
	cout << "* Gra przebiega naprzemiennie" << endl;
	cout << "* Zatopienie statku ma miejsce," << endl;
	cout << "  gdy wszystkie numery symbolujace" << endl;
	cout << "  okret zostana \"trafione\"" << endl;
	cout << "* \"Zatopiony\" oznacza trafienie okretu" << endl;
	cout << "* \"Zatopienie\" oznacza zatopienie okretu" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	cout << "Wcisnij ENTER, aby powrocic do menu..." << endl;
	klawisz = _getch();
	if (klawisz == 13) {
		menuScreen();
	}
}

void instrukcjaScreen() {
	int klawisz;
	system("cls");
	cout << "****************** INSTRUKCJA ******************" << endl;
	cout << "                  Mapa statkow" << endl;
	cout << " * rozmiar: 30x30" << endl;
	cout << " * indeksowana od 0" << endl;
	cout << " * zakres indeksow mapy: x<0;29> i y<0;29>" << endl;
	cout << " * koordynaty punktu maja postac A(x,y)" << endl;
	cout << "    * x - zmienna poziomowa" << endl;
	cout << "    * y - zmienna pionowa" << endl;
	cout << "************************************************" << endl;
	cout << "                     Statki" << endl;
	cout << " * statki dziela sie na dwa typy: " << endl;
	cout << "    * pionowe" << endl;
	cout << "	   2    3    4    5" << endl;
	cout << "	   2    3    4    5" << endl;
	cout << "	        3    4    5" << endl;
	cout << "	             4    5" << endl;
	cout << "	                  5" << endl;
	cout << "    * poziomowe" << endl;
	cout << "      22" << endl;
	cout << "      333" << endl;
	cout << "      4444" << endl;
	cout << "      55555" << endl;
	cout << " * punkt poczatkowy statku: " << endl;
	cout << "    * dla poziomego - punkt najbardziej na lewo" << endl;
	cout << "    * dla pionowego - punkt najbardziej na gorze" << endl;
	cout << " * indeksowanie statkow: " << endl;
	cout << "    * poziomy - (x,y) -> (x+1,y) -> ..." << endl;
	cout << "    * pionowy - (x,y) -> (x,y+1) -> ..." << endl;
	cout << "************************************************" << endl;
	cout << endl;
	cout << "Wcisnij ENTER, aby powrocic do menu..." << endl;
	klawisz = _getch();
	if (klawisz == 13) {
		menuScreen();
	}
}
int howMany() {
	system("cls");
	int ile;
	cout << "*****************************************" << endl;
	cout << "    .--. .-----. .--. .-----..-..-..-.   " << endl;
	cout << "   : .--'`-. .-': .; :`-. .-': :' ;: :   " << endl;
	cout << "   `. `.   : :  :    :  : :  :   ' : :   " << endl;
	cout << "    _`, :  : :  : :: :  : :  : :.`.: :   " << endl;
	cout << "   `.__.'  :_;  :_;:_;  :_;  :_;:_;:_;   " << endl;
	cout << "*****************************************" << endl;
	cout << "Podaj ilosc statkow: " << endl;
	cin >> ile;
	while (ile < 1 || ile > 6) {
		cout << "Minimalnie 1 statek, maksymalnie 6 statkow!" << endl;
		cin >> ile;
	}
	return ile;
}