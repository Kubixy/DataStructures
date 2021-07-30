/******* Pr7.cpp **************************************************/ /**
 *
 * @file Pr7.cpp
 *
 * Fichero principal para gestionar un lavadero
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 *****************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Lavadero.h"
#include "Vehiculo.h"

using namespace std;

void mostrarMenu(string);
Vehiculo crearVehiculo(int);
int calcularHorario(int, int);

int main()
{
    Lavadero lv;
    int opt, hora, servicio;
    string nombre;

    srand(time(NULL));

    do
    {
        system("cls");
        mostrarMenu(lv.devolverNombre());

        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
            cout << "Nuevo nombre: ";
            cin >> nombre;
            lv.ponerNombre(nombre);
            break;

        case 2:

            do
            {
                cout << "Introduce hora valida (Ej 1300): ";
                cin >> hora;
            } while (hora % 100 > 59);

            do
            {
                cout << "\nIntroduce servicio (1-3): ";
                cin >> servicio;
            } while (servicio < 1 || servicio > 3);

            if (hora > 799 &&
                calcularHorario(hora, servicio * 30) < 1601 &&
                lv.devuelveTiempoPendiente() < (481 - servicio * 30))
            {
                lv.nuevoVehiculo(crearVehiculo(servicio));
            }
            else
                cout << "\nNo hay tiempo disponible para realizar el servicio" << endl;
            break;

        case 3:
            if (!lv.vehiculoSiguiente())
                cout << "No quedan vehiculos en cola" << endl;
            break;

        case 4:
            if (lv.devuelveTiempoPendiente() > 0)
                cout << lv.vehiculoEnCurso() << endl;
            else
                cout << "No hay vehiculos en curso" << endl;
            break;

        case 5:
            cout << "Hay " << lv.numeroVehiculosEnCola() << " vehiculos en cola" << endl;
            break;

        case 6:
            lv.mostrarLavadero();
        }

        cout << endl;
        system("pause");

    } while (opt != 0);

    return 0;
}

void mostrarMenu(string nombre)
{
    cout << nombre << endl;
    cout << "\n1. Cambia el nombre del lavadero" << endl;
    cout << "2. Nuevo vehiculo" << endl;
    cout << "3. Vehiculo siguiente" << endl;
    cout << "4. Mostrar informacion del vehiculo en curso" << endl;
    cout << "5. Mostrar numero de clientes en la cola" << endl;
    cout << "6. Mostrar informacion completa del lavadero" << endl;
    cout << "0. Salir" << endl;
    cout << endl
         << "Seleccionar opcion: ";
}

Vehiculo crearVehiculo(int servicio)
{
    Vehiculo vehiculo;
    string matricula, marca, modelo;

    cout << "Introduce matricula: ";
    cin >> matricula;
    cout << "Introduce marca: ";
    cin >> marca;
    cout << "Introduce modelo: ";
    cin >> modelo;
    vehiculo.rellenarDatos(matricula, servicio, marca, modelo);

    return vehiculo;
}

/*** int calcularHorario(int hora, int servicio) ***********************************************/ /**
 *
 *  Calcula la hora de la reserva
 *
 *  @param [in] hora       Entero con la hora
 *  @param [in] servicio   Entero con la duracion del servicio
 * 
 *  @return Devuelve la hora en la que finalizara el servicio
 */
/*************************************************************************/
int calcularHorario(int hora, int servicio)
{
    while (servicio > 0)
    {
        if (hora % 100 + 30 > 59)
            hora = (hora / 100 + 1) * 100 + hora % 100 - 30;
        else
            hora += 30;
        servicio -= 30;
    }

    return hora;
}
