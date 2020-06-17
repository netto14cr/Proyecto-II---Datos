// Modelo.cpp
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase Modelo utilizados para realizar el
//				manenjo y accedo a funciones con el resto de las clases involucradas 
//				durante el desarrollo, manejo, ejecución del sistema y pueda asi funcionar
//				de una manera rapida y eficiente.

#include "Modelo.h"

Interfaz inter;  // Declaración de la clase interfaz de uso global
ArbolBAnimal aBA;// Declaración de uso de la clase arbol de búsqueda animal
Archivos ar;    // Declaración de uso de la clase archivos


// Método que retorna un true o falso si al llamar al método de comprobación de archivos
// puede acceder o no a la información del archivo de texto solicitado.
bool Modelo::verificarDatosArchivo()
{
	return ar.verificarDatosArchivo();
}

// Método que se encarga de manejar la interacció con la interfaz para mostrar un menaje 
// en pantalla para indicar que existe un error al leer el archivo de texto.
void Modelo::mensajeErrorLecturaArchivo()
{
	inter.mensajeErrorLecturaArchivo();
}

// Método que se encarga de relizar el llamado al método de archivo para 
// acceder a la información de un archivo de texto y alamacenarla en el nodo del arbol binario.
void Modelo::obtenerInformacionArchivo()
{
	ar.obtenerInformacionArchivo(ar.abrirArchivoLectura(), aBA.getRaiz());
}

// Método que se encarga de llamar al método de cerrar el archivo abierto recientemente de modo
// lectura y realizar un mejor manejo con de los archivos que utiliza el sistema.
void Modelo::cerrarArchivoLectura()
{
	ar.cerrarArchivo(ar.abrirArchivoLectura());
}

// Método que se encarga de interactuar con la clase arbol y poder asi realizar la funcion 
// del método que realiza y da inicio al funcionamiento del programa de poder interartuar,
// realizar la busqueda de los animales y las características en forma de adivinanza con el
// usuario.
void Modelo::generarPreguntas()
{
	aBA.generarPreguntas(aBA.getRaiz(), NULL, inter);

}

// Método de tipo booleano que retorna un true o falso si la respuesta del programa al
// consultarle indica que se realizaron cambios en la información de la base del sistema.
bool Modelo::aceptaNuevosDatos()
{
	return aBA.getAceptaDatos();
}

void Modelo::guardaInformacion()
{
	ar.guardaInformacion(aBA.getRaiz(), ar.abrirArchivoEscrutura());
}

// Método que manena el llado del método de cerrar el archivo abierto recientemente
// por el sistema de tipo escritura de datos para que asi pueda concluir la accion
// con este y los datos nuevos sean salvados correctamente.
void Modelo::cerrarArchivoEscritura()
{
	ar.cerrarArchivo(ar.abrirArchivoEscrutura());
}

// Método que se encarga de comprobar si después del primer funcionamiento correcto con
// el usuario este pudo tener acceso a ingresar datos, y de ser así entonces realiza el
// llamado de los métodos de la clase archivo para alamacenar los nuevos datos.
void Modelo::verificaModificaciónDatos()
{
	// Se realiza la verificación de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
	if (aceptaNuevosDatos()) {
		// Se guarda la información del árbol previamente modificado y se
		// le indica el archivo utilizado para salvar los datos.
		guardaInformacion();
		// Se llama al método que se encarga cerrar el archivo modificado.
		cerrarArchivoEscritura();
	}
}


// Método que retorna un true o un falso si al llamar al méotodo de interfaz que interactua
// con el usuario este último devuelve una respuesta de continuar ejecutando el programa o
// salir (Dependiendo de la respuesta negativa o positiva dle usuario este sera obtenido)
bool Modelo::verificaProgramaContinua()
{
	string continuaUsuario; continuaUsuario = "";

	// Se realiza y captura la información de la pregunta si el usuario
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

// Método que se encarga de interacturar con la funcion de la interfaz encargada de 
// limpiar los datos basuara mostrados por pantalla y asi poder actualizar de manera
// optima el contenido siguiente.
void Modelo::limpiarPantalla()
{
	inter.limpiarPantalla();
}

// Método que se encarga interartuar con los mensajes de bienevenida, descripción e instruccones
// de menera que se puedan mostrar e interactuen con el usuario al incio del programa.
void Modelo::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

// Método que se encarga de manejar el llamado del mensaje final de la interfaz y
// que está se pueda mostrar en pantalla su mensaje al usuario.
void Modelo::mensajeFinal()
{
	inter.mensajeDespedida();
}
