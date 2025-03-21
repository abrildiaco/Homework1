#include "comparacion.h"
#include <iostream>
using namespace std;

bool son_iguales(const char* p1, const char* p2){
    
    //caso base
    if(*p1 == '\0' && *p2 == '\0') return true; //en una cadena de caracteres, hay un '\0' para indicar su fin
    if(*p1 != *p2) return false; //si los caracteres actuales con istintos-->devuelvo false
    
    //caso recursivo
    return son_iguales(p1+1, p2+1);

}

/*
Elegí utilizar const char* ya que utilizan menos memoria que los strings, y su tiempo
de ejecución es más rápido. Además, al contrario de los strings, los puedo utilizar
con funciones que se ejecutan en tiempo de compilación.
*/