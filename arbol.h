#ifndef ARBOL_H_
#define ARBOL_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Clase del nodo
class Nodo {
private:
    int fecha;  //Fecha de adquisicion
    int litros; //Litros de la vaca
    string nombre;  //Nombre de la vaca
    int salud;  //Salud de la vaca
    Nodo* izquierda;    //Hijo izquierdo del nodo 
    Nodo* derecha;  //Hijo derecho del nodo
    int balance;    //Balance del nodo

public:
    Nodo(int, int, string, int);    //Constructor con parametros
    int getFecha(); //Devuelve la fecha
    int getLitro(); //Devuelve el litro
    string getNombre(); //Devuelve el nombre
    int getSalud(); //Devuelve la salud
    Nodo* getIzquierda();   //Devuelve el nodo izquierdo
    Nodo* getDerecha(); //Devuelve el nodo derecho
    void setIzquierda(Nodo*);   //Establece el nodo izquierdo
    void setDerecha(Nodo*); //Establece el nodo derecho
    void agregar(int, int, std::string, int);   //Agrega un nuevo nodo
    bool buscar(int);   //Busca un nodo
    void encontrar(int, vector<Nodo*>&);    ////Encontrar todos los nodos mayores a la fecha minima 
    void eliminar(int); //Elimina un nodo
    int calcularBalance();  //Calcula el balance de los nodos
    Nodo* revisarArbol(int*, Nodo*, bool*); //Revisa si hay desbalanceo en el arbol
    Nodo* balancear();  //Balancea el arbol
    Nodo* rotarIzquierda(Nodo*);    //Rota hacia la izuqierda
    Nodo* rotarDerecha(Nodo*);  //Rota hacia la derecha
    Nodo* rotarIzquierdaDerecha(Nodo*); //Rota hacia izquierda y luego a la derecha
    Nodo* rotarDerechaIzquierda(Nodo*); //Rota hacia la derecha y luego a la izquierda
    Nodo* predecesor(); //Encuentra el predecesor
    void eliminarHijos();   //Elimina hijos del nodo
};

//Constructor con parametros
Nodo::Nodo(int f, int l, string n, int s) {
    fecha = f;
    litros = l;
    nombre = n;
    salud = s;
    izquierda = nullptr;
    derecha = nullptr;
    balance = 0;
}

//Devuelve la fecha 
int Nodo::getFecha() {
    return fecha;
}

//Devuelve los litros
int Nodo::getLitro() {
    return litros;
}

//Devuelve el nombre
string Nodo::getNombre() {
    return nombre;
}

//Devuelve la salud
int Nodo::getSalud() {
    return salud;
}

//Devuelve el nodo izquierdo
Nodo* Nodo::getIzquierda() {
    return izquierda;
}

//Devuelve el nodo derecho
Nodo* Nodo::getDerecha() {
    return derecha;
}

//Establece el nodo izquierdo
void Nodo::setIzquierda(Nodo* n) {
    izquierda = n;
}

//Establece el nodo derecho
void Nodo::setDerecha(Nodo* n) {
    derecha = n;
}

//Agrega un nuevo nodo
void Nodo::agregar(int f, int l, string n, int s) {
    //Checar si la fecha del nuevo nodo es menor a la del nodo actual
    if (f < fecha) {
        //Checar si tiene un nodo izquierdo
        if (izquierda != nullptr) {
            //Llamada recursiva desde el nodo izquierdo
            izquierda->agregar(f, l, n, s);
        } else {
            //Si no hay nodo establecer el nuevo nodo en la parte izquierda
            izquierda = new Nodo(f, l, n, s);
        }
    } else {
        //Checar si tiene un nodo derecho
        if (derecha != nullptr) {
            //Llamada recursiva desde el nodo derecho
            derecha->agregar(f, l, n, s);
        } else {
            //Si no hay nodo establecer el nuevo nodo en la parte derecha
            derecha = new Nodo(f, l, n, s);
        }
    }
}

//Buscar si existe un nodo con el valor de fecha indicado
bool Nodo::buscar(int f) {
    //Si la fecha dada es igual a la fecha del nodo
    if (f == fecha) {
        return true;
    //Si la fecha dada es menor a la fecha del nodo
    }  else if (f < fecha) {
        //Checar si el nodo tiene hijo izquierdo
        if (izquierda != nullptr) {
            //Llamada recursiva desde el hijo izquierdo
            return izquierda -> buscar(f);
        } else {
            //No existe nodo con ese valor de fecha
            return false;
        }
    //Si la fecha dada es mayor a la fecha del nodo
    } else {
        //Checar si el nodo tiene hijo derecho
        if (derecha != nullptr) {
            //Llamada recursiva desde el hijo derecho
            return derecha -> buscar(f);
        } else {
            //No existe nodo con ese valor de fecha
            return false;
        }
    }
}

