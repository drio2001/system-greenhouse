
#include "include/Temp.h"
#include "iostream"
#include <cstdlib>
#include <ctime>

void 
Temp::getDate() 
{
  // Devuelve el atributo con los datos (número aleatorio entre 0 y 100) del sensor
  date_ = rand() % 101;
}

void 
Temp::printDate() const 
{
  std::cout << "Datos de la temperatura: " << date_ << std::endl;
}

std::string 
Temp::getName() const 
{
  return "Sensor de temperatura:";
}

