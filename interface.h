#pragma once
#include "graphicusGUI.h"
#include "canevas.h"

class Interface : public GraphicusGUI
{
private:
	Canevas dessin;
public:
	Interface(const char* theName = nullptr);
	virtual bool ouvrirFichier(const char* fichier);
	virtual bool sauvegarderFichier(const char*);
	virtual void coucheTranslater(int deltaX, int deltaY);
	virtual void ajouterCercle(int x, int y, int rayon);
	virtual void ajouterRectangle(int x, int y, int long_x, int long_y);
	virtual void ajouterCarre(int x, int y, int cote);
	virtual void modePileChange(bool mode);

	// Menu Canevas
	virtual void reinitialiserCanevas();
	virtual void coucheAjouter();
	virtual void coucheRetirer();
	// Menu Formes
	virtual void retirerForme();
	// Menu navigation
	virtual void couchePremiere();
	virtual void couchePrecedente();
	virtual void coucheSuivante();
	virtual void coucheDerniere();
	virtual void formePremiere();
	virtual void formePrecedente();
	virtual void formeSuivante();
	virtual void formeDerniere();
};