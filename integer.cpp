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
void integer::parse( string s)
{
	arreglo* aux = new arreglo();
	arreglo* m = new arreglo();
	int num;
	int partir = 10;

	while (s.size() > 9)
	{	
		string temp = "";

			int tam = s.size();
			int partir = s.size() - 9;
			for (int i =partir; i < tam; i++)
			{
				temp += s[i];
			}
			for (int i = partir; i < tam; i++)
			{
				s.erase(s.size() - 1);
			}
			stringstream ss(temp);
			ss >> num;
			if (aux->getK() == 9)
			{
				m->agregarFinal(num);
			}
			else
			{
				aux->agregarFinal(num);
			}
	}
	stringstream ss(s);
	ss >> num;
	if (aux->getK() == 9)
	{
		m->agregarFinal(num);
	}
	else
	{
		aux->agregarFinal(num);
	}
	valor->agregar(m);
	valor->agregar(aux);
}
string integer::toString(){
    stringstream s;
    s<<valor->toString()<<endl;
    
    return s.str();
}

integer::~integer() {
}


