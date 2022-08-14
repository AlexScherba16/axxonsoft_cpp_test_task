#include <iostream>

int main(int argc, char *argv[]){
    try {
        (void) argc;
        (void) argv;


        return EXIT_SUCCESS;
    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
