/******* Cola.h ****************************************************/ /**
 *
 * @file Cola.h
 *
 * Fichero de cabecera de la clase Cola 
 * 
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#ifndef _COLA_H
#define _COLA_H

#include <iostream>
#include "Vehiculo.h"

using namespace std;

/**
 * @brief Clase para el manejo de colas
 * 
 *  Esta informacion esta compuesta por:
 *      - inicio (cola)
 *      - fin   (cola)
 * -    - Numero de elementos
 */

class Cola
{
public:
    typedef Vehiculo Valor;
    //Constructores
    Cola();
    Cola(const Cola &);
    //Destructor
    ~Cola();
    //Sobrecarga del operador =
    const Cola &operator=(const Cola &);
    //Anyade un vehiculo a la cola
    void Encolar(Valor);
    //Elimina un vehiculo de la cola
    bool Desencolar();
    //Obtiene el primer vehiculo en la cola
    bool PrimeroCola(Valor &);
    //Comprueba si la cola esta vacia
    bool ColaVacia();
    //Obtiene el numero de vehiculos en la cola
    int NumeroElementos();
    //Muestra los vehiculos en la cola
    void MostrarCola();

private:
    struct Nodo;
    typedef Nodo *Puntero;
    struct Nodo
    {
        Valor info;
        Puntero sig;
    };
    Puntero inicio, fin; ///< Punteros para gestionar la cola
    //Vacia una cola
    void Vaciar();
    //Copia una cola
    void Copiar(const Cola &);
    int numeroElementos; ///< Representa el numero de elementos de la cola
};

#endif