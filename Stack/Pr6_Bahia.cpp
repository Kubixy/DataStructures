
/******* Pr6_Contenedor.cpp **************************************************/ /**
 *
 * @file Pr6_Contenedor.cpp
 *
 * Implementaci�n de los m�todos de la clase Bahia
 *
 * @version 1.0
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#include "Pr6_Bahia.h"

/*** Bahia::Bahia() ****************************************************/ /**
 *  Constructor vacio
 */
/**********************************************************************/
Bahia::Bahia() {}

/*** bool Bahia::apilarAleatoriamiente(Contenedor c) ****************************************************/ /**
 *
 *  Anyade un contenedor aleatoriamente a una pila
 * 
 *  @param  [in] c contenedor a anyadir
 * 
 *  @retval  true	El contendor ha podido ser anyadido
 *  @retval  false  Todas las pilas de la bahia estan llenas
 *
 */
/**********************************************************************/
bool Bahia::apilarAleatoriamente(Contenedor c)
{
    return this->vPilas[rand() % 6].Apilar(c);
}

/*** bool Bahia::desapilarSiguiente() ****************************************************/ /**
 *
 *  Desapila el contendor con menor tiempo de espera
 * 
 *  @return  Devuelve true si la operacion tiene exito
 *
 */
/**********************************************************************/
bool Bahia::desapilarSiguiente()
{
    Contenedor c;
    int menor = 11, pos = -1;
    bool output = false;

    for (int i = 0; i < TOTAL_PILAS; i++)
        if (vPilas[i].CimaPila(c) && (c.DevuelveTiempo() < menor))
        {
            menor = c.DevuelveTiempo();
            pos = i;
        }

    if (pos != -1)
        output = vPilas[pos].Desapilar();

    return output;
}

/*** void Bahia::mostrarBahia()  ********************************************/ /**
 *
 *  Muestra las pilas de la bahia por pantalla
 *
 */
/*************************************************************************/
void Bahia::mostrarBahia()
{
    for (int i = 0; i < TOTAL_PILAS; i++)
        cout << vPilas[i] << endl;
}

/*** bool Bahia::apilarDinamicamente(Contenedor c)  ********************************************/ /**
 *
 *  Anyade un contenedor segun los especificaciones dadas
 * 
 *  @param  [in] c Contenedor a anyadir
 * 
 *  @return  Devuelve true si la operacion tiene exito
 *
 */
/*************************************************************************/
bool Bahia::apilarDinamicamente(Contenedor c)
{
    bool output = false;
    Contenedor con_local;

    for (int i = 0; i < TOTAL_PILAS && !output; i++)
        if (!vPilas[i].CimaPila(con_local) ||
            con_local.DevuelveCategoria() == c.DevuelveCategoria() &&
                con_local.DevuelveTiempo() >= c.DevuelveTiempo())
            output = vPilas[i].Apilar(c);

    return output;
}

/*** int Bahia::buscaPilaLibre(int p)  ********************************************/ /**
 *
 *  Desapila el contendor segun los especificaciones dadas
 * 
 *  @param  [in] p  Pila
 * 
 *  @return   -1 si no se ha encontrado un resultado
 *
 */
/*************************************************************************/
int Bahia::buscaPilaLibre(int p)
{
    int output = -1;

    for (int i = 0; i < TOTAL_PILAS && output == -1; i++)
        if (i != p && (vPilas[i].Capacidad() - vPilas[i].NumeroElementos() > 0))
            output = i;

    return output;
}

/*** bool Bahia::desapilarPorPosicion(int p, int a)  ********************************************/ /**
 *
 *  Desapila el contendor segun los especificaciones dadas
 * 
 *  @param  [in] p  Posicion pila
 *  @param  [in] a  Altura
 * 
 *  @return  Devuelve true si la operacion tiene exito
 *
 */
/*************************************************************************/
bool Bahia::desapilarPorPosicion(int p, int a)
{
    int altura_incial = vPilas[p].NumeroElementos();
    int p_local;
    Contenedor c;

    if (vPilas[p].NumeroElementos() == a)
        vPilas[p].Desapilar();
    else if (vPilas[p].NumeroElementos() > a)
    {
        p_local = buscaPilaLibre(p);
        if (p_local != -1)
        {
            vPilas[p].CimaPila(c);
            vPilas[p].Desapilar();
            vPilas[p_local].Apilar(c);
            desapilarPorPosicion(p, a);
            vPilas[p].Apilar(c);
            vPilas[p_local].Desapilar();
        }
    }

    return altura_incial > vPilas[p].NumeroElementos();
}
