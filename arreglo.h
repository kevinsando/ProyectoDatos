#ifndef ARREGLO_H
#define ARREGLO_H
#include "string"

class arreglo {
public:
    arreglo();
    arreglo(arreglo* orig);
    ~arreglo();
    void agregar(int);
    bool operator==(arreglo*);
    bool operator!=(arreglo*);
    bool operator>(arreglo*);
    void agregarFinal(int);
    void agregarFinalS(int);
    void agregaPorPartes(int);
    void editarEsp(int, int, bool);
    int obtenerEsp(int);
    std::string toString();
    int getK();
    void setNumber(int, int);
    int getLast();
    bool isEmpty();
    std::string primeroToString();
private:
    int _k;
    int _n;
    int last;
    int *_vector;
};

#endif /* ARREGLO_H */

