#include "Modelo.h"
Interfaz inter; // Delcaración de la clase interfaz de uso global
ArbolBAnimal aBA; // Declaración de uso de la clase arbol de búsqueda animal
Archivos ar; // Declaración de uso de la clase archivos

bool Modelo::verificarDatosArchivo()
{
	return ar.verificarDatosArchivo();
}

void Modelo::mensajeErrorLecturaArchivo()
{
	inter.mensajeErrorLecturaArchivo();
}

void Modelo::obtenerInformacionArchivo()
{
	ar.obtenerInformacionArchivo(ar.abrirArchivoLectura(), aBA.getRaiz());
}

void Modelo::cerrarArchivoLectura()
{
	ar.cerrarArchivo(ar.abrirArchivoLectura());
}

void Modelo::generarPreguntas()
{
	aBA.generarPreguntas(aBA.getRaiz(), NULL, inter);
}

bool Modelo::aceptaNuevosDatos()
{
	return aBA.getAceptaDatos();
}

void Modelo::guardaInformacion()
{
	ar.guardaInformacion(aBA.getRaiz(), ar.abrirArchivoEscrutura());
}

void Modelo::cerrarArchivoEscritura()
{
	ar.cerrarArchivo(ar.abrirArchivoEscrutura());
}

bool Modelo::verificaProgramaContinua()
{
	string continuaUsuario; continuaUsuario = "";

	// Se realiza y captura la información de la pregunta si el usuario
	// desea continuar ejecutando el programa.
	continuaUsuario = inter.preguntaContinuar();

	// Se verifica si la respuesta es positiva (SI) por parte del usuario
	// para enviar un valor verdadero.
	if (continuaUsuario == "SI" || continuaUsuario == "S") {
		return true;
	}
	// Se verifica si la respuesta es negativa (NO) por parte del usuario
	// para enviar un valor verdadero.
	else if (continuaUsuario == "NO" || continuaUsuario == "N") {
		return false;
	}
	// Falso si el usuario digito otra letra o palabra distinta a la solicutada
	// en la pregunta, se le mostrará el mensaje de error correspondiente y se 
	// le volverá a formular la pregunta repitiendo este en un ciclo hasta que 
	// responda correctamente.
	else {
		limpiarPantalla();
		inter.mensajeErrorTeclaRespuesta();
		inter.eliminaCacheDatosEntrada();
		// Se vuelve a invocar al mismo método altual para que vuelva a realizar
		// la verificación.
		return verificaProgramaContinua();
	}
	return false;
}

void Modelo::limpiarPantalla()
{
	inter.limpiarPantalla();
}

void Modelo::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

void Modelo::mensajeFinal()
{
	inter.mensajeDespedida();
}
