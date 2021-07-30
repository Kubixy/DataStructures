/****** Pr6.cpp **********************************************************/ /**
 *
 * @file Pr6.cpp
 *
 * @brief Pr�cticas de Programacion.
 *
 * Programa que simula el funcionamiento de una bahia de una terminal de 
 * contenedores.
 *
 * @version 1.0
 * @author Miguel Angel Gamon
 *                                                                         
 */
/***************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Pr6_Contenedor.h"
#include "Pr6_Bahia.h"

/*  
 *  Se trabaja sobre un bahia de pilas de contenedores
 *  La clase "Contenedor" especifica la estructura de informacion de un contenedor
 *  La clase "Bahia" especidfica la estructura de la informaci�n de la bahia
 */

using namespace std;

void MostrarMenu();

/*
 * Programa principal
 */
int main()
{
	Bahia bahia;
	Contenedor cont;
	int opcion;
	int num_pila, altura;

	srand(time(NULL));

	do
	{
		system("cls");

		bahia.mostrarBahia();

		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;

		MostrarMenu();

		cin >> opcion;
		cout << endl;

		switch (opcion)
		{
		case 1:

			cont.RellenarDatos();
			cout << "Nuevo contenedor: " << endl
				 << endl;
			cout << cont << endl
				 << endl;
			if (!bahia.apilarAleatoriamente(cont))
				cout << "El contenedor no ha podido apilarse aleatoriamente" << endl;

			break;
		case 2:
			cont.RellenarDatos();
			cout << "Nuevo contenedor: " << endl
				 << endl;
			cout << cont << endl
				 << endl;
			if (!bahia.apilarDinamicamente(cont))
				cout << "El contenedor no ha podido apilarse segun el algoritmo de posicionamiento "
					 << "o por no disponer de ninguna pila libre que cumpla con los requisitos" << endl;

			break;
		case 3:

			if (!bahia.desapilarSiguiente())
				cout << "No se ha podido desapilar ningun contenedor. La bahia esta vacia" << endl;

			break;
		case 4:

			// Solicitar numero de pila
			do
			{
				cout << "Introduce numero de pila (1-6): ";
				cin >> num_pila;
			} while (num_pila < 1 || num_pila > 6);
			// Solicitar altura
			do
			{
				cout << "Introduce altura (1-4): ";
				cin >> altura;
			} while (altura < 1 || altura > 4);
			cout << endl;
			if (!bahia.desapilarPorPosicion(num_pila - 1, altura))
				cout << "El contenedor indicado no ha podido desapilarse" << endl;

			break;
		}

		cout << endl;
		system("pause");
	} while (opcion != 0);

	return 0;
}

/*** void MostrarMenu(); *************************************************/ /**
 * 
 *  Muestra por pantalla el menu de opciones del programa
 *
 */
/*************************************************************************/
void MostrarMenu()
{
	cout << "1. Apilar contenedor aletoriamente" << endl;
	cout << "2. Apilar contenedor dinamicamente" << endl;
	cout << "3. Desapilar contenedor siguiente" << endl;
	cout << "4. Desapilar contenedor por posicion" << endl;
	cout << "0. Salir" << endl;
	cout << endl;
	cout << "Selecciona un opcion: ";
}
