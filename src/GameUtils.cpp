#include "GameUtils.h"
#include <iostream>
#include <stdexcept>
#include <string>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <cstdio>
#include <cstdlib>
#endif

int GameUtils :: getTerminalWidth() {
    int columns = 80; // Default fallback if width detection fails

    // windows logic
    #if defined(_WIN32) || defined(_WIN64)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        }
    // unix logic
    #else
        std::string command = "tput cols";
        char buffer[128];
        std::string result = "";
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) throw std::runtime_error("popen() failed!");
        try {
            while (fgets(buffer, sizeof buffer, pipe) != NULL) {
                result += buffer;
            }
        } catch (...) {
            pclose(pipe);
            throw;
        }
        pclose(pipe);
        columns = std::stoi(result);
    #endif

    return columns;
}