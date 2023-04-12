#pragma once

#include <iostream>

#include "colors.hpp"

namespace Kokiri {
    namespace Core {
        /**
         * @brief The Debug class is where debug functions are defined, using the power
         * of variadic templates it .
         */
        class Log {
        public:
            /**
             * @brief The default log, it prints args on the stdout.
             * @param args The arguments to be printed on the terminal.
             */
            template<typename... Args>
            static void info(const Args&... args)
            {
                std::cout << SUCCESS_COLOR << "INFO: ";

                int expanded[] = { (std::cout << args << "", 0)... };
                (void)expanded;

                std::cout << RESET_COLOR << std::endl;
            }

            /**
             * @brief The warning log, it prints out args on the stdout
             * which should be taken with care.
             * @param args The arguments to be printed on the terminal.
             */
            template<typename... Args>
            static void warn(const Args&... args)
            {
                std::cout << WARNING_COLOR << "WARN: ";

                int expanded[] = { (std::cout << args, 0)... };
                (void)expanded;

                std::cout << RESET_COLOR << std::endl;
            }

            /**
             * @brief The error log, use this to print really bad things that
             * happened with something.
             * @param args The arguments to be printed on the terminal.
             */
            template<typename... Args>
            static void error(const Args&... args)
            {
                std::cerr << ERROR_COLOR << "ERROR: ";

                int expanded[] = { (std::cerr << args, 0)... };
                (void)expanded;

                std::cerr << RESET_COLOR << std::endl;
            }
        };
    }
}