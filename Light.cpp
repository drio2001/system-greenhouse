
#include "include/Light.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void 
Light::getDate() 
{
    // Devuelve el atributo con los datos (número aleatorio entre 0 y 100) del sensor
    date_ = rand() % 101;
}

void 
Light::printDate() const 
{
    std::cout << "Datos de la iluminación: " << date_ << std::endl;
}

std::string 
Light::getName() const 
{
  return "Sensor de iluminación:";
}

