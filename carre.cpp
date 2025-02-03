#include "carre.h"

Carre::Carre(int c, int x, int y):Rectangle(c,c,x,y)
{
}

Carre::~Carre()
{
}

double Carre::aire()
{
	return (longueur * longueur);
}

void Carre::afficher(ostream &s)
{
		s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << longueur << ", aire=" << aire() << ")" << endl;
}

int Carre::getCote()
{
	return longueur;
}

void Carre::setCote(int x)
{
	longueur = x;
}
