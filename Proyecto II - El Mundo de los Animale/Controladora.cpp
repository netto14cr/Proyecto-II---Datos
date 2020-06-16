// Controladora.cpp
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Implementa los m�todos de la clase Controladora utilizados
//			    controlar de manera eficiente todas las clases que tienen
//				relaci�n con la composici� del proyecto, permitiendo as� 
//				ejecutar el programa e interartuar con el usuario.

#include "Controladora.h"
Modelo mod;

// M�todo que controla el inicio del programa
void Controladora::inicioPrograma()
{
	// Se llama al m�todo que contiene la informaci�n inicial con instrucciones
	// e indicaci�nes para que sirva de gu�a al usuario de como usar el sistema
	mod.mensajeInicial();
	// Despu�s se procede a llamar al m�todo que controlara el inicio y ejecuci�n
	// del programa durante todo el tiempo que este se este ejecutando.
	ejecutarPrograma();
}

// M�todo que se encarga de ejecutar y mantener el programa mientras
// el usuario utiliza el sistema.
void Controladora::ejecutarPrograma()
{
	// Verifica que se pueda realizar la lectura del archivo de texto con la 
	// informacion del programa.
	if (mod.verificarDatosArchivo()) {
		// Se llama al m�todo que realiza la lectura de los datos en el archivo
		// de texto indicado y pasando el nodo para que transfiera la informaci�n
		// este.
		mod.obtenerInformacionArchivo();
		
		// Se llama al m�todo que cierra el archivo ya que sus datos fueron leidos
		// correctamente.
		mod.cerrarArchivoLectura();
		
		// Se llama al m�todo principal de arbol de b�squeda binaria aniamal para
		// que comience con el recorrido de la informaci�n y ej
		mod.generarPreguntas();
		
		
		// Se realiza la verificaci�n de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
		if (mod.aceptaNuevosDatos()) {
			// Se guarda la informaci�n del �rbol previamente modificado y se
			// le indica el archivo utilizado para salvar los datos.
			mod.guardaInformacion();
			
			// Se llama al m�todo que se encarga cerrar el archivo modificado.
			mod.cerrarArchivoEscritura();
			
		}

		// Se llama al m�todo que realiza la pregunta de si desea contianuar con
		// alguna otra b�squeda, esto una vez terminada la funci�n de adivinar
		// el animal que esta pensado,
		if (mod.verificaProgramaContinua()) {
			// De sear verdadera la respuesta por parte del usuario se limpian los 
			// datos en pantalla y se vuelve a llamar al m�todo inicial que se est�
			// ejecutando en este momento para que reinicie todo su proceso y permita
			// al usuario contiuar con una nueva b�squeda en el sistema.
			mod.limpiarPantalla();
			ejecutarPrograma();
		}
		// Falso si la respuesta respuesta es falsa (NO) por parte del usuario se 
		// procede a dar la despedida del sistema y terminar la ejecuci�n del programa.
		else {
			mod.mensajeFinal();
		}
	}
	// Falso termina el programa con un mensaje de error.
	else {
		mod.mensajeErrorLecturaArchivo();
	}
}

