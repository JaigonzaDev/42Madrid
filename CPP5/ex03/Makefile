BIN = 03
COMP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
SRCS = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp

all: $(BIN)

$(BIN): $(SRCS)
	$(COMP) -o $(BIN) $(SRCS) $(CFLAGS) -I.

clean:
	rm -f $(BIN)

fclean: clean

.PHONY: clean fclean