//Encontrar todos los nodos mayores a la fecha minima 
void Nodo::encontrar(int minFecha, vector<Nodo*>& resultado) {
    //Si el nodo es nulo se regresa
    if (this == nullptr) {
        return;
    }

    // Checar si la fecha del nodo es mayor o igual a la fecha minima
    if (fecha >= minFecha) {

        //Checar is el hijo izquierdo existe
        if (izquierda != nullptr) {
            //Llamada recursiva del hijo izquierdo
            izquierda -> encontrar(minFecha, resultado);
        }
        // Agregar este nodo porque es mayor a la fecha minima
        resultado.push_back(this);

        //Checar si el hijo derecho existe
        if (derecha != nullptr) {
            //Llamada recursiva del hijo derecho
            derecha -> encontrar(minFecha, resultado);
        }
    }
    //Si el nodo es menor a la fecha minima, ya no se busca en la izquierda sino en la derecha 
    else {
        //Checa si el hijo derecho existe
        if (derecha != nullptr) {
            //Llamada recursiva del hijo derecho
            derecha -> encontrar(minFecha, resultado);
        }
    }
    return;
}

//Funcion que devuelve el nodo predecesor
Nodo* Nodo::predecesor() {

    // Checar si no hay hijo izquierdo
    if (izquierda == nullptr) {
        //Nodo auxiliar que es el hjo derecho
        Nodo* auxiliar = derecha;
        //Desvincular la derecha del nodo como nulo
        derecha = nullptr;
        return auxiliar;
    }

    //Variable padre que guarda el nodo antes del predecesor
    Nodo* padre = nullptr;
    //Variable que guarda el predecesor
    Nodo* actual = izquierda;

    //Checar si el hijo izquierdo no tiene hijo derecho
    if (actual -> derecha == nullptr) {
        //El hijo izquierda del nodo es el hijo izquierdo del predecesor
        izquierda = actual -> izquierda;
        //Desvincular el hijo izquierdo del predecesor
        actual -> izquierda = nullptr;
        return actual;
    }

    //Ciclo while para buscar el ultimo hijo derecho del primer hijo izquierdo
    while (actual -> derecha != nullptr) {
        //Padre ahora es el nodo actual
        padre = actual;
        //Nodo actual es su hijo derecho
        actual = actual->derecha;
    }

    //Hacer que el padre dle predecesor apunte al subarbol izquierdo del predecesor
    padre -> derecha = actual -> izquierda;
    //Desvincular el hijo izquierdo del predecesor
    actual -> izquierda = nullptr;
    return actual;
}

//Elimina un nodo
void Nodo::eliminar(int f) {
    //Variable nodo que es el que sera borrado
    Nodo* nodoBorrar = nullptr;
    //Variable nodo que es el predecesor
    Nodo* elPredecesor = nullptr;

    //Checar si la fecha buscada es menor y si su hijo izquierdo existe
    if (f < fecha && izquierda != nullptr) {
        //Checar si el hijo izquierdo es igual a la fecha buscada
        if (izquierda->fecha == f) {
            //El nodo a borrar es el hijo izquierdo
            nodoBorrar = izquierda;
            //Buscar el predecesor del nodo a borrar
            elPredecesor = izquierda -> predecesor();
            //Checar si existe el predecesor
            if (elPredecesor != nullptr) {
                //El predecesor tomara el hijo izquierdo y derecho del nodo a borrar
                elPredecesor -> izquierda = nodoBorrar -> izquierda;
                elPredecesor -> derecha   = nodoBorrar -> derecha;
            }
            //El hijo izquierdo ahora sera el predecesor
            izquierda = elPredecesor;
            //Borrar el nodo
            delete nodoBorrar;
        } else {
            //Llamada recursiva del hijo izquierdo
            izquierda->eliminar(f);
        }
        return;
    }

    //Checar si la fecha buscada es mayor y su hijo derecho existe
    if (f > fecha && derecha != nullptr) {
        //Checar si el hijo derecho es igual a la fecha buscada
        if (derecha->fecha == f) {
            //El nodo a borrar es el hijo derecho
            nodoBorrar = derecha;
            //Buscar predecesor del nodo a borrar
            elPredecesor = derecha->predecesor();
            //Checar si existe el predecesor
            if (elPredecesor != nullptr) {
                //El predecesor tomara el hijo izquierdo y derecho del nodo a borrar
                elPredecesor -> izquierda = nodoBorrar -> izquierda;
                elPredecesor -> derecha   = nodoBorrar -> derecha;
            }
            //El hijo derecho ahora sera el predecesor
            derecha = elPredecesor;
            //Borrar el nodo
            delete nodoBorrar;

        } else {
            //Llamada recursiva del hijo derecho
            derecha->eliminar(f);
        }
    }
}

