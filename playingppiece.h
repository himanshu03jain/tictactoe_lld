#ifndef PLAYINGPIECE_H
#define PLAYINGPIECE_H
#include <iostream>
#include "pieces.h"

class playingpiece{
public:
    pieces piecetype;
    //playingpiece() : piecetype(pieces::n) {} // Default constructor to pieces::None

    playingpiece(pieces type) : piecetype(type) {} // Constructor to initialize with a piece type

    pieces getpiecetype() const {
        return piecetype; // Getter for the piece type
    }
};

#endif