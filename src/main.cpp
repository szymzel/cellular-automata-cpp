#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "renderer.h"
#include "board.h"
#include "input.h"
#include "initial_conditions.h"
#include "automata/game_of_life.h"
#include "automata/seeds.h"
#include "automata/high_life.h"
#include "automata/maze.h"
#include "automata/diamoeba.h"

const int W = 320;
const int H = 180;
const int cellSize = 4;

bool IsPaused = 1;

int main(int argc, char* argv[]){
    std::cout << "available cellular automata: game_of_life, seeds, high_life, maze, diamoeba\n";
    std::cout << "available initial conditions: acorn, pulsar, default_scenario, glider_gun, random, all_colored_board, diehard, r_pentomino, rabbits, replicator, replicator_field (high_life only), showcase\n";
    std::cout << "use: " << argv[0] << " [automaton] [pattern]  (or without arguments - it will ask interactively)\n\n";

    std::string automaton_name = "game_of_life";
    std::string pattern_name = "random";

    if (argc > 1){
        automaton_name = argv[1];
    } else {
        std::cout << "pick automaton: ";
        std::cin >> automaton_name;
    }

    if (argc > 2){
        pattern_name = argv[2];
    } else {
        std::cout << "pick initial conditions: ";
        std::cin >> pattern_name;
    }

    std::unique_ptr<cellular_automaton> automaton;
    if (automaton_name == "game_of_life"){
        automaton = std::make_unique<game_of_life>("Conway");
    } else if (automaton_name == "seeds"){
        automaton = std::make_unique<seeds>("Seeds");
    } else if (automaton_name == "high_life"){
        automaton = std::make_unique<high_life>("High Life");
    } else if (automaton_name == "maze"){
        automaton = std::make_unique<maze>("Maze");
    } else if (automaton_name == "diamoeba"){
        automaton = std::make_unique<diamoeba>("Diamoeba");
    }

    std::string name = automaton->getName();
    InitWindow(W*cellSize,H*cellSize, name.c_str());
    SetTargetFPS(120);
    board grid(W,H);

    if (pattern_name == "acorn"){
        Acorn(grid);
    } else if (pattern_name == "pulsar"){
        Pulsar(grid);
    } else if (pattern_name == "default_scenario"){
        DefaultScenario(grid);
    } else if (pattern_name == "glider_gun"){
        GliderGun(grid);
    } else if (pattern_name == "random"){
        Random(grid);
    } else if (pattern_name == "all_colored_board"){
        AllColoredBoard(grid);
    } else if (pattern_name == "diehard"){
        Diehard(grid);
    } else if (pattern_name == "r_pentomino"){
        RPentomino(grid);
    } else if (pattern_name == "rabbits"){
        Rabbits(grid);
    } else if (pattern_name == "replicator"){
        Replicator(grid);
    } else if (pattern_name == "replicator_field"){
        ReplicatorField(grid);
    } else if (pattern_name == "showcase"){
        Showcase(grid);
    }
    
    int GenerationNumber = 0;
    while (!WindowShouldClose()){
        handleInput(grid, cellSize);
        Pause(IsPaused);
        if (IsPaused==0){
            automaton->update(grid);
            GenerationNumber += 1;
        }

        std::string text = "Generation number: " + std::to_string(GenerationNumber);

        BeginDrawing();
        ClearBackground(BLACK);
        draw(grid,cellSize);
        DrawText(text.c_str(),0,0,16,LIME);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}