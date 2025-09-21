//Ivan Arturo Rosas Balderas A01713176
#ifndef VACA_H_
#define VACA_H_
#include <vector>
#include <iostream>

//Definicion de la clase Vaca
class Vaca {
    private:
    int totalVacas;  //Guarda el total de animales
    std::vector<int> losLitros;   //Vector que guarda los litros que producen las vacas
    std::vector<string> losNombres;    //Vector que guarda el nombre de las vacas


    public:
    Vaca();   //Constructor por defecto
    Vaca(int);    //Constructor con parametros
    Vaca(const Vaca&);  //Constructor de copia

    void setTotal(int); //Obtener el total de animales
    void setLitrosNombre(); //Obtener los litros de las vacas y sus nombres

    int getTotal() const;   //Devuelve el total de animales
    void getLitros();    //Devuelve los valores del vector
    void getNombres();   //Devuelve los nombres de las vacas

    void ordenaAscendente();    //Ordena ascendentemente los litros de los vectores
    void ordenaDescendente();    //Ordena descendentemente los litros de los vectores
    void swap(vector<int>&, int, int);  //Intercambiar dos elementos
    int partir(vector<int>&, int, int, bool);    //Apoyo del metodo de ordenamiento
    void quickSort(vector<int>&, int, int, bool);    //Metodo de ordenamiento
    void agregarLitroNombre(int, string);   //Agrega una vaca y su nombre
    void quitarLitroNombre(int);    //Elimina una vaca en base al indice
};

//Constructor por defecto
Vaca::Vaca() : totalVacas(0) {}

//Constructor con parametros
Vaca::Vaca(int n) {
    totalVacas = n;
    losLitros.resize(n);
    losNombres.resize(n);
}

//Constructor por copia
Vaca::Vaca(const Vaca &v) : totalVacas(v.totalVacas), losLitros(v.losLitros), losNombres(v.losNombres) {}

//Obtiene el numeor de vacas y cambia de tamaño los vectores
void Vaca::setTotal(int n) {
    totalVacas = n;
    losLitros.resize(n);
    losNombres.resize(n);
}

//Obtiene los litros y nombres de las vacas y los agrega a sus respectivos vectores
void Vaca::setLitrosNombre() {
    int litros;
    for (int i = 0; i < losLitros.size(); i++) {
        std::cout << "Ingresa los litros de la vaca " << i + 1 << ": ";
        cin >> litros;
        losLitros[i] = litros;
    }
    string nombre;
    for (int i = 0; i < losNombres.size(); i++) {
        std::cout << "Ingresa el nombre de la vaca " << i + 1 << ": ";
        cin >> nombre;
        losNombres[i] = nombre;
    }
}

//Devuelve el total de vacas
int Vaca::getTotal() const{
    return totalVacas;
}

//Imprime los litros de las vacas
void Vaca::getLitros() {
    std::cout << "[";
    for(int i = 0; i < losLitros.size(); i++) {
        if (i == losLitros.size() - 1) {
            std::cout << losLitros[i];
        } else {
            std::cout << losLitros[i] << ",";
        }
   }
   std::cout << "]";
}

//Imprime los nombres de las vacas
void Vaca::getNombres() {
    std::cout << "[";
    for(int i = 0; i < losNombres.size(); i++) {
        if (i == losNombres.size() - 1) {
            std::cout << losNombres[i];
        } else {
            std::cout << losNombres[i] << ",";
        }
   }
   std::cout << "]";
}

// Ordena litros y nombres de forma ascendente
void Vaca::ordenaAscendente() {
    quickSort(losLitros, 0, totalVacas - 1, true);
}

// Ordena litros y nombres de forma descendente
void Vaca::ordenaDescendente() {
    quickSort(losLitros, 0, totalVacas - 1, false);
}

// Intercambia posiciones entre dos elementos
void Vaca::swap(vector<int> &litros, int a, int b) {
    int aux = litros[a];
    litros[a] = litros[b];
    litros[b] = aux;
    
    string aux2 = losNombres[a];
    losNombres[a] = losNombres[b];
    losNombres[b] = aux2;
}

//Funcion auxiliar para la recursion de quick sort
int Vaca::partir(vector<int> &litros, int min, int max, bool ascendente) {
    int comparador = litros[max];
    int i = min - 1;

    for (int j = min; j < max; j++) {
        // Si es ascendente, coloca los menores a la izquierda, si es lo contrario coloca los mayores a la izquierda
        if (ascendente && litros[j] <= comparador || !ascendente && litros[j] >= comparador) {
            i += 1;
            swap(litros, i, j);
        }
    }
    swap(litros, i + 1, max);
    return i + 1;
}

// Método quicksort recursivo para ordenar los litros y nombres
void Vaca::quickSort(vector<int> &litros, int min, int max, bool ascendente) {
    if (min < max) {
        int elPartido = partir(litros, min, max, ascendente);

        quickSort(litros, min, elPartido - 1, ascendente); 
        quickSort(litros, elPartido + 1, max, ascendente); 
    }
}

// Agrega una nueva vaca con su respectivo litro y nombre
void Vaca::agregarLitroNombre(int nuevo, string nombre) {
    totalVacas++;
    losLitros.resize(totalVacas);
    losLitros[totalVacas - 1] = nuevo;
    losNombres.resize(totalVacas);
    losNombres[totalVacas - 1] = nombre;
}

// Quita una vaca en el indice indicado
void Vaca::quitarLitroNombre(int indice) {
    losLitros.erase(losLitros.begin() + indice);
    losNombres.erase(losNombres.begin() + indice);
}


#endif