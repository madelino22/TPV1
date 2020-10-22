#pragma once
#include "Coche.h"

class ListaCoches
{
private:
    int tam;
    int tamReal;
    Coche* coches;


public:
    //Para crearlo se necesita tam
    ListaCoches();

    int GetTam() const;
    int GetTamReal() const;
    Coche* GetNCoche(int n) const;
    int GetNCocheCodigo(int n) const;

    void SetNCoche(int n, Coche car);
    void SetNCocheCodigo(int n, int code);
    void SetNCochePrecio(int n, int precio);
    void SetNCocheNombre(int n, string name);
    void AddTamReal();
    void InicializaArray();
    void SetTam(int t);
    Coche* GetNCochePunt(int n) const;
    bool AddCoche(int code, int price, string name);

};

