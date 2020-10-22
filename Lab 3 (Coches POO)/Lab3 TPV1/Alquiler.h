#pragma once

#include "Date.h"
#include "Coche.h"



class Alquiler
{

private:
    int codigo;
    Date fecha;
    int dias;
    Coche* coche;


public:
    Alquiler();
    Alquiler(int code, Date date, int days);

    int GetCode() const;
    Date GetDate() const;
    int GetDays() const;
    Coche* GetCochePunt() const;
    int GetPrecio() const;

    void SetCoche(Coche* car);
    void SetAlquiler(int code, Date date, int days);


};