//Calcula el balance de los nodos
int Nodo::calcularBalance() {
    int laIzquierda = 0;
    int laDerecha = 0;

    //Checar si el hijo izquierdo existe
    if (izquierda != nullptr) {
        //Llamada recursiva a la izquierda sumando uno
        laIzquierda = izquierda->calcularBalance() + 1;
    }
    //Checar si el hijo derecho existe
    if (derecha != nullptr) {
        //Llamada recursiva a la derecha sumando uno
        laDerecha = derecha->calcularBalance() + 1;
    }

    //Calcular el balance
    balance = laIzquierda - laDerecha;

    //Regresar el subarbol mas largo
    if(laIzquierda > laDerecha) {
        return laIzquierda;
    } else {
        return laDerecha;
    }
}

//Revisa si hay desbalanceos y los arregla
Nodo* Nodo::revisarArbol(int *valor_checado, Nodo *padre, bool *revisado) {
    //Nodo que se balancea
    Nodo* resultado = nullptr;

    //Checar si existe el hijo izquierdo
    if (izquierda != nullptr) {
        //Llamada recursiva a la izquierda
        Nodo* temporal = izquierda->revisarArbol(valor_checado, this, revisado);
        //Checar si temporal no es nulo
        if (temporal != nullptr)  {
            //El resultado es el nodo que se balanceo
            resultado = temporal;
        }
    }

    //Checar si existe el hijo derecho
    if (derecha != nullptr) {
        //Llamada recursiva a la derecha
        Nodo* temporal = derecha->revisarArbol(valor_checado, this, revisado);
        //Checar si temporal no es nulo
        if (temporal != nullptr) {
            //El resultado es el nodo que se balanceo
            resultado = temporal;
        } 
    }

    //Checar si ya se reviso un nodo
    if (*revisado == true) {
        return resultado;
    }


    //Establecer si el nodo esta desequilibrado de la parte derecha o izquierda
    bool desbalanceIzquierdo  = (balance > 1);
    bool desbalanceDerecho  = (balance < -1);

    //Checar si hay un desbalance
    if (desbalanceIzquierdo || desbalanceDerecho) {

        //Guardar el nodo balanceado
        resultado = balancear();
        //Establecer que ya se balanceo un nodo
        *revisado = true;
        //Establecer el valor del nodo que se checo
        *valor_checado = fecha;

        //Checar si el padre existe
        if (padre != nullptr) {
            //Variables que indican si el nodo cambiado es hijo derecho o izquierdo
            bool hijoIzquierdo = false;
            bool hijoDerecho = false;
            //Checar si el hijo izquierdo existe y si el nodo balanceado es hijo izquierdo del padre
            if (padre -> izquierda != nullptr && padre -> izquierda -> fecha == fecha) {
                hijoIzquierdo = true;
            //Si es falso, el nodo balanceado es hijo derecho
            } else {
                hijoDerecho = true;
            }

            //Checar si es nodo balanceado es hijo derecho o izquierdo
            if (hijoIzquierdo == true) {
                //Establecer como hijo izquierdo el nodo balanceado
                padre -> izquierda = resultado;
            } else if (hijoDerecho == true) {
                //Establecer como hijo derecho el nodo balanceado
                padre->derecha = resultado;
            }
        }
    }

    //Devolver el nodo balanceado
    return resultado;
}

//Balancea el nodo
Nodo* Nodo::balancear() {
    //Variable que guarda al nodo y sus hijos
    Nodo* nodo = this;
    Nodo* laIzquierda = izquierda;
    Nodo* laDerecha = derecha;

    //Checar is el balance es mayor a 0, osea que hay desbalance en la izquierda
    if (balance > 0) {
        //Checar si el hijo izquierdo existe y si el balance es mayor a cero, osea que el desbalance viene del subarbol izquierdo
        if (laIzquierda != nullptr && laIzquierda -> balance > 0) {
            //Rotar a la derecha
            nodo = rotarDerecha(nodo);
        } else {
            //Si el desbalance viene del subarbol derecho se rota a la izquierda y luego a la derecha
            nodo = rotarIzquierdaDerecha(nodo);
        }
    //Hay un desbalance en la derecha
    } else {
        //Checar si el hijo derecho existe y si el balance es menor a cero, osea que el desbalance viene del subarbol derecho
        if (laDerecha != nullptr && laDerecha -> balance < 0) {
            //Rotar a la izquierda
            nodo = rotarIzquierda(nodo);
        } else {
            //Si el desbalance viene del subarbol izquierdo se rota a la derecha y luego a la izquierda
            nodo = rotarDerechaIzquierda(nodo);
        }
    }
    //Regresar el nodo balanceado
    return nodo;
}

//Rotar a la izquierda
Nodo* Nodo::rotarIzquierda(Nodo* nodo) {
    //Checar si el nodo es nulo
    if (nodo == nullptr || nodo -> derecha == nullptr)
        return nodo;

    //El nuevo nodo es el hijo derecho
    Nodo* nuevoPadre = nodo -> derecha;
    //La derecha del nodo es el hijo izquierdo del nuevo nodo
    nodo -> derecha = nuevoPadre -> izquierda;
    //La izquierda del nuevo nodo es el nodo actual
    nuevoPadre -> izquierda = nodo;

    //Volver a calcular el balance de los nodos
    nodo -> calcularBalance();
    nuevoPadre -> calcularBalance();

    //Regresar el nuevo nodo
    return nuevoPadre;
}

