// Controladora.h
// Autor: N�stor Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase Controladora utilizados para el control 
//				durante la ejecuci�n del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <iostream>
#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase controladora
class Controladora{

// M�todos p�blicos
public:

	Controladora(){inicioPrograma(); }
	void inicioPrograma();

// M�todos privados
private:

	void mensajeInicial();
	void mensajeFinal();

};
#endif // !CONTROLADORA_H

