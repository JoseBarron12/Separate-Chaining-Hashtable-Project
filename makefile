
CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -pedantic -I.


all: main


main: hashmain.cc htable.cc hashmain.h htable.h entry.h
	g++ $(CXXFLAGS) -o hashmain hashmain.cc htable.cc


clean:
	rm -f hashmain

.PHONY: all clean
