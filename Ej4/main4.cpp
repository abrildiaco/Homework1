#include "comparacion.h"
#include <iostream>
#include <chrono> 
using namespace std;

//g++ -std=c++20 main4.cpp funciones4.cpp -o main4
//valgrind ./main4

constexpr bool son_iguales_compilacion( const char* p1, const char* p2){
    //caso base
    if(*p1 == '\0' && *p2 == '\0') return true;
    if(*p1 != *p2) return false;
    
    //caso recursivo
    return son_iguales_compilacion(p1+1, p2+1);
    
}

int main(){
    
    const char texto1[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    const char texto2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    const char texto3[]= "Hola, bienevenidos al ejercicio 4 del Homework 1";
    
    bool iguales_1_2 = son_iguales(texto1, texto2);
    bool iguales_1_3 = son_iguales(texto1, texto3);

    cout<<(iguales_1_2 ? "true: texto1 es igual al texto2" : "false: texto1 es distinto a texto2")<<endl;

    cout<<(iguales_1_3 ? "true: texto1 es igual al texto3\n" : "false: texto1 es distinto a texto3\n")<<endl;

    
    //medicion del tiempo para son_iguales
    auto startTime = chrono::high_resolution_clock::now(); 
    son_iguales(texto1, texto2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( 
    endTime - startTime); 
    std::cout << "A son_iguales le tomó: " << elapsedTime.count() <<" nanosegundos\n" << endl;
    
    // medición del tiempo para son_iguales_compilacion
    constexpr const char texto1_2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";
    constexpr const char texto2_2[]= "Hola, bienevenidos al ejercicio 4 del Homework 1 de la materia Paradigmas de la Programacion";

    bool iguales2 = son_iguales_compilacion(texto1_2, texto2_2);
    cout<<(iguales2 ? "true: texto1 es igual al texto1_2\n" : "false: texto1 es distinto a texto2_2\n")<<endl;

    auto startTime2 = chrono::high_resolution_clock::now(); 
    son_iguales_compilacion(texto1_2, texto2_2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>( 
    endTime2 - startTime2); 
    std::cout << "A son_iguales_compilacion le tomó: " << elapsedTime2.count() <<" nanosegundos\n" << endl;

    return 0;
}