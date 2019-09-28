
#ifndef LISTA_H
#define LISTA_H
#include "string"
#include "Arreglo.h"


class nodo {
public:
    nodo(arreglo*, nodo* = NULL, nodo* = NULL);
    virtual ~nodo();

    virtual arreglo* obtenerInfo() const;
    virtual nodo* obtenerSiguiente() const;
    virtual void establecerSiguiente(nodo* = NULL);
    virtual nodo* obtenerAnterior()const;
    virtual void establecerAnterior(nodo* = NULL);
    virtual std::string toString();

private:
    arreglo* _info;
    nodo* _siguiente;
    nodo* _anterior;
};


class lista {
public:

    lista();
    lista(const lista &);
    virtual ~lista();

    lista* operator*(const lista*);

    lista* operator+(lista*);
    lista* operator-(lista*);
    bool operator==(lista*);
    bool operator!=(lista*);

    lista* operator=(lista*);
    lista* operator+=(lista*);
    lista* operator-=(lista*);
    lista* operator*=(lista*);
    lista* operator/=(lista*);
    
    static lista* fibonacci(int);
    static lista* fibonacci(int, lista*, lista*);
    int numElementos() const;
    void agregar(arreglo*);
    void agregarInicio(arreglo*);
    arreglo* sumaArr(arreglo*, arreglo*);
    lista* restar(lista*, lista*, bool);
    void extraer(int);

    arreglo* recuperar(int) const;
    arreglo* sumarArr(arreglo*, arreglo*, int&); //Jasson
    std::string toString();

private:
    int _n;
    nodo* _primero;
    nodo* _ultimo;

};

#endif /* LISTA_H */
