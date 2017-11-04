/*
 * Game: Pong Game.
 * Author: Rafael Campos Nunes.
 * License: Apache v2.
 *
 * Fell free to contact me on
 * Email: rafaelnunes737@hotmail.com
 * Github: https://github.com/rafaelcn
 *
 * Also you can contact me on IRC(freenode.net server) my nickname is: ranu.
 */

#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

#if __unix__
#define WARNING_COLOR "\e[1;33m"
#define ERROR_COLOR "\e[0;31m"
#else
#define WARNING_COLOR ""
#define ERROR_COLOR ""
#endif

/**
 * @brief The Debug class is where debug functions are defined, using the power
 * of variadic templates it .
 */
class Debug {
public:
    /**
     * @brief log The default log, it prints args on the stdout.
     * @param args The arguments to be printed on the terminal.
     */
    template<typename... Ts>
    static void log(const Ts&... args)
    {
        std::cout << "LOG: ";

        int expanded[] = { (std::cout << args << "", 0)... };
        (void)expanded;

        std::cout << std::endl;
    }

    /**
     * @brief log_warn The warning log, it prints out args on the stdout
     * which should be taken with care.
     * @param args The arguments to be printed on the terminal.
     */
    template<typename... Ts>
    static void log_warn(const Ts&... args)
    {
        std::cout << WARNING_COLOR << "WARN: ";

        int expanded[] = { (std::cout << args, 0)... };
        (void)expanded;

        std::cout << std::endl;
    }

    /**
     * @brief log_err The error log, use this to print really bad things that
     * happened with something.
     * @param args The arguments to be printed on the terminal.
     */
    template<typename... Ts>
    static void log_err(const Ts&... args)
    {
        std::cerr << ERROR_COLOR << "ERROR: ";

        int expanded[] = { (std::cerr << args, 0)... };
        (void)expanded;

        std::cerr << std::endl;
    }
};
#endif // DEBUG_H
