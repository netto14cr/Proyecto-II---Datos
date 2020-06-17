// Interfaz.h
// Autor: Néstor David Leiva Mora - 116080589
// Descripción: Implementa los métodos de la clase Interfaz que se utilizan para 
//              mostrar la actualización de datos del sistema, permitiendo mostrados
//              guiar y capturar las respuestas del usuario durante la ejecución del
//				programa.

#include "Interfaz.h"

// Método que muestra un mensaje de error cuando el usuario ingresa un comando
// de respuesta no valido para continuar con las acciones del programa.
void Interfaz::mensajeErrorTeclaRespuesta()
{
	cout << "\n\t#################################################################################\n";
	cout << "\n\t\t\t Error comando de respuesta invalida !!..."
		    "\n\t\t Por favor intentelo de nuevo respondiendo con SI o NO!\n";
	cout << "\n\t#################################################################################\n";
}

// Método que muestra en pantalla un mensaje de Bienvenida al usuario en el programa.
void Interfaz::mensajeBienvenida()
{
	cout << "\n\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%			B I E N E V E N I D O  A			%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%		E L  M U N D O  D E  L O S  A N I A M A L E S		%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
}


// Método que muestra en pantalla un mensaje con a información de la descripción
// del programa e indicando lo que puede realizar según el enunciado del proyecto.
void Interfaz::mensajeDescripcion()
{
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t\t\t************	D E S C R I P C I O N  P R O Y E C T O	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";

	cout << " Las respuestas que ofrezca el sistema al usuario dependeran de la cantidad de"
		" informacion que el arbol binario tenga. \n Si el sistema le pregunta al usuario,"
		"  por ejemplo:  Si el animal maulla? y este responde que no y no hay mayor infor-\n"
		" macion entonces la aplicacion proyecta una ventana donde acepta que perdio y despliega otra"
		" ventana donde le solicita\n al usuario que escriba el nombre del animal y una fuerte"
		" caracteristica de el\n\n\n";
	detenerActPantalla();
	limpiarPantalla();
}

// Método que muestra en pantalla un mensaje con las instrucciones de funcionamiento
// del programa para que el usuario se guie antes de iniciar a ejecutar el sistema.
void Interfaz::mensajeInstrucciones()
{
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout<<"\n\n\t\t\t************	I N S T R U C C I O N E S	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";

	cout << "1- Para la ejecucion de este programa se debera responder las preguntas"
		" realizadas por el sistema escribiendo: \n\n"
		"\t\t\t\t\t'SI' o 'NO' u 'S' o 'N'. \n\n\n";

	cout << "2- Si el sistema pierde mostrara una pantalla donde debe ingresar el animal"
		" que pertenecia a ese tipo y seguidamente\n   su caracterisitica.\n\n\n";
	
	cout << "3- Para terminar la ejecución del programa puede seleccionar no continuar jugando"
		" ingresando la paralabra 'No' o \n   la letra 'N'.\n\n\n";
	detenerActPantalla();
	limpiarPantalla();
}

// Método que muestra en pantalla un mensaje de Despedida al usuario en el programa.
void Interfaz::mensajeDespedida()
{
	limpiarPantalla();
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t************	Gracias por usar el sistema, te esperamos pronto!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";
	detenerActPantalla();
}
// Método que permite mostrar en pantalla al usuario que ha acertado con el animal
void Interfaz::mensajeAnimalAdivinado()
{
	limpiarPantalla();
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t\t\t************	 Y O  G A N E !!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";

}
// Método que permite mostrar en pantalla al usuario que NO ha acertado con el animal
void Interfaz::mensajeAnimalNoAdivinado()
{
	limpiarPantalla();
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t\t\t************	 A C E P T O  M I  D E R R O R T A !!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";
}

// Método que se encarga de eliminar el buffer generado en datos de entrada pasados
// su funcion es eliminar estos datos para que permita ingresar nuevos sin problemas
void Interfaz::eliminaCacheDatosEntrada()
{
	cin.ignore();
}


// Método que permite mostrar al usuario la informacion del animal que se encontro en el arbol
// y obtener la respuesta por parte del usuario.
string Interfaz::preguntaAusuario(string dato)
{
	string resp; resp = "";
	cout <<"\n"<< dato << "\n";
	cin>>resp;
	cout << "\n";
	return resp;
}

// Método que permite mostrar en pantalla al usuario la pregunta que el sistema 
// con la información del árbol animal y las caracteristicas previamente seleccionadas
// del usuario, para adivinar el animal que esta pensando.
string Interfaz::preguntaAnimal(string dato)
{
	string resp; resp = "";
	cout << "\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "\n\t <<<<<<<<<<<<			El animal que estas pensado es: " << dato << " ?		>>>>>>>>>>>>\n";
	cout << "\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cin >> resp;
	cout << "\n";
	return resp;
}

// Método que se encarga de preguntar al usuario el dato del nuevo animal que sera
// almacenado en la base de datos del sistema.
string Interfaz::preguntaNuevoAnimal()
{
	eliminaCacheDatosEntrada();// elimina datos basura de entrada
	string resp; resp ="";
	cout << "\n\n\t\t************		Ingrese el animal que estabas pensando?		************\n";
	getline(cin, resp);
	return resp;
}

// Método que se encarga de preguntar al usuario el dato de la carcterística del nuevo
// animal que sera utilizada cómo pregunta para la proxima vez que el sistema entre en
// funcionamiento pueda utilizar la nueva información para adivinar el neuvo animal.
string Interfaz::preguntaNuevaCaracteristica()
{
	string resp; resp = "";
	cout << "\n\n*** Ingrese la caracteristica principal del animal ingresado previamente"
		" en forma de pregunta?	***\n";
	getline(cin, resp);
	return resp;
}
// Método que permite preguntar al usuario si desea seguir utilizando el sistema.
string Interfaz::preguntaContinuar()
{
	string resp; resp = "";
	cout << "\n\n\t Desea seguir buscando animales? \n";
	cin >> resp;
	cout << "\n";
	return resp;
}

// Método que permite la eliminación de información mostrada en pantalla.
void Interfaz::limpiarPantalla()
{
	system("cls");
}

// Método que permite mostar por pantalla el mensaje de error al 
// cargar un archivo, por que este no exista.
void Interfaz::mensajeErrorLecturaArchivo()
{
	limpiarPantalla();
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t****	Error desconocido al intentar acceder al achivo de texto	****\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";
	detenerActPantalla();
}

// Método que permite la puause en la ejecución del programa.
void Interfaz::detenerActPantalla()
{
	system("pause");
}
