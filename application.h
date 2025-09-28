// объявление класса Application (меню)
#ifndef APPLICATION_H
#define APPLICATION_H

#include "array.h"

class Application {
private:
    Array arr;

public:
    void run();
    void showMenu() const;
};

#endif
