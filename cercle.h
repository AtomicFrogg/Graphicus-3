#ifndef CERCLE_H
#define CERCLE_H
#include "forme.h"
#include <iostream>
using namespace std;
double const PI = 3.141592653589;

class Cercle : public Forme
{
	public:
		Cercle(int r = 1, int x = 0, int y = 0);
		~Cercle();
		double aire();
		void afficher(ostream & s);
		int getRayon();
		void setRayon(int x);
		
	private:
		int rayon;
};

#endif
