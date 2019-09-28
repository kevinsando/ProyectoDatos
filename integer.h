#ifndef INTEGER_H
#define INTEGER_H
#include "lista.h"
#include "string"
#include <sstream>
using namespace std;

class integer {
public:
    integer(lista*);
	integer(int);
	integer(long);
    integer(const integer&);
	 void parse(string);

    virtual ~integer();
    string toString();
private:
	lista* valor;
};

#endif /* INTEGER_H */