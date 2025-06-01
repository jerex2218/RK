#include "ComputerFactories.h"
#include "ConcreteComputers.h"

Computer* ComputerFactory::NewComputer(const std::string& description) {
    if (description == "laptop") return new Laptop;
    if (description == "desktop") return new Desktop;
    return nullptr;
}

Computer* ComputerMultiFactory::NewMultiLaptop() {
    return new Laptop();
}

Computer* ComputerMultiFactory::NewMultiDesktop() {
    return new Desktop();
}

Computer* ComputerStaticFactory::NewStaticLaptop() {
    return new Laptop();
}

Computer* ComputerStaticFactory::NewStaticDesktop() {
    return new Desktop();
}
