/********
 * Fichier: graphicus-03.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Olivier Picard et William Laporte
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#include <QApplication>
#include "Interface.h"

#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
 //  Tests tests; 
  // tests.tests_application_cas_02();
	//Vecteur<Couche*> Test;
	//Couche *TestCouche = new Couche();
	//Test.ajouterElement(TestCouche);

	//Forme* TestForme = new Cercle();
	//Test.getElement(0)->ajouterForme(TestForme);



	Canevas TestCanevas;
	ifstream myFile;
	myFile.open("test.txt", ios_base::in);
	if (myFile.is_open()) 
	{
		myFile >> TestCanevas;
		myFile.close();
	}
	cout << TestCanevas;
	//TestCanevas.ajouterCouche();

	//TestCanevas.ajouterForme(TestForme);
	//TestCanevas.ajouterCouche();
	//TestCanevas.ajouterForme(TestForme);
	//TestCanevas.activerCouche(1);
	//TestCanevas.ajouterForme(TestForme);
	//cout << TestCanevas;

	//delete TestForme;
	//delete TestCouche;
	//TestCanevas.ajouterCouche();
	//TestCanevas.ajouterCouche();
	//TestCanevas.ajouterCouche();
	//cout << TestCanevas;
	//Test.afficher(std::cout);
<<<<<<< HEAD
	/*QApplication app(argc, argv);
	Interface gui("test PATATE 2.0");
	return app.exec();*/
=======
	QApplication app(argc, argv);
	Interface gui("Graphicus-3");
	return app.exec();
>>>>>>> origin/main
}

