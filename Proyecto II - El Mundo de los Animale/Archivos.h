// Archivos.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase archivos utilizados para el acceso 
//				a la infomación de datos guardados que sirven como base del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// Se define la ruta de dos archivos de texto con informacion del arbol 
// de animales ( Estos se encuantran en una carpeta llamada Archivos).
// Direccion de archivo de prueba.
#define DIR_ARCHIVO_ARBOL "../Archivos/Arbol_Animal.txt" 
// Dirección de archivo original del enunciado.
#define DIR_ARCHIVO_ORIG "../Archivos/Original_Arbol_Animal.txt" 

#include<iostream>
#include<string>
#include<fstream>
#include "ArbolBusqAnimales.h"

// Declaración de funcion de libreria STD utilizada para manejo de archivos de texto.
using std::fstream;
using std::string;
using std::ios;

// Define la clase archivos
class Archivos {

// Métodos públicos
public:
	Archivos() {} // Constructor de la clase por defecto
	virtual ~Archivos(){} // Destructor de la clase 
	bool verificarDatosArchivo();
	fstream& abrirArchivoLectura();
	fstream& abrirArchivoEscrutura();
	void obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz);
	void guardaInformacion(Nodo*& raiz, fstream& archivo);
	void cerrarArchivo(fstream &archivo);
// Métodos privados
private:
	fstream archivo;
};

#endif // !ARCHIVOS_H