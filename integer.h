#ifndef INTEGER_H
#define INTEGER_H
#include "lista.h"
using namespace std;
class integer {
public:
    integer(lista*);
	integer(int);
	integer(long);
    integer(const integer& orig);
    virtual ~integer();
private:
	lista* valor;
};

#endif /* INTEGER_H */

