#include "ArbolBusqAnimales.h"

// Método recursivo que realiza la lectura por linea del archivo de texto y
// va creando la informacion para ir acomodando en una estructura de arbol
void ArbolBAnimal::obtenerInformacionArchivo(fstream& archivo, Nodo*& raiz)
{
	string lineaTxt;
	if (!archivo.eof())
	{
		getline(archivo, lineaTxt);
		cin.clear();
	}
	else
		return;

	if (lineaTxt != "#")
	{
		raiz = new Nodo;
		raiz->pregunta = lineaTxt;
		obtenerInformacionArchivo(archivo, raiz->izq);
		obtenerInformacionArchivo(archivo, raiz->der);
	}
	else
	{
		raiz = NULL;
	}
}

// Método que se encarga de recorrer el arbol de busqueda animal e
// ir realizando preguntas al usuario con base a la información obtenida
// previamente del archivo de texto con la base de animales y sus caracteristicas.
void ArbolBAnimal::generarPreguntas(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	string respuestaUsuario; respuestaUsuario ="";
	// system("color 0A");
	
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

	else
	{
		adivinarAnimal(raiz, anterior, inter);
	}
}

// Método que realiza la accion de adivinar el animal que cumple con
// las caracteristicas de las respuestas del usuario y con la información
// de la base de datos.
void ArbolBAnimal::adivinarAnimal(Nodo* raiz, Nodo* anterior, Interfaz inter)
{
	string respuestaUsuario; respuestaUsuario = "";
	respuestaUsuario=inter.preguntaAnimal(raiz->pregunta);
	verificaRepuestaAnimal(respuestaUsuario, raiz, anterior, inter);
	
	//else if (reply == "no" || reply == "NO" || reply == "No" || reply == "n" || reply == "N")
	//	updatetree(root, prev);
	//else
	//{
	//	cout << "Sorry, please enter a valid answer Yes or No" << endl;
	//	finalquestion(root, prev);
	//}


}


// Método que se encarga de inicializar los valores de los nodos
void ArbolBAnimal::inicializaNodos()
{
	raiz = NULL;
	raiz->izq = NULL;
	raiz->der = NULL;
	inicio = NULL;
	nuevo = NULL;
}

// Método que se encarga de restructuras de datos nuevos en arbol de busqueda animal
// con base al recorrido y las respuestas del usuario.
// se encarga de ingresar la nueva información para aprender sobre animales y caracte-
// risticas que no posee en la base de datos del sistema.
void ArbolBAnimal::restructuraDatosArbol(Nodo* actual, Nodo* anterior, Interfaz inter)
{
}

// Método que se encarga de verificar que la respuesta enviada por el usuario
// sea una valida definida en las instrucciones en el inicio del programa.
void ArbolBAnimal::verificaRespuestaPregunta(string respuesta, Nodo* raizz, 
	Nodo* anterior, Interfaz inter)
{

	if (respuesta == "SI" || respuesta == "S")
		generarPreguntas(raizz->izq, raizz, inter);
	else if (respuesta == "NO" || respuesta == "N" )
		generarPreguntas(raizz->der, raizz, inter);
	else
	{
		inter.mensajeErrorTeclaRespuesta();
		generarPreguntas(raizz, anterior, inter);
	}

}

// Método que se encarga de verificar la repuesta
bool ArbolBAnimal::verificaRepuestaAnimal(string respuesta, Nodo* raiz,
	Nodo* anterior, Interfaz inter)
{
	// Si respuesta es positiva (SI) entonces el sistema adivino el animal
	// y muestra el mensaje que el usuario acierto.
	if (respuesta == "SI" || respuesta == "S")
	{
		// Muestra mensaje que usuario ha adivinado el animal
		inter.mensajeAnimalAdivinado(); 
	}
	// Falso si la respuesta es NO entonces muestra el mensaje que perdio y
	// ademaás llama al método para restructuras la base de datos del arbol,
	// permitiendo expandir su conocimiento con datos que le proporcione el
	// usuario.
	 else if (respuesta == "NO" || respuesta == "N")
	{
		inter.mensajeAnimalNoAdivinado();
		restructuraDatosArbol(raiz, anterior, inter);
	}
	// Falso si el usuario ingreasa un valor no valido se le muestra un mensaje de 
	// error y se le vulve a preguntar.
	 else {
		inter.mensajeErrorTeclaRespuesta();
		adivinarAnimal(raiz, anterior, inter);
	}
}

//respuesta=inter.preguntaContinuar();

//if (respuesta == "SI" || respuesta == "S")
//{
//	cout << "Rebooting the system";
//	dot(2);
//	system("CLS");
//	question(start, prev);
//}
//else if (reply == "no" || reply == "NO" || reply == "No" || reply == "n" || reply == "N")
//{
//	system("color 09");
//	cout << "Thanks for playing with me, i think we had a good time. See you soon. Bye bye" << endl;
//	for (int i = 0; i < 20; i++)
//	{
//		if (i == 10)
//			cout << "\t\t\t\t\tBUILT BY St.Joseph's Cseians" << endl << "\t\t\t\t\t\t#Viola\n\t\t\t\t\t\t#Hemashree\n\t\t\t\t\t\t#Lakshmi\n\t\t\t\t\t\t#Yogeswaran\n\t\t\t\t\t\t#Sanjay Prashadh\n\t\t\t\t\t\t#Sathvik\n" << endl;
//		else
//			cout << endl;
//	}
//}