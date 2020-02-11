//
// Created by anton on 9.2.2020.
//
#include "app.h"
#include "reader.h"
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

void App::show_usage(const std::string &name) {
    std::cerr << "Usage: " << name << " <option(s)> FILENAME\n"
              << "Options:\n"
              << "\t-h\t\tShow this help message\n"
              << "\tFILENAME\tSpecify the file to read"
              << std::endl;
}

void App::config(int argc, char *argv[]) {
    std::string arg;

    for (int i = 1; i < argc; ++i) {
        arg = argv[i];
        if (arg == "-h") {
            show_usage(argv[0]);
        } else {
            m_filename = arg;
        }
    }

    is_valid_file();
}

void App::is_valid_file() {
    auto path = fs::path(m_filename);

    std::ostringstream msg_stream;
    bool error = false;
    if (fs::is_directory(path)) {
        error = true;
        msg_stream << path.filename() << ": is a directory.";
    } else if (!fs::exists(path)) {
        error = true;
        msg_stream << path.filename() << ": file not exists.";
    } else if (fs::file_size(path) > pattern::MAX_FILE_SIZE) {
        error = true;
        msg_stream << path.filename() << ": file is too big, maximum size is " << pattern::MAX_FILE_SIZE / 1024 << " Kb.";
    } else if (fs::is_empty(path)) {
        error = true;
        msg_stream << path.filename() << ": file is empty.";
    }

    if (error) {
        throw std::runtime_error(msg_stream.str());
    }
}

void App::run() {

    if (m_filename.empty()) {
        throw std::logic_error("Invalid usage");
    }

    pattern::DottedFileHandler dot;

    dot.add(new pattern::FileHandler(m_filename));
    std::cout << dot;
}
