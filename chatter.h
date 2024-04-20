#ifndef CHATTER_H
#define CHATTER_H

#include <iostream>
#include <string>
#include <vector>
#include "chatbotexception.h"

#define MSG_WRONGTYPE "Wrong bot reply type"
#define MSG_WRONGSIZE "Wrong amount of elements for bot reply, consider using other bot reply type"

using namespace std;

class Chatter {
	private:
		vector<vector<string>> botReply;
		string yourReply;
		string yourReplyTemp;
		int botReplyType = 0;
		int botState = 0;
	// Constructors
	public:
		Chatter(vector<vector<string>>& botReply, int botReplyType);
	// Setters
	public:
		void setBotReply(vector<vector<string>>& botReply);
		void setBotReplyType(int botReplyType);

		void setBotState(int botState);
		void setYourReply(string yourReply);
		void setYourReplyTemp(string yourReplyTemp);
	// Getters
	public:
		// Dummy, it's pointless to extend this functionality
	// Public methods
	public:
		void Run();
};

#endif
