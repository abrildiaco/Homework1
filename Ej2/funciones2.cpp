#include "log.h"
#include <fstream>
#include <iostream>

using namespace std;

/*
La funcion etiqueta_a_string permite recibir un enum Etiqueta y devolver un string.
Los enums los puedo castear a int, y en ese caso me devolverían la posición en
la que fueron definidos, pero no puedo castearlos a strings. Para ello, me ayudo de un switch
que mapea cada etiqueta a su respectiva cadena. Si el valor no está definido en el enum, devuelve un 
mensaje de error indicando que la etiqueta no existe.
*/

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

/*
Las siguientes funciones abren (o crean si no existe) un archivo de log llamado "archivo_log.txt" 
y agrega un mensaje con una etiqueta de severidad específica. Se utiliza la función 
`etiqueta_a_string` para convertir el enum a su representación en texto.
*/

void logMessage(const string Mensaje, Etiquetas NivelSeveridad){
    
    //abro/genro el archivo. Uso ios::app para no pisar lo que ya está escrito
    ofstream outFile("archivo_log.txt",ios::app); 
    
    if (outFile.is_open()) {
        
        outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" << "<" << Mensaje <<">\n";
        
        outFile.close();
        cout << "Mensaje logueado\n";
    
    } else cerr << "Error abriendo el archivo!\n";
    
    return;
}

void logMessage(const string Mensaje_de_Error, const string Archivo, const int Línea_de_Código){
    
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
        
        outFile <<"[ERROR][line:"<<Línea_de_Código<<"]" <<"[archivo: "<<Archivo<<"]" << "<" <<  Mensaje_de_Error <<">\n";
     
        outFile.close();
        cout << "Mensaje logueado\n";
    
    } else cerr << "Error abriendo el archivo!\n";
    
    return;
}

void logMessage(const string Mensaje_De_Acceso, const string Nombre_de_Usuario){
    
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
     
        outFile <<"[SECURITY]" <<"[usuario: "<<Nombre_de_Usuario<<"]" << "<" << Mensaje_De_Acceso <<">\n";
     
        outFile.close();
        cout << "Mensaje logueado\n";
    
    } else cerr << "Error abriendo el archivo!\n";
    
    return;
}
