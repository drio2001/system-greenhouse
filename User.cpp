#include "include/User.h"

// Implementación de la clase User
User::User(const std::string& id, const std::string& nif)
    : id(id), nif(nif)  // Se inicializan los atributos id y nif con los parametros proporcionados
{}

User::~User()
{}

std::string User::getId() const {
    return id;  // Devuelve el atributo identificador del usuario
}

std::string User::getNif() const {
    return nif; // Devuelve el atributo identificador del usuario
}

void User::setNif(const std::string& newNif) {
    nif = newNif;   // Cambia el atributo nif con el nuevo Nif proporcionado al usuario
}

