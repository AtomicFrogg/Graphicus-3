/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Olivier Picard et Jacob Beauregard-Tousignant
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
using namespace std;
void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
   
   //Rectangle
   Rectangle TestRectangle;
   TestRectangle.afficher(cout);
   TestRectangle.setHauteur(4);
   TestRectangle.setLongueur(5);
   Coordonnee test;
   test.x = 3;
   test.y = 2;
   TestRectangle.setAncrage(test);
   TestRectangle.afficher(cout);
   
   
   //Cercle
   Cercle TestCercle;
   TestCercle.afficher(cout);
   TestCercle.setRayon(3);
   TestCercle.setAncrage(test);
   TestCercle.afficher(cout);
   
   //Carre
   Carre TestCarre;
   TestCarre.afficher(cout);
   TestCarre.setCote(5);
   TestCarre.setAncrage(test);
   TestCarre.afficher(cout);
   
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
	///*Couche TestCouche;
	//TestCouche.afficher(cout);
	//Forme* TestRectangle = new Rectangle();
	//Forme* TestCercle = new Cercle();
	//Forme* TestCarre = new Carre();
	//
	//TestCouche.ajouterForme(TestRectangle);
	//TestCouche.afficher(cout);
	//TestCouche.setEtat(ACTIVE);
	//TestCouche.ajouterForme(TestCercle);
	//TestCouche.afficher(cout);

	//cout << "Translation = " << TestCouche.translaterCouche(3,-5) << endl;
	//TestCouche.setEtat(INACTIVE);
	//TestCouche.ajouterForme(TestCarre);
	//TestCouche.afficher(cout);
	//cout << TestCouche.aireTotale()<<endl;
	//TestCouche.retirerForme(0);
	//TestCouche.afficher(cout);
	//cout << TestCouche.getTaille();
	//
	//
	//delete TestRectangle;
	//delete TestCercle;
	//d*/elete TestCarre;
}

void Tests::tests_unitaires_vecteur()
{
   //Vecteur TestVecteur;
   //TestVecteur.afficher(cout);
   //Couche *TestCouche0 = new Couche();
   //Couche *TestCouche1 = new Couche();
   //Couche *TestCouche2 = new Couche();
   //TestVecteur.ajouterElement(TestCouche0);
   //TestVecteur.ajouterElement(TestCouche1);
   //TestVecteur.ajouterElement(TestCouche2);
   //TestVecteur.afficher(cout);
   //TestVecteur.retirerElement(1);
   //TestVecteur.afficher(cout);
   //TestVecteur.viderVecteur();
   //TestVecteur.afficher(cout);
   //
   //
   //delete TestCouche0;
   //delete TestCouche1;
   //delete TestCouche2;
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
	cout << "TESTS APPLICATION (CAS 01)" << endl; 
	cout<<"----1----"<<endl;
	Canevas TestCanevas;
	TestCanevas.afficher(cout);
	
	 
	cout<<"----2----"<<endl;
	cout<<TestCanevas.aire()<<endl;
	
	 
	cout<<"----3----"<<endl;
	for(int i = 0; i<5; i++)
	{
		TestCanevas.ajouterCouche();		
	}
	cout << "Ajout fait" << endl; 


	cout<<"----4----"<<endl;
	TestCanevas.afficher(cout);
	
	
	cout<<"----5----"<<endl;
	cout<<"Aire =" << TestCanevas.aire()<<endl;
	
	
	cout<<"----6----"<<endl;
	TestCanevas.activerCouche(2);
	Forme *TestCercle = new Cercle(5,0,1);
	TestCanevas.ajouterForme(TestCercle);
	Forme *TestCarre = new Carre(6,1,2);
	TestCanevas.ajouterForme(TestCarre);
	Forme *TestRectangle = new Rectangle(9,4,2,3);
	TestCanevas.ajouterForme(TestRectangle);
	
	
	cout<<"----7----"<<endl;
	TestCanevas.activerCouche(1);
	Forme *TestRectangle1 = new Rectangle(3,12);
	TestCanevas.ajouterForme(TestRectangle1);
	
	
	cout<<"----8----"<<endl;
	TestCanevas.afficher(cout);
	
	cout<<"----9----"<<endl;
	cout<<"Aire =" << TestCanevas.aire()<<endl;	
	
	
	cout<<"----10----"<<endl;
	TestCanevas.activerCouche(0);
	Forme *TestRectangle2 = new Rectangle();
	TestCanevas.ajouterForme(TestRectangle2);
	Forme *TestCarre1 = new Carre();
	TestCanevas.ajouterForme(TestCarre1);	
	Forme *TestCercle1 = new Cercle();
	TestCanevas.ajouterForme(TestCercle1);
	
	cout<<"----11----"<<endl;
	TestCanevas.activerCouche(2);
	TestCanevas.translater(2,1);
	
	
	cout<<"----12----"<<endl;
	TestCanevas.afficher(cout);
	
	cout<<"----13----"<<endl;
	cout<<"Aire =" << TestCanevas.aire()<<endl;
	
	cout<<"----14----"<<endl;
	TestCanevas.activerCouche(0);
	TestCanevas.retirerForme(1);


	cout<<"----15----"<<endl;	
	TestCanevas.reinitialiserCouche(1);

	
	cout<<"----16----"<<endl;	
	TestCanevas.activerCouche(2);

	
	cout<<"----17----"<<endl;	
	TestCanevas.retirerCouche(2);

	
	cout<<"----18----"<<endl;
	TestCanevas.activerCouche(4);

	
	cout<<"----19----"<<endl;		
	TestCanevas.afficher(cout);

	
	cout<<"----20----"<<endl;		
	cout<<"Aire =" << TestCanevas.aire()<<endl;


	cout<<"----21----"<<endl;
	TestCanevas.reinitialiser();

	
	cout<<"----22----"<<endl;
	TestCanevas.afficher(cout);
	
	
	cout<<"----23----"<<endl;
	cout<<"Aire =" << TestCanevas.aire()<<endl;
	
	
	cout<<"----24----"<<endl;
	TestCanevas.activerCouche(3);
	Forme *TestCarre2 = new Carre();
	TestCanevas.ajouterForme(TestCarre2);
	Forme *ptr_null = nullptr;
	TestCanevas.ajouterForme(ptr_null);
		
		
	cout<<"----25----"<<endl;
	TestCanevas.activerCouche(6);
	
	
	cout<<"----26----"<<endl;
	TestCanevas.afficher(cout);
	
	
	
	cout<<"----27----"<<endl;
	cout<<"Aire =" << TestCanevas.aire()<<endl;
		
	
	
	
	delete TestCercle;
	delete TestCarre;
	delete TestRectangle;
	delete TestRectangle1;
	delete TestCercle1;
	delete TestCarre1;
	delete TestRectangle2;
	delete TestCarre2;
}
void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
  Canevas TestCanevas;

  TestCanevas.ajouterCouche();
  Forme* Carre1 = new Carre(3,6,9);
TestCanevas.ajouterForme(Carre1);
for(int i = 0; i<92;i++)
{
  TestCanevas.ajouterCouche();
}
TestCanevas.activerCouche(69);
Forme* Cercle1 = new Cercle(4,2,8);
TestCanevas.ajouterForme(Cercle1);
TestCanevas.ajouterForme(Carre1);
TestCanevas.translater(-2,-8);
TestCanevas.reinitialiserCouche(1);
    TestCanevas.afficher(cout);
    delete Carre1;
}


















