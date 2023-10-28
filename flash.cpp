#include <string>
#include <time.h>
using namespace std;

class FlashCard{
public:
    FlashCard(string question, string answer){
        _question = question;
        _answer = answer;
    }

    string _question;
    string _answer;
};

/*
Shuffle the given deck of cards using the Fisher-Yates shuffle algorithm
*/
void ShuffleDeck(FlashCard* deck, size_t length){
    srand(time(NULL));
    string temp;
    
    // I don't even fully understand this
    for (int i = 0; i < (int) length - 2; i++){
        int j = i + (rand() % (int) length - i);

        temp = (deck + i)->_question;
        (deck + i)->_question = (deck + j)->_question;
        (deck + j)->_question = temp;

        temp = (deck + i)->_answer;
        (deck + i)->_answer = (deck + j)->_answer;
        (deck + j)->_answer = temp;
    }
}