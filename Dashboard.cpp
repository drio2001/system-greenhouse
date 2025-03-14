#include "include/Sensor.h"
#include "include/AirQ.h"
#include "include/CamRGB.h"
#include "include/CamTherm.h"
#include "include/Temp.h"
#include "include/Moisture.h"
#include "include/Light.h"
#include "include/DBUser.h" 
#include "include/Dashboard.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

void 
Dashboard::userSession() {
    // Pide al usuario que se autentique
    DBUser db;
    db.loadUsers();

    std::string id, nif;
    std::cout << "Introduzca su identificador: ";
    std::cin >> id;
    std::cout << "Introduzca su NIF: ";
    std::cin >> nif;

    User* currentUser = db.findUser(id);
    if (currentUser != nullptr && currentUser->getNif() == nif) {
        std::cout << "Bienvenido, usuario con identificador: " << currentUser->getId() << std::endl;
        displayOptions(db, currentUser);
    } else {
        std::cout << "ID o NIF incorrectos." << std::endl;
    }
}

void
Dashboard::displayOptions(DBUser& db, User* currentUser) {

    int option;
    
    while (true) {
        bool isAdmin = dynamic_cast<Admin*>(currentUser) != nullptr;
        std::cout << "Opciones del sistema:" << std::endl;
        if (isAdmin) {
            std::cout << "1. Mostrar opciones de edición de usuarios (Admin)" << std::endl;
        }
        std::cout << "2. Mostrar sensores" << std::endl;
        std::cout << "3. Salir" << std::endl; 

        try {
            std::cout << "Introduzca una opción:" << std::endl;
            std::cin >> option;
            if (std::cin.fail()) {
                throw std::invalid_argument("Debe ingresar un número.");
            }
            switch (option) {
                case 1: {
                    if (isAdmin) {
                        displayDBOptions(db);
                    } else {
                        std::cout << "Opción no válida para usuario normal." << std::endl;
                    }
                    break;
                }
                case 2: {
                    displaySensors();
                    break;
                }
                case 3: {
                    std::cout << "Saliendo del sistema" << std::endl;
                    return;
                }
                default: {
                    std::cout << "Opción no válida." << std::endl;
                    break;
                }
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error de argumento: " << e.what() << std::endl;
            // Restablece el estado de error
            std::cin.clear();
            std::cin.ignore();
        } catch (const std::ios_base::failure& e) {
            std::cout << "Error de lectura: " << e.what() << std::endl;
            // Restablece el estado de error
            std::cin.clear();          
            std::cin.ignore();
        } 
    }
}

void
Dashboard::displayShowDBOption(DBUser& db) {
    // Muestra todos los usuarios en la base de datos
    std::cout << "Usuarios en la base de datos:" << std::endl;
    db.displayUsers();
}

void
Dashboard::displayAddDBOption(DBUser& db) {
    //Crea un nuevo usuario y lo añade a la lista
    std::string newId, newNif;
    std::cout << "Introduzca el ID del nuevo usuario: ";
    std::cin >> newId;
    std::cout << "Introduzca el NIF del nuevo usuario: ";
    std::cin >> newNif;
    User* newUser = new User(newId, newNif);
    db.addUser(newUser);
    std::cout << "Usuario añadido correctamente." << std::endl;
}

void 
Dashboard::displayDeleteDBOption(DBUser& db) {
    //Pide un id y elimina al user correspondiente
    std::string IdToRemove;
    std::cout << "Introduzca el ID del usuario a eliminar: ";
    std::cin >> IdToRemove;
    User* UserToRemove = db.findUser(IdToRemove);
    if (UserToRemove != nullptr) {
        db.removeUser(UserToRemove);
        std::cout << "Usuario eliminado correctamente." << std::endl;
    } else {
        std::cout << "No se ha encontrado ningún usuario con tal identificador." << std::endl;
    }
}

void
Dashboard::displayEditDBOption(DBUser& db) {
    //Permite editar el NIF de un usuario
    std::string IdToEdit, newNif;
    std::cout << "Introduzca el ID del usuario a editar: ";
    std::cin >> IdToEdit;
    User* UserToEdit = db.findUser(IdToEdit);
    if (UserToEdit != nullptr) {
        std::cout << "Introduzca el nuevo NIF del usuario: ";
        std::cin >> newNif;
        db.editUser(UserToEdit, newNif);
        std::cout << "Usuario editado correctamente." << std::endl;
    } else {
        std::cout << "No se ha encontrado ningún usuario con tal identificador." << std::endl;
    }
}

void
Dashboard::displayExitDBOption(DBUser& db) {
    //Salir del programa
    std::cout << "Saliendo del sistema" << std::endl;
    db.saveUsers();
}

void
Dashboard::displayMenuDB() {

    std::cout << "Opciones de edición de usuarios:" << std::endl;
    std::cout << "1. Mostrar usuarios" << std::endl;
    std::cout << "2. Añadir usuario" << std::endl;
    std::cout << "3. Eliminar usuario" << std::endl;
    std::cout << "4. Editar usuario" << std::endl;
    std::cout << "5. Guardar cambios y salir" << std::endl;  
}

void 
Dashboard::displayDBOptions(DBUser& db) {

    int option;
    bool exit = false;
    
    while (!exit) {
        
	    displayMenuDB();     
        try {
            std::cout << "Seleccione una opción:" << std::endl;	
            std::cin >> option;
            if (std::cin.fail()) {
                throw std::invalid_argument("Debe ingresar un número.");
            }
            switch (option) {
                case 1: {
                    displayShowDBOption(db);
                    break;
                }    	
                case 2: {
                    displayAddDBOption(db);
                    break;
                }
                case 3: {
                    displayDeleteDBOption(db);
                    break;
                }
                case 4: {
                    displayEditDBOption(db);
                    break;
                    }        
                case 5: {
                    displayExitDBOption(db);
                    exit = true;
                    break;
                }
            }
        } catch (const std::invalid_argument& e){
            std::cout << "Error de argumento: " << e.what() << std::endl;
            //Restablecer el estado de error
            std::cin.clear();
            std::cin.ignore();
        } catch (const std::ios_base::failure& e) {
            std::cout << "Error de lectura: " << e.what() << std::endl;
            //Restablecer el estado de error
            std::cin.clear();          
            std::cin.ignore();
        }
    }
}
    
void 
Dashboard::addSensor(Sensor* sensor) 
{
  sensors_.push_back(sensor);
}

void 
Dashboard::displaySensors() {

    // Agrega los sensores a la lista de sensores del desplegable
    addSensor(new AirQ());
    addSensor(new CamRGB());
    addSensor(new CamTherm());
    addSensor(new Temp());
    addSensor(new Moisture());
    addSensor(new Light());

    std::cout << "Seleccione el sensor del cual quiere ver los datos (o escriba 'salir' para salir): " << sensors_.size() << std::endl;
    for (size_t i = 0; i < sensors_.size(); i++) {
        std::cout << i + 1 << ". " << sensors_[i]->getName() << std::endl;
    }
    // Lee la selección del usuario
    std::string option;
    std::cout << "Seleccione una opción:" << std::endl;
    std::cin >> option;

    while (option != "salir") {
        size_t index = std::stoul(option);
        if (index >= 1 && index <= sensors_.size()) {
            sensors_[index - 1]->getDate();
            sensors_[index - 1]->printDate();
        } else {
            std::cout << "Opción inválida" << std::endl;
        }
        std::cout << "Seleccione el sensor del que quiere informacion (o escriba 'salir' para salir):" << std::endl;
        for (size_t i = 0; i < sensors_.size(); ++i) {
            std::cout << i + 1 << ". " << sensors_[i]->getName() << std::endl;
        }
        std::cout << "Seleccione una opción:" << std::endl;
        std::cin >> option;
    }
}


