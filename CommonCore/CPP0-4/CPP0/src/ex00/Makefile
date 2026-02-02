BIN = megaphone
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp

all: $(BIN)
$(BIN): $(SRCS)
	c++ $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -f $(BIN)

fclean: clean

.PHONY: clean fclean

