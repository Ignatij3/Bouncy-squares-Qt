#ifndef BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP
#define BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP

#include <iostream>

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

static short LOGGING_LEVEL;

#define SET_LOGGING_LEVEL(level) \
    switch (str2int(level))      \
    {                            \
    case str2int("info"):        \
        LOGGING_LEVEL = 0;       \
        break;                   \
    case str2int("warning"):     \
        LOGGING_LEVEL = 1;       \
        break;                   \
    case str2int("critical"):    \
        LOGGING_LEVEL = 2;       \
        break;                   \
    case str2int("none"):        \
        LOGGING_LEVEL = 3;       \
        break;                   \
    }

#define LOG_INFO(msg) \
    if (LOGGING_LEVEL == 0) { std::cout << "LOG INFO: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }

#define LOG_WARNING(msg) \
    if (LOGGING_LEVEL <= 1) { std::cout << "LOG WARN: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }

#define LOG_CRITICAL(msg) \
    if (LOGGING_LEVEL <= 2) { std::cout << "LOG CRIT: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }

#endif // BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP