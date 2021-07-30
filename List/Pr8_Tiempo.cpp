/******* Pr8_Tiempo.cpp *************************************************/ /**
 *
 * @file Pr8_Tiempo.cpp
 *
 * Implementaci�n de los m�todos de la clase Tiempo
 *
 * @version 1.0
 * @author Jorge Esteve
 * @author Miguel �ngel Gam�n
 * @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/

#include <iomanip>
#include <iostream>

#include "Pr8_Tiempo.h"

using namespace std;

/**** Tiempo::Tiempo () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Tiempo.
 * Inicializa el valor de tiempo con la hora y minuto a 0.
 *
 */
/**************************************************************************/
Tiempo::Tiempo()
{
	horas = minutos = 0;
	anyo = mes = dia = 1;
}

/**** Tiempo::Tiempo (int hora, int minuto) *******************************/ /**
 *
 * Constructor con argumentos de la clase Tiempo.
 * Inicializa el valor del tiempo a la hora y minuto indicadas.
 *
 * @param [in] hora		Valor de la hora
 * @param [in] minuto  	Valor del minuto
 *
 */
/**************************************************************************/
Tiempo::Tiempo(int hora, int minuto)
{
	if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
	{
		horas = minutos = 0;
		cerr << "Error: la hora introducida es incorrecta." << endl;
	}
	else
	{
		this->horas = hora;
		this->minutos = minuto;
	}

	anyo = mes = dia = 1;
}

/**** Tiempo::Tiempo(int hora, int minuto, int anyo, int mes, int dia) *******************************/ /**
 *
 * Constructor con argumentos de la clase Tiempo.
 * Inicializa todos los valores de la clase.
 *
 * @param [in] hora		Valor de la hora
 * @param [in] minuto  	Valor del minuto
 *
 */
/**************************************************************************/
Tiempo::Tiempo(int hora, int minuto, int anyo, int mes, int dia)
{
	if ((hora < 0 || hora > 23 || minuto < 0 || minuto > 59) && !FechaValida(anyo, mes, dia))
	{
		horas = minutos = 0;
		this->anyo = this->mes = this->dia = 1;
		cerr << "Error: la fecha introducida es incorrecta." << endl;
	}
	else
	{
		this->horas = hora;
		this->minutos = minuto;
		this->anyo = anyo;
		this->mes = mes;
		this->dia = dia;
	}
}

/**** void Tiempo::EstableceHora (int h) **********************************/ /**
 *
 * Establece el valor de la hora.
 *
 * @param [in] h	Valor de la hora
 *
 */
/**************************************************************************/
void Tiempo::EstableceHora(int h)
{
	if (h < 0 || h > 23)
	{
		horas = minutos = 0;
		cerr << "Error: la hora introducida es incorrecta." << endl;
	}
	else
		this->horas = h;
}

/**** int Tiempo::DevuelveHora () *****************************************/ /**
 *
 * Devuelve el valor de la hora.
 *
 * @return Valor de la hora
 *
 */
/**************************************************************************/
int Tiempo::DevuelveHora()
{
	return horas;
}

/**** void Tiempo::EstableceMinuto (int m) ********************************/ /**
 *
 * Establece el valor del minuto.
 *
 * @param [in] m	Valor del minuto
 *
 */
/**************************************************************************/
void Tiempo::EstableceMinuto(int m)
{
	if (m < 0 || m > 59)
	{
		horas = minutos = 0;
		cerr << "Error: el minuto introducida es incorrecto." << endl;
	}
	else
		this->minutos = m;
}

/**** void Tiempo::EstableceAnyo (int a) ********************************/ /**
 *
 * Establece el valor del anyo.
 *
 * @param [in] a	Valor del anyo
 *
 */
/**************************************************************************/
void Tiempo::EstableceAnyo(int a)
{
	if (a < 1)
	{
		cerr << "Error: el anyo introducido es incorrecto." << endl;
	}
	else
		this->anyo = a;
}

