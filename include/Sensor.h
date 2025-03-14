#ifndef SENSOR_H 
#define	SENSOR_H

#include <string>

class Sensor{
public:
  virtual ~Sensor() {}  // Destructor virtual de la clase
  // Metodo virtuales puros que deben implementarse en las clases heredadas de Sensor (virtual):
  virtual void getDate() = 0; // Metodo para obtener la fecha de los datos del sensor
  virtual void printDate() const = 0; // Metodo para imprimir la fecha de los datos del sensor
  virtual std::string getName() const = 0; // Metodo que devuelve el nombre del sensor
  void setIdentificator(int identificator) {
    identificator_ = identificator; 
  }  // Metodo para establecer el identificador del sensor
  int getIdentificator() const { 
    return identificator_; 
  } // Metodo que devuelve el identificador del sensor
  
private:
  int identificator_; // Atributo para el identificador del sensor
};

#endif


