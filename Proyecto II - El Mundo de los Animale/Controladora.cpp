// Controladora.cpp
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase Controladora utilizados
//			    controlar de manera eficiente todas las clases que tienen
//				relación con la composició del proyecto, permitiendo así 
//				ejecutar el programa e interartuar con el usuario.

#include "Controladora.h"

Interfaz inter; // Delcaración de la clase interfaz de uso global
ArbolBAnimal aBA; // Declaración de uso de la clase arbol de búsqueda animal
Archivos ar; // Declaración de uso de la clase archivos

// Método que controla el inicio del programa
void Controladora::inicioPrograma()
{
	// Se llama al método que contiene la información inicial con instrucciones
	// e indicaciónes para que sirva de guía al usuario de como usar el sistema
	mensajeInicial();
	// Después se procede a llamar al método que controlara el inicio y ejecución
	// del programa durante todo el tiempo que este se este ejecutando.
	ejecutarPrograma();
}

// Método que se encarga de ejecutar y mantener el programa mientras
// el usuario utiliza el sistema.
void Controladora::ejecutarPrograma()
{
	// Verifica que se pueda realizar la lectura del archivo de texto con la 
	// informacion del programa.
	if (ar.verificarDatosArchivo()) {
		// Se llama al método que realiza la lectura de los datos en el archivo
		// de texto indicado y pasando el nodo para que transfiera la información
		// este.
		ar.obtenerInformacionArchivo(ar.abrirArchivoLectura(), aBA.getRaiz());
		// Se llama al método que cierra el archivo ya que sus datos fueron leidos
		// correctamente.
		ar.cerrarArchivo(ar.abrirArchivoLectura());
		// Se llama al método principal de arbol de búsqueda binaria aniamal para
		// que comience con el recorrido de la información y ej
		aBA.generarPreguntas(aBA.getRaiz(),NULL,inter);
		
		// Se realiza la verificación de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
		if (aBA.getAceptaDatos()) {
			// Se guarda la información del árbol previamente modificado y se
			// le indica el archivo utilizado para salvar los datos.
			ar.guardaInformacion(aBA.getRaiz(),ar.abrirArchivoEscrutura());
			// Se llama al método que se encarga cerrar el archivo modificado.
			ar.cerrarArchivo(ar.abrirArchivoEscrutura());
		}

		// Se llama al método que realiza la pregunta de si desea contianuar con
		// alguna otra búsqueda, esto una vez terminada la función de adivinar
		// el animal que esta pensado,
		if (verificaProgramaContinua()) {
			// De sear verdadera la respuesta por parte del usuario se limpian los 
			// datos en pantalla y se vuelve a llamar al método inicial que se está
			// ejecutando en este momento para que reinicie todo su proceso y permita
			// al usuario contiuar con una nueva búsqueda en el sistema.
			inter.limpiarPantalla();
			ejecutarPrograma();
		}
		// Falso si la respuesta respuesta es falsa (NO) por parte del usuario se 
		// procede a dar la despedida del sistema y terminar la ejecución del programa.
		else {
			mensajeFinal();
		}
	}
	// Falso termina el programa con un mensaje de error.
	else {
		inter.mensajeErrorLecturaArchivo();
	}
}

// Método que se encarga de verificar realizando una pregunta al usuario 
// si desea seguir ejecutando el programa, pedendiendo de la repuesta
// positiva o negativa sera el valor booleano que devolvera el método.
bool Controladora::verificaProgramaContinua()
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
		inter.limpiarPantalla();
		inter.mensajeErrorTeclaRespuesta();
		inter.eliminaCacheDatosEntrada();
		// Se vuelve a invocar al mismo método altual para que vuelva a realizar
		// la verificación.
		return verificaProgramaContinua();
	}
	return false;
}

// Método que realiza el llamado de los métodos de la interfaz para mostrar
// los mensajes de ininicio del programa.
void Controladora::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

// Método que se encarga de mostrar un mensaje final cuando se tiene claro que ya
// es el final de ejecución del mismo indicado por el usuario.
void Controladora::mensajeFinal()
{
	inter.mensajeDespedida();
}
