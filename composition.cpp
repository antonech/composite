//
// Created by anton on 9.2.2020.
//
#include "composition.h"
#include <iostream>
#include <fstream>

pattern::FileHandler::FileHandler(const std::string &filename) {
    std::ifstream ifs(filename);

    m_output.reserve(MAX_FILE_SIZE);
    m_output.assign((std::istreambuf_iterator<char>(ifs)),std::istreambuf_iterator<char>());

}

void pattern::FileHandler::show() {
    std::cout << m_output << std::endl;
}

