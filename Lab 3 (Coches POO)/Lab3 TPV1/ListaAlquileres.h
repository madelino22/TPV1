#pragma once

#include "Alquiler.h"
#include "ListaCoches.h"

class ListaAlquileres
{
private:
	int tam;
	int tamReal;
	Alquiler* alquileres;

public:

	ListaAlquileres();
	 
	int GetTam() const;
	int GetTamReal() const;
	Coche* GetNCoche(int n) const;
	int GetNCochePrecio(int n) const;
	int GetNCocheDias(int n) const;
	Date GetNCocheFecha(int n) const;

	void SetTam(int tam);
	void SetTamReal(int tamReal);
	void SetNAlquiler(int n, int code, Date date, int dias, Coche* cochePunt);

	void InicializaArray();
	void AddTamReal();
	void OrdenarAlquileres();
	bool AddAlquiler(int code, Date fecha, int dias, Coche* cochePunt);

	Coche* BuscaCoche(int codigo, const ListaCoches& listaCoches);

};

