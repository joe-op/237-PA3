#include <cstdlib>
#include <ctime>
#include "game.h"

int main()
{
    srand(time(NULL));
    cout << "WordGrid by J. Random Student - CS 237 PA3" << endl;
    cout << "Bonus features implemented: none" << endl;
    cout << "Loading wordlist.txt . . . ";
    game game("wordlist.txt");
    cout << endl;

    while (!game.is_ended())
    {
        game.take_turn();
    }
    game.game_over();

    return 0;
}
