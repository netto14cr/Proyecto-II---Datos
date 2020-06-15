// Archivos.h
// Autor: N�stor Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase archivos utilizados para el acceso 
//				a la infomaci�n de datos guardados que sirven como base del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// Se define la ruta de dos archivos de texto con informacion del arbol de animales.
// Direccion de archivo de prueba.
#define DIR_ARCHIVO_ARBOL "Arbol_Animal.txt" 
// Direcci�n de archivo original del enunciado.
#define DIR_ARCHIVO_ORIG "Original_Arbol_Animal.txt" 

#include<iostream>
#include<string>
#include<fstream>

using std::fstream;
using std::string;
using std::ios;
using std::cin;

// Define la clase archivos
class Archivos {

// M�todos p�blicos
public:

	Archivos() {}
	bool verificarDatosArchivo();
	fstream abrirArchivoEntrada();
	fstream abrirArchivoSalida();
	void cerrarArchivo(fstream &archivo);

// M�todos privados
private:
	
};

#endif // !ARCHIVOS_H