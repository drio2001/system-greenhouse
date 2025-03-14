#include "include/DBUser.h"
#include <iostream>
#include <fstream>
#include <sstream>

DBUser::DBUser() {}

void 
DBUser::addUser(User* user) 
{
    users.insert(user);
}

void 
DBUser::addAdmin(Admin* admin) 
{
    users.insert(admin);
}

void 
DBUser::removeUser(User* user) 
{
    users.erase(user);
}

void 
DBUser::editUser(User* user, std::string newNif) 
{
    user->setNif(newNif);
}

User* 
DBUser::findUser(std::string id) 
{
    for (auto& user : users) {  // Recorre todos los elementos del conjunto users (base de datos) con los usuarios
        if (user->getId() == id) {  // Comprueba si el usuario de la iteracion tiene el mismo identificador que el proporcionado
            return user;    // Si tiene el mismo identificador, devuelve el puntero al usuario, sino, continua buscando
        }
    }
    return nullptr; // Si no se encuentra ningun usuario con el mismo identificador, se evuelve un puntero a nullptr
}

void 
DBUser::displayUsers() 
{
    for (auto& user : users) {
        std::cout << "ID: " << user->getId() << ", NIF: " << user->getNif() << std::endl;
    }
}

// Permite guardar los usuarios en el fichero users.dat
void 
DBUser::saveUsers() const {
    std::ofstream file("users.dat");
    if (file.is_open()) {
        for (auto& user : users) {
            file << user->getId() << "," << user->getNif();
            if (dynamic_cast<Admin*>(user) != nullptr) {
            	file << ",A";
            } else {
            	file << ",U";
            }
            file << std::endl;
        }
    	file.close();
    	std::cout << "Usuarios guardados en el fichero" << std::endl;
    } else {
    	throw std::runtime_error("No se pudo abrir el fichero");
    }
}  

// Recorre el archivo users.dat y añade los usuarios a la lista
void 
DBUser::loadUsers() {
    std::ifstream file("users.dat");
    if (file.is_open()) {
        users.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string id, nif, type;
            if (std::getline(iss, id, ',') &&
                std::getline(iss, nif, ',') &&
                std::getline(iss, type)) {
                try {
                    if (type == "U") {
                        User* user = new User(id, nif);
                        addUser(user);
                    } else if (type == "A") {
                        Admin* admin = new Admin(id, nif);
                        addAdmin(admin);
                    }
                } catch (const std::bad_alloc& e) {
                    // Manejo de falta de memoria
                    std::cout << "Error: No se pudo asignar memoria para crear un usuario" << std::endl;
                }
            }
        }
        file.close();
        std::cout << "Usuarios cargados desde el fichero" << std::endl;
    } else {
        throw std::runtime_error("No se pudo abrir el fichero");
    }
}

// auto simplemente detecta automaticamente el tipo de datos de un elemento dado