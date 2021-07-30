/******* Lavadero.h ****************************************************/ /**
 *
 * @file Lavadero.h
 *
 * Fichero de cabecera de la clase Lavadero 
 * 
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#ifndef _LAVADERO_H
#define _LAVADERO_H

#include <iostream>
#include "Vehiculo.h"
#include "Cola.h"

using namespace std;

/**
 * @brief Clase para el manejo de lavaderos
 * 
 *  Esta informacion esta compuesta por:
 *      - Nombre del vehiculo
 *      - Objeto vehiculo que representa el vehiculo que esta siendo atendido
 *      - Tiempo pendiente del vehiculo que esta siendo atendido
 *      - Total de vehiculos atendidos
 *      - Cola de vehiculos
 */

class Lavadero
{
public:
    //Constructor
    Lavadero();
    //Devuelve el nombre del lavadero
    void ponerNombre(string);
    //Anyade un nuevo vehiculo a la cola
    bool nuevoVehiculo(Vehiculo);
    //Desencola un vehiculo
    bool vehiculoSiguiente();
    //Muestra la informacion de los vehiculos que conforman la cola
    void mostrarLavadero();
    //Devuelve el vehiculo que esta siendo atendido
    Vehiculo vehiculoEnCurso();
    //Getters
    string devolverNombre();
    int numeroVehiculosEnCola();
    int devuelveTiempoPendiente();

private:
    string nombre;        ///< Nombre del lavadero
    Vehiculo vehiculo;    ///< Vehiculo en curso
    int tiempo_pendiente; ///< Tiempo pendiente del vehiculo
    int antendidos;       ///< Vehiculos atendidos
    Cola vehiculos;       ///< Cola de vehiculos
};

#endif