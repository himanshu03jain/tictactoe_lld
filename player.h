#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "playingppiece.h"

class player{
public:
    std::string name;
    playingpiece* playpc;

    player(std::string name, playingpiece* piece){
        this->name = name;
        this->playpc = piece;
    }

    void setname(std::string name){
        this->name = name;
    }

    std::string getname(){
        return name;
    }

    void setplayingpiece(playingpiece* piece){
        this->playpc = piece;
    }

    playingpiece getplayingpiece(){
        return *playpc;
    }
};

#endif