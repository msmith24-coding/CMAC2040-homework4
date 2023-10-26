OBJS = IntGame StringGame AbilityGame

CXXFLAGS = -g -O2 -Wall -Wextra -Wpedantic -Werror --std=c++23 -Wnon-virtual-dtor -Wold-style-cast -Wunused-parameter -Wuninitialized  -Winit-self  -Wshadow  -Wparentheses -Wdangling-else 

all: ${OBJS}

AbilityGame: AbilityT.o

clean:
	rm -f ${OBJS} *.o

tar:
	tar -czvf ../homework4.tar.gz ../homework4