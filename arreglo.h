#ifndef ARREGLO_H
#define ARREGLO_H
#include "string"
class arreglo {
public:
    arreglo();
    arreglo(const arreglo& orig);
    virtual ~arreglo();
    void agregar(int);
    void agregarFinal(int);
    int obtenerEsp(int);
    std::string toString();
    int getK();
private:
    int _k;
    int _n;
    int *_vector;
};

#endif /* ARREGLO_H */

