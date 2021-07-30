/******* Pr8_Paciente.h **************************************************/ /**
 *
 * @file Pr8_Paciente.h
 *
 * Fichero de cabecera de la clase Paciente
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#ifndef _PACIENTE_H_
#define _PACIENTE_H_

#include <string>
#include "Pr8_Prueba.h"

using namespace std;

/**
 * @brief Clase para el manejo de pacientes
 *
 * Clase para manejar la informaci�n de un paciente.
 * Esta informaci�n esta compuesta por:
 *  - NHC (N�mero de historial cl�nico)
 *  - Nombre completo
 *  - A�o de nacimiento
 *  - Sexo
 */
class Paciente
{
public:
    // Constructor por defecto
    Paciente();
    // solicita por teclado los datos de un paciente
    void IntroducirPaciente();
    // devuelve el NHC del paciente
    int DevuelveNHC();
    // devuelve el nombre del paciente
    string DevuelveNombre();
    // devuelve el a�o de nacimiento del paciente
    int DevuelveAnyoNacimiento();
    // devuelve el sexo del paciente
    char DevuelveSexo();
    // muestra los datos del paciente
    void MostrarPaciente();
    // a�ade una prueba medica al historial cl�nico del paciente
    bool AnyadirPrueba(Prueba);
    // muestra el historial cl�nico del paciente
    void MostrarHistorialClinico();

private:
    /**
         * M�ximo n�mero de pruebas m�dicas que es posible almacenar
         */
    static const unsigned int MAX_PRUEBAS = 50;

    /**
         * Tipo vector de pruebas m�dicas
         */
    typedef Prueba TVecPruebas[MAX_PRUEBAS];

    // Atributos propios de un paciente
    int nhc;                 ///< Entero para almacenar el NHC
    string nombre;           ///< Cadena para almacenar el nombre completo
    int anyo_nacimiento;     ///< Entero para almacenar el a�o de nacimiento
    char sexo;               ///< Caracter para almecenar el sexo: M = masculino, F = femenino
    TVecPruebas vPruebas;    ///< Vector para almecenar las pruebas m�dicas realizadas
    unsigned int numPruebas; ///< N�mero actual de pruebas almacenadas
};

#endif
