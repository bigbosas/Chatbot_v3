#include "chatbot.h"

// Swaps pronouns. The change occurs only ONCE, for now. Experimental
string Chatbot::changePronouns(string yourReply) {
	int yourReplyTempIdx = 0;
	int botIdx = 0;
	string yourReplyTemp = yourReply;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++) {
			yourReplyTempIdx = yourReplyTemp.find(PRONOUN[i][j]);
			if(yourReplyTempIdx != -1) {
				if(i == 0)
					botIdx = 1;
				else
					botIdx = 0;
				yourReplyTemp.erase(yourReplyTempIdx, PRONOUN[i][j].size());
				yourReplyTemp.insert(yourReplyTempIdx, PRONOUN[botIdx][j]);
				goto break1;
			}
		}
		break1:
	return yourReplyTemp;
}

// Find keywords and change chatbot's behaviour
int Chatbot::changeBotState(int botState, string yourReply) {
	int yourReplyIdx = -1; int botStateNew = -1;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < stateKeywords[i].size(); j++) {
			yourReplyIdx = yourReply.find(stateKeywords[i][j]);
			if(yourReplyIdx != -1) {
				botStateNew = i;
				goto break2;
			}
}
	break2:

	return botStateNew != -1 ? botStateNew : botState;
}

void Chatbot::appendChatter(vector<vector<string>>& botReply, int botReplyType) {
	chatters.insert(chatters.end(), Chatter(botReply, botReplyType));
}
void Chatbot::setKeywords(vector<vector<string>>& newKeywords) {
	this->stateKeywords = newKeywords;
}

void Chatbot::Run() {
	cout << "BOT: Hello, what's your name?\nYOU: ";
	getline(cin, yourName);
	cout << "BOT: Tell me " << yourName << ", what's on your mind?\nYOU: ";
	while(1) {
		getline(cin, yourReply);
		yourReplyTemp = changePronouns(yourReply);

		for (int i = 0; i < chatters.size(); i++) {
			chatters[i].setBotState(botState);
			chatters[i].setYourReply(yourReply);
			chatters[i].setYourReplyTemp(yourReplyTemp);
			chatters[i].Run();

			getline(cin, yourReply);
			botState = changeBotState(botState, yourReply);
		}

		botState = changeBotState(botState, yourReply);
		cout << "BOT: " << BOT_REPLY_EN[botState][0] << yourName << BOT_REPLY_EN[botState][1] << "\nYOU: ";

		getline(cin, yourReply);
		if(yourReply.find("no") != -1)
			break;
		botState = changeBotState(botState, yourReply);
		cout << "BOT: " << BOT_REPLY_ST[botState][0] << yourName << BOT_REPLY_ST[botState][1] << "\nYOU: ";
	}
}

Chatbot::Chatbot() {
}

