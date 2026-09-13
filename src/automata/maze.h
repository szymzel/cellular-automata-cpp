#pragma once
#include "../cellular_automaton.h"
#include "../board.h"
#include <string>

class maze: public cellular_automaton{
    public:
        maze(std::string name);
        void update(board& grid);
};
