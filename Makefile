CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
main: src/ladder.cpp src/ladder_main.cpp
	g++ $(CXXFLAGS) src/ladder.cpp src/ladder_main.cpp -o main
clean:
	/bin/rm main