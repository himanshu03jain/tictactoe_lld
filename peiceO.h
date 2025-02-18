#include <iostream>
#include "pieces.h"
#include "playingppiece.h"

class pieceo : public playingpiece {
public:
    pieceo() : playingpiece(pieces::o) { // Calls the base class constructor with pieces::X
    }
};