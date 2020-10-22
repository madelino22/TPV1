#pragma once

#include <string>
using namespace std;

class Coche
{
private:
    int codigo;
    int precio;
    string nombre;

public:
    Coche();//Constructora Vacía
    Coche(int code, int price, string name);

    //constantes ya que son getters
    int GetCodigo() const;
    int GetPrecio() const;
    string GetNombre() const;

    void SetNombre(string name);
    void SetPrecio(int price);
    void SetCodigo(int code);


};

