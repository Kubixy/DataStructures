/******* Cola.cpp **************************************************/ /**
 *
 * @file Cola.cpp
 *
 * Implementacion de los metodos de la clase Cola
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 *****************************************************************************/
#include "Cola.h"

#include <iostream>

using namespace std;

/*** Cola::Cola() ****************************************************/ /**
 *
 *  Inicia los punteros de la cola
 *
 */
/**********************************************************************/
Cola::Cola()
{
    inicio = nullptr;
    fin = nullptr;
    numeroElementos = 0;
}

/*** bool Cola::ColaVacia() ******************************************/ /**
 *
 *  Nos dice si una cola esta o no vacia
 *
 *  @retval  True  La cola esta vacia
 *  @retval  False  La cola contiene algun elemento
 *
 */
/**********************************************************************/
bool Cola::ColaVacia()
{
    return inicio == nullptr;
}

/*** void Cola::Encolar(Valor x) ******************************************/ /**
 *
 *  Anyade un elemento al final de la cola
 */
/**********************************************************************/
void Cola::Encolar(Valor x)
{
    Puntero p_aux;

    p_aux = new Nodo;
    p_aux->info = x;
    p_aux->sig = nullptr;

    if (inicio == nullptr)
        inicio = p_aux;
    else
        fin->sig = p_aux;

    fin = p_aux;
    numeroElementos++;
}

/*** bool Cola::Desencolar() ******************************************/ /**
 *
 *  Elimina el primer elemento de la cola
 */
/**********************************************************************/
bool Cola::Desencolar()
{
    bool vacio = inicio == nullptr;

    if (!vacio)
    {
        Puntero p_aux;
        p_aux = inicio;
        inicio = inicio->sig;
        if (inicio == nullptr)
            fin = nullptr;
        delete p_aux;
        numeroElementos--;
    }

    return vacio;
}

/*** Cola::PrimeroCola(Valor &x) ******************************************/ /**
 *
 *  Muestra la informacion relativa al primer vehiculo de la cola
 * 
 *  @return  Devuelve true si la cola no esta vacia
 */
/**********************************************************************/
bool Cola::PrimeroCola(Valor &x)
{
    bool vacio = inicio == nullptr;

    if (!vacio)
        x = inicio->info;

    return vacio;
}

/*** void Cola::Vaciar() ******************************************/ /**
 *
 *  Vacia una cola
 */
/**********************************************************************/
void Cola::Vaciar()
{
    Puntero p_aux;

    while (inicio != nullptr)
    {
        p_aux = inicio;
        inicio = inicio->sig;
        delete p_aux;
    }
}

/*** Cola::Copiar(const Cola &c) ******************************************/ /**
 *
 *  Funcion encarga de copiar una cola
 * 
 *  @param  [in] c Puntero a una cola
 */
/**********************************************************************/
void Cola::Copiar(const Cola &c)
{
    Puntero p_aux, dup;
    p_aux = c.inicio;

    while (p_aux != nullptr)
    {
        dup = new Nodo;
        dup->info = p_aux->info;
        dup->sig = nullptr;

        if (inicio == nullptr)
            inicio = dup;
        else
            fin->sig = dup;

        fin = dup;
        p_aux = p_aux->sig;
    }
}

/*** Cola::Cola(const Cola &c) ******************************************/ /**
 *
 *  Segundo constructor de la clase Cola
 * 
 *  @param  [in] c Puntero a una cola
 */
/**********************************************************************/
Cola::Cola(const Cola &c)
{
    inicio = nullptr;
    Copiar(c);
}

/*** const Cola &Cola::operator=(const Cola &c) ******************************************/ /**
 *
 *  Sobrecarga del operador =
 * 
 *  @param  [in] c Puntero a una cola
 */
/**********************************************************************/
const Cola &Cola::operator=(const Cola &c)
{
    Vaciar();
    Copiar(c);
    return *this;
}

/*** Cola::~Cola() ******************************************/ /**
 *
 *  Destructor de la clase Cola
 */
/**********************************************************************/
Cola::~Cola()
{
    Vaciar();
}

/*** int Cola::NumeroElementos() ******************************************/ /**
 *
 *  Devuelve el numero de vehiculos que se encuentran en la cola
 * 
 *  @return  entero que representa el numero de vehiculos en cola
 */
/**********************************************************************/
int Cola::NumeroElementos()
{
    return numeroElementos;
}

/*** void Cola::MostrarCola() ******************************************/ /**
 *
 *  Muestra la informacion de los vehiculos que conforman la cola
 */
/**********************************************************************/
void Cola::MostrarCola()
{
    Puntero p_aux = inicio;

    while (p_aux != nullptr)
    {
        cout << p_aux->info;
        p_aux = p_aux->sig;
    }
}