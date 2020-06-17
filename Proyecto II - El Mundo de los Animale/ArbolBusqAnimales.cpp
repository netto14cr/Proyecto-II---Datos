// ArbolBusqAnimales.cpp
// Autor: N�stor David Leiva Mora - 116080589
// Descripci�n: Implementa los m�todos de la clase �rbol de b�squeda animal, estos sirven
//				para realizar b�squedas de informaci�n en el �rbol de b�squeda animal.

#include "ArbolBusqAnimales.h"

// M�todo que se encarga de recorrer el �rbol de b�squeda animal e
// ir realizando preguntas al usuario con base a la informaci�n obtenida
// previamente del archivo de texto con la base de animales y sus caracter�sticas.
void ArbolBAnimal::generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	// Se declara una variable auxiliar para manejar las respuesta por pate del
	// usuario
	string respuestaUsuario; respuestaUsuario ="";
	
	// Verifica que pueda recorrer los nodos del �rbol izquierdos y drechos
	// para realizar preguntas sobre carasteristicas de los animales.
	if (raiz->izq != NULL && raiz->der != NULL)
	{
		// Se le realiza una pregunta con la informaci�n del �rbol y
		// se obtiene la respuesta de usuario.
		respuestaUsuario=inter.preguntaAusuario(raiz->dato);
		// Se verifica que el usuario haya respondido correctamente
		verificaRespuestaPregunta(respuestaUsuario, raiz, anterior, inter);
	}
	// Falso si se termina de recorrer la informacion de los nodos hijos del 
	// �rbol entonces se realiza el llamado del m�todo adivinar animal para 
	// preguntar al usuario el animal que est� pensando e intentar adivinarlo.
	else
	{
		adivinarAnimal(raiz, anterior, inter);
	}
}

// M�todo que realiza la acci�n de adivinar el animal que cumple con
// las caracter�sticas de las respuestas del usuario y con la informaci�n
// de la base de datos.
void ArbolBAnimal::adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	// Declaraci�n de variable auxiliar para alamcenar la respuesta del usuario
	string respuestaUsuario; respuestaUsuario = "";
	respuestaUsuario=inter.preguntaAnimal(raiz->dato);
	// Se llama al m�todo que se encarga de verificar la repuesta
	verificaRepuestaAnimal(respuestaUsuario, raiz, anterior, inter);
}
// M�todo que crea e inicializa en NULL un nodo ingresado en expecifico.
Nodo* ArbolBAnimal::crearNuevoNodo(Nodo* nuevoAux)
{
	nuevoAux = new Nodo;
	nuevoAux = NULL;
	return nuevoAux;
}

// M�todo que se encarga de inicializar los valores de los nodos
void ArbolBAnimal::inicializaNodo()
{
	raiz = NULL; // Se incializa el nodo a NULL
}

// M�todo que se encarga de preguntar al usuario los datos del animal que
// estaba pensando, que ser�n utilizados despu�s para actualiar la base de
// datos del sistema.
void ArbolBAnimal::ingresarNuevosDatos(Nodo* actual, Nodo* anterior, Interfaz inter)
{
	// Se declaran variable para alamacenar los datos del nuevo animal y
	// tambi�n su pregunta caracter�stica.
	string respuestaNuevoAnimal; respuestaNuevoAnimal = "";
	string respNuevaCaracteristica; respNuevaCaracteristica = "";
	respuestaNuevoAnimal = inter.preguntaNuevoAnimal();
	respNuevaCaracteristica = inter.preguntaNuevaCaracteristica();
	// Se llama al m�todo que se encarga de acomodar correctemente 
	// los datos nuevos y anteriores de acuerdo a la lectura en el
	// �ltimo nodo visitado y el anterior.
	restructuraDatosArbol(actual, anterior, respuestaNuevoAnimal,
							respNuevaCaracteristica, inter);
}

// M�todo que se encarga de restructuras de datos nuevos en �rbol de b�squeda
// animal con base al recorrido y las respuestas del con los nuevos datos
// ingresados por el usuario.
void ArbolBAnimal::restructuraDatosArbol(Nodo* actual, Nodo* anterior,
	string nuevoAnimal,string nuevaCaract, Interfaz inter)
{
	// Se define nodos para el nuevo animal y la nueva caracter�sitica
	Nodo* nuevoNodoAnimal; nuevoNodoAnimal = new Nodo; 
	Nodo* nuevoNodoCaract; nuevoNodoCaract = new Nodo;
	// se agrega el nuevo animal al nodo
	nuevoNodoAnimal->dato = nuevoAnimal;
	nuevoNodoAnimal->izq=NULL;
	nuevoNodoAnimal->der= NULL;
	// Se agrega la nueva caracter�stica de tipo pregunta al animal.
	nuevoNodoCaract->dato = nuevaCaract;
	// Se define la relaci�n del animal en el nodo izquierdo de la caracter�stica.
	nuevoNodoCaract->izq = nuevoNodoAnimal;
	// Se recoloca el dato del �ltimo recorrido y se coloca en el hijo derecho.
	nuevoNodoCaract->der = actual;
	// Se llama al m�todo encargado de verificar la ubicaci�n de la �ltima pregunta
	// para reacomodar la nueva caracter�stica del animal en el �rbol b�squeda animal.
	reordenaOrdenNodosNuevo(actual, anterior, nuevoNodoCaract);
}