/**** void Tiempo::EstableceMes (int m) ********************************/ /**
 *
 * Establece el valor del mes.
 *
 * @param [in] m	Valor del mes
 *
 */
/**************************************************************************/
void Tiempo::EstableceMes(int m)
{
	if (m < 1 || m > 12)
	{
		cerr << "Error: el mes introducido es incorrecto." << endl;
	}
	else
		this->mes = m;
}

/**** bool Tiempo::FechaValida(int a, int m, int d) ********************************/ /**
 *
 * Comprueba que la fecha introducida es correcta.
 *
 * @param [in] a	Valor del anyo
 * @param [in] m	Valor del minuto
 * @param [in] d	Valor del dia
 */
/**************************************************************************/
bool Tiempo::FechaValida(int a, int m, int d)
{
	bool output = false;

	if (a > 0 && d > 0)
	{
		switch (m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			output = d < 32;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			output = d < 31;
			break;
		case 2:
			output = d < (!(a % 4 && a % 100 && a % 400) ? 30 : 29);
		}
	}

	return output;
}

/**** void Tiempo::EstableceDia(int d) ********************************/ /**
 *
 * Establece el valor del minuto.
 *
 * @param [in] d	Valor del minuto
 *
 */
/**************************************************************************/
void Tiempo::EstableceDia(int d)
{
	if (d < 0 || d > 59)
	{
		horas = minutos = 0;
		cerr << "Error: el minuto introducida es incorrecto." << endl;
	}
	else
		this->dia = d;
}

/**** int Tiempo::DevuelveMinuto () ***************************************/ /**
 *
 * Devuelve el valor del minuto.
 *
 * @return Valor del minuto
 *
 */
/**************************************************************************/
int Tiempo::DevuelveMinuto()
{
	return minutos;
}

/**** int Tiempo::DevuelveAnyo () ***************************************/ /**
 *
 * Devuelve el valor del anyo.
 *
 * @return Valor del anyo
 *
 */
/**************************************************************************/
int Tiempo::DevuelveAnyo()
{
	return anyo;
}

/**** int Tiempo::DevuelveMes () ***************************************/ /**
 *
 * Devuelve el valor del mes.
 *
 * @return Valor del mes
 *
 */
/**************************************************************************/
int Tiempo::DevuelveMes()
{
	return mes;
}

/**** int Tiempo::DevuelveDia () ***************************************/ /**
 *
 * Devuelve el valor del dia.
 *
 * @return Valor del dia
 *
 */
/**************************************************************************/
int Tiempo::DevuelveDia()
{
	return dia;
}

/*** ostream & operator<< (ostream & out, Tiempo t) *******************/ /**
 *
 *  Sobrecarga del operador salida que muestra el valor del tiempo
 *
 *  @param  [in,out]  out  stream de salida
 *  @param  [in]      t    tiempo a mostrar
 *
 */
/**********************************************************************/
ostream &operator<<(ostream &out, Tiempo t)
{
	out << "Fecha: " << t.dia << "/" << t.mes << "/" << t.anyo << endl;
	out << setiosflags(ios::right) << setw(2) << setfill('0') << t.horas;
	out << ":";
	out << setiosflags(ios::right) << setw(2) << setfill('0') << t.minutos;

	return out;
}

/*** bool Tiempo::operator<(Tiempo t) *******************/ /**
 *
 *  Sobrecarga del comparador
 *
 *  @param  [in]   t    tiempo a comparar
 *
 */
bool Tiempo::operator<(Tiempo t)
{
	bool output = false;

	if (this->anyo < t.anyo)
		output = true;
	else if (this->anyo == t.anyo)
	{
		if (this->mes < t.mes)
			output = true;
		else if (this->mes == t.mes)
		{
			if (this->dia < t.dia)
				output = true;
			else if (this->dia == t.dia)
			{
				if (this->horas < t.horas)
					output = true;
				else if (this->horas == t.horas)
				{
					if (this->minutos < t.minutos)
						output = true;
				}
			}
		}
	}

	return output;
}