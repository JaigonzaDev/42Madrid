BIN = ThisIsBrain
SRCS = main.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(BIN)

$(BIN) : $(SRCS)
	c++ -o $(BIN) $(SRCS) $(FLAGS) -I.

clean:
	rm $(BIN)

fclean: clean

.PHONY: all clean fclean