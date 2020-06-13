#include "Interfaz.h"

// Método que muestra un mensaje de error cuando el usuario ingresa un comando
// de respuesta no valido para continuar con las acciones del programa.
void Interfaz::mensajeErrorTeclaRespuesta()
{
	cout << "\nError comando de respuesta invalido..."
		    "\nPor favor intentelo de nuevo respondiendo con SI o NO!\n";
}

// Método que muestra en pantalla un mensaje de Bienvenida al usuario en el programa.
void Interfaz::mensajeBienvenida()
{
	cout << "\n\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%			B I E N E V E N I D O  A			%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%		E L  M U N D O  D E  L O S  A N I A M A L E S		%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n";
}


// Método que muestra en pantalla un mensaje con a información de la descripcion
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
	limpiairPantalla();
}

// Método que muestra en pantalla un mensaje con las instrucciones de funcionamiento
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
	
	cout << "3- Para terminar la ejecución del programa puede seleccionar no continuar jugando"
		" ingresando la paralabra 'No' o \n   la letra 'N'.\n\n\n";
	detenerActPantalla();
	limpiairPantalla();
}

// Método que muestra en pantalla un mensaje de Despedida al usuario en el programa.
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


// Método que permite mostrar al usuario la informacion del animal que se encontro en el arbol
// y obtener la respuesta por parte del usuario.
string Interfaz::preguntaAusuario(string dato)
{
	string resp; resp = "";
	cout << dato << "\n";
	cin>>resp;
	cout << "\n";
	return resp;
}

// Método que permite la eliminación de información mostrada en pantalla.
void Interfaz::limpiairPantalla()
{
	system("cls");
}

// Método que permite la puause en la ejecución del programa.
void Interfaz::detenerActPantalla()
{
	system("pause");
}
