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
    std::vector<int> saludable;     //Guarda si la vaca esta saludable o no
    std::vector<int> fecha; //Guarda la fecha de adquisicion de la vaca


    public:
    Vaca();   //Constructor por defecto
    Vaca(int);    //Constructor con parametros
    Vaca(const Vaca&);  //Constructor de copia
    void setTotal(int); //Obtener el total de animales
    int getTotal() const;   //Devuelve el total de animales
    void getLitros();    //Devuelve los valores del vector
    void getNombres();   //Devuelve los nombres de las vacas
    void getSalud();    //Devuelve al salud de las vacas
    void getFecha();    //Devuelve la fecha de la vaca
    int getLitroIndice(int); //Devuelve el litro de la vaca
    string getNombreIndice(int); //Devuelve el nombre de la vaca
    int getFechaIndice(int);    //Devuelve al fecha de la vaca
    void ordenaAscendente();    //Ordena ascendentemente los litros de los vectores
    void ordenaDescendente();    //Ordena descendentemente los litros de los vectores
    void swap(vector<int>&, int, int);  //Intercambiar dos elementos
    void merge(vector<int>&, int, int, int, bool);    //Apoyo del metodo de ordenamiento
    void mergeSort(vector<int>&, int, int, bool);    //Metodo de ordenamiento
    void agregarLitroNombreSaludableFecha(int, string, int, int);   //Agrega una vaca, su nombre, salud y fecha
    void quitarLitroNombreSaludableFecha(int);    //Elimina una vaca en base al indice
};

//Constructor por defecto
Vaca::Vaca() : totalVacas(0) {}

//Constructor con parametros
Vaca::Vaca(int n) {
    totalVacas = n;
    saludable.resize(n);
    losLitros.resize(n);
    losNombres.resize(n);
    fecha.resize(n);
}

//Constructor por copia
Vaca::Vaca(const Vaca &v) : totalVacas(v.totalVacas), saludable(v.saludable), losLitros(v.losLitros), losNombres(v.losNombres), fecha(v.fecha) {}

//Obtiene el numero de vacas y cambia de tamaño los vectores
void Vaca::setTotal(int n) {
    totalVacas = n;
    saludable.resize(n);
    losLitros.resize(n);
    losNombres.resize(n);
    fecha.resize(n);
}

//Devuelve el total de vacas
int Vaca::getTotal() const{
    return totalVacas;
}

