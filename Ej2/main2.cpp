#include "log.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int main(){

    int evento_num;
    cout<<"¿Cual es el tipo de evento a registrar?\nIngrese el número corespondiente:\n0-DEBUG\n1-INFO\n2-WARNING\n3-CRITICAL\n4-ERROR\n5-SECURITY\n6-FATAL"<<endl;
    cin>> evento_num;
    cin.ignore(); //limpio el bufer para ignorar el '\n' que quedo guardado. Ocurre cuando sa usa cin>> para leer numeros
    
    Etiquetas evento_seleccionado = static_cast<Etiquetas>(evento_num);

    try{
        
        if(evento_num < 0 || evento_num > 6){ cout<<etiqueta_a_string(evento_seleccionado)<<" - Programa terminado"<<endl; return 1;}
        
        if (evento_num >= 0 && evento_num <= 3){

            string mensaje; 
            cout <<"Ingrese el mensaje: "<<endl;
            getline(cin, mensaje); //getline capta aquellas sentencias con más de una palabra

            logMessage(mensaje, evento_seleccionado);
        
        }else if (evento_num == 4){

            string mensaje; 
            cout <<"Ingrese el mensaje de error: "<<endl;
            getline(cin, mensaje);

            logMessage(mensaje, __FILE__, __LINE__);
        
        }else if (evento_num == 5){

            string mensaje; 
            cout <<"Ingrese el mensaje de acceso: "<<endl;
            getline(cin, mensaje);

            string usuario; 
            cout <<"Ingrese su nombre de usuario: "<<endl;
            cin>> usuario;

            logMessage(mensaje, usuario);
        
        }else{
            throw runtime_error("FATAL ERROR"); //tira un FATAL ERROR en tiempo de ejcución cuando se selecciona la opcion 6 (FATAL)
        }
    
    }catch(runtime_error &e){ //capturo el runtime error
        
        logMessage(e.what(), evento_seleccionado);
        cout << "Runtime error: " << e.what()<<endl;; //e.what() devuelve el mensaje cargado en runtime_error()
        
        return 1;
    }
    
    return 0;
}