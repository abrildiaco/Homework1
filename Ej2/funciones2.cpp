#include "log.h"
#include <fstream>
#include <iostream>

using namespace std;

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

void logMessage(const string mensaje, Etiquetas NivelSeveridad){
    
    ofstream outFile("archivo_log.txt",ios::app);
    
    if (outFile.is_open()) {
        outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" << "<" << mensaje <<">\n";
        
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

void logMessage(const string Mensage_de_Error, const string Archivo, const int Línea_de_Código){
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
        outFile <<"[line:"<<Línea_de_Código<<"] " <<"["<<Archivo<<"]" << "<" <<  Línea_de_Código <<">\n";
     
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}

void logMessage(const string Mensaje_De_Acceso, const string Nombre_de_Usuario, Etiquetas NivelSeveridad){
    ofstream outFile("archivo_log.txt", ios::app);
    
    if (outFile.is_open()) {
     
        outFile <<"["<<etiqueta_a_string(NivelSeveridad)<<"]" <<"["<<Nombre_de_Usuario<<"]" << "<" << Mensaje_De_Acceso <<">\n";
     
        outFile.close();
        cout << "Mensaje logeado\n";
    
    } else
        cerr << "Error abriendo el archivo!\n";
    return;
}
