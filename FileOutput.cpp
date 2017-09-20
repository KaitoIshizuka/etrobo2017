/**
 * @file file_output.cpp
 * @brief ファイル書き出し
 *
 * @author Suguru Kouchi
 */
#include <cstring>
#include "file_output.hpp"

namespace ie {

/**
 * 出力するファイル名を指定。すでに存在している場合をこいつに上書きされる。
 *
 * @param fileName 出力するファイル名
 */
FileOutput::FileOutput(const char* fileName):
FILE_NAME(fileName), outputFile_(fopen(FILE_NAME, "w")) {
    canOutput_ = outputFile_ == NULL ? false : true;
}

/**
 * 引数をファイル書き出し。
 *
 * @param var 書き出させる数値
 */
void FileOutput::fileWrite(const int var) {
    if (canOutput_) {
        if (fprintf(outputFile_, "%d\n", var) < 0) {
            close();
        }
    }
}

/**
 * 引数をファイル書き出し。
 *
 * @param var 書き出させる数値
 */
void FileOutput::fileWrite(const long var) {
    if (canOutput_) {
        if (fprintf(outputFile_, "%ld\n", var) < 0) {
            close();
        }
    }
}

/**
 * 引数をファイル書き出し。
 *
 * @param var 書き出させる数値
 */
void FileOutput::fileWrite(const double var) {
    if (canOutput_) {
        if (fprintf(outputFile_, "%f\n", var) < 0) {
            close();
        }
    }
}

/**
 * 出力フォーマットを指定してファイル書き出し。
 *
 * @param var 書き出させる数値
 * @param format フォーマット指定子
 */
void FileOutput::fileWrite(const double var, const char* format) {
    char buf[256]; // 念のため多めに
    strcpy(buf, format);
    strcat(buf, "\n");

    if (canOutput_) {
        if (fprintf(outputFile_, buf, var) < 0) {
            close();
        }
    }
}

/**
 * ファイルディスクリプタが開いてれば閉じる
 */
void FileOutput::close() {
    canOutput_ = false;
    if (outputFile_ != NULL) {
        fclose(outputFile_);
    }
}

/**
 * close()を呼び出し。
 */
FileOutput::~FileOutput() {
    close();
}

}

