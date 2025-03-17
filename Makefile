CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
main: src/dijkstras.cpp src/dijkstras_main.cpp
	g++ $(CXXFLAGS) src/dijkstras.cpp src/dijkstras_main.cpp -o main
clean:
	/bin/rm main