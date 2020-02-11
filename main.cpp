#include <iostream>
#include "app.h"


int main(int argc, char* argv[]) {

    // Expecting the FILENAME or -h as a second argument
    if (argc != 2 ) {
        App::show_usage(argv[0]);
        return 1;
    }

    try {
        App app(argc, argv);
        app.run();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;

        return 1;
    }

    return 0;
}
