/******* Pr3_Unidad.h ****************************************************/ /**
 *
 * @file Pr3_Unidad.h
 *
 * Fichero de cabecera de la clase Unidad
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#ifndef _UNIDAD_H_
#define _UNIDAD_H_

#include <string>
#include "Pr8_Paciente.h"
#include "Pr8_Lista.h"

using namespace std;

/**
 * @brief Clase para el manejo de una unidad m�dica
 *
 * Clase para manejar la informaci�n de la unidad m�dica
 * Esta informaci�n esta compuesta por:
 *  - Nombre de la unidad
 *  - Conjunto de pacientes actuales
 */
class Unidad
{
public:
    // Constructor por defecto
    Unidad();
    // establece el nombre de la unidad
    void EstablecerNombre(string);
    // devuelve el nombre de la unidad
    string DevuelveNombre();
    // registra un paciente nuevo en la unidad
    bool RegistrarPaciente();
    // comprueba si existe un paciente
    int BuscarPaciente(int);
    //  muestra las pacientes actuales de la unidad
    void MostrarPacientes();
    // borra un paciente de la unidad
    bool BorrarPaciente(int);
    // registra una prueba realizada a un paciente
    bool RegistrarPruebaPaciente(int);
    // muestra el historial cl�nico del paciente
    bool MostrarHistorialPaciente(int);

    // Ampliacion
    // Registra la cita de un paciente
    void RegistrarCita(int);
    // Busca una cita
    void BuscarCita(int);
    // Elimina una cita
    void EliminarCita(int);
    // Muestra las citas ordenadas por fecha y hora
    void MostrarCitas();
    // Muestra las citas de un paciente concreto
    void MostrarCitasPaciente(int);

private:
    /**
         * M�ximo n�mero de pacientes que es posible almacenar
         */
    static const unsigned int MAX_PACIENTES = 100;

    /**
         * Tipo vector de pacientes
         */
    typedef Paciente TVecPacientes[MAX_PACIENTES];

    // Metedo para insertar un valor ordenadamente
    void InsertarOrden(Cita);

    // Atributos propios de una unidad m�dica
    string nombre;             ///< Cadena para almacenar el nombre de la unidad
    TVecPacientes vPacientes;  ///< Vector para almacenar los pacientes de la unidad
    unsigned int numPacientes; ///< N�mero actual de pacientes almacenados
    int numCita;               ///< ID cita
    Lista lista;               ///< Lista de citas
};

#endif
