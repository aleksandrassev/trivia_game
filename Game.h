#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game
{
private:
    vector<string> m_players;

    int m_places[6];
    int m_purses[6];
    unsigned int m_currentPlayer;
    bool m_isGettingOutOfPenaltyBox;
    bool m_inPenaltyBox[6];

    list<string> m_popQuestions;
    list<string> m_scienceQuestions;
    list<string> m_sportsQuestions;
    list<string> m_rockQuestions;

    bool didPlayerWin();
    void askQuestion();
    string currentCategory();

public:
    Game();
    int* get_places();
    int* get_purses();
    bool* get_inPenaltyBox();
    bool get_isGettingOutOfPenaltyBox();
    int get_currentPlayer();
    vector<string> get_players();
    list<string> get_popQuestions();
    list<string> get_scienceQuestions();
    list<string> get_sportsQuestions();
    list<string> get_rockQuestions();

    string createRockQuestion(int index);
    bool isPlayable();
    bool add(string playerName);
    int howManyPlayers();
    void roll(int roll);
    bool wasCorrectlyAnswered();
    bool wrongAnswer();

};

#endif /* GAME_H_ */
