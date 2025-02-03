#ifndef VECTEUR_H
#define CANEVAS_H

#include <iostream>
#include "couche.h"

using namespace std;

class Vecteur{

public :
	Vecteur();
	~Vecteur();
	int getCapacite();
	int getTaille();
	void doublerCapacite();
	void viderVecteur();
	bool estVide();
	bool ajouterElement(Couche *objet);
	void afficher(ostream &s);
	Couche* retirerElement(int index);
	Couche* getElement(int index);
	

private:
	int capacite;
	int taille;
	Couche* *elements;
};


#endif
