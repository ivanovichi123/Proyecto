//Ivan Arturo Rosas Balderas A01713176
#include <iostream>
#include <fstream> //Para poder recibir informacion del acrchivo .txt
#include <sstream>
#include <cstdlib> //Para utilizar rand()
using namespace std;
#include "vaca.h"   //Incluir la clase vaca
#include "fila.h"   //Incluir la clase fila
#include "cliente.h"    //Incluir la clase cliente
#include "arbol.h"  //Icluir la clase arbol

int main() {

    //Primero leer los datos de las vacas del archivo .txt
    fstream vacasHeredadas("Vacas.txt");

    //Variables que guardaran los datos
    int litro;
    string nombre;
    int salud; 
    int fecha;
    int total;

    //Crear objeto de la clase vaca
    Vaca vacas;

    //Crear el arbol que guardara las vacas
    Arbol arbol;

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
        litroNombre >> litro >> nombre >> salud >> fecha;
        vacas.agregarLitroNombreSaludableFecha(litro, nombre, salud, fecha);
        arbol.agregar(fecha, litro, nombre, salud);
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
    cout << "ademas de poder guardar el nombre de tus vacas junto con los litros que produce cada una y poder vender las vacas a los clientes." << "\n";
    cout << "La importancia de esto es para poder detectar mas facilmente las vacas mas y menos productivas y tener un control de la clientela." << "\n";
    cout << "Para poder vender una vaca a un cliente se debe de considerar el rango de cada cliente, es decir que solo aceptaran una vaca que produzca una cantidad de litros igual o mayor a la cantidad de su rango" << "\n";
    cout << "Ademas tambien se puede encontrar las vacas segun su fecha de adquisicion y saber si estan saludables o no.";

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
        cout << "8.- Vender vaca" << "\n"; //Aqui cambiar
        cout << "9.- Abrir tienda (Poner 5 clientes mas a la fila)" << "\n";
        cout << "10.- Encontrar vacas saludables segun su antiguedad" << "\n";
        cout << "11.- Encontrar vacas no saludables segun su antiguedad" << "\n";
        cout << "12.- Salir" << "\n";

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
            bool salud;
            int fecha;
            cout << "Ponga los litros que produce la vaca" << "\n";
            cin >> litro;
            cout << "Ponga el nombre de la vaca" << "\n"; 
            cin >> nombre;
            cout << "Ponga la salud de la vaca (1 = saludable, 0 = no saludable)" << "\n";
            cin >> salud;
            cout << "Ponga la fecha de la vaca (el formato debe ser [ultimos dos digitos del anio][mes][dia] ej: 15 de febrero de 2024 -> 240216)" <<"\n";
            cin >> fecha;
            vacas.agregarLitroNombreSaludableFecha(litro, nombre, salud, fecha);
            arbol.agregar(fecha, litro, nombre, salud);
            cout << "La vaca ha sido agregada" << "\n";
            vacas.getLitros();
            vacas.getNombres();
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
                arbol.eliminar(vacas.getFechaIndice(indice));
                vacas.quitarLitroNombreSaludableFecha(indice);
                cout << "La vaca ha sido quitada" << "\n";
                vacas.getLitros();
                vacas.getNombres();
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
                    // arbol.eliminar(vacas.getLitroIndice(indice), arbol.getraiz(), nullptr);
                    arbol.eliminar(vacas.getFechaIndice(indice));
                    vacas.quitarLitroNombreSaludableFecha(indice);
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

        //Busacr vacas saludables e base a una fecha
        else if (opcion == 10) {
            cout << "\n";
            cout << "----------  Busqueda de vacas saludables  ----------" << "\n";
            cout << "Selecciona la fecha minima de las vacas (el formato debe ser [ultimos dos digitos del anio][mes][dia] ej: 15 de febrero de 2024 -> 240216): " << "\n";

            //Variable que guarda la fehca minima
            int fechaMin;
            cin >> fechaMin;
            //Vector que guarda las vacas despues de la fecha minima
            vector<Nodo*> valores;
            //Buscar las vacas
            arbol.encontrar(fechaMin, valores);

            //Variables que guardan las fechas
            string fecha;
            string dia;
            string mes;
            string anio;

            //Variable que checa si se encontro una vaca con ese criterio
            bool encontro = false;

            cout << "Las vacas que estan saludables son: " << "\n";

            //Checar si el vector esta vacio
            if (valores.size() != 0) {
                //For que pasa por todos los nodos del vector
                for(int i = 0; i < valores.size(); i++) {
                    //Checar si la vaca esta saludable
                    if(valores[i] -> getSalud() == 1) {
                        //Se encontro por lo menos una vaca con ese criterio
                        encontro = true;
                        //Convertir el numero a string
                        fecha = to_string(valores[i] -> getFecha());
                        //Obtener los datos de la fecha en base a sus indices
                        dia = fecha.substr(4, 2);
                        mes = fecha.substr(2, 2);
                        anio = fecha.substr(0, 2);
                        //Desplegar los valores
                        cout << "Vaca: " << valores[i] -> getNombre() << ", que produce " << valores[i] -> getLitro() << " litros, que fue comprada el " 
                        << dia << " del mes " << mes << " del anio " << anio << "\n";
                    } 
                }
            }
            if (encontro == false) {
                cout << "No se encontro ni una vaca en base a esa fecha que esten saludables" << "\n";
            }
            cout << "\n" << "----------------------------------------------------" << "\n";
            cout << "\n";
        }

        else if(opcion == 11) {
            cout << "\n";
            cout << "----------  Busqueda de vacas no saludables  ----------" << "\n";
            cout << "Selecciona la fecha minima de las vacas (el formato debe ser [ultimos dos digitos del anio][mes][dia] ej: 15 de febrero de 2024 -> 240216): " << "\n";

            //Variable que guarda la fecha minima
            int fechaMin;
            cin >> fechaMin;
            //Vector que guarda las vacas despues de la fecha minima
            vector<Nodo*> valores;
            //Buscar las vacas
            arbol.encontrar(fechaMin, valores);

            //Variables que guardan las fechas
            string fecha;
            string dia;
            string mes;
            string anio;

            //Variable que checa si se encontro una vaca con ese criterio
            bool encontro = false;

            cout << "Las vacas que no estan saludables son: " << "\n";

            //Checar si el vector esta vacio
            if (valores.size() != 0) {
                //For que pasa por todos los nodos del vector
                for(int i = 0; i < valores.size(); i++) {
                    //Checar si la vaca no esta saludable
                    if(valores[i] -> getSalud() == 0) {
                        //Se encontro por lo menos una vaca con ese criterio
                        encontro = true;
                        //Convertir el numero a string
                        fecha = to_string(valores[i] -> getFecha());
                        //Obtener los datos de la fecha en base a sus indices
                        dia = fecha.substr(4, 2);
                        mes = fecha.substr(2, 2);
                        anio = fecha.substr(0, 2);
                        //Desplegar los valores
                        cout << "Vaca: " << valores[i] -> getNombre() << ", que produce " << valores[i] -> getLitro() << " litros, que fue comprada el " 
                        << dia << " del mes " << mes << " del anio " << anio << "\n";
                    } 
                }
            }
            if (encontro == false) {
                cout << "No se encontro ni una vaca en base a esa fecha que no esten saludables" << "\n";
            }
            cout << "\n" << "-------------------------------------------------------" << "\n";
            cout << "\n";
        }

        //Salir del programa
         else if (opcion == 12) {
            quedarse = false;

        //Da una opcion no valida
        } else {
            cout << "Escoge una opcion que si exista";
        }
    }

    return 0;

}


