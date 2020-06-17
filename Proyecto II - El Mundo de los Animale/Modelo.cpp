// Modelo.cpp
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Implementa los m�todos de la clase Modelo utilizados para realizar el
//				manenjo y accedo a funciones con el resto de las clases involucradas 
//				durante el desarrollo, manejo, ejecuci�n del sistema y pueda asi funcionar
//				de una manera rapida y eficiente.

#include "Modelo.h"

Interfaz inter;  // Declaraci�n de la clase interfaz de uso global
ArbolBAnimal aBA;// Declaraci�n de uso de la clase arbol de b�squeda animal
Archivos ar;    // Declaraci�n de uso de la clase archivos


// M�todo que retorna un true o falso si al llamar al m�todo de comprobaci�n de archivos
// puede acceder o no a la informaci�n del archivo de texto solicitado.
bool Modelo::verificarDatosArchivo()
{
	return ar.verificarDatosArchivo();
}

// M�todo que se encarga de manejar la interacci� con la interfaz para mostrar un menaje 
// en pantalla para indicar que existe un error al leer el archivo de texto.
void Modelo::mensajeErrorLecturaArchivo()
{
	inter.mensajeErrorLecturaArchivo();
}

// M�todo que se encarga de relizar el llamado al m�todo de archivo para 
// acceder a la informaci�n de un archivo de texto y alamacenarla en el nodo del arbol binario.
void Modelo::obtenerInformacionArchivo()
{
	ar.obtenerInformacionArchivo(ar.abrirArchivoLectura(), aBA.getRaiz());
}

// M�todo que se encarga de llamar al m�todo de cerrar el archivo abierto recientemente de modo
// lectura y realizar un mejor manejo con de los archivos que utiliza el sistema.
void Modelo::cerrarArchivoLectura()
{
	ar.cerrarArchivo(ar.abrirArchivoLectura());
}

// M�todo que se encarga de interactuar con la clase arbol y poder asi realizar la funcion 
// del m�todo que realiza y da inicio al funcionamiento del programa de poder interartuar,
// realizar la busqueda de los animales y las caracter�sticas en forma de adivinanza con el
// usuario.
void Modelo::generarPreguntas()
{
	aBA.generarPreguntas(aBA.getRaiz(), NULL, inter);

}

// M�todo de tipo booleano que retorna un true o falso si la respuesta del programa al
// consultarle indica que se realizaron cambios en la informaci�n de la base del sistema.
bool Modelo::aceptaNuevosDatos()
{
	return aBA.getAceptaDatos();
}

void Modelo::guardaInformacion()
{
	ar.guardaInformacion(aBA.getRaiz(), ar.abrirArchivoEscrutura());
}

// M�todo que manena el llado del m�todo de cerrar el archivo abierto recientemente
// por el sistema de tipo escritura de datos para que asi pueda concluir la accion
// con este y los datos nuevos sean salvados correctamente.
void Modelo::cerrarArchivoEscritura()
{
	ar.cerrarArchivo(ar.abrirArchivoEscrutura());
}

// M�todo que se encarga de comprobar si despu�s del primer funcionamiento correcto con
// el usuario este pudo tener acceso a ingresar datos, y de ser as� entonces realiza el
// llamado de los m�todos de la clase archivo para alamacenar los nuevos datos.
void Modelo::verificaModificaci�nDatos()
{
	// Se realiza la verificaci�n de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
	if (aceptaNuevosDatos()) {
		// Se guarda la informaci�n del �rbol previamente modificado y se
		// le indica el archivo utilizado para salvar los datos.
		guardaInformacion();
		// Se llama al m�todo que se encarga cerrar el archivo modificado.
		cerrarArchivoEscritura();
	}
}


// M�todo que retorna un true o un falso si al llamar al m�otodo de interfaz que interactua
// con el usuario este �ltimo devuelve una respuesta de continuar ejecutando el programa o
// salir (Dependiendo de la respuesta negativa o positiva dle usuario este sera obtenido)
bool Modelo::verificaProgramaContinua()
{
	string continuaUsuario; continuaUsuario = "";

	// Se realiza y captura la informaci�n de la pregunta si el usuario
	// desea continuar ejecutando el programa.
	continuaUsuario = inter.preguntaContinuar();

	// Se verifica si la respuesta es positiva (SI) por parte del usuario
	// para enviar un valor verdadero.
	if (continuaUsuario == "SI" || continuaUsuario == "si" 
		|| continuaUsuario == "S" || continuaUsuario == "s") {
		return true;
	}
	// Se verifica si la respuesta es negativa (NO) por parte del usuario
	// para enviar un valor verdadero.
	else if (continuaUsuario == "NO" || continuaUsuario == "no"
		|| continuaUsuario == "N" || continuaUsuario == "n") {
		return false;
	}
	// Falso si el usuario digito otra letra o palabra distinta a la solicutada
	// en la pregunta, se le mostrar� el mensaje de error correspondiente y se 
	// le volver� a formular la pregunta repitiendo este en un ciclo hasta que 
	// responda correctamente.
	else {
		limpiarPantalla();
		inter.mensajeErrorTeclaRespuesta();
		inter.eliminaCacheDatosEntrada();
		// Se vuelve a invocar al mismo m�todo altual para que vuelva a realizar
		// la verificaci�n.
		return verificaProgramaContinua();
	}
	return false;
}

// M�todo que se encarga de interacturar con la funcion de la interfaz encargada de 
// limpiar los datos basuara mostrados por pantalla y asi poder actualizar de manera
// optima el contenido siguiente.
void Modelo::limpiarPantalla()
{
	inter.limpiarPantalla();
}

// M�todo que se encarga interartuar con los mensajes de bienevenida, descripci�n e instruccones
// de menera que se puedan mostrar e interactuen con el usuario al incio del programa.
void Modelo::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

// M�todo que se encarga de manejar el llamado del mensaje final de la interfaz y
// que est� se pueda mostrar en pantalla su mensaje al usuario.
void Modelo::mensajeFinal()
{
	inter.mensajeDespedida();
}
