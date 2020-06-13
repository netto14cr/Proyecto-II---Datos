// Interfaz.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Define métodos de la clase Interfaz utilizados para mostrar los
//				mensajes mostrados al usuario durante la ejecucioón del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
// Declaración de funcion de libreria utilizada para imprirmir mensajes
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
	string preguntaAusuario(string dato);

// Métodos privados
private:
	void limpiairPantalla();
	void detenerActPantalla();

};
#endif // !INTERFAZ_H

