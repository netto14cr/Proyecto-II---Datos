#include "Controladora.h"

Interfaz inter; // Delcaración de la clase interfaz de uso global

// Método que controla el inicio del programa
void Controladora::inicioPrograma()
{
	ArbolBAnimal aBA; // Declaracion de uso de la clase arbol de busqueda animal
	Archivos ar; // Declaración de uso de la clase archivos
	Nodo* principal;
	mensajeInicial();
	// Verifica que se pueda realizar la lectura del archivo de texto con la 
	// informacion del programa.
	if (ar.verificarDatosArchivo()) {
		fstream archivo = ar.leerArchivo();
		principal = aBA.getRaiz();
		aBA.obtenerInformacionArchivo(archivo, principal);
		aBA.generarPreguntas(principal,NULL, inter);
		
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
