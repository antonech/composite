//
// Created by anton on 9.2.2020.
//
#include "composition.h"
#include <iostream>
#include <fstream>
#include <sstream>

pattern::FileHandler::FileHandler(const std::string &filename) {
    std::ifstream ifs(filename);

    m_output.reserve(MAX_FILE_SIZE);
    m_output.assign((std::istreambuf_iterator<char>(ifs)),std::istreambuf_iterator<char>());
}

void pattern::FileHandler::show(std::ostream &out) {
    out << m_output << std::endl;
}

void pattern::DotFilesNotation::add(ICompBase *base) {
    children.emplace_back(base);
}

void pattern::DotFilesNotation::show(std::ostream &out) {
    std::stringstream str;

    for (auto &f: children) {
        f->show(str);
    }

    out << str.str();
}