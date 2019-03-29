#ifndef SMTP_CONNECTION_HPP
#define SMTP_CONNECTION_HPP

#include <string>
#include <cstdint>
#include "Exceptions.hpp"

namespace SMTP
{

    // Forward declaration.
    class Message;

    class Connection
    {
    public:
        Connection() noexcept;
        Connection(const std::string& address, uint16_t port);
    };

}

#endif  // SMTP_CONNECTION_HPP
