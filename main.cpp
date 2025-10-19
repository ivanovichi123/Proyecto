//Ivan Arturo Rosas Balderas A01713176
#include <iostream>
#include <fstream> //Para poder recibir informacion del acrchivo .txt
#include <sstream>
#include <cstdlib> //Para utilizar rand()
using namespace std;
#include "vaca.h"   //Incluir la clase vaca
#include "fila.h"   //Incluir la clase fila
#include "cliente.h"    //Incluir la clase cliente

int main() {

    //Primero leer los datos de las vacas del archivo .txt
    fstream vacasHeredadas("Vacas.txt");

    //Variables que guardaran los datos
    int litro;
    string nombre; 
    int total;

    //Crear objeto de la clase vaca
    Vaca vacas;

    //Ver si se abrio correctamente
    if (!vacasHeredadas.is_open()) {
        return 0;
    }

    string linea;
    //Ciclo while que pasa por cada linea
    while(getline(vacasHeredadas,linea)) {
        //Convertir la linea en flujo de texto
        stringstream litroNombre(linea);
        //Guardar los valores
        litroNombre >> litro >> nombre;
        vacas.agregarLitroNombre(litro,nombre);
    }

    //Cerrar el archivo
    vacasHeredadas.close();

    //Leer los datos de los clientes del archivo .txt
    fstream clientela("Clientes.txt");

    //Variables que guardaran los datos
    string nombreCliente;
    int rango;

    //Crear objeto de la fila de clientes
    Fila filaClientes(30);

    //Ver si se abrio correctamente
    if(!clientela.is_open()) {
        return 0;
    }

    string lineaCliente;
    //Ciclo while que pasa por cada linea
    while(getline(clientela,lineaCliente)) {
        //Convertir la linea en flujo de texto
        stringstream nombreRango(lineaCliente);
        //Guardar los valores
        nombreRango >> nombreCliente >> rango;
        //Crear un objeto cliente
        Cliente nuevoCliente = Cliente(nombreCliente, rango);
        //Guardar el cliente en la fila
        filaClientes.ponerCliente(nuevoCliente);
    }

    //Cerrar el archivo
    clientela.close();

    //Mensaje inicial explicando el programa
    cout << "Bienvenido  granjero, acabas de heredar la granja de tu abuelo junto con su lista de clientes," << "\n"; 
    cout << "este programa te permite visualizar todo el ganado que se te fue heredado," << "\n";
    cout << "ademas de poder guardar el nombre de tus vacas junto con los litros que " << "\n";
    cout << "produce cada una y poder vender las vacas a los clientes." << "\n";
    cout << "La importancia de esto es para poder detectar mas facilmente las vacas mas y menos productivas y tener un control de la clientela." << "\n";
    cout << "Para poder vender una vaca a un cliente se debe de considerar el rango de cada cliente, es decir que solo aceptaran una vaca" << "\n";
    cout << "que produzca una cantidad de litros igual o mayor a la cantidad de su rango" << endl;

    //Variable que controla si se queda en el menu de opciones
    bool quedarse = true;


    //Ciclo del menu de opciones
    while (quedarse) {
        int opcion;
        cout << "\n" << "Escoja una de las siguientes opciones" << "\n";
        cout << "1.- Ver informacion" << "\n";
        cout << "2.- Ordenar datos de manera ascendente" << "\n";
        cout << "3.- Ordenar datos de manera descendente" << "\n";
        cout << "4.- Agregar otra vaca" << "\n";
        cout << "5.- Quitar una vaca" << "\n";
        cout << "6.- Ver proximo cliente" << "\n";
        cout << "7.- Ver fila de clientes" << "\n";
        cout << "8.- Vender vaca" << "\n";
        cout << "9.- Abrir tienda (Poner 5 clientes mas a la fila)" << "\n";
        cout << "10.- Salir" << "\n";

        //Obtener la opcion del personaje
        cin >> opcion;

        //Mostrar los litros y nombres de las vacas
        if (opcion == 1) {
            cout << "\n";
            cout << "----------  Informacion  ----------" << "\n";
            cout << "Total de vacas: " << vacas.getTotal() << "\n";
            cout << "Lista de litros que produce cada vaca: " << "\n";
            vacas.getLitros();
            cout << "\n";
            cout << "Lista de nombres de cada vaca: " << "\n";
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

        //Mostrar proximo cliente
        } else if (opcion == 6) {
            cout << "\n";
            cout << "----------  Cliente  ----------" << "\n";
            filaClientes.getActual();
            cout << "\n" << "-------------------------------" << "\n";
            cout << "\n";

        //Mostrar la fila de clientes
        } else if (opcion == 7) {
            cout << "\n";
            cout << "----------  Fila  ----------" << "\n";
            filaClientes.getFila();
            cout << "\n" << "----------------------------" << "\n";
            cout << "\n";

        //Vender vaca
        } else if (opcion == 8) {
            cout << "\n";
            cout << "----------  Vendiendo  ----------" << "\n";
            int indice;
            cout << "Ponga el indice de la vaca que quieres vender" << "\n";
            cin >> indice;
            //Ver que el indice no este fuera de rango
            if(indice >= vacas.getTotal()) {
                std::cout << "El indice no existe" << "\n";
                std::cout << "--------------------------------" << "\n";
            } else {
                //Obtener el valor de los litros de la vaca y el rango del cliente
                int litros = vacas.getLitroIndice(indice);
                int rango = filaClientes.getActualRango();
                cout << "El cliente: ";
                filaClientes.getActual();
                cout << "va a comprar a la vaca " << "\n";
                cout << vacas.getNombreIndice(indice) << ": " << vacas.getLitroIndice(indice) << "\n";

                //Compara que lso litros de la vaca corresponda al rango del cliente
                if(litros >= rango) {
                    vacas.quitarLitroNombre(indice);
                    filaClientes.quitarCliente();
                    cout << "La vaca ha sido vendida";
                    cout << "\n" << "--------------------------------" << "\n";
                    cout << "\n";
                } else {
                    cout << "La vaca no cumple con el rango del cliente";
                    cout << "\n" << "---------------------------------" << "\n";
                    cout << "\n";
                }

            }
        }

        //Agregar cinco clientes a la fila
        else if (opcion == 9) {
            cout << "\n";
            cout << "----------  Abriendo tienda  ----------" << "\n";
            bool listaLlena = false;

            //Leer los datos del archivo .txt
            fstream nuevosClientes("NuevosClientes.txt");

            //Crear un numero aleatorio entre 1 y 30
            int min = 1;
            int max = 25;
            int numeroAleatorio = min + (rand() % (max));

            //Variables que guardaran los datos
            string nombreCliente;

            //Contadores para obtener los nombres
            int contador = 0;
            int contadorMenos = 5;

            //Ver si se abrio correctamente
            if(!nuevosClientes.is_open()) {
                return 0;
            }

            string lineaCliente;
            //Ciclo while que pasa por cada linea
            while(getline(nuevosClientes,lineaCliente)) {
                if(filaClientes.lleno()) {
                    cout << "La lista esta llena" << "\n";
                    cout << "\n" << "---------------------------------------" << "\n";
                    cout << "\n";
                    listaLlena = true;
                    break;
                } else {
                    if(contador == numeroAleatorio && contadorMenos != 0) {
                    //Convertir la linea en flujo de texto
                    stringstream nombreRango(lineaCliente);
                    //Guardar los valores
                    nombreRango >> nombreCliente;
                    //Crear de manera al azar el rango del cliente
                    int minRan = 1;
                    int maxRan = 80;
                    int rangoAleatorio = minRan + (rand() % (maxRan));
                    //Crear un objeto cliente
                    Cliente nuevoCliente = Cliente(nombreCliente, rangoAleatorio);
                    //Guardar el cliente en la fila
                    filaClientes.ponerCliente(nuevoCliente);
                    //Disminuir contadorMenos
                    contadorMenos -= 1;
                    //Aumentar numeroAleatorio para que la condicion if siga siendo sea cierta
                    numeroAleatorio += 1;
                }
                contador += 1;
                }
            }

            //Cerrar el archivo
            nuevosClientes.close();

            //Si la lista se lleno ya no se muestra este mensaje;
            if (!listaLlena) {
                cout << "Ahora tienes 5 clientes mas" << "\n";
                cout << "\n" << "---------------------------------------" << "\n";
                cout << "\n";
            }
        }
        
        //Salir del programa
         else if (opcion == 10) {
            quedarse = false;

        //Da una opcion no valida
        } else {
            cout << "Escoge una opcion que si exista";
        }
    }

    return 0;

}