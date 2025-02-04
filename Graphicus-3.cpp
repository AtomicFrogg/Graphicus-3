/********
 * Fichier: graphicus-02.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Olivier Picard et Jacob Beauregard-Tousignant
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#include <QApplication>
#include "Interface.h"

using namespace std;

int main(int argc, char** argv)
{
 //  Tests tests; 
  // tests.tests_application_cas_02();
	QApplication app(argc, argv);
	Interface gui("test PATATE 2.0");
	return app.exec();
}

