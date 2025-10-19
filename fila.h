//Ivan Arturo Rosas Balderas A01713176
#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "cliente.h"    //Incluir la clase cliente

//Crear la clase fila que es una estructura de datos lineal queue
class Fila {
    private:
    int cabeza;     //Indice del primer cliente en la fila
    int cola;       //Indice donde se estara el nuevo cliente
    int tamano;     //Tamano maximo de la fila
    int contador;   //Numero de clientes en la lista
    Cliente *fila;  //Array que almacena clientes

    public:
    Fila(int);          //Constructor con parametros
    Fila(const Fila&);  //Constructor de copia
    ~Fila();            //Destructor
    void ponerCliente(const Cliente&);  //Agrega un cliente al final de la fila
    void quitarCliente();   //Elimina al cliente al frente de la fila
    bool vacio();           //Checa si esta vacia la fila
    bool lleno();           //Checa si esta llena la fila
    void getActual();       //Muestra al cliente al frente de la fila
    void getFila();         //Muestra a todos los clientes de la fila
    int getActualRango();   //Muestra el rango del cliente al frente de la fila 
};

//Constructo con parametros
Fila::Fila(int tam) {
    cabeza = 0;
    cola = 0;
    tamano = tam;
    contador = 0;
    fila = new Cliente[tam];
}

//Constructor de copia
Fila::Fila(const Fila &f) {
    cabeza = f.cabeza;
    cola = f.cola;
    tamano = f.tamano;
    contador = f.contador;
    fila = new Cliente[tamano];
    for (int i = 0; i < tamano; i++) {
        fila[i] = f.fila[i];
    }
}

//Destructor
Fila::~Fila() {
    delete [] fila;
    fila = 0;
    cabeza = 0;
    cola = 0;
    tamano = 0;
    contador = 0;
}

//Agrega cliente al final de la fila
void Fila::ponerCliente(const Cliente &c) {
    //Verifica si esta llena la fila
    if(lleno()) {
        std::cout << "La fila ya esta llena" << std::endl;
    } else { 
        //Inserta al cliente en la cola
        fila[cola] = c;
        //Avanza la cola de manera circular
        cola = (1 + cola) % tamano;
        //Contador de clientes aumenta
        contador += 1;
    }
}

//Quitar cliente al inicio de la fila
void Fila::quitarCliente() {
    //Verifica si esta vacia la fila
    if(vacio()) {
        std::cout << "La fila esta vacia" << std::endl;
    } else {
        //La cabeza avanza hacia el siguiente indice de manera circular
        cabeza = (1 + cabeza) % tamano;
        //Contador de clientes disminuye
        contador -= 1;
    }
}

//Verifica si esta vacia la lista
bool Fila::vacio() {
    if (contador == 0) {
        return true;
    } else {
        return false;
    }
}

//Verifica si esta llena la fila
bool Fila::lleno() {
    if(contador >= tamano) {
        return true;
    } else {
        return false;
    }
}

//Muestra al cliente que esta al frente de la lista
void Fila::getActual() {
    std::cout << fila[cabeza].getNombre() << " (" << fila[cabeza].getRango() << ")" << std::endl; 
}

//Muestra todos los clientes de la fila
void Fila::getFila() {
    //Comienza en la cabeza
    int i = cabeza;
    //Contador auxiliar
    int contador2 = 0;

    //Mientras que el contador auxiliar sea menor al numero total de clientes
    while (contador2 < contador) {
        std::cout << fila[i].getNombre() << " (" << fila[i].getRango() << ")" << std::endl;
        i = (i + 1) % tamano;
        contador2 += 1;
    }
}

//Devuelve el rango del cliente al frente de la fila
int Fila::getActualRango() {
    return fila[cabeza].getRango();
}


#endif