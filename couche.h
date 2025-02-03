/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "forme.h"

using namespace std;

const int MAX_FORMES = 5;

//Constantes pour les états de la couche
const int INITIALISE = 0;
const int ACTIVE = 1;
const int INACTIVE = 2;
const bool SUCCES = 1;
const bool FAIL = 0;
	
// À completer

class Couche
{
	public:  	
		// Methodes a ajouter
		Couche();
		~Couche();
		void afficher(ostream &s);
		void setEtat(int nouvelEtat);
		int getEtat();
		bool reinitialiserCouche();
		bool ajouterForme(Forme* ptr);
		Forme* retirerForme(int index);
		Forme* getForme(int index);   
		double aireTotale();
		bool translaterCouche(int deltaX, int deltaY);
		int getTaille();

	private:
		Forme* *formes;
		int etat;
		int taille;
};

#endif
