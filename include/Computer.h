#ifndef COMPUTER_H
#define COMPUTER_H

class Computer {
public:
    virtual void price() = 0;
    virtual void description() = 0;
    virtual ~Computer();
};

#endif
