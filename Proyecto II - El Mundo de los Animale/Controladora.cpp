#include "Controladora.h"

Interfaz inter;
ArbolBAnimal aBA;
Archivos ar;

// Método que controla el inicio del programa
void Controladora::inicioPrograma()
{
	mensajeInicial();
	Nodo* arbolAnimal=NULL;
	// Verifica que se pueda realizar la lectura del archivo de texto con la 
	// informacion del programa.
	if (ar.verificarDatosArchivo()) {
		aBA.obtenerInformacionArchivo(ar.leerArchivo, arbolAnimal);
	}
	// Falso termina el programa con un mensaje de error.
	else {

	}
	mensajeFinal();
}

// Método que realiza el llamado de los métodos de la interfaz para mostrar
// los mensajes de ininicio del programa.
void Controladora::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

void Controladora::mensajeFinal()
{
	inter.mensajeDespedida();
}
