#include <stdlib.h>
#include "Game.h"

static bool notAWinner;

int main()
{
    int ext_count = 0;
    while (ext_count < 50)
    {
        srand(ext_count);

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
        } while (counter < 200);

        ext_count++;
    }
}
