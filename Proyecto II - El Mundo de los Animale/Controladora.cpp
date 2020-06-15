#include "Controladora.h"

Interfaz inter; // Delcaración de la clase interfaz de uso global
ArbolBAnimal aBA; // Declaracion de uso de la clase arbol de busqueda animal
Archivos ar; // Declaración de uso de la clase archivos

// Método que controla el inicio del programa
void Controladora::inicioPrograma()
{
	mensajeInicial();
	ejecutarPrograma();
}

// Método que realiza el llamado de los métodos de la interfaz para mostrar
// los mensajes de ininicio del programa.
void Controladora::mensajeInicial()
{
	inter.mensajeBienvenida();
	inter.mensajeDescripcion();
	inter.mensajeInstrucciones();
}

// Método que se encarga de ejecutar y mantener el programa minetras
// el usuario utiliza el sistema.
void Controladora::ejecutarPrograma()
{
	Nodo* principal;
	// Verifica que se pueda realizar la lectura del archivo de texto con la 
	// informacion del programa.
	if (ar.verificarDatosArchivo()) {
		fstream archivo = ar.abrirArchivoEntrada();
		principal = aBA.getRaiz();
		aBA.obtenerInformacionArchivo(archivo, principal);
		ar.cerrarArchivo(archivo);
		aBA.generarPreguntas(principal, NULL, inter);
		if (aBA.getAceptaDatos()) {
			cout << "\n---ACEPTA DATOS NUEVOS !!2 ----\n";
			archivo = ar.abrirArchivoSalida();
			aBA.guardaInformacion(principal, archivo);
			ar.cerrarArchivo(archivo);
		}

		if (verificaProgramaContinua()) {
			inter.limpiairPantalla();
			ejecutarPrograma();
		}
		else {
			mensajeFinal();
		}
		
	}
	// Falso termina el programa con un mensaje de error.
	else {
		cout << "\nERROR LECTURA ARCHIVO\n";
		
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
		inter.limpiairPantalla();
		inter.mensajeErrorTeclaRespuesta();
		inter.eliminaCacheDatosEntrada();
		// se vuelve a invocar al mismo método altual para que vuelva a realizar
		// la verificación.
		return verificaProgramaContinua();
	}

	return false;
}

// Metodo que se encarga de mostrar un mensaje final cuando se tiene claro que ya
// es el final de ejecución del mismo indicado por el usuario.
void Controladora::mensajeFinal()
{
	inter.mensajeDespedida();
}
