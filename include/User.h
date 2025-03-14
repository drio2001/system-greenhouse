#ifndef USER_H
#define USER_H

#include <string>

class User {    // Declara la clase User
public:
    User(const std::string& id, const std::string& nif);    // Constructor de la clase. Recibe dos constantes con el identificador y el Nif
    virtual ~User();    // Destructor virtual de la clase

    std::string getId() const;  // Metodo que deuvelve el identificador del usuario
    std::string getNif() const; // Metodo que devuelve el Nif del usuario
    // Contienen const porque no altera el estado interno del objeto, solo devuelve un objeto
    void setNif(const std::string& newNif); // Metodo para establecer un nuevo valor de Nif del usuario

private:
    std::string id; // Atributo para almacenar el identificador
    std::string nif;    // Atributo para almacenar el Nif
};


#endif // USER_H




