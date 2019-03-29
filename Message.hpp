#ifndef SMTP_MESSAGE_HPP
#define SMTP_MESSAGE_HPP

#include <string>
#include <vector>
#include <sstream>

namespace SMTP
{

    class Message
    {
    public:
        struct Endpoint
        {
            std::string Address;
            std::string PrettyName;
        };

    private:
        Endpoint _originator;
        std::vector<Endpoint> _recipients;
        std::string _subject;
        std::stringstream _message;

    protected:
        std::string _GetMessage();

    public:
        inline Message& Originator(const std::string& address, const std::string& prettyName = std::string())
        {
            _originator.Address = address;
            _originator.PrettyName = prettyName;

            return *this;
        }

        inline Message& AddRecipient(const std::string& address, const std::string& prettyName = std::string())
        {
            _recipients.emplace_back(Endpoint{ address, prettyName });

            return *this;
        }

        inline Message& Subject(const std::string& subject)
        {
            _subject = subject;

            return *this;
        }
    };

}

#endif  // SMTP_MESSAGE_HPP
