BIN = 01
COMP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(BIN)

$(BIN): $(SRCS)
	$(COMP) -o $(BIN) $(SRCS) $(CFLAGS) -I.

clean:
	rm -f $(BIN)

fclean: clean

.PHONY: clean fclean