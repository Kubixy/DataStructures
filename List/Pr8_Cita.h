/******* Pr8_Cita.h **************************************************/ /**
 *
 * @file Pr8_Cita.h
 *
 * Fichero de cabecera de la clase Cita
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia  
 *  
 *****************************************************************************/

#ifndef _CITA_H_
#define _CITA_H_

#include <string>
#include "Pr8_Tiempo.h"

using namespace std;

/**
 * @brief Clase para el manejo de las citas de los pacientes
 *
 * Clase para gestionar las citas de los pacientes.
 */

class Cita
{
public:
    // Constructor
    Cita();

    // Setters
    void EstableceNumero(int);
    void EstableceDescripcion(string);
    void EstableceTiempoPrevisto(Tiempo);
    void EstableceTelefonica(bool);
    void EstablecePaciente(int);
    void EstableceDoctor(string);

    // Getters
    int DevuelveNumero();
    string DevuelveDescripcion();
    Tiempo DevuelveTiempoPrevisto();
    bool DevuelveTelefonica();
    int DevuelvePaciente();
    string DevuelveDoctor();

    // Sobrecarga de operadores
    friend ostream &operator<<(ostream &out, Cita t);

private:
    int numCita;        ///< Numero de cita
    Tiempo fecha;       ///< Fecha y hora de la cita
    bool telefonica;    ///< Telefonica o presencial
    string descripcion; ///< Descripcion cita
    int nhc;            ///< ID paciente
    string doctor;      ///< Nombre del doctor
};

#endif
