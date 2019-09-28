#include "Arreglo.h"
#include "sstream"
#include <iostream>

using namespace std;

arreglo::arreglo() : _k(0), _vector(new int[9]), _n(9), last(8) {
    for (int i = 0; i < _n; i++) {
        _vector[i] = 0;
    }
}

arreglo::arreglo(arreglo* orig) : _vector(new int[9]) {
    _n = 9;
    _k = 0;
    for (int i = 0; i < _n; i++) {
        _vector[i] = orig->obtenerEsp(i);
        _k++;
    }
}

arreglo::~arreglo() {
    if (_vector != NULL) {
        delete _vector;
    }
}

void arreglo::agregar(int e) {
    if (_k < _n) {
        _vector[_k++] = e;
    }
}

void arreglo::agregaPorPartes(int e) {
    int division1, division2;

    int n = e;
    long long r = 0;
    while (n > 0) {
        n = n / 10;
        r++;
    }

    if (r > 7) {
        division1 = e / 10000;
        division2 = e % 10000;

        if (_k < _n) {
            _vector[_k++] = division1;

            _vector[_k++] = division2;

        }
    } else {
        if (_k < _n) {
            _vector[_k++] = e; //agrega el resultado de la multiplicacion a un nuevo arreglo
        }
    }
}

string arreglo::toString() {
    stringstream s;
    s << "[";
    for (int i = 0; i < _n; i++) {
        s << _vector[i] << " ";
    }
    s << "]";
    return s.str();
}

int arreglo::getK() {
    return _k;
}

int arreglo::obtenerEsp(int i) {
    return _vector[i];
}
bool arreglo::operator==(arreglo* otro)
{
	bool v = true;
	if (_k != otro->getK()) {
		v = false; 
		return false;
	}
	else
	{
		for (int i = 0; i < _k; i++)
		{
				if (_vector[i] != otro->_vector[i])
				{
					v = false;
					return v;
				}
		}
	}
	return v;
}
bool arreglo::operator!=(arreglo* otro)
{

	if (operator== (otro))
	{
		return false;
	}
	else
	{
		return true;
	}
}
void arreglo::agregarFinal(int e) {
    if (last >= 0) {
        _vector[last--] = e;
        _k++;
    }

}

void arreglo::agregarFinalS(int e) {
    if (_k < _n) {
        for (int i = _k; i >= 0; i--) {
            _vector[i + 1] = _vector[i];
        }
        _vector[0] = e;
        _k++;

    } else {
        //error
    }
}

void arreglo::setNumber(int n, int pos) {

    _vector[pos] = n;
}

void arreglo::editarEsp(int i, int e, bool n) {
    if (i != 0 && !n) {
        _vector[i] -= e;
    }
    if (i != 0 && n) {
        _vector[i] = _vector[i] * e;
    }
}
