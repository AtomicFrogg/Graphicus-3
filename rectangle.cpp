#include "rectangle.h"

Rectangle::Rectangle(int h, int l,int x1,int y1):Forme(x1, y1),hauteur(h),longueur(l)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::setHauteur(int x)
{
	if(x>0)
	{
		hauteur = x;
	}
	else
	{
		hauteur = -x;
	}
}

void Rectangle::setLongueur(int x)
{
	if(x>0)
	{
		longueur = x;
	}
	else
	{
		longueur = -x;
	}
}

int Rectangle::getHauteur()
{
	return hauteur;
}

int Rectangle::getLongueur()
{
	return longueur;
}

double Rectangle::aire()
{
	return (hauteur * longueur);
}

void Rectangle::afficher(ostream &s)
{
	s << "R " << ancrage.x << " " << ancrage.y << " " << longueur << " " << hauteur << endl;
}


