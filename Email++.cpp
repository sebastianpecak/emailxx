// Email++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Connection.hpp"
#include "Message.hpp"


//#include <curl/easy.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace SMTP
{

    class Message
    {
        string _originator;
        string _recipient;
        string _subject;
        stringstream _message;

    protected:
        string _GetMessage();

    public:
        Message & Originator(const string& name, const string& address);
        Message & Originator(const string& originator);
        Message& Recipient(const string& recipient);
        Message& Subject(const string& subject);

        template <typename Head, typename... Tail>
        Message& AppendLine(Head&& head, Tail&&... tail)
        {
            AppendLine(head);
            AppendLine(tail...);
            _message << "\r\n";

            return *this;
        }

        template <typename Head>
        Message& AppendLine(Head&& value)
        {
            _message << value;
            return *this;
        }
    };

    class Connection
    {
    public:
        bool SendMessage(const Message& msg);
    };

}

int main()
{
    try
    {
        SMTP::Connection connection;
        SMTP::Message msg;

        connection
            .Originator("sebastianpecak@gmail.com")
            .AddRecipient("sebastianpecak@gmail.com")
            .AddRecipient("chemii1@interia.pl")
            .SendMessage(SMTP::Message().Subject("Hello World"));

        msg
            .Originator("sebastianpecak@gmail.com")
            .Recipient("sebastianpecak@gmail.com")
            .Subject("Wiadomość w butelce")
            .AppendLine("Dzień dobry Panie ", "Hekfwef", 11);

        SMTP::Message msg2;

        msg2
            .Originator("Sebastian Pecak", "sebastianpecak@gmail.com")
            .Recipient("sebastianpecak@gmail.com")
            .Subject("Test message");

        connection.SendMessage(msg);
    }
    catch (const exception& e)
    {
        cerr << "Exception caught: '" << e.what() << '\'';
    }

    return 0;
}

