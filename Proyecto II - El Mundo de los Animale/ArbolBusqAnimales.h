// Controladora.h
// Autor: N�stor Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase arbol de busqueda animal utilizados para recorrer 
//				el arbol de busqueda animal con la informacion referente de estos.


// Define el uso de esta clase en cualquier compilador
#ifndef ARBOLBUSQANIMALES_H
#define ARBOLBUSQANIMALES_H

#include <iostream>
#include <string>
#include "Archivos.h"
#include "Interfaz.h"

// Declaracion de uso de implementaciones de la libreria STD
using std::string;

// Define el struct para los nodos
 struct Nodo {
	string pregunta; // Declaraci�n dato tipo string que utiliza la estructura
	Nodo *izq; // Declaraci�n de hijo izquierdo de la estructura
	Nodo *der; // Declaraci�n de hijo derecho de la estructura
};

// Define la clase arbol de busqueda animal
class ArbolBAnimal {


// M�todos p�blicos
public:

	ArbolBAnimal() { inicializaNodos(); }

	// Metodo que devuelve la raiz del arbol animal
	Nodo* getRaiz() { return raiz; }
	bool getAceptaDatos() { return aceptaNDatos; }
	void obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz);
	void generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter);
	void adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter);
	void guardaInformacion(Nodo*& raiz, fstream& archivo);
	//void reordenaOrdenNodosNuevo(Nodo* raiz, Nodo* anterior, Nodo* nuevoNodoCaract);
	// M�todos privados
private:

	// Declaracion de nodos de la clase
	
	Nodo* raiz; 
	Nodo* crearNuevoNodo(Nodo* nuev);
	bool aceptaNDatos;
	void inicializaNodos();
	void ingresarNuevosDatos(Nodo* actual, Nodo* anterior, Interfaz inter);
	void restructuraDatosArbol(Nodo* actual, Nodo* anterior, string nuevoAnimal, 
		string nuevaCaract, Interfaz inter);
	void verificaRespuestaPregunta(string respuesta, Nodo* raiz, 
									Nodo* anterior, Interfaz inter);
	bool verificaRepuestaAnimal(string respuesta, Nodo* raiz, 
									Nodo* anterior, Interfaz inter);

	void reordenaOrdenNodosNuevo(Nodo* raiz, Nodo* anterior, Nodo* nuevoNodoCaract);
	void aceptaNuevosDatos(bool conf);

};


#endif // ARBOLBUSQANIMALES_H

