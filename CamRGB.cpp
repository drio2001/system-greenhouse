
#include "include/CamRGB.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void 
CamRGB::getDate() 
{
  // Devuelve el atributo con los datos (matriz 3x3 de números aleatorios)
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      date_[i][j] = rand() % 100;
    }
  }
}

void 
CamRGB::printDate() const 
{
  // Imprime el atributo con los datos del sensor
  std::cout << "Datos cámara RGB:" << std::endl;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << date_[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

std::string 
CamRGB::getName() const 
{
  return "Cámara RGB";
}

