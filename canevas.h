/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Olivier Picard et William Laporte
 * Date : ...
 * Description: Declaration de la classe Canevas. La classe Canevas gere un 
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#pragma once

#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool ajouterCouche();
   bool retirerCouche(int index);

   bool reinitialiser();
   bool reinitialiserCouche(int index);
   
   bool activerCouche(int index);
   bool desactiverCouche(int index);
   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   
   double aire();
   bool translater(int deltaX, int deltaY);
   ostream& afficher(ostream & s);

/// Navigation
   void couchePremiere();
   void couchePrecedente();
   void coucheSuivante();
   void coucheDerniere();
   void formePremiere();
   void formePrecedente();
   void formeSuivante();
   void formeDerniere();
   Forme* getForme();
   Couche* getCouche(int index);
   int getCouchePosition();
   int getFormePosition();
   void setPile(bool mode);
   Vecteur<Couche*> getVecteur();
   friend istream& operator>>(istream& flot, Canevas& s);
   friend ostream& operator<<(ostream& flot, Canevas& s);
private:   
   Vecteur<Couche*> vecteur;
   Couche* coucheActive;
   
};


