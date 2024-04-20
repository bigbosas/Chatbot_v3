#include "chatter.h"

void Chatter::setBotReply(vector<vector<string>>& botReply) {
	this->botReply = botReply;
}
void Chatter::setBotReplyType(int botReplyType) {
	if(botReplyType >= 1 && botReplyType <= 4 )
		this->botReplyType = botReplyType;
	else
		throw ChatbotException(MSG_WRONGTYPE);
}
void Chatter::setBotState(int botState) {
	this->botState = botState;
};
void Chatter::setYourReply(string yourReply) {
	this->yourReply = yourReply;
}
void Chatter::setYourReplyTemp(string yourReplyTemp) {
	this->yourReplyTemp = yourReplyTemp;
}

void Chatter::Run() {
	if(botReply[botState].size() != 0 && ((botReplyType >= 1 && botReply[botState].size() >= 2) || botReplyType == 1))
		switch (botReplyType) {
			case 1:
				cout << "BOT: " << botReply[botState][0] << "\nYOU: ";
				break;
			case 2:
				cout << "BOT: " << botReply[botState][0] << botReply[botState][1] << "\nYOU: ";
				break;
			case 3:
				cout << "BOT: " << botReply[botState][0] << yourReply << botReply[botState][1] << "\nYOU: ";
				break;
			case 4:
				cout << "BOT: " << botReply[botState][0] << yourReplyTemp << botReply[botState][1] << "\nYOU: ";
				break;
			default:
				// Dummy, this is already handled
				break;
		}
	else
		throw ChatbotException(MSG_WRONGSIZE);
}

Chatter::Chatter(vector<vector<string>>& botReply, int botReplyType) {
	setBotReply(botReply);
	setBotReplyType(botReplyType);
}

