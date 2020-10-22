#include "ListaAlquileres.h"
#include <algorithm>
#include "Date.h"
ListaAlquileres::ListaAlquileres() : tam(0), tamReal(0), alquileres(nullptr){}


int ListaAlquileres::GetTam() const {
	return  tam;
}

int ListaAlquileres::GetTamReal() const {
	return  tamReal;
}

Coche* ListaAlquileres::GetNCoche(int n) const{
	return alquileres[n].GetCochePunt();
}
int ListaAlquileres::GetNCochePrecio(int n) const{
	return alquileres[n].GetPrecio();
}

int ListaAlquileres::GetNCocheDias(int n) const {
	return alquileres[n].GetDays();
}


Date ListaAlquileres::GetNCocheFecha(int n) const {
	return alquileres[n].GetDate();
}

void ListaAlquileres::SetTam(int x) {
	tam = x;
}

void ListaAlquileres::SetTamReal(int x) {
	tamReal = x;
}

void ListaAlquileres::InicializaArray() {
	alquileres = new Alquiler[tam];
}

void ListaAlquileres::AddTamReal() {
	tamReal++;
}

void ListaAlquileres::SetNAlquiler(int n, int code, Date date, int days, Coche* cochePunt) {

	alquileres[n].SetAlquiler(code, date, days);
	alquileres[n].SetCoche(cochePunt);
}

Coche* ListaAlquileres::BuscaCoche(int codigo, const ListaCoches& listaCoches) {
	Coche* puntero = nullptr;

	bool encontrado = false;
	int x = 0;
	while (!encontrado && x < listaCoches.GetTam()) {

		if (codigo == listaCoches.GetNCocheCodigo(x)) puntero = listaCoches.GetNCochePunt(x);
		x++;
	}

	return puntero;
}


bool operator<(const Alquiler& a1, const Alquiler& a2) {
	return a1.GetDate() < a2. GetDate();
}

void ListaAlquileres::OrdenarAlquileres() {
	std::sort(alquileres, alquileres + tamReal, operator<);
}


bool ListaAlquileres::AddAlquiler(int code, Date fecha, int days, Coche* cochePunt) {
	bool devolver = false;
	
	if (tamReal < tam) {
		bool insertado = false;
		int x = 0;
		Alquiler swap;
		Alquiler insertar = Alquiler(code, fecha, days);
		insertar.SetCoche(cochePunt);


		while (!insertado && x < tam) {

			if (insertar.GetDate() < alquileres[x].GetDate() || alquileres[x].GetCode() == 0) {
				swap = alquileres[x];
				alquileres[x] = insertar;
				insertar = swap;
			}

			x++;
		}
		tamReal++;
		devolver = true;
	}


	return devolver;
}
