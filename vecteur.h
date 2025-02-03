#ifndef VECTEUR_H
#define CANEVAS_H

#include <iostream>
#include "couche.h"

using namespace std;
template  <typename T>
class Vecteur{

public :
	Vecteur();
	~Vecteur();
	int getCapacite();
	int getTaille();
	void doublerCapacite();
	void viderVecteur();
	bool estVide();
	bool ajouterElement(T objet);
	void afficher(ostream &s);
	T retirerElement(int index);
	T getElement(int index);
	

private:
	int capacite;
	int taille;
	T *elements;
};


#endif
