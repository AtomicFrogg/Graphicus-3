/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Description: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
********/

#pragma once

#include <iostream>
#include "coordonnee.h"

using namespace std;

class Forme
{
public:
  Forme(int x = 0, int y = 0);
  virtual ~Forme();
  void translater(int deltaX, int deltaY);
  Coordonnee getAncrage();
  void setAncrage(Coordonnee c);
  virtual double aire() = 0;
  virtual void afficher(ostream & s) = 0;
  friend ostream& operator<<(ostream& flot, Forme* X);
protected:
  Coordonnee ancrage;
};


