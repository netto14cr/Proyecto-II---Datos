// ArbolBusqAnimales.cpp
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase árbol de búsqueda animal, estos sirven
//				para realizar búsquedas de información en el árbol de búsqueda animal.

#include "ArbolBusqAnimales.h"

// Método que se encarga de recorrer el árbol de búsqueda animal e
// ir realizando preguntas al usuario con base a la información obtenida
// previamente del archivo de texto con la base de animales y sus características.
void ArbolBAnimal::generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	// Se declara una variable auxiliar para manejar las respuesta por pate del
	// usuario
	string respuestaUsuario; respuestaUsuario ="";
	
	// Verifica que pueda recorrer los nodos del árbol izquierdos y drechos
	// para realizar preguntas sobre carasteristicas de los animales.
	if (raiz->izq != NULL && raiz->der != NULL)
	{
		// Se le realiza una pregunta con la información del árbol y
		// se obtiene la respuesta de usuario.
		respuestaUsuario=inter.preguntaAusuario(raiz->dato);
		// Se verifica que el usuario haya respondido correctamente
		verificaRespuestaPregunta(respuestaUsuario, raiz, anterior, inter);
	}
	// Falso si se termina de recorrer la informacion de los nodos hijos del 
	// árbol entonces se realiza el llamado del método adivinar animal para 
	// preguntar al usuario el animal que está pensando e intentar adivinarlo.
	else
	{
		adivinarAnimal(raiz, anterior, inter);
	}
}

// Método que realiza la acción de adivinar el animal que cumple con
// las características de las respuestas del usuario y con la información
// de la base de datos.
void ArbolBAnimal::adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	// Declaración de variable auxiliar para alamcenar la respuesta del usuario
	string respuestaUsuario; respuestaUsuario = "";
	respuestaUsuario=inter.preguntaAnimal(raiz->dato);
	// Se llama al método que se encarga de verificar la repuesta
	verificaRepuestaAnimal(respuestaUsuario, raiz, anterior, inter);
}
// Método que crea e inicializa en NULL un nodo ingresado en expecifico.
Nodo* ArbolBAnimal::crearNuevoNodo(Nodo* nuevoAux)
{
	nuevoAux = new Nodo;
	nuevoAux = NULL;
	return nuevoAux;
}

// Método que se encarga de inicializar los valores de los nodos
void ArbolBAnimal::inicializaNodo()
{
	raiz = NULL; // Se incializa el nodo a NULL
}

// Método que se encarga de preguntar al usuario los datos del animal que
// estaba pensando, que serán utilizados después para actualiar la base de
// datos del sistema.
void ArbolBAnimal::ingresarNuevosDatos(Nodo* actual, Nodo* anterior, Interfaz inter)
{
	// Se declaran variable para alamacenar los datos del nuevo animal y
	// también su pregunta característica.
	string respuestaNuevoAnimal; respuestaNuevoAnimal = "";
	string respNuevaCaracteristica; respNuevaCaracteristica = "";
	respuestaNuevoAnimal = inter.preguntaNuevoAnimal();
	respNuevaCaracteristica = inter.preguntaNuevaCaracteristica();
	// Se llama al método que se encarga de acomodar correctemente 
	// los datos nuevos y anteriores de acuerdo a la lectura en el
	// último nodo visitado y el anterior.
	restructuraDatosArbol(actual, anterior, respuestaNuevoAnimal,
							respNuevaCaracteristica, inter);
}

// Método que se encarga de restructuras de datos nuevos en árbol de búsqueda
// animal con base al recorrido y las respuestas del con los nuevos datos
// ingresados por el usuario.
void ArbolBAnimal::restructuraDatosArbol(Nodo* actual, Nodo* anterior,
	string nuevoAnimal,string nuevaCaract, Interfaz inter)
{
	// Se define nodos para el nuevo animal y la nueva caracterísitica
	Nodo* nuevoNodoAnimal; nuevoNodoAnimal = new Nodo; 
	Nodo* nuevoNodoCaract; nuevoNodoCaract = new Nodo;
	// se agrega el nuevo animal al nodo
	nuevoNodoAnimal->dato = nuevoAnimal;
	nuevoNodoAnimal->izq=NULL;
	nuevoNodoAnimal->der= NULL;
	// Se agrega la nueva característica de tipo pregunta al animal.
	nuevoNodoCaract->dato = nuevaCaract;
	// Se define la relación del animal en el nodo izquierdo de la característica.
	nuevoNodoCaract->izq = nuevoNodoAnimal;
	// Se recoloca el dato del último recorrido y se coloca en el hijo derecho.
	nuevoNodoCaract->der = actual;
	// Se llama al método encargado de verificar la ubicación de la última pregunta
	// para reacomodar la nueva característica del animal en el árbol búsqueda animal.
	reordenaOrdenNodosNuevo(actual, anterior, nuevoNodoCaract);
}

// Método que se encarga de verificar que la respuesta enviada por el usuario
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

// Método que se encarga de verificar la repuesta
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
		// además llama al método para restructuras la base de datos del árbol,
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

// Método que encarga de verificar la posicion de la ultima pregunta en el ultimo 
// nodo reacomodando la pregunta tipo característica nueva ingresada por el usuario
// en el nodo correspondiente.
void ArbolBAnimal::reordenaOrdenNodosNuevo(Nodo* raiz, Nodo* anterior, 
	Nodo* nuevoNodoCaract)
{
	// Se verifica que la raiz del árbol se encuentra en el lado izquierdo
	// y se comola en este la nueva caracteristica del animal.
	if (anterior->izq == raiz)
	{ 
		anterior->izq = nuevoNodoCaract; 
	}
	// Se verifica que la raiz del árbol se encuentra en el lado derecho
	// y se comola en este la nueva característica del animal.
	else if (anterior->der == raiz)
	{
		anterior->der = nuevoNodoCaract;
	}
	// se llama al método que permite que el usuario realice nuevos cambios
	// a verdadero para que se pueda modificar los datos nuevos en control
	// principal del programa.
	aceptaNuevosDatos(true);
}

// Método que permite ingresar un valor booleano de verdadero o falso 
// en la variable de la clase de aceptar datos que es utilizada para
// controlar si el programa debe aceptar nuevas características que 
// el usuario ingresa previamente.
void ArbolBAnimal::aceptaNuevosDatos(bool confDatos)
{
	this->aceptaNDatos = confDatos;
}