Nodo* Nodo::rotarDerecha(Nodo* nodo) {
    //Checar si el nodo es nulo
    if (nodo == nullptr || nodo -> izquierda == nullptr)
        return nodo;

    //El nuevo nodo es el hijo izquierdo
    Nodo* nuevoPadre = nodo -> izquierda;
    //La izquierda del nodo es el hijo derecho del nuevo nodo
    nodo -> izquierda = nuevoPadre -> derecha;
    //La derecha del nuevo nodo es el nodo actual
    nuevoPadre -> derecha = nodo;

    //Volver a calcular el balance de los nodos
    nodo -> calcularBalance();
    nuevoPadre -> calcularBalance();

    //Regresar el nuevo nodo
    return nuevoPadre;
}

//Rotación izquierda y luego rotacion derecha
Nodo* Nodo::rotarIzquierdaDerecha(Nodo* nodo) {
    //Checar si el nodo es nulo
    if (nodo == nullptr) {
        return nodo;
    }
    //Checar is el hijo izquierdo existe
    if (nodo -> izquierda != nullptr) {
        //Hacer una rotacion izquierda del hijo izquierdo
        nodo -> izquierda = rotarIzquierda(nodo -> izquierda);
    }
    //Regresar una rotacion derecha
    return rotarDerecha(nodo);
}

//Rotacion derecha y luego rotacion izquierda
Nodo* Nodo::rotarDerechaIzquierda(Nodo* nodo) {
    //Checar is el nodo es nulo
    if (nodo == nullptr) {
        return nodo;
    } 
    //Checar su el hijo derecho existe
    if (nodo -> derecha != nullptr) {
        //Hacer una rotacion derecha del hijo derecho
        nodo -> derecha = rotarDerecha(nodo -> derecha);
    }
    //Regresar una rotacion izquierda
    return rotarIzquierda(nodo);
}

//Elimina los hijos de un nodo
void Nodo::eliminarHijos() {
    //Checar si el hijo izquierdo existe
	if (izquierda != nullptr) {
        //Llamada recursiva al hijo izquierdo
		izquierda -> eliminarHijos();
        //Eliminar el nodo hijo izquierdo
		delete izquierda;
        //Establecer como nulo el hijo izquierdo
		izquierda = nullptr;
	}
    //Checar si el hijo derecho existe
	if (derecha != nullptr) {
        //Llamada recursiva al hijo derecho
		derecha -> eliminarHijos();
        //Eliminar el nodo hijo derecho
		delete derecha;
        //Establecer como nulo el hijo derecho
		derecha = nullptr;
	}
}

//Clase del arbol
class Arbol {
private:
    Nodo *raiz; //Apuntador a la raiz del arbol

public:
    Arbol();    //Constructor del arbol
    ~Arbol();   //Destructor del arbol
    bool vacio() const; //Metodo que revisa si el arbol esta vacio
    void agregar(int, int, string, int);    //Metodo que agrega un nuevo nodo al arbol
    bool buscar(int) const; //Metodo que busca un nodo en el arbol
    void encontrar(int, vector<Nodo*>&);    //Metodo que encuentra un nodo en base a una fecha minima
    void eliminar(int); //Metodo que elimina un nodo del arbol
};

//Constructor del arbol
Arbol::Arbol() {
    //Establecer la raiz como nula
    raiz = nullptr;
}

//Destructor del arbol
Arbol::~Arbol() {
    //Checar si la raiz no es nula
    if (raiz != nullptr)
        //Eliminar los hijos del arbol
        raiz -> eliminarHijos();
    //Eliminar la raiz
    delete raiz;
    //Establecer la raiz como nula
    raiz = nullptr;
}

//Checar is el arbol esta vacio
bool Arbol::vacio() const {
    //Checar is la raiz es nula
    if(raiz == nullptr) {
        //El arbol esta vacio
        return true;
    } else {
        //Si la raiz apunta a un nodo, el arbol no esta vacio
        return false;
    }
}

//Agrega un nodo al arbol
void Arbol::agregar(int fecha, int litros, string nombre, int salud) {

    //Checar si la raiz esta vacia, osea el arbol no tiene nodos
    if (raiz == nullptr) {
        //Hacer que la raiz apunte al nuevo nodo
        raiz = new Nodo(fecha, litros, nombre, salud);
        return;
    }

    //Checar si ya existe un nodo con el mismo valor, para evitar valores duplicados
    if (raiz -> buscar(fecha) == true) {
        return;
    }

    //Agregar el valor al arbol
    raiz -> agregar(fecha, litros, nombre, salud);

    //Calcular los balances del arbol
    raiz -> calcularBalance();

    //Variable que guarda si ya se balanceo un nodo
    bool yaBalanceado = false;
    //Variable que guarda el valor del nodo balanceado
    int nodoAjustado = 0;

    //Revisar si hay desbalanceos y corregirlos
    Nodo* nuevaRaiz = raiz -> revisarArbol(&nodoAjustado, nullptr, &yaBalanceado);

    //Checar si el valor del nodo balanceado es igual al valor de la raiz, es decir que se modifico el nodo donde apunta la raiz
    if (nodoAjustado == raiz -> getFecha()) {
        //La nueva raiz es el valor del nodo que devolvio la funcion
        raiz = nuevaRaiz;
    }

    //Volver a calcular los balances del arbol
    raiz->calcularBalance();
}

