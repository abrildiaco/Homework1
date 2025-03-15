 
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

enum class Etiquetas {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY};

string etiqueta_a_string(Etiquetas severidad) {
    switch (severidad) {
        case Etiquetas::DEBUG: return "DEBUG";
        case Etiquetas::INFO: return "INFO";
        case Etiquetas::WARNING: return "WARNING";
        case Etiquetas::ERROR: return "ERROR";
        case Etiquetas::CRITICAL: return "CRITICAL";
        case Etiquetas::SECURITY: return "SECURITY";
        default: return "NO EXISTE LA ETIQUETA";
    }
}

void logMessage(string mensaje, Etiquetas NivelSeveridad){
    
    ofstream outFile("archivo_log.txt", ios::app);
    
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

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario, Etiquetas NivelSeveridad = Etiquetas::SECURITY){
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
     outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" <<"["<<Nombre_de_Usuario<<"]" << "<" << Mensaje_De_Acceso <<">\n";
     outFile.close();
     cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

int main(){

    string respuesta;
    cout<<"¿Desea loguear un evento? [si/no]"<<endl;
    cin>>respuesta;

    while (respuesta == "si"){
        
        string mensaje; 
        cout <<"Ingrese el mensaje: "<<endl;
        cin.ignore();
        getline(cin, mensaje);
        
        int severidad;
        cout<<"¿Cual es el nivel de severidad de su evento?\nIngrese el número corespondiente:\n0-DEBUG\n1-INFO\n2-WARNING\n3-ERROR\n4-CRITICAL"<<endl;
        cin>> severidad;
        
        Etiquetas NivelSeveridad = static_cast<Etiquetas>(severidad);

        logMessage(mensaje, NivelSeveridad);
        
        cout<<"¿Desea loguear otro evento? [si/no]"<<endl;
        cin>>respuesta;
    }
    
    if (respuesta == "no"){cout<< "programa terminado"<<endl; return 0;}
    else if (respuesta != "si"){cout<<"Respuesta desconocida"<<endl; return 1;}
    
    return 0;
}