// M�todo que se encarga de verificar que la respuesta enviada por el usuario
// sea una valida definida en las instrucciones en el inicio del programa.
void ArbolBAnimal::verificaRespuestaPregunta(string respuesta, Nodo* raiz, 
	Nodo* anterior, Interfaz inter)
{
	// Se verifica que el usuario haya ingresado la respuesta de SI correctamente.
	if (respuesta == "SI" || respuesta == "si"
		|| respuesta=="S" || respuesta =="s")
		generarPreguntas(raiz->izq, raiz, inter);
	// Falso es diferente a SI la respuesta entonces se verifica de nuevo la respuesta.
	else
	{	// Se verifica si el usuario ingreso la opcion de NO.
		if (respuesta == "NO" || respuesta == "no"
			|| respuesta=="N" || respuesta=="n")
			generarPreguntas(raiz->der, raiz, inter);
		// Falso si el usuario ingresa una respuesta diferente a la indicada 
		// entonces es una accion equeivocada por lo que se le mostrar el mensaje
		// de error correspondiente y se volvera a repetir el la pregunta.
		else
		{
			inter.mensajeErrorTeclaRespuesta();
			generarPreguntas(raiz, anterior, inter);
		}
	}
}

// M�todo que se encarga de verificar la repuesta
void ArbolBAnimal::verificaRepuestaAnimal(string respuesta, Nodo* raiz,
	Nodo* anterior, Interfaz inter)
{
	// Si respuesta es positiva (SI) entonces el sistema adivino el animal
	// y muestra el mensaje que el usuario acierto.
	if (respuesta == "SI" || respuesta == "si"
		|| respuesta == "S" || respuesta == "s")
	{
		// Muestra mensaje que usuario ha adivinado el animal.
		inter.mensajeAnimalAdivinado(); 
		aceptaNuevosDatos(false);
	}
	
	// Falso entonces se contianua verificando la respuesta.
	else
	{
		// Falso si la respuesta es NO entonces muestra el mensaje que perdio y
		// adem�s llama al m�todo para restructuras la base de datos del �rbol,
		// permitiendo expandir su conocimiento con datos que le proporcione el
		// usuario.
		if (respuesta == "NO" || respuesta == "no"
			|| respuesta == "N" || respuesta == "n")
		{
			inter.mensajeAnimalNoAdivinado();
			ingresarNuevosDatos(raiz, anterior, inter);
		}
		// Falso si el usuario ingreasa un valor no valido se le muestra un mensaje 
		// de error y se le vuelve a preguntar.
		else {
			inter.mensajeErrorTeclaRespuesta();
			adivinarAnimal(raiz, anterior, inter);
		}
	}
}

// M�todo que encarga de verificar la posicion de la ultima pregunta en el ultimo 
// nodo reacomodando la pregunta tipo caracter�stica nueva ingresada por el usuario
// en el nodo correspondiente.
void ArbolBAnimal::reordenaOrdenNodosNuevo(Nodo* raiz, Nodo* anterior, 
	Nodo* nuevoNodoCaract)
{
	// Se verifica que la raiz del �rbol se encuentra en el lado izquierdo
	// y se comola en este la nueva caracteristica del animal.
	if (anterior->izq == raiz)
	{ 
		anterior->izq = nuevoNodoCaract; 
	}
	// Se verifica que la raiz del �rbol se encuentra en el lado derecho
	// y se comola en este la nueva caracter�stica del animal.
	else if (anterior->der == raiz)
	{
		anterior->der = nuevoNodoCaract;
	}
	// se llama al m�todo que permite que el usuario realice nuevos cambios
	// a verdadero para que se pueda modificar los datos nuevos en control
	// principal del programa.
	aceptaNuevosDatos(true);
}

// M�todo que permite ingresar un valor booleano de verdadero o falso 
// en la variable de la clase de aceptar datos que es utilizada para
// controlar si el programa debe aceptar nuevas caracter�sticas que 
// el usuario ingresa previamente.
void ArbolBAnimal::aceptaNuevosDatos(bool confDatos)
{
	this->aceptaNDatos = confDatos;
}

