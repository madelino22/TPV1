#include "ListaCoches.h"

ListaCoches::ListaCoches() : tam(0), tamReal(0), coches(nullptr) {
}




int ListaCoches::GetTam() const {
	return tam;
}

int ListaCoches::GetTamReal() const{
	return tamReal;
}

Coche* ListaCoches::GetNCoche(int n) const {
	
	return &coches[n];

}

int ListaCoches::GetNCocheCodigo(int n) const {
	return coches[n].GetCodigo();
}



void ListaCoches::SetNCoche(int n, Coche car) {
	coches[n] = car;
}

void ListaCoches::SetNCocheCodigo(int n, int code) {

	coches[n].SetCodigo(code);
}

void ListaCoches::SetNCochePrecio(int n, int price) {

	coches[n].SetPrecio(price);
}
void ListaCoches::SetNCocheNombre(int n, string name) {

	coches[n].SetNombre(name);
}



void ListaCoches::AddTamReal() {
	tamReal++;
}

void ListaCoches::SetTam(int t) {
	tam = t;
}

void ListaCoches::InicializaArray() {
	coches = new Coche[tam];

}

Coche* ListaCoches::GetNCochePunt(int n) const {
	return &coches[n];
}

bool ListaCoches::AddCoche(int code, int price, string name) {
	bool devolver = false;
	if (tamReal < tam) {
		bool insertado = false;
		int x = 0;
		Coche swap;
		Coche insertar = Coche(code, price, name);
		while (!insertado && x < tam) {

			if (insertar.GetCodigo() < coches[x].GetCodigo() || coches[x].GetCodigo() == 0) {
				swap = coches[x];
				coches[x] = insertar;
				insertar = swap;
			}
			
		    x++;
		}
		tamReal++;
		devolver = true;
	}
	
	
	return devolver;
}
