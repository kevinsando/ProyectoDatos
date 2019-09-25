#include "integer.h"

integer::integer(lista* l) {
	valor = l;
}
integer::integer(int st)
{
	arreglo* arr = new arreglo();
	arr->agregar(st);
	valor = new lista();
	valor->agregar(arr);
}
integer::integer(long l)
{
	int num = l;
	arreglo* aux = new arreglo();
	aux->agregar(num);
	valor = new lista();
	valor->agregar(aux);
}
integer::integer(const integer& orig) {
}

integer::~integer() {
}

