//Ivan Arturo Rosas Balderas A01713176
#include <iostream>
using namespace std;
#include "vaca.h"   //Incluir la clase vaca

int main() {

    //Mensaje inicial explicando el programa
    cout << "Bienvenido  granjero, acabas de heredar la granja de tu abuelo, este programa te permite visualizar todo el ganado" << "\n";
    cout << "que se te fue heredado, ademas de poder guardar el nombre de tus vacas junto con los litros que produce cada una" << "\n";
    cout << "La importancia de esto es para poder detectar mas facilmente las vacas mas y menos productivas." << "\n";
    cout << "Primero indique cuantas vacas tiene en total: " << "\n";
    
    //Pedir al usuario cuantas vacas tiene
    int total;
    cin >> total;
    //Crear objeto de la clase Vaca
    Vaca vacas(total);

    cout << "Muy bien, ahora a a continuacion indique los litros que produce cada vaca y su nombre" << "\n";
    
    vacas.setLitrosNombre();

    //Variable que controla si se queda en el menu de opciones
    bool quedarse = true;


    //Ciclo del menu de opciones
    while (quedarse) {
        int opcion;
        cout << "Escoja una de las siguientes opciones" << "\n";
        cout << "1.- Ver informacion" << "\n";
        cout << "2.- Ordenar datos de manera ascendente" << "\n";
        cout << "3.- Ordenar datos de manera descendente" << "\n";
        cout << "4.- Agregar otra vaca" << "\n";
        cout << "5.- Quitar una vaca" << "\n";
        cout << "6.- Salir" << "\n";

        //Obtener la opcion del personaje
        cin >> opcion;

        //Mostrar los litros y nombres de las vacas
        if (opcion == 1) {
            cout << "\n";
            cout << "----------  Informacion  ----------" << "\n";
            cout << "Total de vacas: " << vacas.getTotal() << "\n";
            cout << "Lista de litros que produce cada vaca: ";
            vacas.getLitros();
            cout << "\n";
            cout << "Lista de nombres de cada vaca: ";
            vacas.getNombres();
            cout << "\n" << "-----------------------------------" << "\n";
            cout << "\n";

        //Ordena los litros de forma ascendente
        } else if (opcion == 2) {
            cout << "\n";
            cout << "----------  Ordenando de forma ascendente  ----------" << "\n";
            vacas.ordenaAscendente();
            cout << "Los litros han sido ordenados de forma ascendente" << "\n";
            vacas.getLitros();
            cout << "\n" << "-----------------------------------------------------" << "\n";
            cout << "\n";

        //Ordena los litros de forma descendente
        } else if (opcion == 3) {
            cout << "\n";
            cout << "----------  Ordenando de forma descendente  ----------" << "\n";
            vacas.ordenaDescendente();
            cout << "Los litros han sido ordenados de forma descendente" << "\n";
            vacas.getLitros();
            cout << "\n" << "------------------------------------------------------" << "\n";
            cout << "\n";

        //Agregar una vaca con su litro y nombre
        } else if (opcion == 4) {
            cout << "\n";
            cout << "----------  Agregando  ----------" << "\n";
            int litro;
            string nombre;
            cout << "Ponga los litros que produce la vaca" << "\n";
            cin >> litro;
            cout << "Ponga el nombre de la vaca" << "\n"; 
            cin >> nombre;
            vacas.agregarLitroNombre(litro, nombre);
            cout << "La vaca ha sido agregada" << "\n";
            vacas.getLitros();
            cout << "\n" << "---------------------------------" << "\n";
            cout << "\n";

        //Quitar una vaca
        } else if (opcion == 5) {
            cout << "\n";
            cout << "----------  Quitando  ----------" << "\n";
            int indice;
            cout << "Ponga el indice de la vaca que quieres quitar" << "\n";
            cin >> indice;
            if(indice >= vacas.getTotal()) {
                std::cout << "El indice no existe" << "\n";
                std::cout << "--------------------------------" << "\n";
            } else {
                vacas.quitarLitroNombre(indice);
                cout << "La vaca ha sido quitada" << "\n";
                vacas.getLitros();
                cout << "\n" << "--------------------------------" << "\n";
                cout << "\n";
            }
        
        //Salir del programa
        } else if (opcion == 6) {
            quedarse = false;

        //Da una opcion no valida
        } else {
            cout << "Escoge una opcion que si exista";
        }
    }

    return 0;

}