 
//Todos los nuevos mensajes deben ser invocados con logMessage. 

//Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el 
//archivo y la línea de código donde sucedió este error, es decir: 
//logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código) 

//Se requiere la posibilidad de registrar un mensaje de “Acceso de Usuario” a la 
//aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma 
//debe ser ingresada de la siguiente manera: 
//logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario) 
//Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc. 

//Se requiere un código que pruebe que el sistema verifica la funcionalidad 
//requerida y que además demuestre que puede capturar un error en runtime, 
//crear una entrada en el log y después detener la ejecución del programa y salir 
//del mismo con un código de error (return 1).  


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum class Etiquetas {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY, FATAL};

string etiqueta_a_string(Etiquetas);
void logMessage(string, Etiquetas);
void logMessage(string, string, int);
void logMessage(string, string, Etiquetas);

//g++ -std=c++20 ejercicio2.cpp -o ej2
//./ej2


int main(){

    int evento_num;
    cout<<"¿Cual es el tipo de evento a registrar?\nIngrese el número corespondiente:\n0-DEBUG\n1-INFO\n2-WARNING\n3-CRITICAL\n4-ERROR\n5-SECURITY\n6-FATAL"<<endl;
    cin>> evento_num;
    cin.ignore();
    
    Etiquetas evento_seleccionado = static_cast<Etiquetas>(evento_num);

    try{
        
        if(evento_num < 0 || evento_num > 6){ cout<<etiqueta_a_string(evento_seleccionado)<<" - Programa terminado"<<endl; return 1;}
        
        if (evento_num >= 0 && evento_num <= 3){

            string mensaje; 
            cout <<"Ingrese el mensaje: "<<endl;
            getline(cin, mensaje);

            logMessage(mensaje, evento_seleccionado);
        
        }else if (evento_num == 4){

            string mensaje; 
            cout <<"Ingrese el mensaje de error: "<<endl;
            getline(cin, mensaje);

            string archivo;
            cout <<"Ingrese el nombre del archivo donde ocurrió el error: "<<endl;
            getline(cin, archivo);

            int linea_de_codigo;
            cout <<"Ingrese el número de la línea de código: "<<endl;
            cin>> linea_de_codigo;

            logMessage(mensaje, archivo, linea_de_codigo);
        
        }else if (evento_num == 5){

            string mensaje; 
            cout <<"Ingrese el mensaje de acceso: "<<endl;
            getline(cin, mensaje);

            string usuario; 
            cout <<"Ingrese su nombre de usuario: "<<endl;
            cin>> usuario;

            logMessage(mensaje, usuario, evento_seleccionado);
        
        }else{
            throw runtime_error("FATAL ERROR");
        }
    
    }catch(runtime_error &e){
        logMessage(e.what(), evento_seleccionado);
        cout << "Runtime error: " << e.what()<<endl;;
        return 1;
    }
    
    return 0;
}

//-----------------------------------------------------------------------------------------------

// Definición de funciones

string etiqueta_a_string(Etiquetas eventos) {
    switch (eventos) {
        case Etiquetas::DEBUG: return "DEBUG";
        case Etiquetas::INFO: return "INFO";
        case Etiquetas::WARNING: return "WARNING";
        case Etiquetas::CRITICAL: return "CRITICAL";
        case Etiquetas::ERROR: return "ERROR";
        case Etiquetas::SECURITY: return "SECURITY";
        case Etiquetas::FATAL: return "FATAL";
        default: return "NO EXISTE LA ETIQUETA";
    }
}

void logMessage(string mensaje, Etiquetas NivelSeveridad){
    
    ofstream outFile("archivo_log.txt",ios::app);
    
    if (outFile.is_open()) {
        outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" << "<" << mensaje <<">\n";
        
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
        outFile <<"[line:"<<Línea_de_Código<<"] " <<"["<<Archivo<<"]" << "<" <<  Línea_de_Código <<">\n";
     
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario, Etiquetas NivelSeveridad){
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
     
        outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" <<"["<<Nombre_de_Usuario<<"]" << "<" << Mensaje_De_Acceso <<">\n";
     
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

void get_runtime_error(string mensaje){

}