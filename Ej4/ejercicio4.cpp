// Se requiere el código de una función recursiva que compare dos variables que 
// contengan texto e indique mediante una variable bool si son iguales (true si son 
// iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea 
// el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre 
// la funcionalidad de su código con un texto de, al menos, 64 caracteres. 
#include <iostream>
#include <chrono> 
using namespace std;

bool son_iguales(const char* p1, const char* p2){
    //caso base
    if(*p1 == '\0' && *p2 == '\0') return true;
    if(*p1 != *p2) return false;
    //caso recursivo
    return son_iguales(p1+1, p2+1);

}
//elegi usar el tipo char* debido a que es más rapido en tiempo de ejecución que el tipo string

int main(){
    //ejemplo con cadenas distintas
    const char *p1= "hola buenas noches como va, yo estoy muy bien ojala tengas un lindo dia";
    const char *p2= "hola buena noches como va, yo estoy muy bien ojala tengas un lindo dia";
    bool iguales = son_iguales(p1, p2);
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

