#ifndef TEMP_H 
#define	TEMP_H

#include "Sensor.h"

class Temp : public Sensor{
  public:
    // Implementaciones de los metodo virtuales puros concretos que heredan de la clase Sensor (override):
    void getDate() override;
    void printDate() const override;
    std::string getName() const override;
    
  private:
    int date_; // Atributo para los datos del sensor
};

#endif
