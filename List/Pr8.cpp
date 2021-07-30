/****** Pr8.cpp **********************************************************/ /**
 *
 * @file Pr8.cpp
 *
 * @brief Pr�cticas de Programaci�n.
 *
 * Programa final para gestionar los pacientes de una unidad m�dica y las pruebas 
 * realizadas a los mismos.
 *
 * @version 0.9
 * @author Miguel Angel Gam�n
 *
 * @date 01/03/2021
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia                                               
 *                                                                         
 */
/***************************************************************************/

#include <iostream>
#include <string>

#include "Pr8_Unidad.h"

using namespace std;

void MostrarMenu(string);

/*
 * Programa principal
 */
int main()
{
	Unidad unidad;
	int nhc;
	string nombre;
	int opcion, tmp;

	do
	{
		MostrarMenu(unidad.DevuelveNombre());
		cin >> opcion;

		system("cls");

		switch (opcion)
		{
		case 1:
			cout << "Nuevo paciente" << endl;
			cout << "-------------------------------------" << endl;

			if (unidad.RegistrarPaciente())
				cout << "Paciente introducido correctamente" << endl;
			else
				cout << "El paciente introducido ya existe" << endl;
			break;

		case 2:
			cout << "Listado de pacientes" << endl;
			cout << "-------------------------------------" << endl;

			unidad.MostrarPacientes();
			break;

		case 3:
			cout << "Registrar prueba medica a un paciente" << endl;
			cout << "-------------------------------------" << endl;
			cout << endl;
			cout << "Introduce el NHC del paciente: ";
			cin >> nhc;
			cout << endl;

			if (unidad.RegistrarPruebaPaciente(nhc))
				cout << "Prueba anyadida correctamente" << endl;
			else
				cout << "No existe un paciente con el NHC introducido" << endl;
			break;

		case 4:
			cout << "Consultar historial paciente" << endl;
			cout << "-------------------------------------" << endl;
			cout << "Introduce el NHC del paciente a buscar: ";
			cin >> nhc;
			cout << endl;

			if (!unidad.MostrarHistorialPaciente(nhc))
				cout << "No existe un paciente con el NHC introducido" << endl;
			break;

		case 5:
			cout << "Borrar paciente" << endl;
			cout << "-------------------------------------" << endl;
			cout << endl;
			cout << "Introduce el NHC del paciente a borrar: ";
			cin >> nhc;
			cout << endl;

			if (unidad.BorrarPaciente(nhc))
				cout << "Paciente borrado correctamente" << endl;
			else
				cout << "No existe un paciente con el NHC introducido" << endl;
			break;

		case 6:
			cout << "Establecer nombre de unidad medica" << endl;
			cout << "-------------------------------------" << endl;
			cout << endl;
			cout << "Introduce el nombre: ";
			cin.ignore();
			getline(cin, nombre);
			unidad.EstablecerNombre(nombre);
			cout << endl;
			break;

		case 7:
			cout << "Introduce NHC del paciente: ";
			cin >> nhc;
			unidad.RegistrarCita(nhc);
			break;

		case 8:
			cout << "Introduce el numero de cita: ";
			cin >> tmp;
			unidad.EliminarCita(tmp);
			break;

		case 9:
			unidad.MostrarCitas();
			break;

		case 10:
			cout << "Introduce NHC del paciente: ";
			cin >> nhc;
			unidad.MostrarCitasPaciente(nhc);
			break;
		}

		cout << endl;
		system("pause");
	} while (opcion != 0);

	return 0;
}

void MostrarMenu(string nombre_unidad)
{
	system("cls");

	cout << "Unidad Medica: " << nombre_unidad << endl;
	cout << "-------------------------------------" << endl;
	cout << "1. Nuevo paciente" << endl;
	cout << "2. Mostrar todos los pacientes" << endl;
	cout << "3. Registrar prueba medica a un paciente" << endl;
	cout << "4. Consultar historial clinico de un paciente" << endl;
	cout << "5. Borrar paciente" << endl;
	cout << "6. Establecer nombre de unidad medica" << endl;
	cout << "7. Establecer cita medica" << endl;
	cout << "8. Anular cita" << endl;
	cout << "9. Mostrar todas las citas" << endl;
	cout << "10. Mostrar las citas de un paciente" << endl;
	cout << "0. Salir" << endl;
	cout << endl;
	cout << "Selecciona una opcion: ";
}
