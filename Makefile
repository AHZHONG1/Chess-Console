# use CPPFLAGS to set proper configurations in different platforms
CPPFLAGS = -std=c++11 -fsanitize=address,leak,undefined
SRCS = main.cpp Chess.cpp GameBoard.cpp GamePieces.cpp Pawn.cpp Rook.cpp Knight.cpp Bishop.cpp Queen.cpp King.cpp GameUtilities.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: Chess.exe

Chess.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -o $@ $(CPPFLAGS) -MMD -MP -c $<

-include $(DEPS)

clean:
	del *.exe *.o *.d
# (Windows) del *.o *.exe *.d
# (Linux or MacOS) rm -f *.o *.exe *.d