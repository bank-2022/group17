#ifndef DLLSERIALPORT_GLOBAL_H
#define DLLSERIALPORT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLLSERIALPORT_LIBRARY)              //Määritellään DLL projektifilessä
#  define DLLSERIALPORT_EXPORT Q_DECL_EXPORT    //Tämä voimassa DLL:ssä
#else
#  define DLLSERIALPORT_EXPORT Q_DECL_IMPORT    //Tämä voimassa EXE:ssä, koska EXE:n projektifilessä
#endif                                          //ei ole INTERFACECLASS_LIBRARY:ä määriteltynä

#endif // DLLSERIALPORT_GLOBAL_H
