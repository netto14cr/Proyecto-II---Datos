// Controladora.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase arbol de busqueda animal utilizados para recorrer 
//				el arbol de busqueda animal con la informacion referente de estos.


// Define el uso de esta clase en cualquier compilador
#ifndef ARBOLBUSQANIMALES_H
#define ARBOLBUSQANIMALES_H

#include <iostream>
#include <string>
#include "Interfaz.h"

// Declaracion de uso de implementaciones de la libreria STD
using std::string;

// Define el struct para los nodos
 struct Nodo {
	string dato; // Declaración dato tipo string que utiliza la estructura
	Nodo *izq; // Declaración de hijo izquierdo de la estructura
	Nodo *der; // Declaración de hijo derecho de la estructura
};

// Define la clase Arbol de busqueda animal
class ArbolBAnimal {


// Métodos públicos
public:

	// Se define que el constructor por defecto inicialice valores automaticamente
	ArbolBAnimal() { inicializaNodo(); }
	virtual ~ArbolBAnimal(){}

	// Método que devuelve la raiz del árbol animal
	Nodo*& getRaiz() { return raiz; }
	bool getAceptaDatos() { return aceptaNDatos; }
	void generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter);
	void adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter);
	
	// Métodos privados
private:
	// Se define el nodo para el arbol binario de busqueda
	Nodo* raiz; 
	Nodo* crearNuevoNodo(Nodo* nuev);
	bool aceptaNDatos;
	void inicializaNodo();
	void ingresarNuevosDatos(Nodo* actual, Nodo* anterior, Interfaz inter);
	void restructuraDatosArbol(Nodo* actual, Nodo* anterior, string nuevoAnimal, 
		string nuevaCaract, Interfaz inter);
	void verificaRespuestaPregunta(string respuesta, Nodo* raiz, 
									Nodo* anterior, Interfaz inter);
	void verificaRepuestaAnimal(string respuesta, Nodo* raiz, 
									Nodo* anterior, Interfaz inter);

	void reordenaOrdenNodosNuevo(Nodo* raiz, Nodo* anterior, Nodo* nuevoNodoCaract);
	void aceptaNuevosDatos(bool conf);

};

#endif // ARBOLBUSQANIMALES_H

