#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : m_places{}, m_purses{}, m_currentPlayer(0), m_isGettingOutOfPenaltyBox{false}, m_inPenaltyBox{true}
{
    createQuestions(50);
}

int* Game::get_places()
{
    return m_places;
}
int* Game::get_purses()
{
    return m_purses;
}
bool* Game::get_inPenaltyBox()
{
    return m_inPenaltyBox;
}
bool Game::get_isGettingOutOfPenaltyBox()
{
    return m_isGettingOutOfPenaltyBox;
}
int Game::get_currentPlayer()
{
    return m_currentPlayer;
}
vector<string> Game::get_players()
{
    return m_players;
}
list<string> Game::get_popQuestions()
{
    return m_popQuestions;
}
list<string> Game::get_scienceQuestions()
{
    return m_scienceQuestions;
}
list<string> Game::get_sportsQuestions()
{
    return m_sportsQuestions;
}
list<string> Game::get_rockQuestions()
{
    return m_rockQuestions;
}

void Game::createPopQuestion(int questionNr)
{
    ostringstream oss(ostringstream::out);
    oss << "Pop Question " << questionNr;
    m_popQuestions.push_back(oss.str());
}

void Game::createScienceQuestion(int questionNr)
{
    ostringstream oss(ostringstream::out);
    oss << "Science Question " << questionNr;
    m_scienceQuestions.push_back(oss.str());
}

void Game::createSportsQuestion(int questionNr)
{
    ostringstream oss(ostringstream::out);
    oss << "Sports Question " << questionNr;
    m_sportsQuestions.push_back(oss.str());
}

void Game::createRockQuestion(int questionNr)
{
    ostringstream oss(ostringstream::out);
    oss << "Rock Question " << questionNr;
    m_rockQuestions.push_back(oss.str());
}

void Game::createQuestions(int questionAmount)
{
    for (int i = 0; i < questionAmount; i++)
    {
        createPopQuestion(i);
        createScienceQuestion(i);
        createSportsQuestion(i);
        createRockQuestion(i);
    }
}

bool Game::isPlayable()
{
    return (howManyPlayers() >= 2);
}

bool Game::add(string playerName)
{
    m_players.push_back(playerName);
    m_places[howManyPlayers()] = 0;
    m_purses[howManyPlayers()] = 0;
    m_inPenaltyBox[howManyPlayers()] = false;

    cout << playerName << " was added" << endl;
    cout << "They are player number " << m_players.size() << endl;
    return true;
}

int Game::howManyPlayers()
{
    return m_players.size();
}

void Game::roll(int roll)
{
    cout << m_players[m_currentPlayer] << " is the current player" << endl;
    cout << "They have rolled a " << roll << endl;

    if (m_inPenaltyBox[m_currentPlayer])
    {
        if (roll % 2 != 0)
        {
            m_isGettingOutOfPenaltyBox = true;

            cout << m_players[m_currentPlayer] << " is getting out of the penalty box" << endl;
            m_places[m_currentPlayer] = m_places[m_currentPlayer] + roll;
            if (m_places[m_currentPlayer] > 11) m_places[m_currentPlayer] = m_places[m_currentPlayer] - 12;

            cout << m_players[m_currentPlayer] << "'s new location is " << m_places[m_currentPlayer] << endl;
            cout << "The category is " << currentCategory() << endl;
            askQuestion();
        } else
        {
            cout << m_players[m_currentPlayer] << " is not getting out of the penalty box" << endl;
            m_isGettingOutOfPenaltyBox = false;
        }

    } else
    {

        m_places[m_currentPlayer] = m_places[m_currentPlayer] + roll;
        if (m_places[m_currentPlayer] > 11) m_places[m_currentPlayer] = m_places[m_currentPlayer] - 12;

        cout << m_players[m_currentPlayer] << "'s new location is " << m_places[m_currentPlayer] << endl;
        cout << "The category is " << currentCategory() << endl;
        askQuestion();
    }
}

void Game::askQuestion()
{
    if (currentCategory() == "Pop")
    {
        cout << m_popQuestions.front() << endl;
        m_popQuestions.pop_front();
    }
    if (currentCategory() == "Science")
    {
        cout << m_scienceQuestions.front() << endl;
        m_scienceQuestions.pop_front();
    }
    if (currentCategory() == "Sports")
    {
        cout << m_sportsQuestions.front() << endl;
        m_sportsQuestions.pop_front();
    }
    if (currentCategory() == "Rock")
    {
        cout << m_rockQuestions.front() << endl;
        m_rockQuestions.pop_front();
    }
}


string Game::currentCategory()
{
    if (m_places[m_currentPlayer] == 0) return "Pop";
    if (m_places[m_currentPlayer] == 4) return "Pop";
    if (m_places[m_currentPlayer] == 8) return "Pop";
    if (m_places[m_currentPlayer] == 1) return "Science";
    if (m_places[m_currentPlayer] == 5) return "Science";
    if (m_places[m_currentPlayer] == 9) return "Science";
    if (m_places[m_currentPlayer] == 2) return "Sports";
    if (m_places[m_currentPlayer] == 6) return "Sports";
    if (m_places[m_currentPlayer] == 10) return "Sports";
    return "Rock";
}

bool Game::wasCorrectlyAnswered()
{
    if (m_inPenaltyBox[m_currentPlayer])
    {
        if (m_isGettingOutOfPenaltyBox)
        {
            cout << "Answer was correct!!!!" << endl;
            m_purses[m_currentPlayer]++;
            cout << m_players[m_currentPlayer]
                 << " now has "
                 << m_purses[m_currentPlayer]
                 << " Gold Coins." << endl;

            bool winner = didPlayerWin();
            m_currentPlayer++;
            if (m_currentPlayer == m_players.size()) m_currentPlayer = 0;

            return winner;
        } else
        {
            m_currentPlayer++;
            if (m_currentPlayer == m_players.size()) m_currentPlayer = 0;
            return true;
        }


    } else
    {

        cout << "Answer was corrent!!!!" << endl;
        m_purses[m_currentPlayer]++;
        cout << m_players[m_currentPlayer]
             << " now has "
             << m_purses[m_currentPlayer]
             << " Gold Coins." << endl;

        bool winner = didPlayerWin();
        m_currentPlayer++;
        if (m_currentPlayer == m_players.size()) m_currentPlayer = 0;

        return winner;
    }
}

bool Game::wrongAnswer()
{
    cout << "Question was incorrectly answered" << endl;
    cout << m_players[m_currentPlayer] + " was sent to the penalty box" << endl;
    m_inPenaltyBox[m_currentPlayer] = true;

    m_currentPlayer++;
    if (m_currentPlayer == m_players.size()) m_currentPlayer = 0;
    return true;
}


bool Game::didPlayerWin()
{
    return !(m_purses[m_currentPlayer] == 6);
}
