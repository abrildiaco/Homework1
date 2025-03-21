#include "matriz.h"
#include <iostream>
using namespace std;

/*La funcion crear_matriz genera una matriz de tamaño n*n con el uso de la estructura "vector",
la cual me permitió trabajar de manera mas ordenada y legible, sin tener que preocuparme por la
asignacion y liberacion de memoria.
-La funcion recible como parámetro a un entero n que representa la cantidad de filas y columnas 
que tendrá la matriz, y devuelve un vector de vectores con elementos de tipo enteros.
-La variable num es la encargada de asignarle el valor a cada posicion 
*/

vector<vector<int>> crear_matriz(const int n){
    
    int num = 1; 
    
    //creo una matriz de n vectores cada uno con n posiciones inicializadas en 0
    vector<vector<int>> matriz(n, vector<int>(n, 0)); 
    
    //recorro las filas de la matriz y le asigno un valor "num" a cada posicion
    for (int i = 0; i<n; i++){
        
        for (int j = 0; j<n; j++){
            
            matriz[i][j] = num;
            num++;
        }
    }
    return matriz;
}


/*
Para cumplir con la restricción de usar un único ciclo, implementé un for de rango n*n, 
evitando así un doble bucle anidado.
- La impresión comienza desde la posición [n-1][n-1], es decir, desde la última posicion de la matriz.
- Se utilizan dos variables, 'fila' y 'columna', inicializadas en n-1 para recorrer la matriz de abajo hacia arriba
- En cada iteración, 'columna' se decrementa hasta alcanzar 0.
- Cuando columna == 0, se decrementa una fila y 'columna' se reinicia a n-1, 
permitiendo recorrer la nueva fila de derecha a izquierda.
De este modo, consigo recorrer la matriz de abajo hacia arriba,
imprimiendo cada valor con su posicion e iterar en un único ciclo
*/

void imprimir_matriz(const vector<vector<int>> &matriz, int n){
    
    int fila = n-1;
    int columna = n-1;
    
    for (unsigned int i = n*n; i > 0; i-- ){
        
        cout << "M["<<fila<<"]["<<columna<<"] = " <<matriz[fila][columna] << " ";
        cout << "\n";
        
        if (columna == 0) { //condicion para cambiar a una fila menor
            
            fila--;         //me muevo a una fila mas arriba
            columna = n-1; //como ahora estoy en una fila nueva, mis columnas vuelven a empezar en la posicion (n-1)
        
        }else columna--; //me muevo de columna hacia la izquierda
    }
    
    return;
}