#include<iostream>
#include <ctime>
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
    
//    arreglo *a1 = new arreglo();
//    arreglo *a2 = new arreglo();
//    lista *l1 = new lista();
//    lista *l2 = new lista();
//    //integer* num = new integer(1232132);
//    
//
//   
//   a1->agregarFinal(555555555);
//   a1->agregarFinal(777777777);
//    
////    a1->agregarFinal(5555);
////    a1->agregarFinal(4444);
//    
//   
//  // a2->agregarFinal(22922291);
//    
//    a2->agregarFinal(222222222);
//    a2->agregarFinal(667666666);
////    a2->agregarFinal(1111);
//    //                    
//    l1->agregar(a1);
//    l2->agregar(a2);
//    lista *l3 = l1->operator - (l2);
//    //              
//    cout << " " << l1->toString() << endl;
//    cout << " " << l2->toString() << endl;
//    cout << "-__________________" << endl;
//    cout << " " << l3->toString() << endl;
//
 /*   integer* num = new integer(l3);
    cout<<num->toString();
    */

    /*TEST METODOS FORMULAS*/
arreglo* a1 = new arreglo();
arreglo* a2 = new arreglo();
lista* l1 = new lista();
lista* l2 = new lista();
a1->agregar(123456789);
a1->agregar(987654321);
a2->agregar(123456789);
a2->agregar(987654321);
l1->agregar(a1);
l2->agregar(a2);
cout << l1->toString() << endl;
cout << l2->toString() << endl;
if (l1->operator!=(l2))
{
	cout << "Son distintos";
}
else
{
	cout<< "son iguales";
}

arreglo* a20 =new arreglo();
arreglo* a30 = new arreglo();
lista *l10 = new lista();
lista *l20 = new lista();


a20->agregarFinal(55555);
a30->agregarFinal(44444);

a20->agregarFinal(11111);
a30->agregarFinal(1111);


l10->agregar(a20);
l20->agregar(a30);



cout<<endl;
cout<<l10->toString()<<" + "<<l20->toString()<<endl;

l10 = l10->operator +=(l20);

cout<<"L10 SOBRECARGA: "<<l10->toString()<<endl;


//unsigned t0, t1;
//
//t0 = clock();
//int n = 1000;
//lista* l1 = lista::fibonacci(n);
//	cout<<"FIBONACCI DE "<<n<<endl<<l1->toString();
//	delete l1;
//	// Code to execute
//	t1 = clock();
//	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
//	cout << "Execution Time: " << time << endl;
	//lista* l1 = new lista();
//integer* num = new integer(l1);
//num->parse("43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
//cout << num->toString(); 
//	cin.get();

    return 0;
}

