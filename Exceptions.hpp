#ifndef SMTP_EXCEPTIONS_HPP
#define SMTP_EXCEPTIONS_HPP

#include <stdexcept>

namespace SMTP
{

    class CouldNotConnectException : public std::runtime_error
    {
    public:
        CouldNotConnectException();
    };

}

#endif  // SMTP_EXCEPTIONS_HPP
