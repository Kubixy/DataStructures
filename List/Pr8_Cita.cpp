/******* Pr8_Cita.cpp *************************************************/ /**
 *
 * @file Pr8_Cita.cpp
 *
 * Implementacion de la clase Cita
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#include <iostream>

#include "Pr8_Cita.h"

using namespace std;

/**** Cita::Cita() ***************************************************/ /**
 *
 * Constructor por defecto de la clase Cita.
 *
 */
/**************************************************************************/
Cita::Cita()
{
    numCita = -1;
    telefonica = false;
    descripcion = "";
    nhc = -1;
    doctor = "";
}

/*** ostream &operator<<(ostream &out, Cita c) *******************/ /**
 *
 *  Sobrecarga del operador salida que muestra la cita
 *
 *  @param  [in,out]  out  stream de salida
 *  @param  [in]      c    cita a mostrar
 *
 */
/**********************************************************************/
ostream &operator<<(ostream &out, Cita c)
{
    out << "Numero de cita: " << c.numCita << endl;
    out << "Modalidad: " << (c.telefonica ? "telefonica" : "presencial") << endl;
    out << "Descripcion: " + c.descripcion << endl;
    out << "NHC: " << c.nhc << endl;
    out << "Doctor: " + c.doctor << endl;

    out << c.fecha;

    return out;
}
/**** void Cita::EstableceNumero(int numCita) ********************************/ /**
 *
 * Establece el valor numero de cita.
 *
 * @param [in] numCita	Numero cita
 *
 */
/**************************************************************************/
void Cita::EstableceNumero(int numCita)
{
    this->numCita = numCita;
}

/**** void Cita::EstableceDescripcion(string descripcion) ********************************/ /**
 *
 * Establece la descripcion de la cita.
 *
 * @param [in] descripcion	Descripcion cita
 *
 */
/**************************************************************************/
void Cita::EstableceDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

/**** void Cita::EstableceTiempoPrevisto(Tiempo fecha) ********************************/ /**
 *
 * Establece la fecha de la cita.
 *
 * @param [in] fecha	Fecha cita
 */
/**************************************************************************/
void Cita::EstableceTiempoPrevisto(Tiempo fecha)
{
    this->fecha = fecha;
}

/**** void Cita::EstableceTiempoPrevisto(Tiempo fecha) ********************************/ /**
 *
 * Establece la modalidad de la cita.
 *
 * @param [in] telefonica	Telefonica o presencial
 */
/**************************************************************************/
void Cita::EstableceTelefonica(bool telefonica)
{
    this->telefonica = telefonica;
}

/**** void Cita::EstablecePaciente(int nhc) ********************************/ /**
 *
 * Establece el nhc del paciente
 *
 * @param [in] nhc	ID paciente
 */
/**************************************************************************/
void Cita::EstablecePaciente(int nhc)
{
    this->nhc = nhc;
}

void Cita::EstableceDoctor(string doctor)
{
    this->doctor = doctor;
}

int Cita::DevuelveNumero()
{
    return numCita;
}

string Cita::DevuelveDescripcion()
{
    return descripcion;
}

Tiempo Cita::DevuelveTiempoPrevisto()
{
    return fecha;
}

bool Cita::DevuelveTelefonica()
{
    return telefonica;
}

int Cita::DevuelvePaciente()
{
    return nhc;
}

string Cita::DevuelveDoctor()
{
    return doctor;
}