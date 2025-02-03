#include "cercle.h"

Cercle::Cercle(int r, int x, int y): Forme(x,y),rayon(r)
{
}

Cercle::~Cercle()
{
}

double Cercle::aire()
{
	return (PI * rayon * rayon);
}

void Cercle::afficher(ostream &s)
{
		s << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y << ", r=" << rayon << ", aire=" << aire() << ")" << endl;
}

int Cercle::getRayon()
{
	return rayon;
}

void Cercle::setRayon(int x)
{
	rayon = x;
}
