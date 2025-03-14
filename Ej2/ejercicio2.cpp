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
#include <string>
using namespace std;


enum class Etiquetas {DEBUG, INFO, WARNING, ERROR, CRITICAL};
string etiqueta_a_string(Etiquetas nivel) {
    switch (nivel) {
        case Etiquetas::DEBUG: return "DEBUG";
        case Etiquetas::INFO: return "INFO";
        case Etiquetas::WARNING: return "WARNING";
        case Etiquetas::ERROR: return "ERROR";
        case Etiquetas::CRITICAL: return "CRITICAL";
        default: return "DESCONOCIDO";
    }
}

int main(){
    
    string respuesta; 
    cout <<"Ingrese el mensaje: "<<endl;
    getline(cin, respuesta);
    
    int severidad;
    cout<<"¿Cual es el nivel de severidad de su evento?\nIngrese el número corespondiente:\n0-DEBUG\n1-INFO\n2-WARNING\n3-ERROR\n4-CRITICAL"<<endl;
    cin>> severidad;
    
    Etiquetas NivelSeveridad = static_cast<Etiquetas>(severidad);
    cout << "Mensaje: " << respuesta << endl;
    cout << etiqueta_a_string(NivelSeveridad);
    return 0;
    
}