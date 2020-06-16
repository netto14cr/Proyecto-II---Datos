// Controladora.cpp
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase Controladora utilizados
//			    controlar de manera eficiente todas las clases que tienen
//				relación con la composició del proyecto, permitiendo así 
//				ejecutar el programa e interartuar con el usuario.

#include "Controladora.h"
Modelo mod;

// Método que controla el inicio del programa
void Controladora::inicioPrograma()
{
	// Se llama al método que contiene la información inicial con instrucciones
	// e indicaciónes para que sirva de guía al usuario de como usar el sistema
	mod.mensajeInicial();
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
	if (mod.verificarDatosArchivo()) {
		// Se llama al método que realiza la lectura de los datos en el archivo
		// de texto indicado y pasando el nodo para que transfiera la información
		// este.
		mod.obtenerInformacionArchivo();
		
		// Se llama al método que cierra el archivo ya que sus datos fueron leidos
		// correctamente.
		mod.cerrarArchivoLectura();
		
		// Se llama al método principal de arbol de búsqueda binaria aniamal para
		// que comience con el recorrido de la información y ej
		mod.generarPreguntas();
		
		
		// Se realiza la verificación de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
		if (mod.aceptaNuevosDatos()) {
			// Se guarda la información del árbol previamente modificado y se
			// le indica el archivo utilizado para salvar los datos.
			mod.guardaInformacion();
			
			// Se llama al método que se encarga cerrar el archivo modificado.
			mod.cerrarArchivoEscritura();
			
		}

		// Se llama al método que realiza la pregunta de si desea contianuar con
		// alguna otra búsqueda, esto una vez terminada la función de adivinar
		// el animal que esta pensado,
		if (mod.verificaProgramaContinua()) {
			// De sear verdadera la respuesta por parte del usuario se limpian los 
			// datos en pantalla y se vuelve a llamar al método inicial que se está
			// ejecutando en este momento para que reinicie todo su proceso y permita
			// al usuario contiuar con una nueva búsqueda en el sistema.
			mod.limpiarPantalla();
			ejecutarPrograma();
		}
		// Falso si la respuesta respuesta es falsa (NO) por parte del usuario se 
		// procede a dar la despedida del sistema y terminar la ejecución del programa.
		else {
			mod.mensajeFinal();
		}
	}
	// Falso termina el programa con un mensaje de error.
	else {
		mod.mensajeErrorLecturaArchivo();
	}
}

