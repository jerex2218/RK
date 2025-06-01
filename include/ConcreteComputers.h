#ifndef CONCRETE_COMPUTERS_H
#define CONCRETE_COMPUTERS_H

#include "Computer.h"
#include <iostream>

class Laptop : public Computer {
public:
    void price() override;
    void description() override;
    ~Laptop() override;
};

class Desktop : public Computer {
public:
    void price() override;
    void description() override;
    ~Desktop() override;
};

#endif
