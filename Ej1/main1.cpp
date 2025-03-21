#include "matriz.h"
using namespace std;

//Ejemplo con n=3
int main(){
    const int n = 3;
    vector<vector<int>> matriz =  crear_matriz(n);
    imprimir_matriz(matriz, n);
    return 0;
}
