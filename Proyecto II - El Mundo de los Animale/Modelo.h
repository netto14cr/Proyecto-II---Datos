// Modelo.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase Modelo utilizados para el manejo 
//				del programa durante su ejecución.


// Define el uso de esta clase en cualquier compilador
#ifndef MODELO_H
#define MODELO_H

#include "Interfaz.h"
#include "ArbolBusqAnimales.h"
#include "Archivos.h"

// Define la clase Modelo
class Modelo {

	// Métodos públicos
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
	// Métodos privados
private:
};

#endif // !MODELO_H

