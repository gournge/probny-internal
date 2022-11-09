# make: # remove -g for release
# 	g++ -o tictactoe main.cpp src/*.cpp -Isrc -g

make: # remove -g for release
	g++ -o tictactoe main.cpp src/*.cpp -Isrc 