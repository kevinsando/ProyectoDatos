#include <vector>

#include "Lista.h"
#include "sstream"
#include "string"
#include "iostream"
using namespace std;

lista::lista()
: _n(0), _primero(NULL), _ultimo(NULL) {
}

lista::lista(const lista &otra)
: _n(0), _primero(NULL), _ultimo(NULL) {
    nodo* cursor = otra._primero;
    while (cursor != NULL) {
        nodo* nuevo = new nodo(cursor->obtenerInfo());
        if (_primero == NULL) {
            _primero = _ultimo = nuevo;
        } else {
            _ultimo->establecerSiguiente(nuevo);
            nuevo->establecerAnterior(_ultimo);
            _ultimo = nuevo;
        }
        _n++;
        cursor = cursor->obtenerSiguiente();
    }
}

lista::~lista() {

}

lista& lista::operator=(const lista &otra) {
    if (this != &otra) {
        _n = 0;
        _primero = _ultimo = NULL;
        nodo* cursor = otra._primero;
        while (cursor != NULL) {
            nodo* nuevo = new nodo(cursor->obtenerInfo());
            if (_primero == NULL) {
                _primero = _ultimo = nuevo;
            } else {
                _ultimo->establecerSiguiente(nuevo);
                nuevo->establecerAnterior(_ultimo);
                _ultimo = nuevo;
            }
            _n++;
            cursor = cursor->obtenerSiguiente();
        }
    }
    return *this;
}

int lista::numElementos() const {
    return _n;
}

void lista::agregar(arreglo* info) {
    nodo* nuevo = new nodo(info);
    if (_primero == NULL) {
        _primero = _ultimo = nuevo;
    } else {
        _ultimo->establecerSiguiente(nuevo);
        nuevo->establecerAnterior(_ultimo);
        _ultimo = nuevo;
    }
    _n++;
}

void lista::agregarInicio(arreglo* info) {
    nodo* nuevo = new nodo(info);
    if (_primero == NULL) {
        _primero = _ultimo = nuevo;
    } else {
        nuevo->establecerSiguiente(_primero);
        _primero->establecerAnterior(nuevo);
        _primero = nuevo;
    }
}

arreglo* lista::recuperar(int i) const {
    arreglo* r = NULL;
    if (i < _n) {
        nodo* cursor = _primero;
        int p = 0;
        while (p < i) {
            cursor = cursor->obtenerSiguiente();
            p++;
        }
        r = cursor->obtenerInfo();
    }
    return r;
}

string lista::toString() {
    stringstream s;
    nodo *aux = _primero;
    s << "[";
    while (aux != NULL) {
        s << aux->obtenerInfo()->toString();
        aux = aux->obtenerSiguiente();
    }
    s << "]";
    return s.str();
}

void lista::extraer(int posicion) {

    if (numElementos() > 0) {
        if (posicion == 0) {

            nodo* tmp = _primero;
            _primero = _primero->obtenerSiguiente();
            delete tmp;
        } else {
            nodo* cursor = _primero;
            int i = 0;
            while (i < (posicion - 1)) {
                cursor = cursor->obtenerSiguiente();
                i++;
            }

            nodo* tmp = cursor->obtenerSiguiente();
            cursor->establecerSiguiente(cursor->obtenerSiguiente()->obtenerSiguiente());
            delete tmp;
            if (cursor->obtenerSiguiente() == NULL) {
                _ultimo = cursor;
            }
        }
        _n--;
    }

}

lista* lista::operator*(const lista* b) {//multiplicación

    //verifica cual vector tiene más digitos para saber cuantos corrimientos se deben hacer
    int tamb = b->recuperar(0)->getK();
    int tamA = this->recuperar(0)->getK();
    int tamC = 0;
    if (tamb > tamA) {
        tamC = tamb;
    } else {
        tamC = tamA;
    }
    //---------
    lista *tot = new lista(); //lista que retorna el resultado de la multiplicacion sin la suma
    lista *auxiliar = new lista(); //alamacena la lista final con la multiplicacion y suma, es la que se retorna

    long resultado; //guarda el total de la multiplicacion de digito por digito

    int a; //guarda digito a multiplicar
    int bb; //guarda digito a multiplicar
    int carry = 0; //acarreo
    for (int i = b->recuperar(0)->getK() - 1; i >= 0; i--) {//recorrere los arreglos de la lista
        arreglo *total1 = new arreglo(); //contiene la multiplicacion solo por un digito

        for (int j = this->recuperar(0)->getK() - 1; j >= 0; j--) {//recorrere los arreglos de la lista

            a = this->recuperar(0)->obtenerEsp(j); //obtiene digito por digito del arreglo para multiplicarlo
            bb = b->recuperar(0)->obtenerEsp(i); //obtiene digito por digito del arreglo para multiplicarlo
            resultado = (a * bb) + carry; //multiplicacion de a*bb ya terminada
            carry = resultado / 10; //calculo de acarreo
            if (resultado >= 10) {
                resultado = resultado % 10;
            }


            total1->agregarFinalS(resultado); //agrega el resultado de la multiplicacion a un nuevo arreglo
        }
        total1->agregarFinalS(carry); //agrega el acarreo 
        tot->agregar(total1); //agrega a la lista final el arreglo que contiene la multiplicacion
        //cada arreglo contiene la multiplicacion de toda una lista por un digito de la segunda lista
        carry = 0; //retorna el carry a su valor inicial
    }

    for (int i = 0; i < tamC; i++) {//recorre los vectores
        int j = 0;
        while (j < i) {
            tot->recuperar(i)->agregar(0); //agrega n ceros, corrimiento para sumar
            j++;
        }
    }

    for (int i = 1; i < tamC; i++) {//completa los vectores a nueve digitos con ceros
        int j = 0;
        while (j < 9) {
            tot->recuperar(i)->agregarFinalS(0);
            tot->recuperar(0)->agregarFinalS(0);
            j++;
        }

    }
    tot->recuperar(0)->agregarFinalS(0);

    //********** Calculo Suma **********

    auxiliar->agregar(sumaArr(tot->recuperar(0), tot->recuperar(1)));
    for (int i = 2; i < tamC; i++) {

        auxiliar->agregar(sumaArr(auxiliar->recuperar(0), tot->recuperar(i)));

        auxiliar->extraer(0);
    }
    return auxiliar;
    //   return tot;
}

