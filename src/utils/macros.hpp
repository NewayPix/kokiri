#ifndef MACROS_H
#define MACROS_H

#if __unix__
#define WARNING_COLOR "\x1b[33;1m"
#define ERROR_COLOR   "\x1b[31;1m"
#define SUCCESS_COLOR "\x1b[34;1m"
#define RESET_COLOR   "\x1b[0m"
#else
#define WARNING_COLOR ""
#define ERROR_COLOR ""
#define SUCCESS_COLOR ""
#define RESET_COLOR ""
#endif // __unix__

#endif // MACROS_H
