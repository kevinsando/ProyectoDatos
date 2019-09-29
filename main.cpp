#include<iostream>
#include <ctime>
#include<cstring>
#include "lista.h"
#include "arreglo.h"
#include"integer.h"
#include "string"
using namespace std;

#define max 2568
//int max = 2568;

void display(int arr[]) {
    int ctr = 0;
    for (int i = 0; i < max; i++) {
        if (!ctr && arr[i])
            ctr = 1;
        if (ctr)
            std::cout << arr[i];
    }
}

int fibonacci(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(arr, n - 2) + fibonacci(arr, n - 1);
}

void factorial(int arr[], int n) {
    if (!n) return;
    int carry = 0; //Valor de acarreo
    for (int i = max - 1; i >= 0; --i) {//Del tamaño menos 1 del arreglo(Por aquello de tener que acarrear al final) hasta 0
        arr[i] = (arr[i] * n) + carry; //El valor en la posición i del arreglo sería ese dígito, multiplicado por n + el carreo
        carry = arr[i] / 10;
        arr[i] %= 10;
    }
    factorial(arr, n - 1);
}

int main() {
    int *arr = new int[max];

    std::memset(arr, 0, max * sizeof (int)); //Incializo la matríz con 0s
    arr[max - 1] = 1;
    int num;
    std::cout << "Digite un numero: ";
    std::cin>>num;
    std::cout << "el factorial de " << num << " es :\n";
    factorial(arr, num);
    display(arr);
    delete[] arr;
    cout<<endl;




    arreglo* a111 = new arreglo();
    arreglo* a222 = new arreglo();
    lista* l111 = new lista();
    lista* l222 = new lista();
    a111->agregar(123456789);
    a111->agregar(987654321);
    a222->agregar(123456789);
    a222->agregar(987654321);
    l111->agregar(a111);
    l222->agregar(a222);
    cout << l111->toString() << endl;
    cout << l222->toString() << endl;
    if (l111->operator!=(l222)) {
        cout << "Son distintos";
    } else {
        cout << "son iguales";
    }

    arreglo* a20 = new arreglo();
    arreglo* a30 = new arreglo();
    lista *l10 = new lista();
    lista *l20 = new lista();


    a20->agregarFinal(55555);
    a30->agregarFinal(44444);

    a20->agregarFinal(11111);
    a30->agregarFinal(1111);


    l10->agregar(a20);
    l20->agregar(a30);



    cout << endl;
    cout << l10->toString() << " + " << l20->toString() << endl;

    l10 = l10->operator+=(l20);

    cout << "L10 SOBRECARGA: " << l10->toString() << endl;






    unsigned t0, t1;

    t0 = clock();
    int n = 1000;
    lista* l8 = lista::fibonacci(n);
    cout << "FIBONACCI DE " << n << endl << l8->toString();
    delete l8;
    // Code to execute
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    lista* l9 = new lista();
    integer* num1 = new integer(l9);
    num1->parse("43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
    cout << num1->toString();





    lista *l1 = new lista();
    lista *l2 = new lista();
    lista* l3 = new lista();
    arreglo *a1 = new arreglo();
    arreglo *a2 = new arreglo();
    arreglo* a3 = new arreglo();
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a1->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a2->agregarFinal(999999999);
    a3->agregarFinal(999999999);
    l1->agregar(a1);
    l2->agregar(a2);

    cout << "Numero 1: " << l1->toString() << endl;
    cout << "Numero 2: " << l2->toString() << endl;
    cout << "Son iguales?: " << l1->operator==(l2) << " ,Diferentes?: " << l1->operator!=(l2) << endl;
    cout << "N1 mayor?: " << l1->operator>(l2) << " ,N2 menor?: " << l1->operator<(l2) << endl;

    cout << "N3=N1+N2" << endl;
    l3 = l1->operator+(l2);
    cout << l1->toString() << " + " << l2->toString() << endl;
    cout << "N3: " << l3->toString() << endl;

    cout << "N4=N1-N2" << endl;
    lista* l4 = l1->operator-(l2);
    cout << l1->toString() << " - " << l2->toString() << endl;
    cout << "N4: " << l3->toString() << endl;


    cout << "N3 mayor que N1?: " << l3->operator>(l1) << ", es N1 menor que N3?: " << l1->operator<(l3) << endl;
    cout << "se eliminan N1, N2 y N3" << endl;
    delete l3;
    delete l2;
    delete l1;
    cout << "Se les asignan nuevos numeros" << endl;
    l1 = new lista();
    l2 = new lista();
    a1 = new arreglo();
    a2 = new arreglo();
    a1->agregarFinal(987536287);
    a1->agregarFinal(849915367);
    a1->agregarFinal(987536287);
    a1->agregarFinal(546789032);
    a1->agregarFinal(911111111);
    a1->agregarFinal(987536287);
    a1->agregarFinal(456546462);
    a1->agregarFinal(132414344);
    a1->agregarFinal(987536287);
    a2->agregarFinal(982434258);
    l1->agregar(a1);
    l2->agregar(a2);
    cout << "N1: " << l1->toString() << endl;
    cout << "N2: " << l2->toString() << endl;
    l3 = l1->operator*(l2);
    cout << "N3= N1*N2: " << l3->toString() << endl;

    cout << "N1: " << l1->toString() << endl;
    cout << "N2: " << l2->toString() << endl;


    return 0;
}

