#include <random>
#include <sstream>
#include "Interface.h"
#include "carre.h"
#include "rectangle.h"
#include "cercle.h"

using namespace std;

Interface::Interface(const char* theName) : GraphicusGUI(theName)
{
}

void Interface::reinitialiserCanevas()
{
	ostringstream os;
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(0, 300), dim(20, 100);

	// On s'amuse � g�n�rer al�atoirement un canevas en format texte � chaque
	// fois que la commande de r�initialisation de canevas est choisie par l'usager.
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

	// Ensuite, on dessine ce qui a �t� g�n�r� dans Graphicus
	dessiner(os.str().c_str());
}

bool Interface::ouvrirFichier(const char*) {
	return false;
}

bool Interface::sauvegarderFichier(const char*) {
	return false;
}

void Interface::coucheTranslater(int deltaX, int deltaY) {
	dessin.translater(deltaX, deltaY);
}

void Interface::ajouterCercle(int x, int y, int rayon) {
	Forme* cercle = new Cercle(x, y, rayon);
	dessin.ajouterForme(cercle);
}

void Interface::ajouterRectangle(int x, int y, int long_x, int long_y) {
	Forme* rectangle = new Rectangle(x, y, long_x,long_y);
	dessin.ajouterForme(rectangle);
}

void Interface::ajouterCarre(int x, int y, int cote) {
	Forme* carre = new Carre(x, y, cote);
	dessin.ajouterForme(carre);
}

void Interface::modePileChange(bool mode) {

}

// Menu Canevas
void Interface::reinitialiserCanevas() {
	dessin.reinitialiser();
}

void Interface::coucheAjouter() {
	dessin.ajouterCouche();
}

void Interface::coucheRetirer() {
	dessin.retirerCouche();
}
// Menu Formes
void Interface::retirerForme() {
	Forme* it = dessin.retirerForme();
	delete it;
}

// Menu navigation
void Interface::couchePremiere() {
	l
}

void Interface::couchePrecedente() {
	l
}

void Interface::coucheSuivante() {
	l
}
void Interface::coucheDerniere() {
l
}
void Interface::formePremiere() {
	l
}
void Interface::formePrecedente() {
	l
}
void Interface::formeSuivante() {
	l
}
void Interface::formeDerniere() {
	l
}