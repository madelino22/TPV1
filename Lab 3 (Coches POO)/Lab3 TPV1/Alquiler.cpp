#include "Alquiler.h"


Alquiler::Alquiler() : codigo(), fecha(), dias() {
	coche = new Coche;
	coche = nullptr;
};
Alquiler::Alquiler(int code, Date date, int days) : codigo(code), fecha(date), dias(days) {
	coche = new Coche;
	coche = nullptr;
};

int Alquiler::GetCode() const {
	return codigo;
}

Date Alquiler::GetDate() const {
	return fecha;
}

int Alquiler::GetDays() const {
	return dias;
}

Coche* Alquiler::GetCochePunt() const {
	return coche;
}

int Alquiler::GetPrecio() const {
	return coche->GetPrecio();
}

void Alquiler::SetAlquiler(int code, Date date, int days) {
	codigo = code;
	fecha = date;
	dias = days;
}

void Alquiler::SetCoche(Coche* car) {
	coche = car;
}

