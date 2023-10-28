#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "flash.cpp"
using namespace std;

void PrintQuestion(FlashCard*);
void PrintAnswer(FlashCard*);

int main(){
    /* Read and store */
    vector<FlashCard> cardList;

    // Read from file
    fstream txt("cards.txt");
    string question, answer;
    char delim = ':';

    // Store text in cards
    while (getline(txt, question, delim)){
        getline(txt, answer);
        FlashCard card(question, answer);
        cardList.push_back(card);
    }
    txt.close();

    /* Frontend */
    system("cls");
    cout << "Are you ready to study?\n";
    getchar();
    system("cls");

    while(true){
        ShuffleDeck(cardList.data(), cardList.size());

        for (int i = 0; i < cardList.size(); i++){
            PrintQuestion(cardList.data() + i);
            getchar();
            PrintAnswer(cardList.data() + i);
            cout << "\n([Q] to quit)\n> ";
            if (getchar() == 'q'){
                return 0;
            }
            system("cls");
        }

        cout << "Are you finished? [Q] to quit.\n>";
        if (getchar() == 'q'){
            return 0;
        }
        system("cls");
    }
}

void PrintQuestion(FlashCard* card){
    string question = "Question: ";
    question.append(card->_question);
    cout << question;
}

void PrintAnswer(FlashCard* card){
    string answer = "Answer: ";
    answer.append(card->_answer);
    cout << answer;
}