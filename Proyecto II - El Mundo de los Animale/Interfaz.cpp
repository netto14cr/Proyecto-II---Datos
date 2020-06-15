#include "Interfaz.h"

// M�todo que muestra un mensaje de error cuando el usuario ingresa un comando
// de respuesta no valido para continuar con las acciones del programa.
void Interfaz::mensajeErrorTeclaRespuesta()
{
	cout << "\nError comando de respuesta invalido..."
		    "\nPor favor intentelo de nuevo respondiendo con SI o NO!\n";
}

// M�todo que muestra en pantalla un mensaje de Bienvenida al usuario en el programa.
void Interfaz::mensajeBienvenida()
{
	cout << "\n\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%			B I E N E V E N I D O  A			%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%		E L  M U N D O  D E  L O S  A N I A M A L E S		%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
}


// M�todo que muestra en pantalla un mensaje con a informaci�n de la descripcion
// del programa e indicando lo que puede realizar seg�n el enunciado del proyecto.
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
	limpiairPantalla();
}

// M�todo que muestra en pantalla un mensaje con las instrucciones de funcionamiento
// del programa para que el usuario se guie antes de iniciar a ejecutar el programa.
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
	
	cout << "3- Para terminar la ejecuci�n del programa puede seleccionar no continuar jugando"
		" ingresando la paralabra 'No' o \n   la letra 'N'.\n\n\n";
	detenerActPantalla();
	limpiairPantalla();
}

// M�todo que muestra en pantalla un mensaje de Despedida al usuario en el programa.
void Interfaz::mensajeDespedida()
{
	limpiairPantalla();
	cout << "__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t************	Gracias por usar el sistema esperamos que te haya servido de ayuda!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";
	detenerActPantalla();
}
// M�todo que permite mostrar en pantalla al usuario que ha acertado con el animal
void Interfaz::mensajeAnimalAdivinado()
{
	cout << "\n\n__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t\t\t************	 Y O  G A N E !!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";

}
// M�todo que permite mostrar en pantalla al usuario que NO ha acertado con el animal
void Interfaz::mensajeAnimalNoAdivinado()
{
	cout << "\n\n__________________________________________________________"
		"___________________________________________________________";
	cout << "\n\n\t\t\t************	 A C E P T O  M I  D E R R O R T A !!	************\n";
	cout << "__________________________________________________________"
		"___________________________________________________________\n\n\n";
}

// M�todo que se encarga de eliminar el buffer generado en datos de entrada pasados
// su funcion es eliminar estos datos para que permita ingresar nuevos sin problemas
void Interfaz::eliminaCacheDatosEntrada()
{
	cin.ignore();
}


// M�todo que permite mostrar al usuario la informacion del animal que se encontro en el arbol
// y obtener la respuesta por parte del usuario.
string Interfaz::preguntaAusuario(string dato)
{
	string resp; resp = "";
	cout <<"\n"<< dato << "\n";
	cin>>resp;
	cout << "\n";
	return resp;
}

// M�todo que permite mostrar en pantalla al usuario la pregunta que el sistema 
// con la informaci�n del arbol animal y las caracteristicas previamente seleccionadas
// del usuario, para adivinar el animal que esta pensando.
string Interfaz::preguntaAnimal(string dato)
{
	string resp; resp = "";
	cout << "\n\t El animal que estas pensado es: " << dato << " ?\n";
	cin >> resp;
	cout << "\n";
	return resp;
}

// M�todo que se encarga de preguntar al usuario el dato del nuevo animal que sera
// almacenado en la base de datos del sistema.
string Interfaz::preguntaNuevoAnimal()
{
	string resp; resp = "";
	eliminaCacheDatosEntrada();// elimina datos basura de entrada
	cout << "\n\n\t************	Ingrese el animal que estabas pensando?	************\n";
	getline(cin, resp);
	return resp;
}

// M�todo que se encarga de preguntar al usuario el dato de la carcter�stica del nuevo
// animal que sera utilizada c�mo pregunta para la proxima vez que el sistema entre en
// funcionamiento pueda utilizar la nueva informaci�n para adivinar el neuvo animal.
string Interfaz::preguntaNuevaCaracteristica()
{
	string resp; resp = "";
	eliminaCacheDatosEntrada();// elimina datos basura de entrada
	cout << "\n\n\t*** Ingrese la caracteristica principal del animal ingresado previamente\n"
		" en forma de pregunta?	***\n";
	getline(cin, resp);
	return resp;
}
// M�todo que permite preguntar al usuario si desea seguir utilizando el sistema.
string Interfaz::preguntaContinuar()
{
	string resp; resp = "";
	cout << "\n\t Desea seguir buscando animales? \n";
	cin >> resp;
	cout << "\n";
	return resp;
}

// M�todo que permite la eliminaci�n de informaci�n mostrada en pantalla.
void Interfaz::limpiairPantalla()
{
	system("cls");
}

// M�todo que permite la puause en la ejecuci�n del programa.
void Interfaz::detenerActPantalla()
{
	system("pause");
}
