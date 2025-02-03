#include "vecteur.h"

Vecteur<T>::Vecteur(){
	this->capacite = 1;
	this->taille = 0;
	this->elements = new Couche*[this->capacite];
}


Vecteur<T>::~Vecteur(){
		delete [] this->elements;
}

int Vecteur<T>::getCapacite(){
	return this->capacite;
}

int Vecteur<T>::getTaille(){
	return this->taille;
}

void Vecteur<T>::doublerCapacite(){
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

void Vecteur<T>::viderVecteur(){
	//Supprimer l'ancien tableau pour en créer un nouveau vide
	delete [] this->elements;
	this->elements = new Couche*[this->capacite];
	this->taille = 0;
}


bool Vecteur<T>::estVide(){
	return this->taille == 0;

}


bool Vecteur<T>::ajouterElement(T element){
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

void Vecteur<T>::afficher(ostream &s){
	if(this->taille == 0){
		s << "Vecteur vide" << endl;
	}
	else{
		for(int i = 0; i < taille; i++){
			
			this->elements[i]->afficher(s);
		}
	}
	
	
}


T Vecteur<T>::retirerElement(int index){
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


T Vecteur<T>::getElement(int index){
	
	if(index < this->taille && index >= 0){
		return this->elements[index];
	}
	else{
		return nullptr;
	}
}








































