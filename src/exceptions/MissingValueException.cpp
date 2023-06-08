#include <MissingValueException.h>

MissingValueException::MissingValueException(char const *createMessage)
    : std::logic_error(createMessage) {}

char const *MissingValueException::what()
{
    return "Cannot acces value of a missing parameter.";
}
