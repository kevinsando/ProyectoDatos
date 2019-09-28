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

    long long resultado = 0; //guarda el total de la multiplicacion de digito por digito

    int a = 0; //guarda digito a multiplicar
    int bb = 0; //guarda digito a multiplicar
    long long carry = 0; //acarreo


    for (int i = b->recuperar(0)->getK() - 1; i >= 0; i--) {//recorrere los arreglos de la lista
        arreglo *total1 = new arreglo(); //contiene la multiplicacion solo por un digito

        for (int j = this->recuperar(0)->getK() - 1; j >= 0; j--) {//recorrere los arreglos de la lista

            a = this->recuperar(0)->obtenerEsp(j); //obtiene digito por digito del arreglo para multiplicarlo
            bb = b->recuperar(0)->obtenerEsp(i); //obtiene digito por digito del arreglo para multiplicarlo
            resultado = (long long) a * (long long) bb + (long long) carry; //multiplicacion de a*bb ya terminada
            carry = resultado / 10; //calculo de acarreo
            if (resultado >= 10) {
                resultado = resultado % 10;
            }

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

    if (tot->numElementos() < 2) //VERIFICAR ESTO!!!!!! SI UNICAMENTE HAY UN ELEMENTO POR CELDA EN LOS ARREGLOS, ENTRA EN ESTA CONDICION
    {
        auxiliar->agregar(tot->recuperar(0));
    } else {
        auxiliar->agregar(sumaArr(tot->recuperar(0), tot->recuperar(1)));
    }
    for (int i = 2; i < tamC; i++) {

        auxiliar->agregar(sumaArr(auxiliar->recuperar(0), tot->recuperar(i)));

        auxiliar->extraer(0);
    }
    return auxiliar;
    //  return tot;
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
    return NULL;
    //implementar Jasson
}

lista* lista::operator+(lista* plus) {
	
    nodo* aux1 = this->_ultimo;
    nodo* aux2 = plus ->_ultimo;
    lista* nl = new lista();

    arreglo* insert;
    int carry = 0;
    while (aux1 != NULL && aux2 != NULL) {
        nl->agregarInicio(sumarArr(aux1->obtenerInfo(), aux2->obtenerInfo(), carry));
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
	delete aux1;
	delete aux2;
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
    lista* esta = this;
    nodo* aux1 = this->_primero;
    nodo* aux2 = resta ->_primero;
    lista* auxiliar = new lista();
    nodo* auxi = NULL;
    lista* nl = new lista();


    if (aux2->obtenerInfo()->obtenerEsp(0) < 0) {
        nl = this->operator+(resta);
    } else {

        //            if (aux1->obtenerInfo()->obtenerEsp(0) > aux2->obtenerInfo()->obtenerEsp(0)) {
        //                nl = restar(esta, resta, true); //normal
        //                
        //
        //            }
        if (aux1->obtenerInfo()->obtenerEsp(0) < aux2->obtenerInfo()->obtenerEsp(0)) {
            //nl = restar(resta, this, false);
            while (aux1 != NULL && aux2 != NULL) {
                auxi = aux1;
                aux1 = aux2;
                aux2 = auxi;
                
                aux1 = aux1->obtenerSiguiente();
                aux2 = aux2->obtenerSiguiente();
            }
        }

    }

    nl = restar(esta, resta, true);

    return nl;
}
lista* lista::fibonacci(int n)
{
	lista* a = new lista();
	lista* b = new lista();
	arreglo* arrAux = new arreglo();
	arreglo* arrAux2 = new arreglo();
	arrAux->agregarFinal(0);
	a->agregar(arrAux);//b=0
	arrAux2->agregarFinal(1);
	b->agregar(arrAux2);//a=1
	return fibonacci(n,a,b);
	delete a;
	delete b;
}
lista * lista::fibonacci(int n, lista* a, lista* b)
{
	lista* z = new lista();
	/*if (n == 0)
	{
		return a;
	}
	if (n == 1)
	{
		return b;
	}
	return fibonacci(n - 1, b, a->operator+(b));*/
	for (int i = 0; i < n-1; i++) {
		z = a->operator+(b);
		a = b;
		b = z;
	}
	return z;
}

lista* lista::restar(lista* r1, lista* resta, bool neg) {
    nodo* aux1 = r1->_ultimo;
    nodo* aux2 = resta ->_ultimo;
    lista* nl = new lista();
    arreglo* insert = new arreglo();
    int carry = 0;
    int cont = 8;
    while (aux1 != NULL && aux2 != NULL) {
        int x = 0;
        int c = 0;
        for (int i = 8; i >= 0; i--) {

            int a = aux1->obtenerInfo()->obtenerEsp(i);
            int b = (aux2->obtenerInfo()->obtenerEsp(i));

            if (a < b) {//si el de arriba es menor al de abajo
                a += 10;
                c = i - 1;
                // aux2->obtenerInfo()->editarEsp(c + 1, 1, false);
            }
            x = a - b;
            insert->agregarFinal(x);
            cont--;
        }
        x = 0;
        cont = 8;
        //  insert->editarEsp(c, 1, false);

        if (!neg) {
            insert->editarEsp(cont, -1, true);
        }
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
            insert->setNumber(8, insert->obtenerEsp(8) - 1);
        }
    }
    while (aux2 != NULL) {
        insert = new arreglo(aux2->obtenerInfo());
        nl->agregarInicio(insert);
        aux2 = aux2->obtenerAnterior();
        if (carry > 0) {
            insert->setNumber((insert->obtenerEsp(8) - 1), 8);
        }
    }
    return nl;

}
bool lista::operator ==(lista* otra){
    nodo* _actual1 =this->_primero;
    nodo* _actual2 = otra->_primero;
    bool resultado=false;
    
    while(_actual1 !=NULL && _actual2 !=NULL){
       /* if(_actual1->obtenerInfo()->operator == (_actual2->obtenerInfo())){
            resultado = true;
        }*/
        _actual1=_actual1->obtenerSiguiente();
        _actual2=_actual2->obtenerSiguiente();
    }
    return resultado;
}
nodo::nodo(arreglo* info, nodo* siguiente, nodo * anterior) :
_info(info), _siguiente(siguiente), _anterior(anterior) {

}

nodo::~nodo() {
}

arreglo * nodo::obtenerInfo() const {
    return _info;
}

nodo * nodo::obtenerSiguiente() const {
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