arreglo* lista::sumaArr(arreglo* a1, arreglo* a2) {//recibe dos arreglos para sumarlos
    arreglo* total = new arreglo(); //se alamacena un nuevo arreglo equivalente a suma de los dos que se reciben por parametro

    cout << a1->toString() << endl; //test
    cout << a2->toString() << endl; //test
    cout << endl;
    int a = 0, b = 0, carry = 0;

    cout << a1->obtenerEsp(9) << endl; //test
    cout << a2->obtenerEsp(9) << endl; //test

    for (int i = 8; i >= 0; i--) {//recorre los dos arreglos
        a = a1->obtenerEsp(i);
        b = a2->obtenerEsp(i);

        cout << endl;
        a += b += carry; //suma de los dos arreglos
        if (a > 9) {//acarreo
            carry = 1;
            a -= 10;
        } else {
            carry = 0;
        }

        total->agregarFinalS(a); //agrega al arreglo la suma de digitos 

    }
    if (carry == 1) {//acarreo
        total->agregarFinalS(1);
    }
    return total;
}

lista* lista::operator+=(lista* plus) {
    //implementar Jasson
}

lista* lista::operator+(lista* plus) {
    nodo* aux1 = this->_ultimo;
    nodo* aux2 = plus ->_ultimo;
    lista* nl = new lista();
    
    arreglo* insert;
    int carry = 0;
    while (aux1 != NULL && aux2 != NULL) {
        insert = sumarArr(aux1->obtenerInfo(), aux2->obtenerInfo(), carry);
        nl->agregarInicio(insert);
        aux1 = aux1->obtenerAnterior();
        aux2 = aux2->obtenerAnterior();
    }
    if (aux1 == NULL && aux2 == NULL && carry > 0) {
        insert = new arreglo();
        insert->agregarFinal(carry);
        nl->agregarInicio(insert);
    }
    while (aux1 != NULL) {
        insert = new arreglo(aux1->obtenerInfo());
        nl->agregarInicio(insert);
        aux1 = aux1->obtenerAnterior();
        if (carry > 0) {
            insert->setNumber(8, insert->obtenerEsp(8) + 1);
        }
    }
    while (aux2 != NULL) {
        insert = new arreglo(aux2->obtenerInfo());
        nl->agregarInicio(insert);
        aux2 = aux2->obtenerAnterior();
        if (carry > 0) {
            insert->setNumber((insert->obtenerEsp(8) + 1), 8);
        }
    }
    return nl;
}

arreglo* lista::sumarArr(arreglo* a, arreglo* b, int& carry) { //METODO DE JASSON
    int x;
    arreglo* r = new arreglo();
    for (int i = 8; i >= 0; i--) {
        x = a ->obtenerEsp(i) + b->obtenerEsp(i) + carry;
        if (x > 999999999) {
            carry = 1;
            x -= 1000000000;
        } else {
            carry = 0;
        }
        r->agregarFinal(x);
    }
    return r;
}

lista* lista::operator-(lista* resta) {
    nodo* aux1 = this->_ultimo;
    nodo* aux2 = resta ->_ultimo;
    lista* nl = new lista();
    
    arreglo* insert;
    int carry = 0;
    cout<<aux1->obtenerInfo()->toString()<<endl;
    cout<<aux2->obtenerInfo()->toString()<<endl;
    cout<<endl;
    
    while (aux1->obtenerAnterior()!= NULL && aux2->obtenerAnterior()!= NULL) {
        int x;
        for (int i = 8; i >= 0; i--) {
            x = aux1->obtenerInfo()->obtenerEsp(i) - aux2->obtenerInfo()->obtenerEsp(i);

            insert->agregarFinal(x);
        }
        nl->agregarInicio(insert);
        aux1 = aux1->obtenerAnterior();
        aux2 = aux2->obtenerAnterior();
    }
    
    
    return nl;
}

nodo::nodo(arreglo* info, nodo* siguiente, nodo * anterior) :
_info(info), _siguiente(siguiente), _anterior(anterior) {

}

nodo::~nodo() {
}

arreglo* nodo::obtenerInfo() const {
    return _info;
}

nodo* nodo::obtenerSiguiente() const {
    return _siguiente;
}

void nodo::establecerSiguiente(nodo * siguiente) {
    _siguiente = siguiente;
}

nodo * nodo::obtenerAnterior() const {
    return _anterior;
}

void nodo::establecerAnterior(nodo * anterior) {
    _anterior = anterior;
}

string nodo::toString() {
    stringstream s;
    s << _info->toString() << ", " << hex << _siguiente->toString();
    return s.str();

}