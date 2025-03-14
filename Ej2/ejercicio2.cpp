//Cada evento recibe una etiqueta que indica su nivel de importancia o 
//gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y 
//CRITICAL.

//a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un 
//archivo mediante el llamado a una función logMessage definida en pseudo código de 
//la siguiente manera: 
// 
//void logMessage(String mensaje, Integer/Otro NivelSeveridad) 
// 
//Donde NivelSeveridad corresponderá con unas de las leyendas previamente 
//mencionadas. El formato esperado en una línea del archivo de log es el siguiente: 
//Homework #1  
//I102 – Paradigmas de Programación 
//[ERROR] <Mensaje> 

#include <iostream>
using namespace std;

int main(){
    enum class Etiquetas {DEBUG, INFO, WARNING, ERROR, CRITICAL}
    string respuesta; 
    cout<<"Ingrese el mensaje: ";
    cin >> respuesta;
    string severidad;
    cout<<"¿Cual es el nivel de severidad de su evento?\nIngrese:\nDEBUG
            /INFO/WARNING/ERROR/CRITICAL";
    cin>> severidad

    
}