/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

// Implementation a faire...

Couche::Couche()
{
	this->formes = new Forme*[MAX_FORMES];
	this->etat = INITIALISE;
	this->taille = 0;
}

Couche::~Couche()
{
	delete formes;
}

void Couche::setEtat(int nouvelEtat)
{
	if(nouvelEtat >= 0 and nouvelEtat <=2){
		this->etat = nouvelEtat;
	}
	
}

int Couche::getEtat()
{
	return this->etat;
}

bool Couche::reinitialiserCouche()
{
	if(this->etat == INITIALISE)
	{
		return FAIL;
	}
	else
	{
		this->etat = INITIALISE;
		Forme* *formes2 = new Forme*[MAX_FORMES];
		delete formes;
		formes = formes2;
		taille = 0;
		return SUCCES;
	}
}

double Couche::aireTotale()
{
	double aire = 0;
	for(int i = 0; i<taille;i++)
	{
		aire = aire + formes[i]->aire();
	}
	return aire;
}

bool Couche::ajouterForme(Forme* ptr)
{
	if(taille < MAX_FORMES)
	{
		formes[taille] = ptr;
		taille++;
		return SUCCES;
	}
	return FAIL;
}

Forme* Couche::retirerForme(int index)
{
	if(index >= 0 and index < taille)
	{
		Forme* ptr = formes[index];
		for(int i = index; i< taille - 1; i++)
		{
			formes[i] = formes[i+1];
		}
		taille--;
		return ptr;
	}
	else
	{
		return nullptr;
	}
}

Forme* Couche::getForme(int index)
{
	if(index >= 0 and index < taille)
	{
		return formes[index];
	}
	else
	{
		return nullptr;
	}
}

bool Couche::translaterCouche(int deltaX, int deltaY)
{
	if(deltaX != 0 and deltaY != 0)
	{
		for(int i = 0; i < taille; i++)
		{
			formes[i]->translater(deltaX, deltaY);
		}
		return SUCCES;
	}
	else
	{
		return FAIL;
	}
}

void Couche::afficher(ostream &s)
{
	s << "Etat: ";
	if(etat == INITIALISE)
	{
		s<< "INITIALISE" << endl;
	}
	if(etat == ACTIVE)
	{
		s<< "ACTIVE" << endl;	
	}
	if(etat == INACTIVE)
	{
		s<< "INACTIVE"<<endl;
	}
	if(taille > 0)
	{
		for(int i = 0; i < taille; i++)
		{
			formes[i]->afficher(s);
		}
	}
	else if(taille == 0)
	{
		s << "Couche = vide" << endl;
	}
	else
	{
		s << "ERREUR TAILLE DE LA COUCHE"<<endl;
	}
}

int Couche::getTaille()
{
	return taille;
}





















