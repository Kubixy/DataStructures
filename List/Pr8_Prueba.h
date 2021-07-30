/******* Pr8_Prueba.h ****************************************************/ /**
 *
 * @file Pr8_Prueba.h
 *
 * Fichero de cabecera de la clase Prueba
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#ifndef _PRUEBA_H_
#define _PRUEBA_H_

using namespace std;

#include <string>

/**
 * @brief Clase para el manejo de pruebas m�dicas
 *
 * Clase para manejar la informacion de una prueba m�dica.
 * Esta informaci�n esta compuesta por:
 *  - Fecha de la prueba
 *  - Tipo de prueba
 *  - Resultado
 */
class Prueba
{
public:
    // Constructor por defecto
    Prueba();
    // solicita por teclado los datos de una prueba
    void IntroducirPrueba();
    // devuelve la fecha de la prueba
    string DevuelveFecha();
    // devuelve el tipo de prueba
    string DevuelveTipo();
    // devuelve el resultado de la prueba
    bool DevuelveResultado();
    // muestra la informaci�n de la prueba
    void MostrarPrueba();

private:
    // Atributos propios de una prueba m�dica
    string fecha;   ///< Cadena para almacenar la fecha de la prueba
    string tipo;    ///< Cadena para almacenar el tipo de prueba
    bool resultado; ///< Booleano para almacenar el resultado de la prueba
};

#endif
