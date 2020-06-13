// Controladora.h
// Autor: Néstor Leiva Mora - 116080589
// Descripción: Define métodos de la clase arbol de busqueda animal utilizados para recorrer 
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
	string pregunta; // Declaración de dato tipo string que maneja la estructura
	struct Nodo *izq; // Declaración de hijo izquierdo de la estructura
	struct Nodo *der; // Declaración de hijo derecho de la estructura
};



// Define la clase arbol de busqueda animal
class ArbolBAnimal {


// Métodos públicos
public:
	// Metodo que devuelve la raiz del arbol animal
	Nodo* getRaiz() { return raiz; }
	void obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz);
	void realizarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter);

	// Métodos privados
private:

	// Declaracion de nodos de la clase
	Nodo* nuevo;
	Nodo* raiz; 
	Nodo* inicio;
	bool verificaRespuestaCorrecta(string respesta, Nodo* raiz, Nodo* anterior, Interfaz inter);
};


#endif // ARBOLBUSQANIMALES_H

