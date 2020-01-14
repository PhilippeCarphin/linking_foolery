#include "interface.h"
#include "backend/backend.h"
#include <iostream>

extern "C" {
    int power_of_two(int param) {

        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return backend::power_of_two(param);
    }
}