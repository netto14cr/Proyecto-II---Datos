// Modelo.h
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase Modelo utilizados para el manejo 
//				del programa durante su ejecuci�n.


// Define el uso de esta clase en cualquier compilador
#ifndef MODELO_H
#define MODELO_H

#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase Modelo
class Modelo {

	// M�todos p�blicos
public:
	Modelo() {}
	bool verificarDatosArchivo();
	void mensajeErrorLecturaArchivo();
	void obtenerInformacionArchivo();
	void cerrarArchivoLectura();
	void generarPreguntas();
	bool aceptaNuevosDatos();
	void guardaInformacion();
	void cerrarArchivoEscritura();
	bool verificaProgramaContinua();
	void limpiarPantalla();
	void mensajeInicial();
	void mensajeFinal();
	// M�todos privados
private:
};

#endif // !MODELO_H