//Busca si el valor existe en el arbol
bool Arbol::buscar(int fecha) const {
    //Checa si la raiz existe
    if(raiz != nullptr) {
        //Regresar el resultado de la funcion del nodo de buscar
        return raiz -> buscar(fecha);
    } else {
        //Si el arbol esta vacio no hay valores por buscar
        return false;
    }
}

//Encuentra un nodo en base a una fecha minima
void Arbol::encontrar(int f, vector<Nodo*>& valores) {
    //Checar si la raiz existe
    if(raiz != nullptr) {
        //Llamar a la funcion del nodo para encontrar el nodo
        raiz -> encontrar(f, valores);
    } else {
        return;
    }
}

//Elimina un nodo del arbol
void Arbol::eliminar(int fecha) {
    //Si la raiz esta vacia, no borra nada
    if (raiz == nullptr) {
        return;
    }
    //Checar si el valor es la raiz
    if (raiz -> getFecha() == fecha) {
        //Encontrar el predecesor
        Nodo* reemplazo = raiz -> predecesor();
        //Checar si el predecesor existe
        if (reemplazo != nullptr) {
            //Establecer los hijos izquierdo y derecho del predecesor
            reemplazo -> setIzquierda(raiz->getIzquierda());
            reemplazo -> setDerecha(raiz->getDerecha());
        }
        //Eliminar la raiz
        delete raiz;
        //La raiz apunta al predecesor
        raiz = reemplazo;
    }
    //El nodo no es la raiz
    else {
        //Llamar la funcion del nodo para eliminar
        raiz->eliminar(fecha);
    }

    //Calcular los balances del arbol
    raiz -> calcularBalance();
    //Variable que guarda si ya se balanceo un nodo
    bool yaBalanceado = false;
    //Variable que guarda el valor del nodo balanceado
    int nodoAjustado = 0;

    //Revisar si hay desbalanceos y corregirlos
    Nodo* nuevaRaiz = raiz->revisarArbol(&nodoAjustado, 0, &yaBalanceado);

    //Checar si el valor del nodo balanceado es igual al valor de la raiz, es decir que se modifico el nodo donde apunta la raiz
    if (nodoAjustado == raiz->getFecha()) {
        //La nueva raiz es el valor del nodo que devolvio la funcion
        raiz = nuevaRaiz;
    }

    //Volver a calcular los balances del arbol
    raiz -> calcularBalance();
}

#endif


// #ifndef ARBOL_H_
// #define ARBOL_H_
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;


// class Nodo {
// private:
//     int fecha;
//     int litros;
//     string nombre;
//     int salud;
//     Nodo* izquierda;
//     Nodo* derecha;
//     int nivel;
//     int balance;

// public:
//     Nodo(int, int, string, int);
//     int getFecha();
//     int getLitro();
//     string getNombre();
//     int getSalud();
//     Nodo* getIzquierda();
//     Nodo* getDerecha();
//     void setIzquierda(Nodo*);
//     void setDerecha(Nodo*);
//     void agregar(int, int, std::string, int);
//     bool buscar(int);
//     void encontrar(int, vector<Nodo*>&);
//     void eliminar(int);
//     void inorder(vector<int>&);
//     int calcularBalance();
//     Nodo* revisarArbol(int*, Nodo*, bool*);
//     Nodo* balancear();
//     Nodo* rotarIzquierda(Nodo*);
//     Nodo* rotarDerecha(Nodo*);
//     Nodo* rotarIzquierdaDerecha(Nodo*);
//     Nodo* rotarDerechaIzquierda(Nodo*);
//     Nodo* predecesor();
//     void eliminarHijos();
//     void inorder(stringstream&);
//     void inorderS(vector<int>&);
// 	void preorder(stringstream&);
// };

// Nodo::Nodo(int f, int l, string n, int s) {
//     fecha = f;
//     litros = l;
//     nombre = n;
//     salud = s;
//     izquierda = nullptr;
//     derecha = nullptr;
//     nivel = 0;
//     balance = 0;
// }

// int Nodo::getFecha() {
//     return fecha;
// }

// int Nodo::getLitro() {
//     return litros;
// }

// string Nodo::getNombre() {
//     return nombre;
// }

// int Nodo::getSalud() {
//     return salud;
// }

// Nodo* Nodo::getIzquierda() {
//     return izquierda;
// }

// Nodo* Nodo::getDerecha() {
//     return derecha;
// }

