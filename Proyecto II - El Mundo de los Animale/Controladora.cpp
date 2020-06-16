// Controladora.cpp
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Implementa los m�todos de la clase Controladora utilizados
//			    controlar de manera eficiente todas las clases que tienen
//				relaci�n con la composici� del proyecto, permitiendo as� 
//				ejecutar el programa e interartuar con el usuario.

#include "Controladora.h"

Interfaz inter; // Delcaraci�n de la clase interfaz de uso global
ArbolBAnimal aBA; // Declaraci�n de uso de la clase arbol de b�squeda animal
Archivos ar; // Declaraci�n de uso de la clase archivos

// M�todo que controla el inicio del programa
void Controladora::inicioPrograma()
{
	// Se llama al m�todo que contiene la informaci�n inicial con instrucciones
	// e indicaci�nes para que sirva de gu�a al usuario de como usar el sistema
	mensajeInicial();
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
	if (ar.verificarDatosArchivo()) {
		// Se llama al m�todo que realiza la lectura de los datos en el archivo
		// de texto indicado y pasando el nodo para que transfiera la informaci�n
		// este.
		ar.obtenerInformacionArchivo(ar.abrirArchivoLectura(), aBA.getRaiz());
		// Se llama al m�todo que cierra el archivo ya que sus datos fueron leidos
		// correctamente.
		ar.cerrarArchivo(ar.abrirArchivoLectura());
		// Se llama al m�todo principal de arbol de b�squeda binaria aniamal para
		// que comience con el recorrido de la informaci�n y ej
		aBA.generarPreguntas(aBA.getRaiz(),NULL,inter);
		
		// Se realiza la verificaci�n de que se debe acceder a guardar datos
		// nuevos en el sistema
		// Si el el dato es true se procede a actualizar los datos
		if (aBA.getAceptaDatos()) {
			// Se guarda la informaci�n del �rbol previamente modificado y se
			// le indica el archivo utilizado para salvar los datos.
			ar.guardaInformacion(aBA.getRaiz(),ar.abrirArchivoEscrutura());
			// Se llama al m�todo que se encarga cerrar el archivo modificado.
			ar.cerrarArchivo(ar.abrirArchivoEscrutura());
		}

		// Se llama al m�todo que realiza la pregunta de si desea contianuar con
		// alguna otra b�squeda, esto una vez terminada la funci�n de adivinar
		// el animal que esta pensado,
		if (verificaProgramaContinua()) {
			// De sear verdadera la respuesta por parte del usuario se limpian los 
			// datos en pantalla y se vuelve a llamar al m�todo inicial que se est�
			// ejecutando en este momento para que reinicie todo su proceso y permita
			// al usuario contiuar con una nueva b�squeda en el sistema.
			inter.limpiarPantalla();
			ejecutarPrograma();
		}
		// Falso si la respuesta respuesta es falsa (NO) por parte del usuario se 
		// procede a dar la despedida del sistema y terminar la ejecuci�n del programa.
		else {
			mensajeFinal();
		}
	}
	// Falso termina el programa con un mensaje de error.
	else {
		inter.mensajeErrorLecturaArchivo();
	}
}

// M�todo que se encarga de verificar realizando una pregunta al usuario 
// si desea seguir ejecutando el programa, pedendiendo de la repuesta
// positiva o negativa sera el valor booleano que devolvera el m�todo.
bool Controladora::verificaProgramaContinua()
{
	string continuaUsuario; continuaUsuario = "";

	// Se realiza y captura la informaci�n de la pregunta si el usuario
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
	// en la pregunta, se le mostrar� el mensaje de error correspondiente y se 
	// le volver� a formular la pregunta repitiendo este en un ciclo hasta que 
	// responda correctamente.
	else {
		inter.limpiarPantalla();
		inter.mensajeErrorTeclaRespuesta();
		inter.eliminaCacheDatosEntrada();
		// Se vuelve a invocar al mismo m�todo altual para que vuelva a realizar
		// la verificaci�n.
		return verificaProgramaContinua();
	}
	return false;
}

// M�todo que realiza el llamado de los m�todos de la interfaz para mostrar
// los mensajes de ininicio del programa.
void Controladora::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

// M�todo que se encarga de mostrar un mensaje final cuando se tiene claro que ya
// es el final de ejecuci�n del mismo indicado por el usuario.
void Controladora::mensajeFinal()
{
	inter.mensajeDespedida();
}
