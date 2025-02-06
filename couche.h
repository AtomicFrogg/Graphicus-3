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
		template<class T>
		friend istream& operator>>(istream& flot, Vecteur<T>& vector);
		template<class T>
		friend ostream& operator<<(ostream& flot, Vecteur<T>& item);
	private:
		Vecteur<Forme*> formes;
		int etat;
		//int taille;
};

//
//template<class T>
//istream& operator>>(istream& flot, Vecteur<T>& vector)
//{
//	char item;
//	flot >> item;
//	while (item != EOF)
//	{
//		int i = -1;
//		switch (item)
//		{
//		case 'L':
//			Couche * nouvelleCouche = new Couche();
//			char etat;
//			flot >> etat;
//			switch (etat)
//				i++;
//			{
//			case 'a':
//				nouvelleCouche->setEtat(ACTIVE);
//				break;
//
//			case 'i':
//				nouvelleCouche->setEtat(INITIALISE);
//				break;
//
//			case 'x':
//				nouvelleCouche->setEtat(INACTIVE);
//				break;
//
//			default:
//				cerr << "Erreur de lecture de l'état de la couche (CODE 18)";
//
//				break;
//			}
//			vector->ajouterElement(nouvelleCouche);
//			break;
//
//		case 'R':
//			int x, y, l, h;
//			flot >> x >> y >> l >> h;
//			Forme** nouveauRectangle = new Rectangle(l, h, x, y);
//			vector.getElement[i].ajouterForme(nouveauRectangle);
//			break;
//
//		case 'K':
//			int x, y, c;
//			flot >> x >> y >> c;
//			Forme** nouveauCarre = new Carre(c, x, y);
//			vector.getElement[i].ajouterForme(nouveauCarre);;
//			break;
//
//		case 'C':
//			int x, y, r;
//			flot >> x >> y >> r;
//			Forme** nouveauCercle = new Cercle(r, x, y);
//			vector.getElement[i].ajouterForme(nouveauCercle);
//			break;
//
//		default:
//			cerr << "Erreur de lecture de l'input du vecteur (CODE 18)";
//			break;
//		}
//	}
//	return flot;
//}
//
//template<class T>
//ostream& operator<<(ostream& flot, Vecteur<T>& item)
//{
//	for (int i = 0; i < item.getTaille(); i++)
//	{
//		item[i]->afficher(flot);
//	}
//	return flot;
//}