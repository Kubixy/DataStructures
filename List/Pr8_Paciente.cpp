/******* Pr8_Paciente.cpp ************************************************/ /**
 *
 * @file Pr8_Paciente.cpp
 *
 * Implementaci�n de los m�todos de la clase Paciente
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#include "Pr8_Paciente.h"

#include <iostream>

using namespace std;

/*** Paciente::Paciente () ***********************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase. En nuestro caso iniciamos NHC con valor 0, a�o de nacimiento 2000, 
 *  sexo 'M', y n�mero de pruebas actuales a 0.
 *
 */
/*************************************************************************/
Paciente::Paciente()
    : nhc(0), anyo_nacimiento(2000), sexo('M'), numPruebas(0)
{
}

/*** Paciente::IntroducirPaciente () *************************************/ /**
 *
 *  Solicita al usuario los datos de un paciente.
 *  NHC (n�mero de historial clinico), nombre completo, a�o de nacimiento,
 *  y sexo ('M'asculino o 'F'emenino)
 *
 */
/*************************************************************************/
void Paciente::IntroducirPaciente()
{
    cout << "Introduce NHC: ";
    cin >> nhc;

    cin.ignore();

    cout << "Introduce Nombre: ";
    getline(cin, nombre);

    cout << "Introduce Anyo de Nacimiento: ";
    cin >> anyo_nacimiento;

    do
    {
        cout << "Introduce sexo (M/F): ";
        cin >> sexo;
    } while (sexo != 'M' && sexo != 'F');
}

/*** int Paciente::DevuelveNHC ();  **************************************/ /**
 *
 *  Devuelve el c�digo NHC del paciente
 *
 *  @return	NHC del paciente
 *
 */
/*************************************************************************/
int Paciente::DevuelveNHC()
{
    return nhc;
}

/*** string Paciente::DevuelveNombre ();  ********************************/ /**
 *
 *  Devuelve el nombre del paciente
 *
 *  @return	Nombre del paciente
 *
 */
/*************************************************************************/
string Paciente::DevuelveNombre()
{
    return nombre;
}

/*** char Paciente::DevuelveSexo ();  ************************************/ /**
 *
 *  Devuelve el sexo del paciente
 *
 *  @retval	'M'	masculino
 *  @retval	'F'	femenino
 *
 */
/*************************************************************************/
char Paciente::DevuelveSexo()
{
    return sexo;
}

/*** int Paciente::DevuelveAnyoNacimiento ();  ***************************/ /**
 *
 *  Devuelve el a�o de nacimiento del paciente
 *
 *  @return	A�o de nacimiento
 *
 */
/*************************************************************************/
int Paciente::DevuelveAnyoNacimiento()
{
    return anyo_nacimiento;
}

/*** void Paciente::MostrarPaciente (); **********************************/ /**
 *
 *  Muestra por pantalla toda la informaci�n del paciente
 *
 */
/*************************************************************************/
void Paciente::MostrarPaciente()
{
    cout << "NHC: " << nhc << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Anyo Nacimiento: " << anyo_nacimiento << endl;
    cout << "Sexo: " << sexo << endl;

    return;
}

/*** void Paciente::AnyadirPrueba (Prueba p); ****************************/ /**
 *
 *  A�ade una prueba m�dica al historial cl�nico del paciente.
 *
 *  @retval  true	La prueba se ha a�adido correctamente.
 *  @retval  false  No se ha podido a�adir la prueba al historial porque no
 *                  hay espacio suficiente en memoria.
 *
 */
/*************************************************************************/
bool Paciente::AnyadirPrueba(Prueba p)
{
    bool ok = false;

    if (numPruebas < MAX_PRUEBAS)
    {
        vPruebas[numPruebas] = p;
        numPruebas++;
        ok = true;
    }

    return ok;
}

/*** void Paciente::MostrarHistorialClinico (); **************************/ /**
 *
 *  Muestra por pantalla el historial cl�nico (lista de pruebas m�dicas) 
 *  del paciente
 *
 */
/*************************************************************************/
void Paciente::MostrarHistorialClinico()
{
    if (numPruebas == 0)
        cout << "No hay pruebas registradas" << endl;
    else
    {
        cout << "Listado de pruebas: " << endl;
        cout << endl;

        for (unsigned int i = 0; i < numPruebas; i++)
        {
            vPruebas[i].MostrarPrueba();
            cout << endl;
        }
    }
}
