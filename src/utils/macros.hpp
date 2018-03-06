#ifndef MACROS_H
#define MACROS_H

#if __unix__
#define WARNING_COLOR "\e[1;33m"
#define ERROR_COLOR "\e[0;31m"
#define SUCCESS_COLOR ""
#else
#define WARNING_COLOR ""
#define ERROR_COLOR ""
#endif

#endif // MACROS_H
