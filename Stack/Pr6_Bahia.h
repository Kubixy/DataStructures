/******* Pr6_Bahia.h ****************************************************/ /**
 *
 * @file Pr6_Bahia.h
 *
 * Fichero de cabecera de la clase Bahia 
 * 
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#ifndef _BAHIA_H
#define _BAHIA_H

#include <iostream>
#include "Pr6_Contenedor.h"
#include "Pr6_Pila.h"

using namespace std;

/**
 * @brief Clase para el manejo de Bahias
 * 
 *  Gestionamos un conjunto de 1 a 6 pilas
 */

class Bahia
{
public:
    // Constructor
    Bahia();
    // Apila aletoramiente el contenedor en una pila de la bahia
    bool apilarAleatoriamente(Contenedor);
    // Despila el contendor cuyo tiempo estimado de salida sea menor
    bool desapilarSiguiente();
    // Muestra el contenido de cada pila.
    void mostrarBahia();
    // Apilar el contenedor a partir de su categoria y tiempo estimado de salida
    bool apilarDinamicamente(Contenedor);
    // Desapila el contendor indicado
    bool desapilarPorPosicion(int, int);

private:
    // Busca una pila distinta a la pila indicada
    int buscaPilaLibre(int);

    // Numero de contenedores requeridos
    static const unsigned int TOTAL_PILAS = 6;

    // Tipo vector para almacenar contenedores
    typedef Pila pilas[TOTAL_PILAS];

    pilas vPilas; ///< Vector para almacenar las pilas de la bahia
};

#endif
