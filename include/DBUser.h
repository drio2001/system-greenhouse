#ifndef DBUSER_H
#define DBUSER_H

#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Admin.h"

class DBUser {  // Declara la clase DBUser
  public:
      DBUser();   // Constructor de la clase DBUser. No recibe nada
      void addUser(User* user);   // Metodo para agregar un usuario a la base de datos
      void addAdmin(Admin* admin); // Metodo para agregar un administrador a la base de datos
      void removeUser(User* user); // Metodo para eliminar un usuario a la base de datos
      void editUser(User* user, std::string newNif);  // Metodo para editar el NIF de un usuario de la bse de datos
      User* findUser(std::string id); // Metodo para buscar un usuario de la base de datos segun su identificador
      void displayUsers();    // Metodo para mostrar todos los usuarios de la base de datos
      void saveUsers() const;
      void loadUsers();

  private:
      std::set<User*> users;  // Atributo de conjunto de punteros de objetos de tipo User (base de datos) con los usuarios
};

#endif



