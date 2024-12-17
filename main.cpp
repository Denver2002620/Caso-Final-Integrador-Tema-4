#include <iostream>
#include "Variant.h"

int main() {
    // Create some Variant instances
    Variant symbol(Variant::Symbol, "x");
    Variant number(Variant::Number, "42");
    Variant str(Variant::Cadena, "Hello, World!");

    // Create a list Variant
    Variant list(Variant::List);
    list.list.push_back(symbol);
    list.list.push_back(number);
    list.list.push_back(str);

    // Use to_string() to display the Variant contents
    std::cout << "Symbol: " << symbol.to_string() << std::endl;
    std::cout << "Number: " << number.to_string() << std::endl;
    std::cout << "String: " << str.to_string() << std::endl;
    std::cout << "List: " << list.to_string() << std::endl;

    // Use to_json_string() to display JSON representation
    std::cout << "Symbol as JSON: " << symbol.to_json_string() << std::endl;
    std::cout << "Number as JSON: " << number.to_json_string() << std::endl;
    std::cout << "String as JSON: " << str.to_json_string() << std::endl;
    std::cout << "List as JSON: " << list.to_json_string() << std::endl;

    // Create a JSON string and convert it back to a Variant
    std::string jsonString = "{\"type\":\"symbol\", \"value\":\"y\"}";
    try {
        Variant jsonVariant = Variant::from_json_string(jsonString);
        std::cout << "Parsed Variant from JSON: " << jsonVariant.to_string() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
    }

    return 0;
}
