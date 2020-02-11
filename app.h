//
// Created by anton on 9.2.2020.
//
#ifndef PATTERNS_APP_H
#define PATTERNS_APP_H
#include <string>

class App {
public:
    App()= default;
    App(int argc, char* argv[]) { config(argc, argv); }

    void config(int argc, char* argv[]);

    void run();

    static void show_usage(const std::string &name);
private:
    void is_valid_file();

    std::string m_filename;
};
#endif //PATTERNS_APP_H
