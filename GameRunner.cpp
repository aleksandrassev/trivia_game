#include <stdlib.h>
#include "Game.h"

static bool notAWinner;

int main()
{
    int game_count = 0;
    while (game_count < 50)
    {
        srand(game_count);

        Game aGame;

        aGame.add("Chet");
        aGame.add("Pat");
        aGame.add("Sue");

        int counter = 0;

        do
        {
            counter++;

            aGame.roll(rand() % 5 + 1);

            if (rand() % 9 == 7)
            {
                notAWinner = aGame.wrongAnswer();

            } else
            {
                notAWinner = aGame.wasCorrectlyAnswered();
            }
            std::cout<<notAWinner<<std::endl;
        } while (counter < 200);

        game_count++;
    }
}
