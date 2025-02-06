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
		s << "C " << ancrage.x << " " << ancrage.y << " " << rayon << endl;
}

int Cercle::getRayon()
{
	return rayon;
}

void Cercle::setRayon(int x)
{
	rayon = x;
}

ostream& operator<<(ostream& flot, Cercle& C)
{
	flot << "C " << C.getAncrage().x << " " << C.getAncrage().y << " " << C.getRayon()<< endl;
	return flot;
}