#ifndef LIGHT_H 
#define	LIGHT_H

#include "Sensor.h"

class Light : public Sensor{
  public:
    // Implementaciones de los metodo virtuales puros concretos que heredan de la clase Sensor (override):
    void getDate() override;
    void printDate() const override;
    std::string getName() const override;

  private:
    int date_; // Atributo para los datos del sensor
};

#endif
