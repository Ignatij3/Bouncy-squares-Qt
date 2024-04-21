#ifndef BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP
#define BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP

#include <iostream>

static short LOGGING_LEVEL;

#ifndef NDEBUG

#define LOG_INFO(msg) \
    if (LOGGING_LEVEL == 0) { std::cout << "LOG INFO: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }
#define LOG_WARNING(msg) \
    if (LOGGING_LEVEL <= 1) { std::cout << "LOG WARN: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }
#define LOG_CRITICAL(msg) \
    if (LOGGING_LEVEL <= 2) { std::cout << "LOG CRIT: " << msg << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl; }

#else

#define LOG_INFO(msg)
#define LOG_WARNING(msg)
#define LOG_CRITICAL(msg)

#endif // NDEBUG

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

#define SET_LOGGING_LEVEL(level) \
    switch (str2int(level))      \
    {                            \
    case str2int("info"):        \
        LOGGING_LEVEL = 0;       \
        break;                   \
                                 \
    case str2int("warning"):     \
        LOGGING_LEVEL = 1;       \
        break;                   \
                                 \
    case str2int("critical"):    \
        LOGGING_LEVEL = 2;       \
        break;                   \
    }

#endif // BOUNCY_SQUARE_LIBS_LOGGING_LOGGING_HPP