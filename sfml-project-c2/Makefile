output: texture_holder.o main.o
		g++ main.o texture_holder.o -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/sysprof-4 -pthread -lsfml-graphics -lsfml-window -lsfml-system -o output

main.o: main.cpp
		g++ -c main.cpp
texture_holder.o: texture_holder.cpp texture_holder.hpp
		g++ -c texture_holder.cpp
clean:
		rm *.o output main.o texture_holder.o