// void Nodo::setIzquierda(Nodo* n) {
//     izquierda = n;
// }

// void Nodo::setDerecha(Nodo* n) {
//     derecha = n;
// }

// void Nodo::agregar(int f, int l, string n, int s) {
//     if (f < fecha) {
//         if (izquierda != nullptr)
//             izquierda->agregar(f, l, n, s);
//         else
//             izquierda = new Nodo(f, l, n, s);
//     } else {
//         if (derecha != nullptr)
//             derecha->agregar(f, l, n, s);
//         else
//             derecha = new Nodo(f, l, n, s);
//     }
// }

// bool Nodo::buscar(int f) {
//     if (f == fecha) {
//         return true;
//     }
//     else if (f < fecha)
//         return izquierda != nullptr && izquierda -> buscar(f);
//     else
//         return derecha != nullptr && derecha -> buscar(f);
// }

// void Nodo::encontrar(int minFecha, vector<Nodo*>& resultado) {
//     // Si este nodo es NULL, no hay nada
//     if (this == nullptr) {
//         return;
//     }

//     // Si la fecha del nodo es mayor o igual a minFecha:
//     //  → entonces el subárbol izquierdo puede contener valores útiles
//     if (fecha >= minFecha) {
//         if (izquierda != nullptr)
//             izquierda -> encontrar(minFecha, resultado);

//         // Agregar este nodo porque es válido
//         resultado.push_back(this);

//         // También buscar en el subárbol derecho
//         if (derecha != nullptr)
//             derecha -> encontrar(minFecha, resultado);
//     }
//     else {
//         // Si este nodo < minFecha,
//         // todo el subárbol izquierdo es más chico → IGNORARLO.
//         if (derecha != nullptr)
//             derecha -> encontrar(minFecha, resultado);
//     }
//     return;
// }

// Nodo* Nodo::predecesor() {
//     Nodo* laIzquierda = izquierda;
//     Nodo* laDerecha = derecha;
//     if (izquierda == nullptr) {
//         if (derecha != nullptr) {
//             derecha = nullptr;
//         }
//         return laDerecha;
//     }
//     if (izquierda -> derecha == nullptr) {
//         izquierda = izquierda -> izquierda;
//         laIzquierda -> izquierda = nullptr;
//         return laIzquierda;
//     }

//     Nodo *padre = izquierda;
//     Nodo* hijo = izquierda -> derecha;
//     while (hijo -> derecha != nullptr) {
//         padre = hijo;
//         hijo = hijo -> derecha;
//     }
//     padre -> derecha = hijo -> izquierda;
//     hijo -> izquierda = nullptr;
//     return hijo;
// }

// void Nodo::eliminar(int f) {
//     Nodo* elPredecesor;
//     Nodo* viejo;
//     if (f < fecha) {
//         if (izquierda != nullptr) {
//             if (izquierda -> fecha == f) {
//                 viejo = izquierda;
//                 elPredecesor = izquierda -> predecesor();
//                 if (elPredecesor != nullptr) {
//                     elPredecesor -> izquierda = viejo -> izquierda;
//                     elPredecesor -> derecha = viejo -> derecha;
//                 }
//                 izquierda = elPredecesor;
//                 delete viejo;
//             } else {
//                 izquierda->eliminar(f);
//             }
//         }
//     } else if (f > fecha) {
//         if (derecha != nullptr) {
//             if (derecha -> fecha == f) {
//                 viejo = derecha;
//                 elPredecesor = derecha -> predecesor();
//                 if (elPredecesor != nullptr) {
//                     elPredecesor -> izquierda = viejo -> izquierda;
//                     elPredecesor -> derecha = viejo -> derecha;
//                 }
//                 derecha = elPredecesor;
//                 delete viejo;
//             } else {
//                 derecha->eliminar(f);
//             }
//         }
//     }
// }

// void Nodo::inorder(vector<int>& f) {
//     if (izquierda != 0)
//         izquierda->inorder(f);
//     f.push_back(fecha);
//     if (derecha != 0)
//         derecha->inorder(f);
// }

// int Nodo::calcularBalance() {
//     int laIzquierda = 0;
//     int laDerecha = 0;
//     if(izquierda != nullptr) {
//         laIzquierda = izquierda -> calcularBalance() + 1;
//     }
//     if(derecha != nullptr) {
//         laDerecha = derecha -> calcularBalance() + 1;
//     }

//     if(laIzquierda > laDerecha) {
//         nivel = laIzquierda;
//     } else {
//         nivel = laDerecha;
//     }
//     balance = laIzquierda - laDerecha;
//     return nivel;
// }

// Nodo* Nodo::revisarArbol(int *valor_checado, Nodo *padre, bool *revisado) {
//     Nodo* laIzquierda = nullptr;
//     Nodo* laDerecha = nullptr;
//     Nodo* balanceo = nullptr;

