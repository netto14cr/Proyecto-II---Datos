// Controladora.h
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase Controladora utilizados para el control 
//				durante la ejecuci�n del programa.

// Define el uso de esta clase en cualquier compilador
#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <iostream>
#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase Controladora
class Controladora{

// M�todos p�blicos
public:

	Controladora(){inicioPrograma(); }
	virtual ~Controladora(){}
	void inicioPrograma();

// M�todos privados
private:

	// M�todos que no retornan valor
	void mensajeInicial();
	void ejecutarPrograma();
	void mensajeFinal();
	// Metodo que retorna un valor
	bool verificaProgramaContinua();

};
#endif // !CONTROLADORA_H

