#include <vector>

#include "Lista.h"
#include "sstream"
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
    lista *auxiliar = new lista();
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
                if (carry == 1) {
                    total1->agregarFinal(1);
                }
            }
        }
        tot->agregar(total1);
        carry = 0;
    }

    for (int i = 0; i < tamC; i++) {//recorre los vectores
        int j = 0;
        while (j < i) {
            tot->recuperar(i)->agregar(0); //agrega n ceros

            j++;
        }
    }

    for (int i = 1; i < tamC; i++) {
        int j = 0;
        while (j < 9) {
            tot->recuperar(i)->agregarFinal(0);
            tot->recuperar(0)->agregarFinal(0);
            j++;
        }

    }
    tot->recuperar(0)->agregarFinal(0);

    auxiliar->agregar(sumaArr(tot->recuperar(0), tot->recuperar(1)));
    for (int i = 0; i < 3; i++) {
        auxiliar->agregar(sumaArr(auxiliar->recuperar(0), tot->recuperar(2)));

    }
    return auxiliar;
    //return tot;
}

arreglo* lista::sumaArr(arreglo* a1, arreglo* a2) {
    arreglo* total = new arreglo();

    cout << a1->toString() << endl;
    cout << a2->toString() << endl;
    cout << endl;
    int a = 0, b = 0, carry = 0;
    for (int i = 8; i >= 0; i--) {
        a = a1->obtenerEsp(i);
        b = a2->obtenerEsp(i);

        cout << endl;
        a += b += carry;
        if (a > 9) {
            carry = 1;
            a -= 10;
        } else {
            carry = 0;
        }

        total->agregarFinal(a);

    }
    total->agregarFinal(1);

    return total;
}

lista* lista::operator+=(lista* plus) {
    lista* resultado = new lista();
    arreglo* vector = new arreglo();
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
            if (a > 9) {
                carry = 1;
                a -= 10;
            } else
                carry = 0;

            vector->agregarFinal(a);

        }
        resultado->agregar(vector);
        aux1 = aux1->obtenerAnterior();
        aux2 = aux2->obtenerAnterior();
    }
    if (aux1 == NULL && aux2 == NULL) {
        if (carry == 1) {
            if (vector->obtenerEsp(0) == 9999) {
                vector = new arreglo();
                vector->agregar(1);
                resultado->agregarInicio(vector);
            } else {
                vector->agregarFinal(1);
                //vector->setNumber(vector->obtenerEsp(0) + 1, 0);
            }
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
    if (aux1 == NULL) {
        aux1 = aux2;
    }

    while (aux1 != NULL) {
        insert = aux1->obtenerInfo();
        nl->agregarInicio(insert);
    }

    return nl;
}

arreglo* lista::sumarArr(arreglo* a, arreglo* b, int carry) {
    int x;
    arreglo* r = new arreglo();
    for (int i = 4; i >= 0; i--) {
        x = a->obtenerEsp(i) + b->obtenerEsp(i) + carry;
        if (x > 999999999) {
            carry = 1;
            x -= 1000000000;
        } else
            carry = 0;
        r->agregar(x);
    }
    return r;
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