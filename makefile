graphicus-02:graphicus-02.o tests.o canevas.o vecteur.o forme.o couche.o rectangle.o carre.o cercle.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o vecteur.o forme.o couche.o rectangle.o carre.o cercle.o

canevas.o:canevas.cpp canevas.h couche.h forme.h coordonnee.h vecteur.h cercle.h rectangle.h carre.h
	g++ -g -c -Werror canevas.cpp 
	
forme.o:forme.cpp forme.h coordonnee.h
	g++ -g -c -Werror forme.cpp

couche.o:couche.cpp couche.h forme.h coordonnee.h cercle.h rectangle.h carre.h
	g++ -g -c -Werror couche.cpp

test.o:test.cpp test.h canevas.h couche.h forme.h coordonnee.h vecteur.h cercle.h rectangle.h carre.h
	g++ -g -c -Werror test.cpp

vecteur.o:vecteur.cpp vecteur.h couche.cpp couche.h forme.h coordonnee.h cercle.h rectangle.h carre.h
	g++ -g -c -Werror vecteur.cpp

cercle.o:cercle.cpp cercle.h forme.h coordonnee.h
	g++ -g -c -Werror cercle.cpp

rectangle.o:rectangle.cpp rectangle.h forme.h coordonnee.h
	g++ -g -c -Werror rectangle.cpp

carre.o:carre.cpp carre.h rectangle.h forme.h coordonnee.h
	g++ -g -c -Werror carre.cpp

graphicus-02.o:graphicus-02.cpp tests.h canevas.h couche.h forme.h coordonnee.h vecteur.h cercle.h rectangle.h carre.h
	g++ -g -c -Werror graphicus-02.cpp
	
	
clean:
	rm -f *.o 
