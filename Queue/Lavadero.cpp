/******* Lavadero.cpp ************************************************/ /**
 *
 * @file Lavadero.cpp
 *
 * Implementacion de los metodos de la clase Lavadero
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 *****************************************************************************/

#include "Lavadero.h"

#include <iostream>

using namespace std;

/*** Lavadero::Lavadero() ***********************************************/ /**
 *
 *  Asigna los valores por defecto especificados en la practica
 */
/*************************************************************************/
Lavadero::Lavadero()
    : nombre("Lavadero S.L."), antendidos(0), tiempo_pendiente(0) {}

/*** bool Lavadero::nuevoVehiculo(Vehiculo v) ***********************************************/ /**
 *
 *  Anyade un nuevo vehiculo a la cola si no esta vacia
 *
 *  @param [in] v   Objeto vehiculo
 * 
 *  @return Devuelve true si el vehiculo se ha podido anyadir a la cola
 */
/*************************************************************************/
bool Lavadero::nuevoVehiculo(Vehiculo v)
{
    bool output = false;

    if (tiempo_pendiente != 0)
    {
        vehiculos.Encolar(v);
        output = true;
    }
    else
    {
        vehiculo = v;
    }

    tiempo_pendiente += v.devuelveServicio() * 30;

    return output;
}

/*** bool Lavadero::vehiculoSiguiente() ***********************************************/ /**
 *
 *  Desencola un vehiculo
 * 
 *  @return Devuelve true si el vehiculo se ha podido desencolar
 */
/*************************************************************************/
bool Lavadero::vehiculoSiguiente()
{
    bool output = false;

    if (tiempo_pendiente > 0)
    {
        cout << "Vehiculo finaliza: " << endl;
        cout << vehiculo << endl;
        antendidos++;
        output = true;

        cout << "Vehiculo entra: " << endl;
        if (!vehiculos.ColaVacia())
        {
            vehiculos.PrimeroCola(vehiculo);
            cout << vehiculo << endl;
            vehiculos.Desencolar();
        }
        else
        {
            cout << "\nNo quedan vehiculos en cola" << endl;
        }
    }
    else if (tiempo_pendiente != 0)
    {
        tiempo_pendiente = 0;
    }

    return output;
}

/*** void Lavadero::mostrarLavadero() ******************************************/ /**
 *
 *  Muestra la informacion de los vehiculos que conforman la cola
 */
/**********************************************************************/
void Lavadero::mostrarLavadero()
{
    cout << "Nombre lavadero: " + nombre << endl;
    cout << "Se han atendido " << antendidos << " clientes" << endl;
    cout << "Tiempo pendiente: vehiculo en curso " << vehiculo.devuelveServicio() * 30 << endl;
    cout << "Tiempo pendiente de la cola: " << tiempo_pendiente << endl;

    if (tiempo_pendiente > 0)
    {
        cout << "\nVehiculo en curso:" << endl;
        cout << vehiculo << endl;
        cout << "Cola de vehiculos:" << endl;
        vehiculos.MostrarCola();
    }
    else
        cout << "\nActualmente no hay vehiculos en cola" << endl;
}

void Lavadero::ponerNombre(string nombre)
{
    this->nombre = nombre;
}

string Lavadero::devolverNombre()
{
    return nombre;
}

Vehiculo Lavadero::vehiculoEnCurso()
{
    return vehiculo;
}

int Lavadero::numeroVehiculosEnCola()
{
    return vehiculos.NumeroElementos();
}

int Lavadero::devuelveTiempoPendiente()
{
    return tiempo_pendiente;
}
