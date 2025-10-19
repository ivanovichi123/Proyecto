//Ivan Arturo Rosas Balderas A01713176
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

//Crear clase de cliente
class Cliente {
    private:
    std::string nombre;     //Nombre del cliente
    int rango;              //Rango de litros de leche

    public:
    Cliente();              //Constructor por defecto
    Cliente(std::string, int);  //Constructor con parametros
    Cliente(const Cliente&);    //Constructor de copia
    std::string getNombre();    //Devuelve el nombre del cliente
    int getRango();             //Devuelve el rango del cliente
};

//Constructor por defecto
Cliente::Cliente() {
    nombre = "";
    rango = 0;
}

//Constructor con parametros
Cliente::Cliente(std::string n, int r) {
    nombre = n;
    rango = r;
}

//Constructo de copia
Cliente::Cliente(const Cliente &c) {
    nombre = c.nombre;
    rango = c.rango;
}

//Devuelve el nombre del cliente
std::string Cliente::getNombre() {
 return nombre;
}

//Devuelve el rango del cliente
int Cliente::getRango() {
    return rango;
}

#endif