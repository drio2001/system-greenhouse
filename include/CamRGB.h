#ifndef CAMRGB_H 
#define	CAMRGB_H 

#include "Sensor.h"


class CamRGB : public Sensor{
  public:
    // Implementaciones de los metodo virtuales puros concretos que heredan de la clase Sensor (override):
    void getDate() override;
    void printDate() const override;
    std::string getName() const override;

  private:
    int date_[3][3]; // Atributo para los datos del sensor (matriz 3x3)
};

#endif
