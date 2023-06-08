#ifndef MISSING_VALUE_EXCEPTION_H
#define MISSING_VALUE_EXCEPTION_H

#include <stdexcept>

class MissingValueException : public std::logic_error
{
public:
    MissingValueException(char const *createMessage);
    char const *what();

private:
    char const *message;
};

#endif