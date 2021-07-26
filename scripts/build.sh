rm ../bin/2dGame
g++ ../sources/main.cpp ../sources/gameEngine.cpp ../sources/object.cpp ../sources/tileMap.cpp -lsfml-graphics -lsfml-window -lsfml-system -o ../bin/2dGame