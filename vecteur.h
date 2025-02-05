#pragma once

#include <iostream>
#include "carre.h"
#include "cercle.h"


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
	T operator[](int i);
	void operator+=(T item);
	T operator++();
	T operator--();
	void maxPosition();
	void resetPosition();
	int getPosition();
	void setPile(bool mode);
	bool getPile();

private:
	int capacite;
	int taille;
	int position;
	T *elements;
	bool pile;
};

template <class T>
Vecteur<T>::Vecteur() {
	capacite = 1;
	taille = 0;
	position = 0;
	elements = new T[capacite];
	pile = false;
}


template <class T>
Vecteur<T>::~Vecteur() {
	delete[] elements;
}

template <class T>
int Vecteur<T>::getCapacite() {
	return capacite;
}

template <class T>
int Vecteur<T>::getTaille() {
	return taille;
}

template <class T>
void Vecteur<T>::doublerCapacite() {
	capacite = capacite * 2;
	T* elements2;
	elements2 = new T[capacite];
	//Copier le contenu
	for (int i = 0; i < taille; i++) {
		elements2[i] = elements[i];
	}
	delete[] elements;
	elements = elements2;
}

template <class T>
void Vecteur<T>::viderVecteur() {
	//Supprimer l'ancien tableau pour en cr�er un nouveau vide
	delete[] elements;
	elements = new T[capacite];
	taille = 0;
}


template <class T>
bool Vecteur<T>::estVide() {
	return taille == 0;

}


template <class T>
bool Vecteur<T>::ajouterElement(T element) {
	//V�rifier si plein
	if (taille >= capacite) {
		doublerCapacite();
	}
	//Ajouter le nouvel �l�ment � la fin
	elements[taille] = element;
	taille++;
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
	if (taille == 0) {
		s << "Vecteur vide" << endl;
	}
	else {
		for (int i = 0; i < taille; i++) {

			elements[i].afficher(s);
		}
	}


}


template <class T>
T Vecteur<T>::retirerElement(int index) {
	if (index < taille && index >= 0) {
		T elementRetire = elements[index];
		//Tasser tous ceux apr�s
		for (int i = index; i < taille - 1; i++) {
			elements[i] = elements[i + 1];
		}
		taille--;
		return elementRetire;
	}
	else {
		return nullptr;
	}
}


template <class T>
T Vecteur<T>::getElement(int index) {

	if (index < taille && index >= 0) {
		return elements[index];
	}
	else {
		return nullptr;
	}
}
template<class T>
void Vecteur<T>::operator+=(T item)
{
	ajouterElement(item);
}


template<class T>
T Vecteur<T>::operator++()
{
	++position;
	return elements[position%taille];
}

template<class T>
T Vecteur<T>::operator--()
{
	if (!position)
	{
		position = taille - 1;
		return elements[position];
	}
	--position;
	return elements[position];
}

template<class T>
T Vecteur<T>::operator[](int i )
{
	return elements[i];
}


template<class T>
void Vecteur<T>::resetPosition() {
	position = 0;
}

template<class T>
int Vecteur<T>::getPosition() {
	return position;
}
template<class T>
void Vecteur<T>::setPile(bool mode)
{
	pile = mode;
}
template<class T>
bool Vecteur<T>::getPile()
{
	return pile;
}
template<class T>
void Vecteur<T>::maxPosition() {
	position = taille - 1;
}

template<class T>
ostream& operator<<(ostream& flot, Vecteur<T>& vector)
{
	if (vector.getPile())
	{
		for (int i = 0; i < vector.getTaille(); i++)
		{
			flot << vector[vector.getTaille()-i];
		}
	}
	else 
	{
		for (int i = 0; i < vector.getTaille(); i++)
		{
			flot << vector[i];
		}
	}
	return flot;
}
template<class T>
istream& operator>>(istream& flot, Vecteur<T>& vector)
{
	if (vector.getPile())
	{
		for (int i = 0; i < vector.getTaille(); i++)
		{
			flot >> vector[vector.getTaille() - i];
		}
	}
	else
	{
		for (int i = 0; i < vector.getTaille(); i++)
		{
			flot >> vector[i];
		}
	}
	return flot;
}