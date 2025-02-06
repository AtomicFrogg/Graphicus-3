#include <random>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Interface.h"
#include "carre.h"
#include "rectangle.h"
#include "cercle.h"

using namespace std;

Interface::Interface(const char* theName) : GraphicusGUI(theName)
{
}

/*void Interface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse à générer aléatoirement un canevas en format texte à chaque
	// fois que la commande de réinitialisation de canevas est choisie par l'usager.
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L a" << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "L x" << endl;
	os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
	os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
	os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

	// Ensuite, on dessine ce qui a été généré dans Graphicus
	dessiner(os.str().c_str());
}*/

bool Interface::ouvrirFichier(const char* fichier) {
	ifstream myFile;
	myFile.open(fichier, ios_base::in);
	if (myFile.is_open()) 
	{
		myFile >> dessin;
		myFile.close();
		return true;
	}
	else {
		return false;
	}
}

bool Interface::sauvegarderFichier(const char*fichier) {
	ofstream myFile;
	myFile.open(fichier, ios_base::out);
	if (myFile.is_open()) 
	{
		//myFile << dessin;
		myFile.close();
		return true;
	}
	return false;
}

void Interface::coucheTranslater(int deltaX, int deltaY) {
	dessin.translater(deltaX, deltaY);
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::ajouterCercle(int x, int y, int rayon) {
	Forme* cercle = new Cercle(x, y, rayon);
	dessin.ajouterForme(cercle);
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::ajouterRectangle(int x, int y, int long_x, int long_y) {
	Forme* rectangle = new Rectangle(x, y, long_x,long_y);
	dessin.ajouterForme(rectangle);
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::ajouterCarre(int x, int y, int cote) {
	Forme* carre = new Carre(x, y, cote);
	dessin.ajouterForme(carre);
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::modePileChange(bool mode) {

	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

// Menu Canevas
void Interface::reinitialiserCanevas() {
	dessin.reinitialiser();
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::coucheAjouter() {
	dessin.ajouterCouche();
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}

void Interface::coucheRetirer() {
	dessin.retirerCouche(dessin.getCouchePosition());
	ostringstream os;
	os << dessin;
	dessiner(os.str().c_str());
}
// Menu Formes
void Interface::retirerForme() {
	Forme* it = dessin.getForme();
	dessin.retirerForme(dessin.getFormePosition());
	delete it;
}

// Menu navigation
void Interface::couchePremiere() {
	dessin.couchePremiere();
}

void Interface::couchePrecedente() {
	dessin.couchePrecedente();
}

void Interface::coucheSuivante() {
	dessin.coucheSuivante();
}
void Interface::coucheDerniere() {
	dessin.coucheDerniere();
}
void Interface::formePremiere() {
	dessin.formePremiere();
}
void Interface::formePrecedente() {
	dessin.formePrecedente();
}
void Interface::formeSuivante() {
	dessin.formeSuivante();
}
void Interface::formeDerniere() {
	dessin.formeDerniere();
}