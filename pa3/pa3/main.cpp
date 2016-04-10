#include <cstdlib>
#include <ctime>
#include "game.h"

/*
 * CS237 PA3
 * Joe Opseth & Jens Myklebust
 * 18 April 2016
 */


int main()
{
    srand(time(NULL));
    cout << "WordGrid by Joe Opseth & Jens Myklebust - CS237 PA3" << endl;
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
