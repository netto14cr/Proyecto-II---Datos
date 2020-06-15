#include "Archivos.h"

// Método que se encarga de leer un archivo de texto con la información del
// árbol de busqueda de los animales.
fstream& Archivos::abrirArchivoEntrada()
{
	//Apertura de archivo con la direccion del archivo de texto que se requiere abrir
	archivo.open(DIR_ARCHIVO_ARBOL, ios::in);
	return archivo;
}

// Método recursivo que realiza la lectura por linea del archivo de texto y
// va creando la informacion para ir acomodando en una estructura de arbol
void Archivos::obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz)
{
	string lineaTxt;
	if (!archivo.eof())
	{
		getline(archivo, lineaTxt);
		cin.clear();
	}
	else return;
	if (lineaTxt != "#")
	{
		raiz = new Nodo;
		raiz->pregunta = lineaTxt;
		obtenerInformacionArchivo(archivo, raiz->izq);
		obtenerInformacionArchivo(archivo, raiz->der);
	}

	// Falso si no puede leer la información devolvera el valor de nodo 
	// raiz en nulo.
	else { raiz = NULL; }
}

// Método que se encarga de leer un archivo de tipo salida de datos
// que funciona de escritura del mismo.
fstream& Archivos::abrirArchivoSalida()
{
	//Apertura de archivo con la direccion del archivo de texto que se 
	//requiere abrir
	archivo.open(DIR_ARCHIVO_ARBOL, ios::out);
	return archivo;
}

// Método que se encarga de guardar la información del nuevo árbol de busqueda animal
// en un archivo de texto para que se actialice la base de datos del sistema.
void Archivos::guardaInformacion(Nodo*& raiz, fstream& archivo)
{
	if (raiz == NULL)
		archivo << "#" << "\n";
	else
	{
		archivo << raiz->pregunta << "\n";
		guardaInformacion(raiz->izq, archivo);
		guardaInformacion(raiz->der, archivo);
	}
}

// Método que cierra el archivo leido
void Archivos::cerrarArchivo(fstream& archivo)
{
	archivo.close();
}

// Método que busca la información de un archivo de texto indicado y 
// devuelve una respuesta verdadera o falsa si pudo acceder a la información
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
