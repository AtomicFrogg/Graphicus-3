#pragma once
#include "forme.h"
#include <iostream>
using namespace std;


class Rectangle : public Forme
{
	public:
		Rectangle(int h = 1, int l = 1, int x1 = 0, int y1 = 0);
		virtual ~Rectangle();
		virtual double aire();
		virtual void afficher(ostream & s);
		int getHauteur();
		int getLongueur();
		void setHauteur(int x);
		void setLongueur(int x);
		
	private:
		int hauteur;

	protected:
		int longueur;
};


