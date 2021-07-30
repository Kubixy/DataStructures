/******* Pr6_Contenedor.cpp **********************************************/ /**
 *
 * @file Pr6_Contenedor.cpp
 *
 * Implementaci�n de los m�todos de la clase Contenedor
 *
 * @version 1.0
 * @author Miguel Angel Gamon
 *  
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Pr6_Contenedor.h"

/**
 * Puertos de destino
 */
const string PUERTOS_DESTINO[10] = {"Shangai", "Singapur", "Hong Kong", "Roterdam",
									"Los Angeles", "Hamburgo", "Shenzhen", "Busan", "FelixStowe", "Santos"};

/**
 * Categorias del contenedor (exportacion, transito, importacion)
 */
const string CATEGORIAS[3] = {"exporta", "transit", "importa"};

using namespace std;

/*** Contenedor::Contenedor () *******************************************/ /**
 *
 *  Asigna valores iniciales al contenedor. 
 *
 */
/*************************************************************************/
Contenedor::Contenedor()
{
	categoria = 0;
	tiempo_salida = 0;
	peso = 2300;
	destino = "(desconocido)";
}

/*** Contenedor::RellenarDatos () ****************************************/ /**
 *
 *  Rellena los datos del contenedor (categoria, tiempo estimado de salida,
 *  peso y puerto de destino) con valores aletorios.
 *
 */
/*************************************************************************/

void Contenedor::RellenarDatos()
{
	// Categoria aleatoria (exportacion, transito, importacion)
	categoria = rand() % 3;

	// Tiempo de salida entre 0 y 10 dias.
	tiempo_salida = rand() % 11;

	// Peso del contenedor: Entre 2300 (vacio) y 28000 kg.
	peso = rand() % 25700 + 2300;

	// Puerto de destino
	// En el caso de categoria 'importacion' el destino es el puerto local
	if (categoria == 2)
		destino = "Valencia";
	else
		destino = PUERTOS_DESTINO[rand() % 10];
}

/*** int Contenedor::DevuelveCategoria ();  ******************************/ /**
 *
 *  Devuelve la categor�a del contenedor.
 *
 *  @retval	1 - Exportacion
 *  @retval	2 - Transito
 *  @retval	3 - Importacion 
 *
 */
/*************************************************************************/
int Contenedor::DevuelveCategoria()
{
	return categoria;
}

/*** int Contenedor::DevuelveTiempo ();  *********************************/ /**
 *
 *  Devuelve el tiempo estimado de salida (en d�as) del contenedor.
 *
 *  @return	Tiempo estimado de salida (en d�as)
 *
 */
/*************************************************************************/
int Contenedor::DevuelveTiempo()
{
	return tiempo_salida;
}

/*** int Contenedor::DevuelvePeso ();  ***********************************/ /**
 *
 *  Devuelve el peso (en kg.) del contenedor.
 *
 *  @return	Peso (en kg.)
 *
 */
/*************************************************************************/
int Contenedor::DevuelvePeso()
{
	return peso;
}

/*** string Contenedor::DevuelveDestino ();  *****************************/ /**
 *
 *  Devuelve el puerto de destino del contenedor
 *
 *  @return	Puerto de destino
 *
 */
/*************************************************************************/
string Contenedor::DevuelveDestino()
{
	return destino;
}

/*** ostream & operator<<(ostream & out, Contenedor c) *******************/ /**
 *
 *  Sobrecarga del operador '<<' para llevar al stream de salida la
 *  informacion del contenedor
 *
 *  @return  El stream modificado
 *
 */
/*************************************************************************/
ostream &operator<<(ostream &out, Contenedor c)
{
	out << "  Categoria: " << CATEGORIAS[c.categoria];
	out << " - Salida (dias): " << c.tiempo_salida;
	out << " - Peso (kg): " << c.peso;
	out << " - Destino: " << c.destino;
	return out;
}
