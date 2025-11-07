# Executable name
NAME = philo 

# PATH directories
BIN_PATH = ./bin
SRC_PATH = ./src
INCLUDE_PATH = ./include
BUILD_PATH = ./build
LIB_PATH = ./lib

# Source paths
SRC_OBLIGATORY_PATH = $(SRC_PATH)/Obligatory
SRC_BONUS_PATH = $(SRC_PATH)/Bonus

# Build paths
OBLIGATORY_BUILD_PATH = $(BUILD_PATH)/Obligatory
BONUS_BUILD_PATH = $(BUILD_PATH)/Bonus

# .h files
INCLUDE_FILES_OBLIGATORY = philosophers.h
INCLUDE_FILES_BONUS = philosophers_bonus.h

# Include path and files
INCLUDE_PATH_FILES_OBLIGATORY = $(INCLUDE_PATH)/$(INCLUDE_FILES_OBLIGATORY)
INCLUDE_PATH_FILES_BONUS = $(INCLUDE_PATH)/$(INCLUDE_FILES_BONUS)

# All includes (includes libft and ft_printf)
ALL_INCLUDES = -I $(INCLUDE_PATH)

# .c files (without path)
C_FILES_OBLIGATORY =  init_data.c main.c philosopher.c utils.c monitor.c
C_FILES_BONUS = 

# .c files with path
SRCS_OBLIGATORY = $(addprefix $(SRC_OBLIGATORY_PATH)/, $(C_FILES_OBLIGATORY))
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH)/, $(C_FILES_BONUS))

# Convert .c files to .o
OBJS_OBLIGATORY = $(patsubst $(SRC_OBLIGATORY_PATH)/%.c, $(OBLIGATORY_BUILD_PATH)/%.o, $(SRCS_OBLIGATORY))
OBJS_BONUS = $(patsubst $(SRC_BONUS_PATH)/%.c, $(BONUS_BUILD_PATH)/%.o, $(SRCS_BONUS))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar -rcs
RM = rm -rf

# External libraries (libft, get_next_line, ft_printf, minilibx)
LIBS = 
# Main rules
all: $(NAME)

# Compilation
$(NAME): $(OBJS_OBLIGATORY) $(LIBFT_LIB) $(GNL_LIB) $(PRINTF_LIB) $(MLX_LIB)
	@echo "Building $(NAME)..."
	@mkdir -p $(BIN_PATH)/Obligatory
	@$(CC) $(CFLAGS) $(OBJS_OBLIGATORY) $(LIBS) -o $(BIN_PATH)/Obligatory/$(NAME)
	@echo "$(NAME) built successfully."

# Rule to compile obligatory object files
$(OBLIGATORY_BUILD_PATH)/%.o: $(SRC_OBLIGATORY_PATH)/%.c $(INCLUDE_PATH_FILES_OBLIGATORY)
	@mkdir -p $(OBLIGATORY_BUILD_PATH)
	$(CC) $(CFLAGS) $(ALL_INCLUDES) -c $< -o $@

# Rule to compile bonus object files
# bonus: $(OBJS_BONUS)
# 	@echo "Building bonus..."
# 	@mkdir -p $(BIN_PATH)/Bonus
# 	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(BIN_PATH)/Bonus/$(NAME)
# 	@echo "Bonus built successfully."

# $(BONUS_BUILD_PATH)/%.o: $(SRC_BONUS_PATH)/%.c $(INCLUDE_PATH_FILES_BONUS)
# 	@mkdir -p $(BONUS_BUILD_PATH)
# 	$(CC) $(CFLAGS) $(ALL_INCLUDES) -c $< -o $@

# Clean files
clean:
	@$(RM) $(BUILD_PATH)
	@echo "Cleaned build files."

# Clean everything, including libft, gnl, ft_printf, and minilibx
fclean: clean
	@$(RM) $(BIN_PATH)
	@echo "Cleaned all files."

# Rebuild everything
re: fclean all

# PHONY rule
.PHONY: all clean fclean re bonus
