#include "../cellular_automaton.h"
#include "../board.h"
#include "diamoeba.h"
#include <string>

diamoeba::diamoeba(std::string name): cellular_automaton(name){}

void diamoeba::update(board& grid){
    // B35678/S5678 - do zycia (narodzin lub przezycia) potrzeba duzo sasiadow,
    // wiec gesto upakowane skupiska trwaja, a rzadkie komorki wymieraja.
    // Efekt: zwarte plamy o falujacych, "diamentowych" krawedziach
    board next(grid);
    for (int i = 0; i<grid.getWidth();i++){
        for (int j = 0;j<grid.getHeight();j++){
            int n = this->neighbours(grid,i,j);
            if (grid.getCell(i,j) == 1){
                if (n==5 || n==6 || n==7 || n==8){
                    continue;
                } else {
                    next.setCell(i,j,0);
                }
            } else {
                if (n==3 || n==5 || n==6 || n==7 || n==8){
                    next.setCell(i,j,1);
                }
            }
        }
    }
    grid = next;
}
