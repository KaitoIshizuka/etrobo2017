/**
 * @file file_output.hpp
 * @author Suguru Kouchi
 */
#ifndef FILE_OUTPUT_HPP
#define FILE_OUTPUT_HPP

#include <cstdio>

namespace ie {

class FileOutput {
public:
    FileOutput(const char* fileName);
    ~FileOutput();
    void close();
    void fileWrite(const int var);
    void fileWrite(const long var);
    void fileWrite(const double var);
    void fileWrite(const double var, const char* format);

private:
    const char* FILE_NAME;
    FILE* outputFile_;
    bool canOutput_ = false;
};

}

#endif


