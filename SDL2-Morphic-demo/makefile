sdl2_includes 	= $(shell pkg-config --cflags-only-I sdl2)
sdl2_others   	= $(shell pkg-config --cflags-only-other sdl2)
sdl2_libs     	= $(shell pkg-config --libs-only-L) $(shell pkg-config --libs-only-l sdl2)

sdl2_gfx_includes =
sdl2_gfx_others   = 
sdl2_gfx_libs     = -lSDL2_gfx

INCLUDES = $(SDL2_includes) $(sdl2_gfx_includes) -I../include
OTHERS   = $(sdl2_others) $(sdl2_gfx_others)

INCLUDES 		= $(sdl2_includes) -I../SDL2-Morphic/include
OTHERS   		= $(sdl2_others)

CXX      		= g++
CXXFLAGS 		= -W -Wall -Wextra -O2 $(INCLUDES) $(OTHERS)

LD       		= g++
LDFLAGS  		= -mwindows
LIBS     		= -L../SDL2-Morphic/src -lSDL2-Morphic $(sdl2_libs) $(sdl2_gfx_libs)

target 			= SDL2-Morphic-demo

all: $(target)

$(target): main.o
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
