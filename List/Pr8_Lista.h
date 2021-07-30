/******* Pr8_Lista.h **************************************************/ /**
 *
 * @file Pr8_Lista.h
 *
 * Fichero de cabecera de la clase Lista
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia  
 *  
 *****************************************************************************/

#ifndef _LISTA_H_
#define _LISTA_H_

#include "Pr8_Cita.h"

using namespace std;

/**
 * @brief Clase para el manejo de las citas de las listas
 */
class Lista
{
public:
    typedef Cita Valor;
    // Constructores
    Lista();
    Lista(const Lista &);
    // Destructor
    ~Lista();
    // Sobrecarga del operador =
    const Lista &operator=(const Lista &);

    //Operaciones
    void Insertar(Valor);
    bool Eliminar();
    bool Consultar(Valor &);
    bool ListaVacia();
    void IrAInicio();
    bool Avanzar();
    bool FinalLista();
    void Mostrar();

private:
    struct Nodo;
    typedef Nodo *Puntero;
    struct Nodo
    {
        Valor info;
        Puntero sig;
    };
    Puntero ini, fin, pto; ///< Punteros para gestionar la lista
    //Copia una lista
    void Copiar(const Lista &);
    void Vaciar();
};

#endif
