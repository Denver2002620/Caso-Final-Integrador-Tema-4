#ifndef VARIANT_H
#define VARIANT_H

#include <vector>
#include <string>
#include <map>
#include "json11.hpp"  // Asegúrate de que esta biblioteca esté disponible.

// Enumera los tipos posibles en Variant.
enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

// Adelanto de la declaración estructural para Entorno.
struct Entorno;

class Variant {
public:
    // Tipos para las funcionalidades y almacenamiento.
    typedef Variant (*proc_type) (const std::vector<Variant>&);
    typedef std::vector<Variant>::const_iterator iter;
    typedef std::map<std::string, Variant> map;

    // Miembros de la clase.
    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    // Constructores.
    Variant(variant_type type = Symbol);
    Variant(variant_type type, const std::string& val);
    Variant(proc_type proc);

    // Declaración de funciones miembro.
    std::string to_string();
    std::string to_json_string();
    static Variant from_json_string(const std::string& json);
    static Variant parse_json(const json11::Json& job);

private:
    // Puedes añadir funciones auxiliares aquí.
};

#endif // VARIANT_H
