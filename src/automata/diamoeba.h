#pragma once
#include "../cellular_automaton.h"
#include "../board.h"
#include <string>

class diamoeba: public cellular_automaton{
    public:
        diamoeba(std::string name);
        void update(board& grid);
};
