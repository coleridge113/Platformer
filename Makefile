CXX = clang++
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra
INC = -I/opt/homebrew/include

LDFLAGS = /opt/homebrew/lib/libraylib.a -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SOURCES = main.cpp

game: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o game $(INC) $(LDFLAGS)

run:
	./game

clean:
	rm -f game
