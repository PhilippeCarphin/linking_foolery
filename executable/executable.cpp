//
// Created by Philippe Carphin on 2020-01-13.
//

#include "executable.h"
#include "../interface/interface.h"
#include <iostream>
#include "dlfcn.h"

typedef int (*power_of_two_t)(int);

power_of_two_t load_symbol_from_library();
int main(void){
    int exponent = 16;

    // We can call the function itself and even though interface doesn't link
    // with backend, it can call backend functions at runtime because
    // the symbols are loaded by virtue of the executable linking with backend.
    int pot_direct = power_of_two(exponent);
    std::cout << "2^"<<exponent<<" = " << pot_direct << std::endl;


    // We can do the same with the function loaded using dlopen.
    auto power_of_two_f = load_symbol_from_library();

    int pot = power_of_two_f(exponent);
    std::cout << "2^"<<exponent<<" = " << pot << std::endl;

    return 0;
}


power_of_two_t load_symbol_from_library()
{
    void *plugin = dlopen(LIB_INTERFACE_PATH, RTLD_NOW);

    if(plugin){
        std::cout << "C++      : " << __PRETTY_FUNCTION__ << " : Plugin loaded successfully" << std::endl;
    } else {
        std::cout << "C++      : " << __PRETTY_FUNCTION__ << " : ERROR loading plugin : " << dlerror() << std::endl;
    }

    void *power_of_two_symbol_ptr = dlsym(plugin, "power_of_two");

    if(power_of_two_symbol_ptr){
        std::cout << "C++      : " << __PRETTY_FUNCTION__ << " : Symbol loaded successfully" << std::endl;
    } else {
        std::cout << "C++      : " << __PRETTY_FUNCTION__ << " : ERROR loading symbol: " << dlerror() << std::endl;
    }

    return reinterpret_cast<power_of_two_t>(power_of_two_symbol_ptr);

}
