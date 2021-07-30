/******* Pr8_Lista.cpp *************************************************/ /**
 *
 * @file Pr8_Lista.cpp
 *
 * Implementacion de la clase Lista
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#include <iostream>

#include "Pr8_Lista.h"

using namespace std;

/*** Lista::Lista() ****************************************************/ /**
 *
 *  Inicia los punteros de la cola
 *
 */
/**********************************************************************/
Lista::Lista()
{
    ini = nullptr;
    fin = nullptr;
    pto = nullptr;
}

/*** bool Lista::ListaVacia() ******************************************/ /**
 *
 *  Nos dice si una lista esta o no vacia
 *
 *  @retval  True  La lista esta vacia
 *  @retval  False  La lista contiene algun elemento
 *
 */
/**********************************************************************/
bool Lista::ListaVacia()
{
    return ini == nullptr;
}

/*** void Lista::IrAInicio() ******************************************/ /**
 *
 *  Pone el punto en el inicio de la lista
 *
 */
/**********************************************************************/
void Lista::IrAInicio()
{
    pto = ini;
}

/*** bool Lista::Avanzar() ******************************************/ /**
 *
 *  Avanza, si es posible, la posicion del punto en la lista
 *
 */
/**********************************************************************/
bool Lista::Avanzar()
{
    bool ok;
    if (pto == nullptr)
        ok = false;
    else
    {
        ok = true;
        pto = pto->sig;
    }
    return ok;
}

/*** bool Lista::FinalLista() ******************************************/ /**
 *
 *  Nos dice si el punto ha llegado al final de la lista
 *
 */
/**********************************************************************/
bool Lista::FinalLista()
{
    return pto == nullptr;
}

/*** bool Lista::Consultar(Valor &x) ******************************************/ /**
 *
 *  Obtenemos el valor del punto en la lista
 *
 */
/**********************************************************************/
bool Lista::Consultar(Valor &x)
{
    bool ok;
    if (pto == nullptr)
        ok = false;
    else
    {
        ok = true;
        x = pto->info;
    }
    return ok;
}

/*** void Lista::Insertar(Valor x) ******************************************/ /**
 *
 *  Inserta un valor en la lista
 *
 */
/**********************************************************************/
void Lista::Insertar(Valor x)
{
    Puntero p;
    p = new Nodo;
    if (pto == nullptr)
    {
        p->info = x;
        p->sig = nullptr;
        if (ini == nullptr)
            ini = p;
        else
            fin->sig = p;
        fin = p;
    }
    else
    {
        *p = *pto;
        pto->info = x;
        pto->sig = p;
        if (pto == fin)
            fin = p;
        pto = p;
    }
}

/*** bool Lista::Eliminar() ******************************************/ /**
 *
 *  Elimina un valor en la lista
 *
 */
/**********************************************************************/
bool Lista::Eliminar()
{
    Puntero p;
    bool ok;
    if (pto == nullptr)
        ok = false;
    else
    {
        ok = true;
        if (pto == fin)
        {
            if (pto == ini)
            {
                delete pto;
                ini = fin = pto = nullptr;
            }
            else
            {
                p = ini;

                while (p->sig != fin)
                    p = p->sig;

                fin = p;
                fin->sig = nullptr;
                delete pto;
                pto = nullptr;
            }
        }
        else
        {
            p = pto->sig;
            *pto = *p;
            if (p == fin)
                fin = pto;
            delete p;
        }
    }
    return ok;
}

/*** void Lista::Vaciar() ******************************************/ /**
 *
 *  Vacia una lista
 */
/**********************************************************************/
void Lista::Vaciar()
{
    Puntero p_aux;

    while (ini != nullptr)
    {
        p_aux = ini;
        ini = ini->sig;
        delete p_aux;
    }
}

/*** void Lista::Copiar(const Lista &l) ******************************************/ /**
 *
 *  Funcion encarga de copiar una lista
 * 
 *  @param  [in] l Puntero a una lista
 */
/**********************************************************************/
void Lista::Copiar(const Lista &l)
{
    Puntero p_aux, dup;
    p_aux = l.ini;

    while (p_aux != nullptr)
    {
        dup = new Nodo;
        dup->info = p_aux->info;
        dup->sig = nullptr;

        if (ini == nullptr)
            ini = dup;
        else
            fin->sig = dup;

        fin = dup;
        p_aux = p_aux->sig;
    }
}

/*** Lista::Lista(const Lista &l) ******************************************/ /**
 *
 *  Segundo constructor de la clase Lista
 * 
 *  @param  [in] l Puntero a una lista
 */
/**********************************************************************/
Lista::Lista(const Lista &l)
{
    ini = nullptr;
    Copiar(l);
}

/*** const Lista &Lista::operator=(const Lista &l) ******************************************/ /**
 *
 *  Sobrecarga del operador =
 * 
 *  @param  [in] l Puntero a una lista
 */
/**********************************************************************/
const Lista &Lista::operator=(const Lista &l)
{
    Vaciar();
    Copiar(l);
    return *this;
}

/*** Lista::~Lista() ******************************************/ /**
 *
 *  Destructor de la clase Lista
 */
/**********************************************************************/
Lista::~Lista()
{
    Vaciar();
}

/*** void Lista::Mostrar() ******************************************/ /**
 *
 *  Muestra la informacion de las citas
 */
/**********************************************************************/
void Lista::Mostrar()
{
    Puntero p_aux = ini;

    while (p_aux != nullptr)
    {
        cout << p_aux->info;
        p_aux = p_aux->sig;
    }
}