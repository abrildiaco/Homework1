#include "comparacion.h"
#include <iostream>
#include <chrono> 
using namespace std;

int main(){
    
    cout<<"\nComparacion de textos en tiempo de ejecución:\n"<<endl;

    const char texto1[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    const char texto2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    const char texto3[]= "Hola, bienevenidos al ejercicio 4 del Homework 1";
    
    //ejemplo con textos iguales y textos distintos
    bool iguales_1_2 = son_iguales(texto1, texto2);
    bool iguales_1_3 = son_iguales(texto1, texto3);

    cout<<(iguales_1_3 ? "true: texto1 es igual al texto3" : "false: texto1 es distinto a texto3")<<endl;
    cout<<(iguales_1_2 ? "true: texto1 es igual al texto2\n" : "false: texto1 es distinto a texto2\n")<<endl;

    //medicion del tiempo para son_iguales
    auto startTime = chrono::high_resolution_clock::now(); 
    son_iguales(texto1, texto2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( 
    endTime - startTime); 
    cout << "A son_iguales le tomó: " << elapsedTime.count() <<" nanosegundos\n" << endl;
    
    
    cout<<"--------------------------------------------------------\n"<<endl;
    
    cout<<"Comparacion de textos en tiempo de compilación:\n"<<endl;
    
    constexpr const char texto1_2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    constexpr const char texto2_2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    
    // medición del tiempo para son_iguales_compilacion
    auto startTime2 = chrono::high_resolution_clock::now(); 
    son_iguales_compilacion(texto1_2, texto2_2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>( 
    endTime2 - startTime2); 
    cout << "A son_iguales_compilacion le tomó: " << elapsedTime2.count() <<" nanosegundos\n" << endl;

    return 0;
}