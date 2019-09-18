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
        _ultimo = nuevo;
    }
    _n++;
}

void lista::agregarInicio(arreglo* info) {
    nodo* nuevo = new nodo(info);
    nuevo->establecerSiguiente(_primero);
    _primero = nuevo;
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

lista* lista::operator*(const lista* b) {
    int tamb = b->recuperar(0)->getK();
    int tamA = this->recuperar(0)->getK();
    int tamC = 0;
    if (tamb > tamA) {
        tamC = tamb;
    } else {
        tamC = tamA;
    }
    lista *tot = new lista();
    int resultado;
    int carry = 0;
    for (int i = b->recuperar(0)->getK() - 1; i >= 0; i--) {
        arreglo *total1 = new arreglo();
        for (int j = this->recuperar(0)->getK() - 1; j >= 0; j--) {

            resultado = (b->recuperar(0)->obtenerEsp(i) * this->recuperar(0)->obtenerEsp(j)) + carry;
            carry = resultado / 10;
            if (resultado >= 10) {
                resultado = resultado % 10;
            }
            if (total1->getK() < tamC) {
                total1->agregarFinal(resultado);
            }
        }
        tot->agregar(total1);
    }
    for (int i = 0; i < tamC; i++) {//recorre los vectores
        int j = 0;
        while (j < i) {
            tot->recuperar(i)->agregar(0); //agrega n ceros
            j++;
        }
    }



    return tot;
}

lista* lista::operator+=(lista* plus) {
    lista* resultado = new lista();
    arreglo* vector;
    nodo* aux1 = this->_ultimo;
    nodo* aux2 = plus->_ultimo;
    int a;
    int b;
    int carry = 0;

    while (aux1 != NULL && aux2 != NULL) {
        vector = new arreglo();
        for (int i = 5; i >= 0; i--) {
            a = aux1->obtenerInfo()->obtenerEsp(i);
            b = aux2->obtenerInfo()->obtenerEsp(i);
            a += b += carry;
            if (a > 9999) {
                carry = 1;
                a -= 10000;
            } else
                carry = 0;

            vector->agregarFinal(a);

        }
        resultado->agregar(vector);
        aux1 = aux1->obtenerAnterior();
        aux2 = aux2->obtenerAnterior();
    }


    if (aux1 == NULL && aux2 == NULL) {
        if (carry == 1 && vector->obtenerEsp(0) == 9999) {
            vector = new arreglo();
            vector->agregar(1);
            resultado->agregarInicio(vector);
        } else {
            vector->setNumber(vector->obtenerEsp(0) + 1, 0);
        }
    } else {
        if (aux1 == NULL) {
            aux1 = aux2;
        }
        while (aux1 != NULL) {
            vector = new arreglo(aux1->obtenerInfo());
            resultado->agregarInicio(vector);
        }
    }





    return resultado;
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