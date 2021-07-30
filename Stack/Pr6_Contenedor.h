/******* Pr6_Contenedor.h ************************************************/ /**
 *
 * @file Pr6_Contenedor.h
 *
 * Fichero de cabecera de la clase Contenedor
 *
 * @version 1.0
 * @author Miguel Angel Gamon
 *  
 *****************************************************************************/

#ifndef _CONTENEDOR_H_
#define _CONTENEDOR_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Clase para el manejo de contenedores
 *
 * Clase para manejar la informacion de un contenedor.
 * Esta informacion esta compuesta por:
 *  - Categoria (exportacion, transito, importacion)
 *  - Tiempo estimado de salida (en dias)
 *  - Peso (en kg.)
 *  - Puerto de destino
 */
class Contenedor
{
public:
	// Constructor por defecto
	Contenedor();
	// rellena los datos del contenedor con valores aleatorios
	void RellenarDatos();
	// devuelve la categoria del contenedor
	int DevuelveCategoria();
	// devuelve el tiempo estimado de salida del contenedor
	int DevuelveTiempo();
	// devuelve el peso del contenedor
	int DevuelvePeso();
	// devuelve el puerto de destino del contenedor
	string DevuelveDestino();
	// muestra los datos del contenedor
	friend ostream &operator<<(ostream &, Contenedor);

private:
	// Atributos propios de un contenedor
	int categoria;	   // Entero para almancenar la categoria (1-exportacion, 2-transito, 3-importacion)
	int tiempo_salida; // Entero para almencenar el tiempo estimado de salida (en d�as)
	int peso;		   // Entero para almacenar el peso (en kg.)
	string destino;	   // Cadena para almacenar el puerto de destino
};

#endif
