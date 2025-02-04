#pragma once
#include "rectangle.h"
#include <iostream>
using namespace std;

class Carre : public Rectangle
{
	public:
		Carre(int c = 1, int x = 0, int y = 0);
		~Carre();
		double aire();
		void afficher(ostream &s);
		int getCote();
		void setCote(int x);
};

