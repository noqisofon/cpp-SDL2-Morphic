sdl2_includes = $(shell pkg-config --cflags-only-I SDL2)
sdl2_others   = $(shell pkg-config --cflags-only-other SDL2)
sdl2_libs     = $(shell pkg-config --libs-only-l SDL2)

sdl2_gfx_includes =
sdl2_gfx_others   = 
sdl2_gfx_libs     = -lSDL2_gfx

INCLUDES = $(SDL2_includes) $(sdl2_gfx_includes) -I../include
OTHERS   = $(sdl2_others) $(sdl2_gfx_others)

CC       = gcc
CFLAGS   = -W -Wall -Wextra -O2 $(INCLUDES) $(OTHERS)

CXXFLAGS = $(CFLAGS)

LD       = gcc
LIBS     = $(sdl2_libs) $(sdl2_gfx_libs)

AR       = ar

srcs   = $(shell ls *.cpp)
objs   = $(patsubst %.cpp, %.o, $(srcs))

target = libSDL2-Morphic.a

all: $(target)

$(target): $(objs)
	$(AR) r $@  $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -v $(objs) $(target)
.PHONY : clean
