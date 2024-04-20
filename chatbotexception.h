#ifndef CHATBOTEXCEPTION_H
#define CHATBOTEXCEPTION_H

#include <string>

using namespace std;

class ChatbotException: public exception {
	private:
		string message;
	public:
		ChatbotException(const char* msg) : message(msg) {}
		const char* what() const throw()
		{
			return message.c_str();
		}
};

#endif
