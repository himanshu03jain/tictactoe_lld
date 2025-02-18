#include <iostream>
#include "pieces.h"
#include "playingppiece.h"

class pieceX : public playingpiece {
public:
    pieceX() : playingpiece(pieces::x) { // Calls the base class constructor with pieces::X
    }
};