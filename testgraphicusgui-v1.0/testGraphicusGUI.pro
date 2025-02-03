TEMPLATE     = vcapp
TARGET       = testGraphicusGUI
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h 
SOURCES     += testGraphicusGUI.cpp monInterface.cpp
INCLUDEPATH += ../GraphicusGUI-Qt6.7
LIBS        += ../GraphicusGUI-Qt6.7/graphicusGUI.lib
QT          += widgets
