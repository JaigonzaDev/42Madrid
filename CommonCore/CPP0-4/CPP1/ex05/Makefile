BIN = Harl2.0 
SRCS = main.cpp Harl.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: $(BIN)

$(BIN) : $(SRCS)
	c++ -o $(BIN) $(SRCS) $(FLAGS) -I.

clean:
	rm $(BIN)

fclean: clean

.PHONY: all clean fclean