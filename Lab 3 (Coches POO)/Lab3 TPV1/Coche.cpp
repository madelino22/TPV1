#include "Coche.h"

Coche::Coche() : codigo(), precio(), nombre() {}
Coche::Coche(int code, int price, string name) : codigo(code), precio(price), nombre(name) {}


int Coche::GetCodigo() const {
	return codigo;
}

int Coche::GetPrecio() const {
	return precio;
}

string Coche::GetNombre() const {
	return nombre;
}

void Coche::SetNombre(string name) {
    nombre = name;
}

void Coche::SetPrecio(int price) {
    precio = price;
}

void Coche::SetCodigo(int code) {
    codigo = code;
}

