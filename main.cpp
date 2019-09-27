#include<iostream>
#include<cstring>
#include "lista.h"
#include "arreglo.h"
#include"integer.h"
#include "string"
using namespace std;


//int max = 2568;

//void display(int arr[]) {
//    int ctr = 0;
//    for (int i = 0; i < max; i++) {
//        if (!ctr && arr[i])
//            ctr = 1;
//        if (ctr)
//            std::cout << arr[i];
//    }
//}
//
//int fibonacci(int arr[], int n) {
//    if (n == 0 || n == 1)
//        return n;
//    else
//        return fibonacci(arr, n - 2) + fibonacci(arr, n - 1);
//}
//
//void factorial(int arr[], int n) {
//    if (!n) return;
//    int carry = 0; //Valor de acarreo
//    for (int i = max - 1; i >= 0; --i) {//Del tamaño menos 1 del arreglo(Por aquello de tener que acarrear al final) hasta 0
//        arr[i] = (arr[i] * n) + carry; //El valor en la posición i del arreglo sería ese dígito, multiplicado por n + el carreo
//        carry = arr[i] / 10;
//        arr[i] %= 10;
//    }
//    factorial(arr, n - 1);
//}

int main() {
    //    int *arr = new int[max];
    //    
    //    std::memset(arr,0,max*sizeof(int));//Incializo la matríz con 0s
    //    arr[max-1] = 1;
    //    int num;
    //    std::cout<<"Digite un numero: ";
    //    std::cin>>num;
    //    std::cout<<"el factorial de "<<num<<" es :\n";
    //    factorial(arr,num);
    //    display(arr);
    //    delete[] arr;
    //    std::cin.get();
    //    std::cin.get();




    //Test de suma


//    lista *l1 = new lista();
//    lista *l2 = new lista();
//    lista* l3 = new lista();
//    arreglo *a1 = new arreglo();
//    arreglo *a2 = new arreglo();
//    arreglo* a3 = new arreglo();
//    
//    a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//   a1->agregarFinal(100000000);
//    
//    
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//    a2->agregarFinal(22222222);
//
//    
//
//    
//    l1->agregar(a1);
//    l2->agregar(a2);
//
//
//    
//    cout<<l1->toString()<<" + "<<l2->toString()<<endl;
//    
//  
//    
//    
//   l3= l1->operator +(l2);
//    cout<<l3->toString();
//    
    
    
    
    
    
    
    
    
    //*** test Multiplicacion ***
    
    arreglo *a1 = new arreglo();
    arreglo *a2 = new arreglo();
    lista *l1 = new lista();
    lista *l2 = new lista();
    //integer* num = new integer(1232132);
    a1->agregar(12345678);
    a2->agregar(87654321);

    //                    
    l1->agregar(a1);
    l2->agregar(a2);
    lista *l3 = l1->operator * (l2);
    //              
    cout << " " << l1->toString() << endl;
    cout << " " << l2->toString() << endl;
    cout << "*__________________" << endl;
    cout << " " << l3->toString() << endl;

 /*   integer* num = new integer(l3);
    cout<<num->toString();
    */
    
	cin.get();
    return 0;
}

