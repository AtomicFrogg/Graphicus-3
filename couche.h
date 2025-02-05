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
#pragma once

#include "forme.h"
#include "vecteur.h"

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
		Forme* getForme2();
		double aireTotale();
		bool translaterCouche(int deltaX, int deltaY);
		int getTaille();

		/// Navigation
		void formePremiere();
		void formePrecedente();
		void formeSuivante();
		void formeDerniere();
		int getPosition();
		

	private:
		Vecteur<Forme*> formes;
		int etat;
		//int taille;
};


template<class T>
void operator>>(istream &flot, Vecteur<T>& vector)
{
	char item;
	flot >> item;
	while(item != EOF)
	{
		
		switch (item)
		{
		case 'L':
			Couche * nouvelleCouche = new Couche();
			char etat;
			flot >> etat;
			switch (etat)
			{
			case 'a':
				nouvelleCouche->setEtat(ACTIVE);
				break;

			case 'i':
				nouvelleCouche->setEtat(INITIALISE);
				break;

			case 'x':
				nouvelleCouche->setEtat(INACTIVE);
				break;

			default:
				cerr << "Erreur de lecture de l'état de la couche (CODE 18)";
				
				break;
			}
			vector->ajouterElement(nouvelleCouche);
			break;

		case 'R':
			int x, y, l, h;
			flot >> x >> y >> l >> h;
			Forme** nouveauRectangle = new Rectangle(l, h, x, y);
			vector.ajouterElement(nouveauRectangle);
			break;

		case 'K':
			int x, y, c;
			flot >> x >> y >> c;
			Forme** nouveauCarre = new Carre(c, x, y);
			vector.ajouterElement(nouveauCarre);
			break;

		case 'C':
			int x, y, r;
			flot >> x >> y >> r;
			Forme** nouveauCercle = new Cercle(r, x, y);
			vector.ajouterElement(nouveauCercle);
			break;

		default:
			cerr << "Erreur de lecture de l'input du vecteur (CODE 18)";
			break;
		}
	}
}

template<class T>
void operator<<(ostream& flot, Vecteur<T>& item)
{
	for (int i = 0; i < item->getTaille(); i++)
	{
		item[i]->afficher(flot);
	}
}