//Imprime los litros de las vacas
void Vaca::getLitros() {
    std::cout << "[" << "\n";
    for(int i = 0; i < losLitros.size(); i++) {
        if (i == losLitros.size() - 1) {
            std::cout << losLitros[i];
        } else {
            std::cout << " " << losLitros[i] << " " << ",";
        }
        if((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
   }
   std::cout << "\n" << "]";
}

//Imprime los nombres de las vacas
void Vaca::getNombres() {
    std::cout << "[" << "\n";
    for(int i = 0; i < losNombres.size(); i++) {
        if (i == losNombres.size() - 1) {
            std::cout << losNombres[i];
        } else {
            std::cout << " " << losNombres[i] << " " << ",";
        }
        if((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
   }
   std::cout << "\n" << "]";
}

//Imprime la salud de las vacas
void Vaca::getSalud() {
    std::cout << "[" << "\n";
    for(int i = 0; i < saludable.size(); i++) {
        if (i == saludable.size() - 1) {
            std::cout << saludable[i];
        } else {
            std::cout << " " << saludable[i] << " " << ",";
        }
        if((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
   }
   std::cout << "]";
}

//Imprime la fecha de las vacas
void Vaca::getFecha() {
    std::cout << "[" << "\n";
    for(int i = 0; i < fecha.size(); i++) {
        if (i == fecha.size() - 1) {
            std::cout << fecha[i];
        } else {
            std::cout << " " << fecha[i] << " " << ",";
        }
        if((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
   }
   std::cout << "]";
}

//Devuelve el valor del litro de la vaca en el indice
int Vaca::getLitroIndice(int i) {
    return losLitros[i];
}

//Devuelve el nombre de la vaca en el indice
string Vaca::getNombreIndice(int i) {
    return losNombres[i];
}

//Devuelvela fecha de la vaca en el indice
int Vaca::getFechaIndice(int i) {
    return fecha[i];
}

// Ordena litros, nombres, salud y fecha de forma ascendente
void Vaca::ordenaAscendente() {
    mergeSort(losLitros, 0, totalVacas - 1, true);
}

// Ordena litros, nombres, salud y fecha de forma descendente
void Vaca::ordenaDescendente() {
    mergeSort(losLitros, 0, totalVacas - 1, false);
}

// Intercambia posiciones entre dos elementos
void Vaca::swap(vector<int> &litros, int a, int b) {
    int aux = litros[a];
    litros[a] = litros[b];
    litros[b] = aux;
    
    string aux2 = losNombres[a];
    losNombres[a] = losNombres[b];
    losNombres[b] = aux2;

    int aux3 = saludable[a];
    saludable[a] = saludable[b];
    saludable[b] = aux3;

    int aux4 = fecha[a];
    fecha[a] = fecha[b];
    fecha[b] = aux4;
}

//Función auxiliar para la recursion de merge sort
void Vaca::merge(vector<int> &litros, int inicio, int medio, int final, bool ascendente) {
    std::vector<int> vectorAyuda; //Vector que guardara los datos ordenados
    std::vector<std::string> vectorAyudaNombres;    //Vector que guardara los nombres ordenados
    std::vector<int> vectorAyudaSaludable;  //Vector que guardara la saludo ordenada
    std::vector<int> vectorAyudaFecha;  //Vector que guarda la fecha
    int i = inicio;     //Indice de la parte izquierda del vector
    int j = medio + 1;  //Indice de la parte derecha del vector
    int k = inicio;     //Indice del vectorAyuda

    //Mientras que haya elementos en ambas mitades
    while (i <= medio && j <= final) {
        bool condicion;
        //Saber si se quiere ordenar de forma ascendente
        if (ascendente) {
            //Menor primero
            condicion = (litros[i] < litros[j]);  
        } 
        //Si se ordena de forma descendente
        else {
            //Mayor primero
            condicion = (litros[i] > litros[j]);  
        }
        //Si la condición es verdadera
        if (condicion) {
            //Agregar el elemento al vectorAyuda
            vectorAyuda.push_back(litros[i]);
            vectorAyudaNombres.push_back(losNombres[i]);
            vectorAyudaSaludable.push_back(saludable[i]);
            vectorAyudaFecha.push_back(fecha[i]);
            i++;
        } else {
            //Agregar el elemento al vectorAyuda
            vectorAyuda.push_back(litros[j]);
            vectorAyudaNombres.push_back(losNombres[j]);
            vectorAyudaSaludable.push_back(saludable[j]);
            vectorAyudaFecha.push_back(fecha[j]);
            j++;
        }
        k++;
    }

    //Si quedan elementos en la parte izquierda
    if (i <= medio) { 
        //Ciclo for para copiar los elementos restantes
        for (; i <= medio; i++) { 
            vectorAyuda.push_back(litros[i]); 
            vectorAyudaNombres.push_back(losNombres[i]);
            vectorAyudaSaludable.push_back(saludable[i]);
            vectorAyudaFecha.push_back(fecha[i]);
            k++; 
        } 
    } else {    //Si quedan elementos en la parte derecha
        //Ciclo for para copiar los elementos restantes
        for (; j <= final; j++) { 
            vectorAyuda.push_back(litros[j]); 
            vectorAyudaNombres.push_back(losNombres[j]);
            vectorAyudaSaludable.push_back(saludable[j]);
            vectorAyudaFecha.push_back(fecha[j]);
            k++; 
        } 
    }

    int ayudaIndice = 0; 
    //Ciclo for para copiar los valores del vectorAyuda al vector original
    for (int ayuda = inicio; ayuda <= final; ayuda++) { 
        litros[ayuda] = vectorAyuda[ayudaIndice];
        losNombres[ayuda] = vectorAyudaNombres[ayudaIndice]; 
        saludable[ayuda] = vectorAyudaSaludable[ayudaIndice];
        fecha[ayuda] = vectorAyudaFecha[ayudaIndice];
        ayudaIndice++;
    }

}

// Método mergeSort recursivo para ordenar los litros y nombres
void Vaca::mergeSort(vector<int> &litros, int min, int max, bool ascendente) {
    if (min < max) {
        //Obtener la mitad del vector
        int mid = (min + max) / 2;
        //Llamada recursiva para ordenar los valores de la izquierda
        mergeSort(litros, min, mid, ascendente);
        //Llamada recursiva para ordenar los valores de la derecha
        mergeSort(litros, mid + 1, max, ascendente);
        //Llamada a una función que ordena los valores del vector
        merge(litros, min, mid, max, ascendente);
    }
}

// Agrega una nueva vaca con su respectivo litro y nombre
void Vaca::agregarLitroNombreSaludableFecha(int nuevo, string nombre, int salud, int laFecha) {
    totalVacas++;
    losLitros.resize(totalVacas);
    losLitros[totalVacas - 1] = nuevo;
    losNombres.resize(totalVacas);
    losNombres[totalVacas - 1] = nombre;
    saludable.resize(totalVacas);
    saludable[totalVacas - 1] = salud;
    fecha.resize(totalVacas);
    fecha[totalVacas - 1] = laFecha;
}

// Quita una vaca en el indice indicado
void Vaca::quitarLitroNombreSaludableFecha(int indice) {
        losLitros.erase(losLitros.begin() + indice);
        losNombres.erase(losNombres.begin() + indice);
        saludable.erase(saludable.begin() + indice);
        fecha.erase(fecha.begin() + indice);
        totalVacas -= 1;
}


#endif