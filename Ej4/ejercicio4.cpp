#include <iostream>
#include <chrono> 
using namespace std;

//bool son_iguales(const char* p1, const char* p2){
//    //caso base
//    if(*p1 == '\0' && *p2 == '\0') return true;
//    if(*p1 != *p2) return false;
//    //caso recursivo
//    return son_iguales(p1+1, p2+1);
//
//}
//elegi usar el tipo char* debido a que es más rapido en tiempo de ejecución que el tipo string


//Modifique el código del ejercicio 4.1 para que la comparación de los textos se 
//realice en tiempo de compilación y obtenga el tiempo de ejecución. Compare 
//este tiempo con el obtenido en el ejercicio 4.2 y justifique brevemente la 
//diferencia (puede escribir su conclusión como un comentario al final del código 
//de este item). 

//codigo modificado
constexpr bool son_iguales(const char* p1, const char* p2){
    //caso base
    if(*p1 == '\0' && *p2 == '\0') return true;
    if(*p1 != *p2) return false;
    
    //caso recursivo
    return son_iguales(p1+1, p2+1);
    
}

int main(){
    //ejemplo con cadenas distintas
    constexpr const char p1[]= "hola buenas noches como va, yo estoy muy bien ojala tengas un lindo dia";
    constexpr const char p2[]= "hola buena noches como va, yo estoy muy bien ojala tengas un lindo dia";
    
    constexpr bool iguales = son_iguales(p1, p2);
    
    cout<<(iguales ? "true" : "false")<<endl;
    
    //medicion del tiempo
    auto startTime = std::chrono::high_resolution_clock::now(); 
    son_iguales(p1, p2); 
    auto endTime = std::chrono::high_resolution_clock::now(); 
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( 
    endTime - startTime); 
    std::cout << "A son_iguales le tomó: " << elapsedTime.count() <<" nanosegundos" << std::endl;
    
    return 0;
}