//     if (izquierda != nullptr) {
//         laIzquierda = izquierda -> revisarArbol(valor_checado, this, revisado);   
//     }
//     if (derecha != nullptr) {
//         laDerecha = derecha -> revisarArbol(valor_checado, this, revisado);
//     }
//     if (*revisado == false) {
//         if (balance > 1) { // demasiado peso a la izquierda
//             balanceo = balancear();
//             *valor_checado = fecha;
//             *revisado = true;
//             if (padre != nullptr) {
//                 // determinamos si este nodo era left o right del padre por el id
//                 if (padre -> izquierda != nullptr && padre -> izquierda -> fecha == fecha) {
//                     padre -> izquierda = balanceo;
//                 } else {
//                     padre -> derecha = balanceo;
//                 }
//             }
//         } else if (balance < -1) { // demasiado peso a la derecha
//             balanceo = balancear();
//             *valor_checado = fecha;
//             *revisado = true;
//             if (padre != nullptr) {
//                 if (padre -> derecha != nullptr && padre -> derecha -> fecha == fecha) {
//                     padre -> derecha = balanceo;
//                 } else {
//                     padre -> izquierda = balanceo;
//                 }
//             }
//         }
//     }

//     return balanceo;
// }

// Nodo* Nodo::balancear() {
//     Nodo* nodo = this;
//     Nodo* laIzquierda = izquierda;
//     Nodo* laDerecha = derecha;

//     // Asegurarse de que no accedemos a nodos nulos al comprobar balances
//     if (balance > 0) { // subárbol izquierdo más alto
//         if (laIzquierda != nullptr && laIzquierda -> balance > 0) {
//             nodo = rotarDerecha(nodo);
//         } else {
//             nodo = rotarIzquierdaDerecha(nodo);
//         }
//     } else { // balance < = 0 -> subárbol derecho más alto o igual
//         if (laDerecha != nullptr && laDerecha -> balance < 0) {
//             nodo = rotarIzquierda(nodo);
//         } else {
//             nodo = rotarDerechaIzquierda(nodo);
//         }
//     }
//     return nodo;
// }

// Nodo* Nodo::rotarIzquierda(Nodo* nodo) {
//     if (nodo == nullptr || nodo -> derecha == nullptr) {
//         return nodo;
//     }
//     Nodo* hijoDerecho = nodo -> derecha;
//     Nodo* hijoIzquierdoDerecho = hijoDerecho -> izquierda;

//     // Rotación
//     hijoDerecho -> izquierda = nodo;
//     nodo -> derecha = hijoIzquierdoDerecho;

//     // Actualizar alturas/balances de los nodos afectados
//     if (nodo -> izquierda != nullptr) {
//         nodo -> izquierda -> calcularBalance();
//     }
//     if (nodo -> derecha != nullptr) {
//         nodo -> derecha -> calcularBalance();
//     }
//     nodo -> calcularBalance();

//     if (hijoDerecho -> izquierda != nullptr) {
//         hijoDerecho -> izquierda -> calcularBalance();
//     } 
//     if (hijoDerecho -> derecha) {
//         hijoDerecho -> derecha -> calcularBalance();
//     }
//     hijoDerecho -> calcularBalance();

//     return hijoDerecho;
// }

// Nodo* Nodo::rotarDerecha(Nodo* nodo) {
//     if (nodo == nullptr || nodo -> izquierda == nullptr) {
//         return nodo;
//     }
//     Nodo* hijoIzquierdo = nodo -> izquierda;
//     Nodo* hijoIzquierdoDerecho = hijoIzquierdo -> derecha;

//     // Rotación
//     hijoIzquierdo -> derecha = nodo;
//     nodo -> izquierda = hijoIzquierdoDerecho;

//     // Actualizar alturas/balances
//     if (nodo -> izquierda != nullptr) {
//         nodo -> izquierda -> calcularBalance();
//     }
//     if (nodo -> derecha != nullptr) {
//         nodo -> derecha -> calcularBalance();
//     }
//     nodo -> calcularBalance();
//     if (hijoIzquierdo -> izquierda != nullptr) {
//         hijoIzquierdo -> izquierda -> calcularBalance();
//     }
//     if (hijoIzquierdo -> derecha != nullptr) {
//         hijoIzquierdo -> derecha -> calcularBalance();
//     }
//     hijoIzquierdo -> calcularBalance();

//     return hijoIzquierdo;
// }

// // Rotación doble: primero rotación izquierda en el hijo izquierdo, luego derecha en el nodo
// Nodo* Nodo::rotarIzquierdaDerecha(Nodo* nodo) {
//     if (nodo == nullptr) {
//         return nodo;
//     }
//     if (nodo -> izquierda != nullptr) {
//         nodo -> izquierda = rotarIzquierda(nodo -> izquierda);
//     }
//     return rotarDerecha(nodo);
// }

// // Rotación doble: primero rotación derecha en el hijo derecho, luego izquierda en el nodo
// Nodo* Nodo::rotarDerechaIzquierda(Nodo* nodo) {
//     if (nodo == nullptr) {
//         return nodo;
//     } 
//     if (nodo -> derecha != nullptr) {
//         nodo -> derecha = rotarDerecha(nodo -> derecha);
//     }
//     return rotarIzquierda(nodo);
// }

