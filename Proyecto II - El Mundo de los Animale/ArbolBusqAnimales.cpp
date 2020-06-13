#include "ArbolBusqAnimales.h"

// Método recursivo que realiza la lectura por linea del archivo de texto y
// va creando la informacion para ir acomodando en una estructura de arbol
void ArbolBAnimal::obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz)
{
	string lineaTxt;
	if (!archivo.eof())
	{
		getline(archivo, lineaTxt);
		cin.clear();
	}
	else
		return;

	if (lineaTxt != "#")
	{
		raiz = new Nodo;
		raiz->pregunta = lineaTxt;
		obtenerInformacionArchivo(archivo, raiz->izq);
		obtenerInformacionArchivo(archivo, raiz->der);
	}
	else
	{
		raiz = NULL;
	}
}

// Método que se encarga de recorrer el arbol de busqueda animal e
// ir realizando preguntas al usuario con base a la información obtenida
// previamente del archivo de texto con la base de animales y sus caracteristicas.
void ArbolBAnimal::realizarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	string respuestaUsuario; respuestaUsuario ="";
	// system("color 0A");
	
	// Verifica que los hijos del nodo no sean nulos
	if (raiz->izq != NULL && raiz->der != NULL)
	{
		// Se le realiza una pregunta con la informacion del arbol y
		// se obtiene la respuesta de usuario.
		respuestaUsuario=inter.preguntaAusuario(raiz->pregunta);
		
		// Se verifica que el usuario haya respondido correctamente
		if (verificaRespuestaCorrecta(respuestaUsuario, raiz, anterior, inter)) {

		}
	}

	// QUEDE AQUI EN LA 50 DE ANIMALES
	else
	{
		//finalquestion(root, prev);
	}
}

// Método que se encarga de verificar que la respuesta enviada por el usuario
// sea una valida definida en las instrucciones en el inicio del programa.
bool ArbolBAnimal::verificaRespuestaCorrecta(string respuesta, Nodo* raizz, Nodo* anterior, Interfaz inter)
{

	if (respuesta == "SI" || respuesta == "S")
		realizarPreguntas(raizz->izq, raizz, inter);
	else if (respuesta == "NO" || respuesta == "N" )
		realizarPreguntas(raizz->der, raizz, inter);
	else
	{
		inter.mensajeErrorTeclaRespuesta();
		realizarPreguntas(raizz, anterior, inter);
	}
}
