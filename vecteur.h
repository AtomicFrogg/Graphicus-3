#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "couche.h"

using namespace std;
template  <class T>
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

template <class T>
Vecteur<T>::Vecteur() {
	this->capacite = 1;
	this->taille = 0;
	this->elements = new Couche * [this->capacite];
}


template <class T>
Vecteur<T>::~Vecteur() {
	delete[] this->elements;
}

template <class T>
int Vecteur<T>::getCapacite() {
	return this->capacite;
}

template <class T>
int Vecteur<T>::getTaille() {
	return this->taille;
}

template <class T>
void Vecteur<T>::doublerCapacite() {
	this->capacite = this->capacite * 2;
	Couche** elements2;
	elements2 = new Couche * [this->capacite];
	//Copier le contenu
	for (int i = 0; i < this->taille; i++) {
		elements2[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = elements2;
}

template <class T>
void Vecteur<T>::viderVecteur() {
	//Supprimer l'ancien tableau pour en créer un nouveau vide
	delete[] this->elements;
	this->elements = new Couche * [this->capacite];
	this->taille = 0;
}


template <class T>
bool Vecteur<T>::estVide() {
	return this->taille == 0;

}


template <class T>
bool Vecteur<T>::ajouterElement(T element) {
	//Vérifier si plein
	if (this->taille >= this->capacite) {
		this->doublerCapacite();
	}
	//Ajouter le nouvel élément à la fin
	this->elements[this->taille] = element;
	this->taille++;
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

template <class T>
void Vecteur<T>::afficher(ostream& s) {
	if (this->taille == 0) {
		s << "Vecteur vide" << endl;
	}
	else {
		for (int i = 0; i < taille; i++) {

			this->elements[i]->afficher(s);
		}
	}


}


template <class T>
T Vecteur<T>::retirerElement(int index) {
	if (index < this->taille && index >= 0) {
		Couche* elementRetire = this->elements[index];
		//Tasser tous ceux après
		for (int i = index; i < this->taille - 1; i++) {
			this->elements[i] = this->elements[i + 1];
		}
		this->taille--;
		return elementRetire;
	}
	else {
		return nullptr;
	}
}


template <class T>
T Vecteur<T>::getElement(int index) {

	if (index < this->taille && index >= 0) {
		return this->elements[index];
	}
	else {
		return nullptr;
	}
}



#endif
