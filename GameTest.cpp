//
// Created by Alex on 2021-12-22.
//

#include "GameTest.h"
#include "Game.h"

TEST_F(GameTest, game_constructor_member_initalization)
{
    Game game;
    int* ptr_places = game.get_places();
    int* ptr_purses = game.get_purses();
    bool* ptr_penaltyBox = game.get_inPenaltyBox();
    int currentPlayer = game.get_currentPlayer();
    bool isGettingOutOfPenaltyBox = game.get_isGettingOutOfPenaltyBox();
    std::vector<std::string> players = game.get_players();
    std::list<std::string> popQuestions = game.get_popQuestions();
    std::list<std::string> scienceQuestions = game.get_scienceQuestions();
    std::list<std::string> sportsQuestions = game.get_sportsQuestions();
    std::list<std::string> rockQuestions = game.get_rockQuestions();

    EXPECT_EQ(ptr_places[0], 0);
    EXPECT_EQ(ptr_purses[0], 0);
    EXPECT_EQ(ptr_penaltyBox[0], true);
    EXPECT_EQ(currentPlayer, 0);
    EXPECT_EQ(isGettingOutOfPenaltyBox, false);
    EXPECT_TRUE(players.empty());
    EXPECT_EQ(popQuestions.front(), "Pop Question 0");
    EXPECT_EQ(scienceQuestions.front(), "Science Question 0");
    EXPECT_EQ(sportsQuestions.front(), "Sports Question 0");
    EXPECT_EQ(rockQuestions.front(), "Rock Question 0");
}

TEST_F(GameTest, create_questions)
{
    Game game;

    std::list<std::string> popQuestions = game.get_popQuestions();
    std::list<std::string> scienceQuestions = game.get_scienceQuestions();
    std::list<std::string> sportsQuestions = game.get_sportsQuestions();
    std::list<std::string> rockQuestions = game.get_rockQuestions();
    EXPECT_EQ(popQuestions.size(), 50);
    EXPECT_EQ(scienceQuestions.size(), 50);
    EXPECT_EQ(sportsQuestions.size(), 50);
    EXPECT_EQ(rockQuestions.size(), 50);
}