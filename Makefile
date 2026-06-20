CXX = clang++
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra

# Detect OS
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    # macOS configuration
    INC = -I/opt/homebrew/include
    LDFLAGS = /opt/homebrew/lib/libraylib.a -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
    # Linux (Arch) configuration
    INC =
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

SOURCES = main.cpp

game: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o game $(INC) $(LDFLAGS)

run:
	./game

clean:
	rm -f game
