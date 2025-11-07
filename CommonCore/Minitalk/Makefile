# Executable names
NAME_CLIENT = client
NAME_SERVER = server

# Directory Paths
BIN_PATH = ./bin
SRC_PATH = ./src
INCLUDE_PATH = ./include
BUILD_PATH = ./build
LIB_PATH = ./lib

# Libraries
LIBFT = Libft
PRINTF = Ft_printf

# External libft library path
LIBFT_PATH = $(LIB_PATH)/$(LIBFT)
LIBFT_LIB = $(LIBFT_PATH)/lib/$(LIBFT)

# External ft_printf library path
PRINTF_PATH = $(LIB_PATH)/$(PRINTF)
PRINTF_LIB = $(PRINTF_PATH)/lib/libftprintf.a

# .h files
INCLUDE_FILES = minitalk.h

# Include Path and Files
INCLUDE_PATH_FILES = $(INCLUDE_PATH)/$(INCLUDE_FILES)

# All includes (including libft and ft_printf)
ALL_INCLUDES = -I $(INCLUDE_PATH) -I $(LIBFT_PATH)/include -I $(PRINTF_PATH)/include

# .c files (without path)
C_FILES_CLIENT = client/client.c \
client/send_config/send_config.c \
client/send_config/send_message_handler/send_message_handler.c \
client/send_message/send_message.c \
client/try_connection/try_connection.c \
client/try_connection/try_connection_handler/try_connection_handler.c \

C_FILES_SERVER = server/server.c \
server/common/common.c \
server/server_config/server_config.c \
server/server_config/server_handler/server_handler.c \
server/server_config/server_handler/save_message/save_message.c \
server/server_config/server_handler/save_message/append_char/append_char.c \
server/server_loop/server_loop.c \

# .c files with path
SRCS_CLIENT = $(addprefix $(SRC_PATH)/, $(C_FILES_CLIENT))
SRCS_SERVER = $(addprefix $(SRC_PATH)/, $(C_FILES_SERVER))

# Object files for client
OBJS_CLIENT = $(patsubst $(SRC_PATH)/%.c, $(BUILD_PATH)/%.o, $(SRCS_CLIENT))

# Object files for server
OBJS_SERVER = $(patsubst $(SRC_PATH)/%.c, $(BUILD_PATH)/%.o, $(SRCS_SERVER))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar -rcs
RM = rm -rf

# External libraries (libft and ft_printf)
LIBS = -L$(LIBFT_PATH)/lib/Libft -L$(PRINTF_PATH)/lib -lft -lftprintf

# Main rules
all: libft printf $(NAME_CLIENT) $(NAME_SERVER)

bonus: all
# Rule for external libft library
libft:
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_PATH)

# Rule for external ft_printf library
printf:
	@echo "Building ft_printf..."
	@$(MAKE) -C $(PRINTF_PATH)

# Client compilation
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT_LIB) $(PRINTF_LIB)
	@echo "Building $(NAME_CLIENT)..."
	@mkdir -p $(BIN_PATH)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(BIN_PATH)/$(NAME_CLIENT)
	@echo "$(NAME_CLIENT) built successfully."

# Server compilation
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT_LIB) $(PRINTF_LIB)
	@echo "Building $(NAME_SERVER)..."
	@mkdir -p $(BIN_PATH)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(BIN_PATH)/$(NAME_SERVER)
	@echo "$(NAME_SERVER) built successfully."

# Rule to compile object files
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE_PATH_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(ALL_INCLUDES) -c $< -o $@

# Clean files
clean:
	@$(RM) $(BUILD_PATH)
	@echo "Cleaned build files."

# Clean all, including libft and ft_printf
fclean: clean
	@$(RM) $(BIN_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@echo "Cleaned all files."

# Recompile all
re: fclean all

# PHONY rules
.PHONY: all clean fclean re bonus libft printf
