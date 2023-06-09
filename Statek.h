#pragma once
#include <vector>

class Statek
{
private:
	void setSize();
	void setRotation();
	void setCoordinates();
	void setCoordinatesAI();
public:
	int dlugosc;
	bool zatopiony;
	int health;
	int rotation;	//0 - pionowo, 1 - poziomo
	std::vector<int> x_cor;
	std::vector<int> y_cor;
	void printInfo();
	Statek();
	Statek(int i);

};

