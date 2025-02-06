/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
#include "couche.h"

Canevas::Canevas()
{
	this->vecteur = *new Vecteur<Couche*>();
	this->coucheActive = nullptr;
}

Canevas::~Canevas()
{
}

bool Canevas::ajouterCouche()
{
	Couche *nouvelleCouche = new Couche();
	//Vérifier s'il y a une couche active
	if(this->coucheActive == nullptr){
		this->coucheActive = nouvelleCouche;
		nouvelleCouche->setEtat(ACTIVE);
	}
	this->vecteur.ajouterElement(nouvelleCouche);
	return true;
}

bool Canevas::retirerCouche(int index)
{
	//S'assurer que l'index est valide
	if(index >= 0 && index < this->vecteur.getTaille())
	{
	this->desactiverCouche(index);
		bool resultReinitialisation = this->reinitialiserCouche(index);
		if(resultReinitialisation)
		{
			Couche* coucheRetire = this->vecteur.retirerElement(index);

			return coucheRetire != nullptr;
		}
	}
	return false;
}


bool Canevas::reinitialiser()
{
	//Retirer toutes les couches
	//Passer au travers de toutes les couches, la désactivée si nécessaire, puis le retirer
	for (int i = this->vecteur.getTaille()-1; i >= 0; i--)
	{
		if(this->coucheActive == this->vecteur.getElement(i))
		{
			this->desactiverCouche(i);
		}
		this->retirerCouche(i);
	}
	return true;
}

bool Canevas::reinitialiserCouche(int index)
{
	Couche* coucheAReinitialiser = this->vecteur.getElement(index);
	//Vérifier que la couche n'est pas active
	if(coucheAReinitialiser != nullptr && coucheAReinitialiser->getEtat() != ACTIVE){
		coucheAReinitialiser->reinitialiserCouche();
		return true;
	}
	return false;
}


bool Canevas::activerCouche(int index)
{
	Couche* coucheAActiver = this->vecteur.getElement(index);
	if(coucheAActiver != nullptr){
		//Desactiver l'ancienne couche
		this->coucheActive->setEtat(INACTIVE);
		this->coucheActive = coucheAActiver;
		coucheAActiver->setEtat(ACTIVE);
		return true;
	}
	return false;
	
}

bool Canevas::desactiverCouche(int index)
{
	Couche* coucheADesactiver = this->vecteur.getElement(index);
	if(coucheADesactiver != nullptr){
		//Si la couche était celle active
		//Retirer le pointeur vers la couche active
		if(coucheADesactiver == this->coucheActive){
			this->coucheActive = nullptr;
		}
		coucheADesactiver->setEtat(INACTIVE);		
		return true;
	}
	return false;
}


bool Canevas::ajouterForme(Forme *p_forme)
{
	if(this->coucheActive != nullptr)
	{
		return this->coucheActive->ajouterForme(p_forme);
	}
	return false;
}

bool Canevas::retirerForme(int index)
{
	if(this->coucheActive != nullptr){
	
		return this->coucheActive->retirerForme(index) != nullptr;
	}
	return false;
}

double Canevas::aire()
{
	double aireTotaleCanevas = 0;
	for(int i = 0; i < this->vecteur.getTaille(); i++)
	{
		aireTotaleCanevas += this->vecteur.getElement(i)->aireTotale();
	}
	return aireTotaleCanevas;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	if(this->coucheActive != nullptr){
		return this->coucheActive->translaterCouche(deltaX, deltaY);
	}
	return false;
}

ostream& Canevas::afficher(ostream & s)
{
	//cout<<"AFFICHAGE"<<endl;
	////Vérifier s'il y a des couches
	//if(this->vecteur.getTaille() == 0)
	//{
	//	s << "----- Aucune couche ----" << endl;
	//}
	//else if(vecteur.getTaille() != 0)
	//{
	//cout<<"ELSE"<<endl;
	//	for(int i = 0; i < this->vecteur.getTaille(); i++)
	//	{
	//		s << "----- Couche " << i << " -----" << endl;
	//		this->vecteur.getElement(i)->afficher(s);
	//		s << endl;
	//	}
	//	
	//}

	//s << vecteur;

	return s;
}
void Canevas::couchePremiere() {
	vecteur.resetPosition();
	activerCouche(vecteur.getPosition());
}

void Canevas::couchePrecedente() {
	--vecteur;
	activerCouche(vecteur.getPosition());
}

void Canevas::coucheSuivante() {
	++vecteur;
	activerCouche(vecteur.getPosition());
}

void Canevas::coucheDerniere() {
	vecteur.maxPosition();
	activerCouche(vecteur.getPosition());
}

void Canevas::formePremiere() {
	vecteur.getElement(vecteur.getPosition())->formePremiere();
}

void Canevas::formePrecedente() {
	vecteur.getElement(vecteur.getPosition())->formePrecedente();
}

void Canevas::formeSuivante() {
	vecteur.getElement(vecteur.getPosition())->formeSuivante();
}

void Canevas::formeDerniere() {
	vecteur.getElement(vecteur.getPosition())->formeDerniere();
}
Forme* Canevas::getForme() {
	return vecteur.getElement(vecteur.getPosition())->getForme2();
}

int Canevas::getCouchePosition()
{
	return vecteur.getPosition();
}

int Canevas::getFormePosition()
{
	return vecteur.getElement(vecteur.getPosition())->getPosition();
}

Vecteur<Couche*> Canevas::getVecteur()
{
	return vecteur;
}



