#include "vecteur.h"

Vecteur::Vecteur(){
	this->capacite = 1;
	this->taille = 0;
	this->elements = new Couche*[this->capacite];
}


Vecteur::~Vecteur(){
		delete [] this->elements;
}

int Vecteur::getCapacite(){
	return this->capacite;
}

int Vecteur::getTaille(){
	return this->taille;
}

void Vecteur::doublerCapacite(){
	this->capacite = this->capacite * 2;
	Couche* *elements2;
	elements2 = new Couche*[this->capacite];
	//Copier le contenu
	for(int i = 0; i < this->taille; i++){
		elements2[i] = this->elements[i];
	}
	delete [] this->elements;
	this->elements = elements2;	
}

void Vecteur::viderVecteur(){
	//Supprimer l'ancien tableau pour en créer un nouveau vide
	delete [] this->elements;
	this->elements = new Couche*[this->capacite];
	this->taille = 0;
}


bool Vecteur::estVide(){
	return this->taille == 0;

}


bool Vecteur::ajouterElement(Couche *element){
	//Vérifier si plein
	if(this->taille >= this->capacite){
		this->doublerCapacite();
	}
	//Ajouter le nouvel élément à la fin
	this->elements[this->taille] = element;
	this->taille ++;
	return true;
}

/*
void Vecteur::afficher(ostream &s){
	if(this->taille == 0){
		s << "----- Aucune couche ----" << endl;
	}
	else{
		for(int i = 0; i < taille; i++){
			s << "----- Couche " << i << "-----" << endl;
			this->elements[i]->afficher(s);
		}
	}
	
}
*/

void Vecteur::afficher(ostream &s){
	if(this->taille == 0){
		s << "Vecteur vide" << endl;
	}
	else{
		for(int i = 0; i < taille; i++){
			
			this->elements[i]->afficher(s);
		}
	}
	
	
}


Couche* Vecteur::retirerElement(int index){
	if(index < this->taille && index >= 0){
		Couche* elementRetire = this->elements[index];
		//Tasser tous ceux après
		for(int i = index; i < this->taille - 1; i ++){
			this->elements[i] = this->elements[i+1];
		}
		this->taille --;
		return elementRetire;
	}
	else{
		return nullptr;
	}
}


Couche* Vecteur::getElement(int index){
	
	if(index < this->taille && index >= 0){
		return this->elements[index];
	}
	else{
		return nullptr;
	}
}








































