//
// Created by anton on 9.2.2020.
//
#include "composition.h"
#include <iostream>
#include <sstream>

namespace pattern {
    std::ostream& operator<< (std::ostream& stream, const ICompBase& base) {
        base.show(stream);
    }

   FileHandler::FileHandler(const std::string &filename) {
        std::ifstream ifs(filename);

        m_output.reserve(MAX_FILE_SIZE);
        m_output.assign((std::istreambuf_iterator<char>(ifs)),std::istreambuf_iterator<char>());
    }

    void FileHandler::show(std::ostream &out) const {
        out << m_output << std::endl;
    }

    void DotFilesNotation::add(ICompBase *base) {
        children.emplace_back(base);
    }

    void DotFilesNotation::show(std::ostream &out) const {
        std::stringstream str;

        for (auto &f: children) {
            str << *f ;
        }

        while( std::getline(inStream, line) ) {
            numbering_list(out, line);
        }
    }

    void DotFilesNotation::numbering_list(std::ostream &out, const std::string &line) {
        size_t pos = line.find_first_not_of(" \t");
    }
}



