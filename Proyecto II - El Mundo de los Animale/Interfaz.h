// Interfaz.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase Interfaz utilizados para mostrar los
//				mensajes mostrados al usuario durante la ejecucioón del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
// Declaración de funcion de libreria STD utilizada para imprirmir mensajes
using std::cout;
using std::string;
using std::cin;

// Define la clase interfaz
class Interfaz {

// Métodos públicos
public:
	void mensajeErrorTeclaRespuesta();
	void mensajeBienvenida();
	void mensajeDescripcion();
	void mensajeInstrucciones();
	void mensajeDespedida();
	void mensajeAnimalAdivinado();
	void mensajeAnimalNoAdivinado();
	void eliminaCacheDatosEntrada();
	void limpiarPantalla();
	void mensajeErrorLecturaArchivo();
	string preguntaAusuario(string dato);
	string preguntaAnimal(string dato);
	string preguntaNuevoAnimal();
	string preguntaNuevaCaracteristica();
	string preguntaContinuar();

// Métodos privados
private:
	void detenerActPantalla();
};
#endif // !INTERFAZ_H

