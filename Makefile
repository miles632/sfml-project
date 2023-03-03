output: game.o main.o 
	g++ main.o game.o  -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/sysprof-4 -pthread -lsfml-graphics -lsfml-window -lsfml-system -o output

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

clean: 
	rm *.o output