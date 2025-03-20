#pragma once


bool son_iguales(const char*, const char*);

/*la definición de la funcuón esta en el archivo .h para que entonces pueda ser usada en tiempo de compilacion,
evitando errores de referencia*/

//constexpr bool son_iguales_compilacion(const char* p1, const char* p2){
//    //caso base
//    if(*p1 == '\0' && *p2 == '\0') return true;
//    if(*p1 != *p2) return false;
//    
//    //caso recursivo
//    return son_iguales_compilacion(p1+1, p2+1);
//    
//}