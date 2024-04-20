#include <iostream>
#include <string>
#include <vector>
#include "chatbotexception.h"
#include "chatbot.h"
#include "chatter.h"

using namespace std;

#define MSG_UNEXPECTED "Unexpected error occured"

int main() {
	try {
		Chatbot chatBot = Chatbot();

		vector<vector<string>> newKeywords = {{"act neutral", "act neutral"},
			{"act confused", "act confused"},
			{"sad", "depressed"},
			{"buffoon", "see you next tuesday"},
			{"funny", "happy"}};
		chatBot.setKeywords(newKeywords);

		vector<vector<string>> newChatter1 = {{"So you're saying, that ", ". Can you explain why?"},
			{"\"", ".\" What? I don't understand"},
			{"Saying, that ", " can't be good. Explaining why might help you out."},
			{"Wow. Saying, that ", " insults me. I need explanation. Now."},
			{"You saying ", " brings a smile to my face. Though I would like you to explain why."}};
		// 1 - Bot replies first element
		// 2 - Bot replies both elements
		// 3 - Bot replies both elements and your reply
		// 4 - Bot replies both elements and your modified reply
		chatBot.appendChatter(newChatter1, 4);

		// For testing exceptions
		// vector<vector<string>> newChatter2 = {{"test0"}, {"test1"}, {"test1"}, {"test2"}, {"test3"}, {"test4"}};
		// chatBot.appendChatter(newChatter2, 3);
		
	chatBot.Run();
	} catch(ChatbotException &e) {
		cout << e.what() << "\n";
	} catch(...) {
		cout << MSG_UNEXPECTED << "\n";
	}
}
