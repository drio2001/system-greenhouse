#ifndef DASHBOARD_H
#define	DASHBOARD_H

#include "vector"
#include "Sensor.h"
#include "DBUser.h"


class Dashboard{
  public:
    void initializeSensors(); // Metodo para inicializar los sensores
    void addSensor(Sensor* sensor); // Metodo para agregar un sensor a la base de datos
    void userSession();
    void displayShowDBOption(DBUser& db);
    void displayAddDBOption(DBUser& db);
    void displayDeleteDBOption(DBUser& db);
    void displayEditDBOption(DBUser& db);
    void displayExitDBOption(DBUser& db);
    void displayMenuDB();
    void displayDBOptions(DBUser& db);
    
    void displayOptions(DBUser& db, User* currentUser);
    void displayEditUsers(DBUser& db);
    void displaySensors();

  private:
    std::vector<Sensor*> sensors_;  // Atributo de vector de objetos de tipo Sensor (base de datos) con los sensores
}; 

#endif


