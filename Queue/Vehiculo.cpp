/******* Vehiculo.cpp ************************************************/ /**
 *
 * @file Vehiculo.cpp
 *
 * Implementacion de los metodos de la clase Vehiculo
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 *****************************************************************************/

#include "Vehiculo.h"

#include <iostream>

using namespace std;

/*** Vehiculo::Vehiculo() ***********************************************/ /**
 *
 *  Asigna valores por defecto (NO especificados en la practica)
 *
 */
/*************************************************************************/
Vehiculo::Vehiculo()
    : matricula(""), servicio(0), marca(""), modelo("") {}

/*** void Vehiculo::rellenarDatos(string matricula, int servicio, string marca, string modelo) ***********************************************/ /**
 *
 *  Asigna los valores dados al vehiculo
 * 
 *  @param [in] matricula   Cadena matricula
 *  @param [in] servicio    Entero servicio
 *  @param [in] marca       Cadena marca
 *  @param [in] modelo      Cadena modelo
 *
 */
/*************************************************************************/
void Vehiculo::rellenarDatos(string matricula, int servicio, string marca, string modelo)
{
    this->matricula = matricula;
    this->servicio = servicio;
    this->marca = marca;
    this->modelo = modelo;
}

/*** ostream &operator<<(ostream &os, const Vehiculo &vh)  ********************************/ /**
 *
 *  Sobrecarga el operador << para devolver la informacion de un vehiculo
 *  @param [in] os Puntero al flujo de datos de salido
 *	@param [in] vh Puntero al objeto Vehiculo a mostrar

 *  @return Devuelve la salida de datos
 *
 */
/**********************************************************************/
ostream &operator<<(ostream &os, const Vehiculo &vh)
{
    os << endl
       << "Matricula: " + vh.matricula << endl;
    os << "Servicio: " << vh.servicio << endl;
    os << "Marca: " + vh.marca << endl;
    os << "Modelo: " + vh.modelo << endl;

    return os;
}

string Vehiculo::devuelveMatricula()
{
    return matricula;
}

int Vehiculo::devuelveServicio()
{
    return servicio;
}

string Vehiculo::devuelveModelo()
{
    return modelo;
}

string Vehiculo::devuelveMarca()
{
    return marca;
}