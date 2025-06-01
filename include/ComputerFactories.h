#ifndef COMPUTER_FACTORIES_H
#define COMPUTER_FACTORIES_H

#include "Computer.h"
#include <string>

class ComputerFactory {
public:
    static Computer* NewComputer(const std::string& description);
};

class ComputerMultiFactory {
public:
    Computer* NewMultiLaptop();
    Computer* NewMultiDesktop();
};

class ComputerStaticFactory {
public:
    static Computer* NewStaticLaptop();
    static Computer* NewStaticDesktop();
};

#endif
