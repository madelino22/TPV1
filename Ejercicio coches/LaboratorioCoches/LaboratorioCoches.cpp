// LaboratorioCoches.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Coche {
    int codigo;
    int precio;
    string nombre;
 };

struct Fecha {

    int dia;
    int mes;
    int anho;
};




struct Alquiler {
    int codigo;
    Fecha fecha;
    int dias;
    Coche* coche;
};



struct ListaCoches {

   
    int tam;
    int tamReal;
    Coche* coches = new Coche[tam];
};


struct ListaAlquileres {


    int tam;
    int tamReal;
    Alquiler* alquileres = new Alquiler[tam];



};

bool cargarCoches(ListaCoches& listaCoches) {

    ifstream input;
    input.open("coches.txt");

    if (!input.is_open()) {
        cout << "Fichero no encontrado\n";
        return false;
    }
    else {
        int numCoches;
        input >> numCoches;

        for (int x = 0; x < numCoches; x++) {
            
            char Nombre;
            input >> listaCoches.coches[x].codigo;
            input >> listaCoches.coches[x].precio;
            getline(input, listaCoches.coches[x].nombre);
            listaCoches.coches[x].nombre.erase(0, 1);
            listaCoches.tamReal++;
        }


        

        return true;
    }

}


Coche* buscaCoche(int codigo, ListaCoches& listaCoches) {
    Coche* puntero = nullptr;

    bool encontrado = false;
    int x = 0;
    while (!encontrado && x < listaCoches.tam) {

        if (codigo == listaCoches.coches[x].codigo) puntero = &listaCoches.coches[x];
        x++;
    }

    return puntero;
}

bool leerAlquileres(ListaAlquileres& listaAlquileres, ListaCoches& listaCoches) {

    ifstream input;
    input.open("rent.txt");

    if (!input.is_open()) {
        cout << "Fichero no encontrado\n";
        return false;
    }
    else {
        int numCoches;
        input >> numCoches;

        for (int x = 0; x < numCoches; x++) {

            char c;
            input >> listaAlquileres.alquileres[x].codigo;
            input >> listaAlquileres.alquileres[x].fecha.dia >> c >> listaAlquileres.alquileres[x].fecha.mes >> c >> listaAlquileres.alquileres[x].fecha.anho;
            input >> listaAlquileres.alquileres[x].dias;
            listaAlquileres.tamReal++;
            listaAlquileres.alquileres[x].coche = buscaCoche(listaAlquileres.alquileres[x].codigo, listaCoches);
        }




        return true;
    }

}


bool operator<(const Alquiler& a1, const Alquiler& a2) {
    return (a1.fecha.anho < a2.fecha.anho ||
        (a1.fecha.anho == a2.fecha.anho && (a1.fecha.mes < a2.fecha.mes ||
            (a1.fecha.mes == a2.fecha.mes && a1.fecha.dia < a2.fecha.dia))));
}

 void ordenarAlquileres(ListaAlquileres& listaAlquileres) {

    sort(listaAlquileres.alquileres, listaAlquileres.alquileres + listaAlquileres.tamReal, operator<);
}


void mostrarAlquileres(ListaAlquileres& listaAlquileres) {

    for (int x = 0; x < listaAlquileres.tamReal; x++) {
       
        if (listaAlquileres.alquileres[x].coche != nullptr) {
            int precio = listaAlquileres.alquileres[x].coche->precio * listaAlquileres.alquileres[x].dias;
            cout << listaAlquileres.alquileres[x].fecha.dia << "/" << listaAlquileres.alquileres[x].fecha.mes << "/" << listaAlquileres.alquileres[x].fecha.anho << " "
                << listaAlquileres.alquileres[x].coche->nombre << " " << listaAlquileres.alquileres[x].dias << " " << "dia(s) por " << precio << " euros" << "\n";
        }
        else {
            cout << "ERROR: Coche inexistente \n" ;
        }
        
        

    }


}

int main()
{
<<<<<<< HEAD
    ListaCoches listaCoches = new ListaCoches{20,10};
    ListaAlquileres* listaAlquileres = new ListaAlquileres{20, 10};
=======
    ListaCoches* listaCoches = new ListaCoches{20,0};
    ListaAlquileres* listaAlquileres = new ListaAlquileres{20, 0};
>>>>>>> d03b28d3d469080883ef343b36c153ba3017033d
   
    cargarCoches(*listaCoches);
    leerAlquileres(*listaAlquileres, *listaCoches);
    ordenarAlquileres(*listaAlquileres);
    mostrarAlquileres(*listaAlquileres);


    delete[] listaCoches->coches;
    delete[] listaAlquileres->alquileres;
    delete listaCoches;
    delete listaAlquileres;

    system("pause");
}


