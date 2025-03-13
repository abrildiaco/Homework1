
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> crear_matriz(const int n){
    int num = 1;
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            matriz[i][j] = num;
            num++;
        }
    }
    return matriz;
}

void imprimir_matriz(vector<vector<int>> matriz, int size){
    int fila = size-1;
    int columna = size-1;
    for (int n = size*size; n>0; n-- ){
        cout << "M["<<fila<<"]["<<columna<<"] = " <<matriz[fila][columna] << " ";
        cout << "\n";
        if (columna == 0) {
            columna = size-1;
            fila--;
        }
        else columna--;
    }
    return;
}

//Ejemplo con n=3
int main(){
    int n = 3;
    vector<vector<int>> matriz =  crear_matriz(n);
    imprimir_matriz(matriz, n);
    return 0;
}