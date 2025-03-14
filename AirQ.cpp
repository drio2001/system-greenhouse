#include "include/AirQ.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void 
AirQ::getDate() 
{
  // Devuelve el atributo con los datos (número aleatorio entre 0 y 100) del sensor
  date_ = rand() % 101;
}

void 
AirQ::printDate() const 
{
  // Imprime el atributo con los datos del sensor
  std::cout << "Datos de la calidad del aire: " << date_ << std::endl;
}
    
std::string 
AirQ::getName() const 
{
  // Devuelve el nombre del sensor
  return "Sensor calidad del aire:";
}

