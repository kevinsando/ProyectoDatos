#include<iostream>
#include<cstring>
#include "lista.h"
#include "arreglo.h"
#include"integer.h"
#include "string"
#include "iostream"
#include "sstream"
using namespace std;


//int max = 2568;
//
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
    //    return 0;
    
    
        arreglo *a1 = new arreglo();
        arreglo *a2 = new arreglo();
        lista *l1 = new lista();
        lista *l2 = new lista();
    	integer* num = new integer(1232132);
                    a1->agregar(3);
                    a1->agregar(6);
                    a1->agregar(4);
                
                    a2->agregar(4);
                    a2->agregar(5);
                    a2->agregar(6);
        //            a2->agregar(8);
        //            a2->agregar(7);
                    
                    l1->agregar(a1);
                    l2->agregar(a2);
                    lista *l3 = l1->operator *(l2);
                    
                    cout<<" "<<l1->toString()<<endl;
                    cout<<" "<<l2->toString()<<endl;
                    cout<<"*__________________"<<endl;
                    cout<<" "<<l3->toString()<<endl;



    //Test de suma

    //    a1->agregar(4);
    //    a1->agregar(5);
    //    a1->agregar(8);
    //    a1->agregar(1);
    //    a1->agregar(1);
    //    a1->agregar(1);
    //
    //    a2->agregar(7);
    //    a2->agregar(6);
    //    a2->agregar(7);
    //    a2->agregar(9999);
    //    a2->agregar(9999);
    //
    //
    //
    //    l1->agregar(a1);
    //    l2->agregar(a2);
    //
    //
    //
    //    cout << " " << l1->toString() << " +" << " " << l2->toString() << endl;
    //    lista* l3 = l1->operator+=(l2);
    ////
    //   cout << " " << l3->toString() << endl;
    //cin.get();

    return 0;
}

