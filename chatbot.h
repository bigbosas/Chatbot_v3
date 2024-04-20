#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <string>
#include <vector>
#include "chatter.h"

using namespace std;

class Chatbot {
	protected:
		const string BOT_REPLY_EN[5][2] = {{"That's interesting the way you put it, ", ". Do you want to continue our conversation?"},
			{"\"", ".\" I'm very confused. Feel like talking about something else?"},
			{"I'm glad to lend an ear, ", ". now let's talk about something else, do you want to?"},
			{"This explanation... ", "... Fine, I guess that suffices. Feel like conversing more? It's up to you."},
			{"Perfect! ", "! This explanation is great! I'm keen to conversing more, are you?"}};
		const string BOT_REPLY_ST[5][2] = {{"Okay. Tell me ", ", what's on your mind?"},
			{"So ", ", what's on your mind?"},
			{"My friend, ", ", are you OK? what's on your mind?"},
			{"Speak. ", ", speak."},
			{"Yes! ", "! I'm all ears!"}};
		vector<vector<string>> stateKeywords = {{"default", "default"},
			{"default", "default"},
			{"default", "default"},
			{"default", "default"},
			{"default", "default"}};
	private:
		vector<Chatter> chatters;
		const string PRONOUN[2][3] = {{"i'm ", "my ", "i "},
			{"you're ", "your ", "you "}};
		string yourName;
		string yourReply;
		string yourReplyTemp;
		int botState = 0;
	// Private methods
	private:
		string changePronouns(string yourReply);
		int changeBotState(int botState, string yourReply);
	// Constructors
	public:
		Chatbot();
	// Setters
	public:
		void appendChatter(vector<vector<string>>& botReply, int botReplyType);
		void setKeywords(vector<vector<string>>& newKeywords);
	// Getters
	public:
		// Dummy, it's pointless to extend this functionality
	public:
	// Public methods
		void Run();
};

#endif
