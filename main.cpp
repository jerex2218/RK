#include "ComputerFactories.h"
#include <iostream>

int main() {
    Computer *computer1 = ComputerFactory::NewComputer("laptop");
    computer1->price();
    computer1->description();
    
    Computer *computer2 = ComputerFactory::NewComputer("desktop");
    computer2->price();
    computer2->description();
    std::cout << "----------" << std::endl;

    ComputerMultiFactory *factory = new ComputerMultiFactory();
    Computer *multiLaptop = factory->NewMultiLaptop();
    multiLaptop->price();
    multiLaptop->description();
    std::cout << "----------" << std::endl;

    Computer *staticLaptop = ComputerStaticFactory::NewStaticLaptop();
    staticLaptop->price();
    staticLaptop->description();
    std::cout << "----------" << std::endl;

    delete computer1;
    delete computer2;
    delete multiLaptop;
    delete staticLaptop;
    delete factory;

    return 0;
}
