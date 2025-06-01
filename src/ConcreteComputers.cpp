#include "ConcreteComputers.h"

void Laptop::price() {
    std::cout << "4000$" << std::endl;
}

void Laptop::description() {
    std::cout << "Laptops are mobile, portable and multimedia" << std::endl;
}

Laptop::~Laptop() = default;

void Desktop::price() {
    std::cout << "5000$" << std::endl;
}

void Desktop::description() {
    std::cout << "Desktops are fixed" << std::endl;
}

Desktop::~Desktop() = default;
