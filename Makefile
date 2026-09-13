SOURCES = src/main.cpp src/automata/game_of_life.cpp src/initial_conditions.cpp src/renderer.cpp src/input.cpp src/cellular_automaton.cpp src/board.cpp src/automata/seeds.cpp src/automata/high_life.cpp src/automata/maze.cpp src/automata/diamoeba.cpp

game: $(SOURCES)
	clang++ -std=c++17 -Wall $(SOURCES) $(shell pkg-config --cflags --libs raylib) -o game

go: game
	./game