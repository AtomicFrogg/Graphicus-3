TEMPLATE     = vcapp
TARGET       = Graphiscus3-Le-Best
CONFIG      += warn_on qt debug windows console
HEADERS     += canevas.h carre.h cercle.h coordonnee.h couche.h forme.h rectangle.h tests.h vecteur.h interface.h 
SOURCES     += graphicus-3.cpp canevas.cpp carre.cpp cercle.cpp couche.cpp forme.cpp rectangle.cpp tests.cpp interface.cpp 
INCLUDEPATH += GraphicusGUI-Qt6.7
LIBS        += GraphicusGUI-Qt6.7/graphicusGUI.lib
QT          += widgets
