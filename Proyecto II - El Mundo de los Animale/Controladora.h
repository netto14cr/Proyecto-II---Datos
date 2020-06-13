// Controladora.h
// Autor: Néstor Leiva Mora - 116080589
// Descripción: Define métodos de la clase Controladora utilizados para el control 
//				durante la ejecución del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <iostream>
#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase controladora
class Controladora{

// Métodos públicos
public:

	Controladora(){inicioPrograma(); }
	void inicioPrograma();

// Métodos privados
private:

	void mensajeInicial();
	void mensajeFinal();

};
#endif // !CONTROLADORA_H

