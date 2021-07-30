/******* Pr8_Prueba.cpp **************************************************/ /**
 *
 * @file Pr8_Prueba.cpp
 *
 * Implementaci�n de los m�todos de la clase Prueba
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#include "Pr8_Prueba.h"

#include <iostream>

using namespace std;

/*** Prueba::Prueba () ***************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase. En nuestro caso iniciamos el resultado a false.
 *
 */
/*************************************************************************/
Prueba::Prueba()
    : resultado(false)
{
}

/*** Prueba::IntroducirPrueba (); ****************************************/ /**
 *
 *  Solicita al usuario los datos de la prueba m�dica.
 *  Fecha, tipo de la prueba y resultado (positivo o negativo)
 *
 */
/*************************************************************************/
void Prueba::IntroducirPrueba()
{
    char caracter;

    cout << "Introduce Fecha: ";
    cin >> fecha;

    cin.ignore();

    cout << "Introduce Tipo: ";
    getline(cin, tipo);

    do
    {
        cout << "Introduce resultado (P)ositivo/(N)egativo): ";
        cin >> caracter;
    } while (caracter != 'P' && caracter != 'N');
    resultado = caracter == 'P';
}

/*** string Prueba::DevuelveFecha ();  ***********************************/ /**
 *
 *  Devuelve la fecha de realizaci�n de la prueba
 *
 *  @return	Fecha de la prueba
 *
 */
/*************************************************************************/
string Prueba::DevuelveFecha()
{
    return fecha;
}

/*** string Prueba::DevuelveTipo ();  ************************************/ /**
 *
 *  Devuelve el tipo de la prueba
 *
 *  @return	Tipo de la prueba
 *
 */
/*************************************************************************/
string Prueba::DevuelveTipo()
{
    return tipo;
}

/*** bool Prueba::DevuelveResultado ();  *********************************/ /**
 *
 *  Devuelve el resultado de la prueba
 *
 *  @retval	true	Resultado positivo
 *	@retval	false	Resultado negativo
 *
 */
/*************************************************************************/
bool Prueba::DevuelveResultado()
{
    return resultado;
}

/*** void Prueba::MostrarPrueba (); **************************************/ /**
 *
 *  Muestra por pantalla toda la informaci�n de la prueba
 *
 */
/*************************************************************************/
void Prueba::MostrarPrueba()
{
    cout << "Fecha: " << fecha << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Resultado: ";
    if (resultado == true)
        cout << "Positivo" << endl;
    else
        cout << "Negativo" << endl;

    return;
}
