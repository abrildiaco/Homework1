#include "comparacion.h"
#include <iostream>
using namespace std;

bool son_iguales(const char* p1, const char* p2){
    //caso base
    if(*p1 == '\0' && *p2 == '\0') return true;
    if(p1[0] != p2[0]) return false;
    //caso recursivo
    return son_iguales(p1+1, p2+1);

}
//egi usar el tipo char* debido a que es más rapido en tiempo de ejecución que el tipo string