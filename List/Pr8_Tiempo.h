/******* Pr8_Tiempo.h **************************************************/ /**
 *
 * @file Pr8_Tiempo.h
 *
 * Fichero de cabecera de la clase Tiempo
 *
 * @version 1.0
 * @author Jorge Esteve
 * @author Miguel �ngel Gam�n
*  @author Alberto Serrano Molto
 * @author Elena Saez Garcia
 *  
 ***************************************************************************/
#ifndef _TIEMPO_H_
#define _TIEMPO_H_

#include <iostream>

using namespace std;

/**
* @brief Clase que implementa el TAD Tiempo
*
* Clase que guarda el valor del tiempo en horas y minutos.
*/

class Tiempo
{
public:
	// Constructores
	Tiempo();
	Tiempo(int, int);
	Tiempo(int, int, int, int, int);

	// Operaciones
	void EstableceHora(int);
	void EstableceMinuto(int);
	void EstableceAnyo(int);
	void EstableceMes(int);
	void EstableceDia(int);
	int DevuelveHora();
	int DevuelveMinuto();
	int DevuelveAnyo();
	int DevuelveMes();
	int DevuelveDia();
	void Mostrar();

	// Sobrecarga de operadores
	friend ostream &operator<<(ostream &out, Tiempo t);
	bool operator<(Tiempo);

private:
	//Comprueba que la fecha es valida
	bool FechaValida(int, int, int);

	int horas;	 ///< Valor de las horas
	int minutos; ///< Valor de los minutos
	int anyo;	 ///< Valor del anyo
	int mes;	 ///< Valor del mes
	int dia;	 ///< Valor del dia
};

#endif
