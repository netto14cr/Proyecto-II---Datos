// Interfaz.h
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Define m�todos de la clase Interfaz utilizados para mostrar los
//				mensajes mostrados al usuario durante la ejecucio�n del programa.


// Define el uso de esta clase en cualquier compilador
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
// Declaraci�n de funcion de libreria utilizada para imprirmir mensajes
using std::cout;
using std::string;
using std::cin;

// Define la clase interfaz
class Interfaz {

// M�todos p�blicos
public:
	void mensajeErrorTeclaRespuesta();
	void mensajeBienvenida();
	void mensajeDescripcion();
	void mensajeInstrucciones();
	void mensajeDespedida();
	string preguntaAusuario(string dato);

// M�todos privados
private:
	void limpiairPantalla();
	void detenerActPantalla();

};
#endif // !INTERFAZ_H

