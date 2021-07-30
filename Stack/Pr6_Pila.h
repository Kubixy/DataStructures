
/******* Pr6_Pila.h ****************************************************/ /**
 *
 * @file Pr6_Pila.h
 *
 * Fichero de cabecera de la clase Pila (estatica)
 *
 * @version 1.0
 * @author Jose Fco. Garcia
 * @author Miguel Angel Gamon
 *  
 ***************************************************************************/

#ifndef _PILA_H
#define _PILA_H

#include <iostream>
#include "Pr6_Contenedor.h"

using namespace std;

/**
 * @brief Clase para el manejo de Pilas
 *
 * Clase para manejar la informacion de Pilas.
 * Estan implementadas las operaciones basicas y se ha a�adido la sobrecarga
 * del operador '<<' para poder mostrar el contenido completo de la pila por
 * pantalla, y una operaci�n para obtener el n�mero de elementos de la pila.
 */
class Pila
{
public:
    typedef Contenedor Valor;

    // Constructores
    Pila();

    /// Metodos de modificacion de la Pila
    bool Apilar(Valor);
    bool Desapilar();

    // Metodos de consulta de la Pila
    bool CimaPila(Valor &);
    bool PilaVacia();

    // Metodos adicionales de la Pila
    int NumeroElementos();
    int Capacidad();

    // Sobrecarga del operador '<<'
    friend ostream &operator<<(ostream &, const Pila &);

private:
    /**
         * Numero de elementos maximo que podremos poner en la pila
         * Como esta pila se va a utilizar para la gestion de contenedores,
         * es el numero maximo de contenedores que se pueden apilar.
         */
    static const int MAX = 4;

    /**
         * Tipo auxiliar para guardar la informacion contenida en la Pila
         */
    typedef Valor Vector[MAX];

    Vector datos; ///< Vector donde guardaremos los elementos de la Pila

    /**
         * Indice que indica la posicion donde esta la informacion de la cima
         * de la pila
         */
    int cima;
};

#endif
