#include "Arreglo.h"
#include "sstream"
//
using namespace std;
arreglo::arreglo():_k(0),_vector(new int[6]),_n(6) {
    for(int i=0;i<_n;i++){
        _vector[i]=0;
    }
}

arreglo::arreglo(const arreglo* orig) {
    this->_k=orig->_k;
    this->_n=orig->_n;
    for(int i=0;i<this->_n;i++){
        _vector[_k++]=orig->_vector[i];
    }
}

arreglo::~arreglo() {
    if(_vector !=NULL){
        delete _vector;
    }
}
void arreglo::agregar(int e){
    if(_k<_n){
        _vector[_k++]=e;
    }
}
string arreglo::toString(){
    stringstream s;
    s<<"[";
    for(int i=0;i<_k;i++){
        s<<_vector[i]<<" ";
    }
    s<<"]";
    return s.str();
}
int arreglo::getK(){
    return _k;
}
int arreglo::obtenerEsp(int i){
    return _vector[i];
}
void arreglo::agregarFinal(int e){
    if(_k<_n){
        for(int i=_k;i>=0;i--){
            _vector[i+1]=_vector[i];
        }
        _vector[0]=e;
        _k++;
        
    }else{
        //error
    }
}

void arreglo::setNumber(int n, int pos){
    _vector[pos]=n;
}