// void Nodo::eliminarHijos() {
// 	if (izquierda != nullptr) {
// 		izquierda -> eliminarHijos();
// 		delete izquierda;
// 		izquierda = nullptr;
// 	}
// 	if (derecha != nullptr) {
// 		derecha -> eliminarHijos();
// 		delete derecha;
// 		derecha = nullptr;
// 	}
// }

// void Nodo::inorder(stringstream &lista) {
// 	if (izquierda != nullptr) {
// 		izquierda -> inorder(lista);
// 	}
// 	if (lista.tellp() != 1) {
// 		lista << " ";
// 	}
// 	lista << "(" << fecha << " " << litros << " " << nivel << " " << balance << ")";
// 	if (derecha != nullptr) {
// 		derecha -> inorder(lista);
// 	}
// }

// void Nodo::inorderS(vector<int>& valores) {
//     if (izquierda != nullptr) {
//         izquierda -> inorderS(valores);
//     }

//     valores.push_back(fecha);

//     if (derecha != nullptr) {
//         derecha -> inorderS(valores);
//     }
// }

// void Nodo::preorder(stringstream &lista) {
// 	lista << "(" << fecha << " " << litros << " " << nivel << " " << balance << ")";
// 	if (izquierda != nullptr) {
// 		lista << " ";
// 		izquierda -> preorder(lista);
// 	}
// 	if (derecha != nullptr) {
// 		lista << " ";
// 		derecha -> preorder(lista);
// 	}
// }

// class Arbol {
// private:
//     Nodo *raiz;

// public:
//     Arbol();
//     ~Arbol();
//     bool vacio() const;
//     void agregar(int, int, string, int);
//     bool buscar(int) const;
//     void encontrar(int, vector<Nodo*>&);
//     void eliminar(int);
//     void eliminarTodo();
//     string inorder();
//     string preorder(); 
// };

// Arbol::Arbol() {
//     raiz = nullptr;
// }

// Arbol::~Arbol() {
//     eliminarTodo();
// }

// bool Arbol::vacio() const {
//     if(raiz == nullptr) {
//         return true;
//     } else {
//         return false;
//     }
// }

// void Arbol::agregar(int fecha, int litros, string nombre, int salud) {
//     if (raiz != nullptr) {
//         if (raiz -> buscar(fecha) != true) {
//             raiz -> agregar(fecha, litros, nombre, salud);
//             raiz -> calcularBalance();
//             int valorRevisado = false;
//             bool revisado = false;
//             Nodo *temporal = raiz -> revisarArbol(&valorRevisado, 0, &revisado);
//             if (valorRevisado == raiz -> getFecha()) {
//                 raiz = temporal;
//             }
//             raiz->calcularBalance();
//         }
//     } else {
//         raiz = new Nodo(fecha, litros, nombre, salud);
//     }
// }

// bool Arbol::buscar(int fecha) const {
//     if(raiz != nullptr) {
//         return raiz -> buscar(fecha);
//     } else {
//         return false;
//     }
// }

// void Arbol::encontrar(int f, vector<Nodo*>& valores) {
//     if(raiz != nullptr) {
//         raiz -> encontrar(f, valores);
//     } else {
//         return;
//     }
// }

// void Arbol::eliminar(int fecha) {
//     if (raiz != nullptr) {
//         if (fecha == raiz -> getFecha()) {
//             Nodo *elPredecesor = raiz -> predecesor();
//             if (elPredecesor != nullptr) {
//                 elPredecesor -> setIzquierda(raiz -> getIzquierda());
//                 elPredecesor-> setDerecha(raiz -> getDerecha());
//             }
//             delete raiz;
//             raiz = elPredecesor;
//         } else {
//             raiz -> eliminar(fecha);
//         }
//         raiz -> calcularBalance();
//         int valorRevisado = false;
//         bool revisado = false;
//         Nodo* temporal = raiz -> revisarArbol(&valorRevisado, 0, &revisado);
//         if (valorRevisado == raiz -> getFecha()) {
//             raiz = temporal;
//         }
//         raiz -> calcularBalance();
//     }
// }

// void Arbol::eliminarTodo() {
//     if (raiz != nullptr)
//         raiz -> eliminarHijos();
//     delete raiz;
//     raiz = nullptr;
// }

// string Arbol::inorder() {
//     stringstream auxiliar;
//     auxiliar << "[";
//     if (vacio() != true) {
//         raiz -> inorder(auxiliar);
//     }
//     auxiliar << "]";
//     return auxiliar.str();
// }

// string Arbol::preorder() {
//     stringstream auxiliar;
//     auxiliar << "[";
//     if (vacio() != true) {
//         raiz -> preorder(auxiliar);
//     }
//     auxiliar << "]";
//     return auxiliar.str();
// }


// #endif



