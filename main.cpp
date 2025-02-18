#include <iostream>
#include "tictactoegame.h"

int main(){
    tictactoegame game;
    game.initialize();
    std::string winner = game.startgame();
    std::cout<<"winner is : "<<winner<<"\n";
    return 0;
}