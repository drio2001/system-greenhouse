
#include "include/Moisture.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void 
Moisture::getDate() 
{
  // Devuelve el atributo con los datos (número aleatorio entre 0 y 100) del sensor
  date_ = rand() % 101;
}

void 
Moisture::printDate() const 
{
  std::cout << "Datos de la humedad: " << date_ << std::endl;
}

std::string 
Moisture::getName() const 
{
  return "Sensor de humedad:";
}

