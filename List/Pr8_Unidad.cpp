/******* Pr8_Unidad.cpp **************************************************/ /**
 *
 * @file Pr8_Unidad.cpp
 *
 * Implementaci�n de los m�todos de la clase Unidad
 *
 * @version 1.0
 * @author Miguel Angel Gam�n
 *  
 *****************************************************************************/

#include "Pr8_Unidad.h"

#include <iostream>

using namespace std;

/*** Unidad::Unidad () ***************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase. En nuestro caso iniciamos nombre con el valor "Sin nombre", el
 *  n�mero de pacientes actuales a 0 y el numero de cita a 1.
 *
 */
/*************************************************************************/
Unidad::Unidad()
	: nombre("Sin nombre"), numPacientes(0), numCita(0)
{
}

/*** void Unidad::EstablecerNombre (string n); ***************************/ /**
 *
 *  Establece el nombre de la unidad m�dica
 * 
 *  @param  [in]	n	Nombre de la unidad
 *
 */
/*************************************************************************/
void Unidad::EstablecerNombre(string n)
{
	nombre = n;
}

/*** string Unidad::DevuelveNombre (); ***********************************/ /**
 *
 *  Devuelve el nombre de la unidad m�dica
 *
 *  @return	Nombre de la unidad
 *
 */
/*************************************************************************/
string Unidad::DevuelveNombre()
{
	return nombre;
}

/*** bool Unidad::RegistrarPaciente (); **********************************/ /**
 *
 *  Registra un nuevo paciente en la unidad: solicita los datos del paciente y,
 *  si no existe otro paciente con el mismo NHC, lo a�ade a la lista de
 *  pacientes actuales.
 *
 *  @retval  true	El paciente se ha registrado correctamente.
 *  @retval  false  Se ha encontrado otro paciente con el mismo NHC, o no hay
 *                  espacio suficiente en memoria para almacenar el paciente.
 *
 */
/*************************************************************************/
bool Unidad::RegistrarPaciente()
{
	Paciente paciente;
	int nhc;
	bool ok = false;

	paciente.IntroducirPaciente();
	nhc = paciente.DevuelveNHC();

	if (BuscarPaciente(nhc) == -1 && numPacientes < MAX_PACIENTES)
	{
		vPacientes[numPacientes] = paciente;
		numPacientes++;
		ok = true;
	}

	return ok;
}

/*** int Unidad::BuscarPaciente (int nhc);  ******************************/ /**
 *
 *  Comprueba si existe un paciente en la lista de pacientes con el NHC
 *	indicado.
 *
 *  @param  [in]	nhc	n�mero de historial clinico (NHC) del paciente
 *
 *  @return	La posici�n del paciente con el NHC indicado, si existe. En caso
 *			contrario, devuelve el valor -1.
 *
 */
/*************************************************************************/
int Unidad::BuscarPaciente(int nhc)
{
	unsigned int i = 0;
	int pos = -1;

	while (i < numPacientes && pos == -1)
	{
		if (vPacientes[i].DevuelveNHC() == nhc)
			pos = i;
		else
			i++;
	}

	return pos;
}

/*** void Unidad::MostrarPacientes (); ***********************************/ /**
 
 *  Muestra por pantalla la informaci�n de todos los pacientes actuales.
 *
 */
/*************************************************************************/
void Unidad::MostrarPacientes()
{
	if (numPacientes == 0)
		cout << "Sin pacientes" << endl;
	else
		for (unsigned int i = 0; i < numPacientes; i++)
		{
			vPacientes[i].MostrarPaciente();
			cout << endl;
		}

	return;
}

/*** bool Unidad::BorrarPaciente (int nhc);  *****************************/ /**
 *
 *  Borra un paciente de la lista de pacientes de la unidad.
 *
 *  @param  [in]	nhc	n�mero de historial cl�nico (NHC) del paciente
 *
 *  @retval  true	El paciente se ha borrado correctamente.
 *  @retval  false  No se ha encontrado ning�n paciente con el NHC indicado.
 *
 */
/*************************************************************************/
bool Unidad::BorrarPaciente(int nhc)
{
	int pos;
	bool ok = false;

	pos = BuscarPaciente(nhc);
	if (pos != -1)
	{
		for (unsigned int i = pos; i < numPacientes - 1; i++)
			vPacientes[i] = vPacientes[i + 1];

		numPacientes--;
		ok = true;
	}

	return ok;
}

/*** bool Unidad::RegistrarPruebaPaciente (int nhc); *********************/ /**
 *
 *  Registra un prueba m�dica de un paciente: solicita el NHC del paciente y,
 *	si existe dicho paciente, a�ade la prueba m�dica a su historial cl�nico.
 *
 *  @retval  true	La prueba se ha registrado correctamente.
 *  @retval  false  No se ha encontrado ning�n paciente con el NHC indicado, o no
 *                  hay espacio suficiente en memoria para almacenar la prueba.
 *
 */
/*************************************************************************/
bool Unidad::RegistrarPruebaPaciente(int nhc)
{
	Prueba prueba;
	int pos;
	bool ok = false;

	pos = BuscarPaciente(nhc);
	if (pos != -1)
	{
		prueba.IntroducirPrueba();
		ok = vPacientes[pos].AnyadirPrueba(prueba);
	}

	return ok;
}

