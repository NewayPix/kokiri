/**
 * MIT License
 *
 * Copyright (c) 2016 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

#include "macros.hpp"

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
        std::cout << SUCCESS_COLOR << "LOG: ";

        int expanded[] = { (std::cout << args << "", 0)... };
        (void)expanded;

        std::cout << RESET_COLOR << std::endl;
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

        std::cout << RESET_COLOR << std::endl;
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

        std::cerr << RESET_COLOR << std::endl;
    }
};

#endif // DEBUG_H
