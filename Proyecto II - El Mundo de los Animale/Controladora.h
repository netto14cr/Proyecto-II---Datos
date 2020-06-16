// Controladora.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase Controladora utilizados para el control 
//				durante la ejecución del programa.

// Define el uso de esta clase en cualquier compilador
#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <iostream>
#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase Controladora
class Controladora{

// Métodos públicos
public:

	Controladora(){inicioPrograma(); }
	virtual ~Controladora(){}
	void inicioPrograma();

// Métodos privados
private:

	// Métodos que no retornan valor
	void mensajeInicial();
	void ejecutarPrograma();
	void mensajeFinal();
	// Metodo que retorna un valor
	bool verificaProgramaContinua();

};
#endif // !CONTROLADORA_H

