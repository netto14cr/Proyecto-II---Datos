#include "Archivos.h"



// M�todo que se encarga de leer un archivo de texto con la informaci�n del
// �rbol de busqueda de los animales.
fstream Archivos::leerArchivo()
{
	fstream archivo; // Declaracion de vaiable para lectura archivo
	//Apertura de archivo con la direccion del archivo de texto que se requiere abrir
	archivo.open(DIR_ARCHIVO_ARBOL, ios::in);
	return archivo;
}

// M�todo que cierra el archivo leido
void Archivos::cerrarArchivo(fstream archivo)
{
	archivo.close();
}


// M�todo que busca la informaci�n de un archivo de texto indicado y 
// devuelve una respuesta verdadera o falsa si pudo acceder a la informaci�n
// sin problemas.
bool Archivos::verificarDatosArchivo()
{
	struct stat datosAmacenadosTxt;
	int estadoLectura = 0;
	estadoLectura = stat(DIR_ARCHIVO_ARBOL, &datosAmacenadosTxt);
	// Si el estado es 0 significa que se ha encontrado datos en el archivo de 
	// texto indicado
	if (estadoLectura == 0) {
		return true;
	}
		
return false;
}
