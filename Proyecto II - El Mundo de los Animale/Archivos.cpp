// Archivos.cpp
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase archivos utilizados para el acceso 
//				a la información de datos, tanto de apertura, lectura como escritura y
//				modificacion de archivos con información nueva en el programa que se 
//				guardará como base de datos permanente del progrograma.

#include "Archivos.h"

// Método que se encarga de leer un archivo de texto con la información del
// árbol de busqueda de los animales.
fstream& Archivos::abrirArchivoLectura()
{
	//Apertura de archivo con la dirección del archivo de texto que se requiere abrir
	archivo.open(DIR_ARCHIVO_ARBOL, ios::in);
	return archivo;
}

// Método recursivo que realiza la lectura por linea del archivo de texto y
// va creando la informacion para ir acomodando en una estructura de arbol
void Archivos::obtenerInformacionArchivo(fstream& archivos, Nodo*& raiz)
{
	string lineaTxt;
	// Se obtiene los datos del archivo de texto mientras este sea diferente
	// al final del archivo, asi puede obtener leyendo linea por linea.
	if (!archivos.eof())
	{
		getline(archivos, lineaTxt); // Se obtinene linea del archivo
		cin.clear();// Se limpia la información para evitar un posible
		// error de datos basura.
	}
	else return; // Falso termina el ciclo y sale

	// Se verifica si la linea de texto es difente a $ (Caracter definido para 
	// separar la información e imitar la union de está como perteneciente a un nodo)
	if (lineaTxt != "$")
	{
		// Si la linea obtenida del archivo de texto  es diferente al caracter 
		// entonces se le su informacion a un nodo del arbol de busqueda animal
		raiz = new Nodo;
		raiz->dato = lineaTxt;
		// Se llama al método para que funcione de manera recursiva para que salve 
		// los datos obtenidos de forma de hijos del arbol, guardando datos en el nodo
		// izquierdo como el derecho.
		obtenerInformacionArchivo(archivos, raiz->izq);
		obtenerInformacionArchivo(archivos, raiz->der);
	}

	// Falso si no puede leer la información devolvera el valor de nodo 
	// raiz en nulo.
	else { raiz = NULL; }
}

// Método que se encarga de leer un archivo de tipo salida de datos
// que funciona de escritura del mismo.
fstream& Archivos::abrirArchivoEscrutura()
{
	//Apertura de archivo con la direccion del archivo de texto que se 
	//requiere abrir
	archivo.open(DIR_ARCHIVO_ARBOL, ios::out);
	return archivo;
}

// Método que se encarga de guardar la información del nuevo árbol de busqueda animal
// en un archivo de texto para que se actialice la base de datos del sistema.
void Archivos::guardaInformacion(Nodo*& raiz, fstream& archivoo)
{
	// Se verifica que si el nodo hijo actual es nulo entonces se escribira en el archivo
	// el caracter $ para que concatene el nodo con un identificador para guarda correctamente
	// el nuevo dato.
	if (raiz == NULL)
		archivoo <<"$"<<"\n";

	// Falso si el nodo ingresado posee información nueva entonces se salvan sus datos
	else
	{// Se obtiene el texto y se guarda en archivo
		archivoo << raiz->dato <<"\n";
		// Se guarda en orden de nodo izquierdo primero y luego derecho
		// recursivamente de está manera la pregunta y el nuevo animal quedaran
		// salvados correctamente.
		guardaInformacion(raiz->izq, archivoo);
		guardaInformacion(raiz->der, archivoo);
	}
}

// Método que cierra el archivo de texto abierto
void Archivos::cerrarArchivo(fstream& archivox)
{
	// Se cierra el archivo utilizado para manejar la información de texto.
	archivox.close();
}

// Método que busca la información de un archivo de texto indicado y 
// devuelve una respuesta verdadera o falsa si pudo acceder a la información
// sin problemas.
bool Archivos::verificarDatosArchivo()
{
	// Se declara el uso de la funcion stat para comprobar el estado correcto del archivo
	struct stat datosAmacenadosTxt;
	int estadoLectura = 0;
	// Se realiza realiza la comprobación mediante la función stat, para que se puede deter-
	// minar si en la dirección de archivo determinada, se puede acceder, escribir, o ejecutar
	// en la dirección del archivo solicitado.
	estadoLectura = stat(DIR_ARCHIVO_ARBOL, &datosAmacenadosTxt);
	// Si el estado es 0 significa que se ha encontrado datos en el archivo de 
	// texto indicado y que no existen problemas para acceder a la información del archivo
	// de texto.
	if (estadoLectura == 0) 
		return true;
	

return false;
}
