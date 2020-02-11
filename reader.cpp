//
// Created by anton on 9.2.2020.
//
#include "reader.h"
#include <iostream>
#include <sstream>
#include <vector>

namespace pattern {

    /***********************************************
     * Helper struct to store and manipulate dot notation
     * ********************************************/
    struct DottedNumber {
        // store dotted numbers
        uint root = 0;
        std::vector<uint> dotted_numbers;

        void set(const size_t &pos) {

            size_t seq = dotted_numbers.size();
            if (pos == 0) {
                dotted_numbers.clear();
                ++root;
            } else if (seq < pos) {
                if (!root)
                    root = 1;

                dotted_numbers.insert(dotted_numbers.end(), pos - seq , 1);

            } else {
                if (!root)
                    root = 1;

                while (dotted_numbers.size() > pos ) {
                    dotted_numbers.pop_back();
                }

                ++dotted_numbers[pos - 1];
            }
        }
    };

    std::ostream& operator<< (std::ostream& stream, DottedNumber& dot) {
        stream << dot.root << ".";

        for (auto &i : dot.dotted_numbers) {
            stream << i << '.';
        }
    }

    std::ostream& operator<< (std::ostream& stream, ICompBase& base) {
        base.show(stream);
    }

   FileHandler::FileHandler(const std::string &filename) {
        std::ifstream ifs(filename);

        m_output.reserve(MAX_FILE_SIZE);
        m_output.assign((std::istreambuf_iterator<char>(ifs)),std::istreambuf_iterator<char>());
    }

    /***********************************************
     * Print file content to the stream
     **********************************************/
    void FileHandler::show(std::ostream &out) {
        out << m_output;
    }


    /**********************************************
     * Composite, add leaf
     *********************************************/
    void DottedFileHandler::add(ICompBase *base) {
        children.emplace_back(base);
    }

    /***********************************************
    * Composite, print file content to the stream
    **********************************************/
    void DottedFileHandler::show(std::ostream &out) {
        std::stringstream ss;

        for (auto &f: children) {
            f->show(ss);
        }

        DottedNumber dotted;
        std::string line;

        while ( std::getline(ss, line) ) {

            size_t pos = line.find_first_not_of(" \t");
            if (pos == std::string::npos) {
                pos = line.length();
            }

            dotted.set(pos);

            out << std::string(pos, ' ') << dotted << " " << line.substr(pos) << std::endl;
        }
    }

}



