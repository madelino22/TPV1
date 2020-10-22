// Lab3 TPV1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Date.h"
#include "Coche.h"
#include "ListaCoches.h"
#include "ListaAlquileres.h"
#include <string>

using namespace std;

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
        
        listaCoches.SetTam(numCoches + 1); // +1 para que se pueda insertar al menos un coche
        listaCoches.InicializaArray();

        for (int x = 0; x < numCoches ; x++) {

           
            int code, price;
            string name;
            input >> code;
            listaCoches.SetNCocheCodigo(x, code);

            input >> price;
            listaCoches.SetNCochePrecio(x, price);

            getline(input, name);
            name.erase(0, 1);

            listaCoches.SetNCocheNombre(x, name);

           
            listaCoches.AddTamReal();
        }




        return true;
    }

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

        listaAlquileres.SetTam(numCoches + 1 );//para que se peudea insertar al menos un alquiler
        listaAlquileres.InicializaArray();

        int dia, mes, anho;
        int codigo, dias;
        Date fecha;
        Coche* cochePunt;

        for (int x = 0; x < numCoches; x++) {

            char c;
            input >> codigo;
            input >> dia >> c >> mes >> c >> anho;
            input >> dias;

            fecha = Date(dia, mes, anho);
            cochePunt = listaAlquileres.BuscaCoche(codigo, listaCoches);


            listaAlquileres.SetNAlquiler(x, codigo, fecha, dias, cochePunt);
            listaAlquileres.AddTamReal();
        }

        listaAlquileres.OrdenarAlquileres();
       

        return true;
    }

}

void mostrarAlquileres(const ListaAlquileres& listaAlquileres) {


    for (int x = 0; x < listaAlquileres.GetTamReal(); x++) {

        if (listaAlquileres.GetNCoche(x) != nullptr) {
            int dias = listaAlquileres.GetNCocheDias(x);
            int precio = listaAlquileres.GetNCochePrecio(x) * dias;
            Date fecha = listaAlquileres.GetNCocheFecha(x);
            fecha.print();
            Coche coche = *(listaAlquileres.GetNCoche(x));
            cout << " " << coche.GetNombre() << " " << dias << " dia(s) " << " por " << precio << " euros" << "\n";

        }
        else {
            Date fecha = listaAlquileres.GetNCocheFecha(x);
            fecha.print();
            cout << " ERROR: Coche inexistente \n";
        }



    }


}

void mostrarCoches(const ListaCoches& listaCoches) {


    for (int x = 0; x < listaCoches.GetTamReal(); x++) {

        if (listaCoches.GetNCoche(x) != nullptr) {
            //Dos formas de acceder a un valor de una clase:
            //mediante un método de otra clase que invoca al getter
            int codigo = listaCoches.GetNCocheCodigo(x);
            //consiguiendo la variable con un metodo de otra clase y accediedno al getter
            int precio = listaCoches.GetNCoche(x)->GetPrecio();


            string nombre = listaCoches.GetNCoche(x)->GetNombre();
            cout << codigo <<  " Precio al dia: " << precio << "$ " << nombre << "\n";

        }
        else {
           
            cout << " ERROR: Coche inexistente \n";
        }



    }


}

bool Menu( ListaAlquileres& listaAlquileres,   ListaCoches& listaCoches) {
   bool continuar = true;

   cout << " VerListaCoche ========> Ver la lista de los coches \n" <<
           " VerListaAlquileres  ==> Ver la lista de los alquileres \n" <<
           " AddCar ===============> Anhadir un coche a la lista de coches \n" <<
           " AddRent ==============> Anhadir un alquiler a la lista alquileres \n" <<
           " Salir ================> Salir del programa \n";

   string comando;
   cin >> comando;

   if (comando == "VerListaCoche") {
       mostrarCoches(listaCoches);
   }
   else if (comando == "VerListaAlquileres") {
      mostrarAlquileres(listaAlquileres);
   }
   else if(comando == "AddCar"){
       int code, price;
       string name;

       cout << "Codigo? \n";
       cin >> code;

       cout << "Precio por dia? \n";
       cin >> price;

       cin.ignore();//porque si no pasa directamete y no lee el nombre
       cout << "Nombre? \n";
       getline(cin, name);
       
       if (!listaCoches.AddCoche(code, price, name)) {

           cout << "No se puede insertar \n";
       }
       else {
           cout << "Insertado";
       }
   }
   else if (comando == "AddRent") {
       int code, days;
       Date fecha;
       Coche* cochePunt= nullptr;

       cout << "Codigo? \n";
       cin >> code;

       cout << "Dias alquilado? \n";
       cin >> days;

       cout << "Fecha(x/x/x)? \n";
       char c;
       int dia, mes, anho;
       cin >> dia >> c >> mes >> c >> anho;

       fecha = Date(dia, mes, anho);

       cochePunt = listaAlquileres.BuscaCoche(code, listaCoches);


       if (!listaAlquileres.AddAlquiler(code, fecha, days, cochePunt)) {

           cout << "No se puede insertar \n";
       }
       else {
           cout << "Insertado";
       }
       
       
   }
   else if (comando == "Salir") {
       continuar = false;
   }
   
   else {
     cout << " Introducir bien el comando \n";
   }
      
       
   
   system("pause");
   
   return continuar;




}



int main()
{
    ListaCoches listaCoches;
    ListaAlquileres listaAlquileres;


    cargarCoches(listaCoches);
    leerAlquileres(listaAlquileres, listaCoches);

    

   while(Menu(listaAlquileres, listaCoches)){}

    system("pause");
    std::cout << "Hello World!\n";
}


