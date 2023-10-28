# Flash Card App

## Goals:
- [x] FlashCard class containing a question and an answer
- [x] Text file containing pairs of questions and answers to read from at startup
- [x] Vector of FlashCard type to store cards in memory
- [x] Actually read from the text file
- [x] Shuffle deck of cards
- [x] Frontend update to prompt user

## Notes:
- Each line in cards.txt should represent a question and an answer, separated by a :
- I use getchar() because I don't care about actually giving an answer to the computer, so don't overflow the input lol
- I love you