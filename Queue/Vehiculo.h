/******* Vehiculo.h ****************************************************/ /**
 *
 * @file Vehiculo.h
 *
 * Fichero de cabecera de la clase Vehiculo 
 * 
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#ifndef _VEHICULO_H
#define _VEHICULO_H

#include <iostream>

using namespace std;

/**
 * @brief Clase para el manejo de coches
 * 
 *  Esta informacion esta compuesta por:
 *      - Matricula
 *      - Servicio (entero de 1 a 3)
 *      - Marca
 *      - Modelo
 */

class Vehiculo
{
public:
    //Constructor
    Vehiculo();
    //Asigna los datos al vehiculo
    void rellenarDatos(string, int, string, string);

    //Getters
    string devuelveMatricula();
    int devuelveServicio();
    string devuelveMarca();
    string devuelveModelo();

    //Sobrecarga del operador << para mostrar la informacion de un vehiculo
    friend ostream &operator<<(ostream &os, const Vehiculo &vh);

private:
    string matricula; ///< Matricula del vehiculo
    int servicio;     ///< Numero de servicio (1-3)
    string marca;     ///< Marca del vehiculo
    string modelo;    ///< Modelo del vehiculo
};

#endif