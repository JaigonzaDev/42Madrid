BIN = UnnecesaryViolence 
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(BIN)

$(BIN) : $(SRCS)
	c++ -o $(BIN) $(SRCS) $(FLAGS) -I.

clean:
	rm $(BIN)

fclean: clean

.PHONY: all clean fclean