//
// Created by Philippe Carphin on 2020-01-13.
//
#include <iostream>

#include "backend.h"
namespace backend {

    int power_of_two(int param) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        int retval = (1 << param);
        return retval;
    }
}
