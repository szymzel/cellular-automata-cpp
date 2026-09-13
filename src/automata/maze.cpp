#include "../cellular_automaton.h"
#include "../board.h"
#include "maze.h"
#include <string>

maze::maze(std::string name): cellular_automaton(name){}

void maze::update(board& grid){
    // B3/S12345 - zywa komorka przezywa przy 1-5 sasiadach (zamiast 2-3 jak w Conwayu),
    // co pozwala korytarzom trwac zamiast rozpadac sie, wiec z szumu samoorganizuje sie labirynt
    board next(grid);
    for (int i = 0; i<grid.getWidth();i++){
        for (int j = 0;j<grid.getHeight();j++){
            int n = this->neighbours(grid,i,j);
            if (grid.getCell(i,j) == 1){
                if (n>=1 && n<=5){
                    continue;
                } else {
                    next.setCell(i,j,0);
                }
            } else {
                if (n == 3){
                    next.setCell(i,j,1);
                }
            }
        }
    }
    grid = next;
}
