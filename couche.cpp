/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

// Implementation a faire...

Couche::Couche()
{
	//this->formes = new Forme*[MAX_FORMES];
	this->formes = new Vecteur<Forme*>();
	this->etat = INITIALISE;
	//this->taille = 0;
}

Couche::~Couche()
{
	delete formes;
}

void Couche::setEtat(int nouvelEtat)
{
	if(nouvelEtat >= 0 && nouvelEtat <=2){
		this->etat = nouvelEtat;
	}
	
}

int Couche::getEtat()
{
	return this->etat;
}

bool Couche::reinitialiserCouche()
{
	if(this->etat == INITIALISE)
	{
		return FAIL;
	}
	else
	{
		this->etat = INITIALISE;
		/*Forme** formes2 = new Forme * [MAX_FORMES];
		delete formes;
		formes = formes2;
		taille = 0;*/
		formes->viderVecteur();
		return SUCCES;
	}
}

double Couche::aireTotale()
{
	double aire = 0;
	Forme* ptr = nullptr;
	for(int i = 0; i<formes->getTaille()/*taille*/;i++)
	{
		ptr = formes->getElement(i);
		aire = aire + ptr->aire();
	}
	return aire;
}

bool Couche::ajouterForme(Forme* ptr)
{
	if(formes->getTaille()/*taille*/ < MAX_FORMES)
	{
		//formes[taille] = ptr;
		//taille++;
		formes->ajouterElement(ptr);
		return SUCCES;
	}
	return FAIL;
}

Forme* Couche::retirerForme(int index)
{
	if(index >= 0 && index < formes->getTaille()/*taille*/)
	{
		Forme* ptr = formes->retirerElement(index);
		/*Forme* ptr = formes[index];
		for(int i = index; i< taille - 1; i++)
		{
			formes[i] = formes[i+1];
		}
		taille--;*/
		return ptr;
	}
	else
	{
		return nullptr;
	}
}

Forme* Couche::getForme(int index)
{
	if(index >= 0 && index < formes->getTaille()/*taille*/)
	{
		return formes->getElement(index)/*formes[index]*/;
	}
	else
	{
		return nullptr;
	}
}
Forme* Couche::getForme2() {
	return formes->getElement(formes->getPosition());
}

bool Couche::translaterCouche(int deltaX, int deltaY)
{
	if(deltaX != 0 && deltaY != 0)
	{
		Forme* it = nullptr;
		for(int i = 0; i < formes->getTaille()/*taille*/; i++)
		{
			/*formes[i]->translater(deltaX, deltaY);*/
			it = formes->getElement(i);
			it->translater(deltaX, deltaY);
		}
		return SUCCES;
	}
	else
	{
		return FAIL;
	}
}

//void Couche::afficher(ostream &s)
//{
//	s << "L ";
//	if(etat == INITIALISE)
//	{
//		s<< "i" << endl;
//	}
//	else if(etat == ACTIVE)
//	{
//		s<< "a" << endl;	
//	}
//	else if(etat == INACTIVE)
//	{
//		s<< "x"<<endl;
//	}
//	//if(formes.getTaille() > 0)
//	//{
//	//	/*for (int i = 0; i < taille; i++)
//	//	{
//	//		formes[i]->afficher(s);
//	//	}*/
//	//	formes.afficher(s);
//	//}
//	//else if(formes.getTaille() == 0)
//	//{
//	//	s << "Couche = vide" << endl;
//	//}
//	else
//	{
//		s << "erreur etat de la couche"<<endl;
//	}
//	for (int i = 0; i < getTaille(); i++)
//	{
//		//s << formes;
//	}
//}

int Couche::getTaille()
{
	return formes->getTaille()/*taille*/;
}

void Couche::formePremiere() {
	formes->resetPosition();
}

void Couche::formePrecedente() {
	--formes;
}
void Couche::formeSuivante() {
	++formes;
}
void Couche::formeDerniere() {
	formes->maxPosition();
}

int Couche::getPosition()
{
	return formes->getPosition();
}


ostream& operator<<(ostream& flot, Couche* item)
{
	flot << "L ";
	if (item->etat == INITIALISE)
	{
		flot << "i" << endl;
	}
	else if (item->etat == ACTIVE)
	{
		flot << "a" << endl;
	}
	else if (item->etat == INACTIVE)
	{
		flot << "x" << endl;
	}
	else
	{
		cout << "ERREUR etat couche";
	}
	for (int i = 0; i < item->getTaille(); i++)
	{
		flot << item->getForme(i);
	}
	return flot;
}
istream& operator>>(istream& flot, Couche* couche)
{
	char item;
	int x, y;
	Forme* nouvelleForme;
	do
	{

		switch (item)
		{
		case 'R':
			int l, h;
			flot >> x >> y >> l >> h;;
			cout << x << y << l << h;
			nouvelleForme = new Rectangle(l, h, x, y);
			couche->ajouterForme(nouvelleForme);
			break;

		case 'K':
			int c;
			flot >> x >> y >> c;
			cout << x << y << c;
			nouvelleForme = new Carre(c, x, y);
			couche->ajouterForme(nouvelleForme);
			break;

		case 'C':
			int r;
			flot >> x >> y >> r;
			cout << x << y << r;
			nouvelleForme = new Cercle(r, x, y);
			couche->ajouterForme(nouvelleForme);
			break;

		default:
			cerr << "Erreur de lecture de l'input du vecteur (CODE 18)";
			break;
		}
		flot >> item;
	} while (item != EOF);
	return flot;
}

















