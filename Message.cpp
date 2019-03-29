#include "Message.hpp"

namespace SMTP
{

    using namespace std;

    string Message::_GetMessage()
    {
        stringstream builder;

        builder
            << "Date: " << "Date: Tue, 15 Jan 2008 16:02:43 -0500"
            << "From: " << '"' << _originator.PrettyName << "\" <" << _originator.Address << ">\r\n"
            << "To: " <<
    }

}
