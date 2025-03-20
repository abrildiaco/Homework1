#pragma once

#include <string>

enum class Etiquetas {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY, FATAL};

std::string etiqueta_a_string(Etiquetas);

void logMessage(const std::string, Etiquetas);
void logMessage(const std::string, std::string, const int);
void logMessage(const std::string, std::string, Etiquetas);
