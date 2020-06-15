#include "ArbolBusqAnimales.h"

// M�todo que se encarga de recorrer el arbol de busqueda animal e
// ir realizando preguntas al usuario con base a la informaci�n obtenida
// previamente del archivo de texto con la base de animales y sus caracteristicas.
void ArbolBAnimal::generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	string respuestaUsuario; respuestaUsuario ="";
	
	// Verifica que pueda recorrer los nodos del arbol izquierdos y drechos
	// para rewlizar preguntas sobre carasteristicas de los animales.
	if (raiz->izq != NULL && raiz->der != NULL)
	{
		// Se le realiza una pregunta con la informacion del arbol y
		// se obtiene la respuesta de usuario.
		respuestaUsuario=inter.preguntaAusuario(raiz->pregunta);
		// Se verifica que el usuario haya respondido correctamente
		verificaRespuestaPregunta(respuestaUsuario, raiz, anterior, inter);
	}
	// Falso si se termina de recorrer la informacion de los nodos hijos del 
	// arbol entonces se realiza el llamado del m�todo adivinar animal para 
	// preguntar al usuario el animal que est� pensando e intentar adivinarlo.
	else
	{
		adivinarAnimal(raiz, anterior, inter);
	}
}

// M�todo que realiza la accion de adivinar el animal que cumple con
// las caracteristicas de las respuestas del usuario y con la informaci�n
// de la base de datos.
void ArbolBAnimal::adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	string respuestaUsuario; respuestaUsuario = "";
	respuestaUsuario=inter.preguntaAnimal(raiz->pregunta);
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
void ArbolBAnimal::inicializaNodos()
{
	raiz = NULL;
}

// M�todo que se encarga de preguntar al usuario los datos del animal que
// estaba pensando, que seran utilizados despu�s para actualiar la base de
// datos del sistema.
void ArbolBAnimal::ingresarNuevosDatos(Nodo* actual, Nodo* anterior, Interfaz inter)
{
	string respuestaNuevoAnimal; respuestaNuevoAnimal = "";
	string respNuevaCaracteristica; respNuevaCaracteristica = "";
	respuestaNuevoAnimal = inter.preguntaNuevoAnimal();
	respNuevaCaracteristica = inter.preguntaNuevaCaracteristica();
	restructuraDatosArbol(actual, anterior, respuestaNuevoAnimal,
							respNuevaCaracteristica, inter);
}

// M�todo que se encarga de restructuras de datos nuevos en arbol de b�squeda
// animal con base al recorrido y las respuestas del con los nuevos datos
// ingresados por el usuario.
void ArbolBAnimal::restructuraDatosArbol(Nodo* actual, Nodo* anterior,
	string nuevoAnimal,string nuevaCaract, Interfaz inter)
{
	// Se define nodos para el nuevo animal y la nueva caracter�sitica
	Nodo* nuevoNodoAnimal; nuevoNodoAnimal = new Nodo; 
	Nodo* nuevoNodoCaract; nuevoNodoCaract = new Nodo;
	// se agrega el nuevo animal al nodo
	nuevoNodoAnimal->pregunta = nuevoAnimal;
	nuevoNodoAnimal->izq=NULL;
	nuevoNodoAnimal->der= NULL;
	// Se agrega la nueva caracter�stica de tipo pregunta al animal 
	nuevoNodoCaract->pregunta = nuevaCaract;
	// Se define la relaci�n del animal en el nodo izquierdo de la caracter�stica
	nuevoNodoCaract->izq = nuevoNodoAnimal;
	// Se recoloca el dato del ultimo recorrido y se coloca en el hijo derecho 
	nuevoNodoCaract->der = actual;
	// Se llama al m�todo encargado de verificar la ubicaci�n de la ultima pregunta
	// para reacomodar la nueva caracteristica del animal en el arbol busqueda animal.
	reordenaOrdenNodosNuevo(actual, anterior, nuevoNodoCaract);
}

// M�todo que se encarga de verificar que la respuesta enviada por el usuario
// sea una valida definida en las instrucciones en el inicio del programa.
void ArbolBAnimal::verificaRespuestaPregunta(string respuesta, Nodo* raiz, 
	Nodo* anterior, Interfaz inter)
{
	// Se verifica que el usuario haya ingresado la respuesta de SI o NO correctamente
	if (respuesta == "SI" || respuesta == "S")
		generarPreguntas(raiz->izq, raiz, inter);
	else if (respuesta == "NO" || respuesta == "N" )
		generarPreguntas(raiz->der, raiz, inter);
	else
	{
		inter.mensajeErrorTeclaRespuesta();
		generarPreguntas(raiz, anterior, inter);
	}

}

// M�todo que se encarga de verificar la repuesta
bool ArbolBAnimal::verificaRepuestaAnimal(string respuesta, Nodo* raiz,
	Nodo* anterior, Interfaz inter)
{
	// Si respuesta es positiva (SI) entonces el sistema adivino el animal
	// y muestra el mensaje que el usuario acierto.
	if (respuesta == "SI" || respuesta == "S")
	{
		// Muestra mensaje que usuario ha adivinado el animal
		inter.mensajeAnimalAdivinado(); 
		aceptaNuevosDatos(false);
	}
	// Falso si la respuesta es NO entonces muestra el mensaje que perdio y
	// adema�s llama al m�todo para restructuras la base de datos del arbol,
	// permitiendo expandir su conocimiento con datos que le proporcione el
	// usuario.
	 else if (respuesta == "NO" || respuesta == "N")
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

	return false;
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
	// y se comola en este la nueva caracteristica del animal.
	else if (anterior->der == raiz)
	{
		anterior->der = nuevoNodoCaract;
	}
	// se llama al m�todo que permite que el usuario realice nuevos cambios
	// a verdadero para que se pueda modificar los datos  nuevos en control
	// principal del programa.
	aceptaNuevosDatos(true);

}

// M�todo que permite ingresar un valor booleano de verdadero o falso 
// en la variable de la clase de aceptar datos que es utilizada para
// controlar si el programa debe aceptar nuevas caracteristicas que 
// el usuario ingresa previamente.
void ArbolBAnimal::aceptaNuevosDatos(bool confDatos)
{
	this->aceptaNDatos = confDatos;
}