/*** bool Unidad::MostrarHistorialPaciente (int nhc) *********************/ /**
 *
 *  Muestra los datos de un paciente, si existe, y su historial cl�nico (lista
 *  de pruebas m�dicas).
 *
 *  @retval  true	Los datos del historial del paciente se han mostrado
 * 					correctamente.
 *  @retval  false  No se ha encontrado ning�n paciente con el NHC indicado.
 *
 */
/*************************************************************************/
bool Unidad::MostrarHistorialPaciente(int nhc)
{
	int pos;
	bool ok = false;

	pos = BuscarPaciente(nhc);
	if (pos != -1)
	{
		vPacientes[pos].MostrarPaciente();
		cout << endl;
		vPacientes[pos].MostrarHistorialClinico();
		ok = true;
	}

	return ok;
}

/*** void Unidad::InsertarOrden(Cita c) ***********************************/ /**
 *
 *  Registra una cita ordenadamente
 *
 */
/*************************************************************************/
void Unidad::InsertarOrden(Cita c)
{
	bool fin = false;
	Cita tmp;
	lista.IrAInicio();

	while (!lista.FinalLista() && !fin)
	{
		lista.Consultar(tmp);

		if (c.DevuelveTiempoPrevisto() < tmp.DevuelveTiempoPrevisto())
			fin = true;
		else
			lista.Avanzar();
	}

	lista.Insertar(c);
}

/*** void Unidad::RegistrarCita(int nhc) ***********************************/ /**
 *
 *  Registra un paciente si existe
 *
 */
/*************************************************************************/
void Unidad::RegistrarCita(int nhc)
{
	int hora, minutos, anyo, mes, dia, mod;
	int paciente = BuscarPaciente(nhc);
	string descripcion, doctor;

	if (paciente != -1)
	{
		Cita c, tmp;

		cout << "Introduce hora: ";
		cin >> hora;
		cout << "Introduce minutos: ";
		cin >> minutos;
		cout << "Introduce anyo: ";
		cin >> anyo;
		cout << "Introduce mes: ";
		cin >> mes;
		cout << "Introduce dia: ";
		cin >> dia;

		Tiempo t(hora, minutos, anyo, mes, dia);
		c.EstableceTiempoPrevisto(t);

		cout << "Introduce modalidad (0 telef / 1 presenc): ";
		cin >> mod;
		c.EstableceTelefonica(mod == 0);
		cout << "Introduce descripcion: ";
		cin >> descripcion;
		c.EstableceDescripcion(descripcion);
		cout << "Introduce doctor: ";
		cin >> doctor;
		c.EstableceDoctor(doctor);

		c.EstablecePaciente(nhc);
		c.EstableceNumero(++numCita);

		InsertarOrden(c);
	}
	else
	{
		cout << "El paciente no existe." << endl;
	}
}

/*** void Unidad::BuscarCita(int numcita) ***********************************/ /**
 *
 *  Busca una cita en la lista
 *
 */
/*************************************************************************/
void Unidad::BuscarCita(int numcita)
{
	bool encontrado = false;
	Cita c;

	lista.IrAInicio();

	while (!lista.FinalLista() && !encontrado)
	{
		lista.Consultar(c);

		if (c.DevuelveNumero() == numcita)
		{
			encontrado = true;
			cout << c << endl;
		}
		else
			lista.Avanzar();
	}

	if (!encontrado)
		cout << "Cita no encontrada" << endl;
}

/*** void Unidad::EliminarCita(int numcita) ***********************************/ /**
 *
 *  Elimina una cita en la lista
 *
 */
/*************************************************************************/
void Unidad::EliminarCita(int numcita)
{
	bool encontrado = false;
	Cita c;
	int opt;

	lista.IrAInicio();

	while (!lista.FinalLista() && !encontrado)
	{
		lista.Consultar(c);

		if (c.DevuelveNumero() == numcita)
		{
			encontrado = true;

			cout << "Confirmar accion (-1 cancelar): ";
			cin >> opt;

			if (opt != -1)
				lista.Eliminar();
		}
		else
			lista.Avanzar();
	}

	if (!encontrado)
		cout << "Cita no encontrada" << endl;
}

/*** void Unidad::MostrarCitas() ***********************************/ /**
 *
 *  Muestra todas las citas
 *
 */
/*************************************************************************/
void Unidad::MostrarCitas()
{
	Cita c;

	if (!lista.ListaVacia())
	{
		lista.IrAInicio();

		while (!lista.FinalLista())
		{
			lista.Consultar(c);
			cout << c;
			lista.Avanzar();
		}
	}
	else
		cout << "No hay citas registradas" << endl;
}

/*** void Unidad::MostrarCitasPaciente(int nhc) ***********************************/ /**
 *
 *  Muestra todas las citas de un paciente concreto
 *
 */
/*************************************************************************/
void Unidad::MostrarCitasPaciente(int nhc)
{
	Cita c;
	if (!lista.ListaVacia())
	{
		lista.IrAInicio();

		while (!lista.FinalLista())
		{
			lista.Consultar(c);

			if (c.DevuelvePaciente() == nhc)
				cout << c;

			lista.Avanzar();
		}
	}
	else
		cout << "No hay citas registradas" << endl;
}