#include "application/default_application/default_application.h"
#include <iostream>
#include <memory>

int main(int argc, char *argv[]){
    using namespace application::default_application;

    try {
        std::unique_ptr<application::IRunnable> app(new DefaultApplication());
        return app->run(argc, argv);
    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
