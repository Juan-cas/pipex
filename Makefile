# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address,leak

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
$(SRC_DIR)/parsing/pathfinder.c \
$(SRC_DIR)/parsing/init_struct.c \
$(SRC_DIR)/pipex.c \
$(SRC_DIR)/utils/free_matrix.c \
$(SRC_DIR)/error/errors.c \
$(SRC_DIR)/utils/struct_free.c \
$(SRC_DIR)/utils/child_birth.c \
$(SRC_DIR)/utils/command_split.c \
$(SRC_DIR)/utils/append.c \
$(SRC_DIR)/pipex_bonus.c \
$(SRC_DIR)/utils/wait_for_complete.c \
$(SRC_DIR)/utils/fd_closer.c \
$(SRC_DIR)/utils/pipe_management.c \
$(SRC_DIR)/parsing/relative_or_absolute.c \
$(SRC_DIR)/error/no_path.c \
$(SRC_DIR)/utils/infile_outfile.c \
$(SRC_DIR)/utils/fd_swapper.c \
$(SRC_DIR)/utils/executor.c \

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft 

# Executable
TARGET := pipex
NAME := $(TARGET)

# Conditional compilation based on target
ifeq ($(MAKECMDGOALS),debug)
 CFLAGS += -g
else ifeq ($(MAKECMDGOALS),optimize)
 CFLAGS += -O2
endif

all: libft $(TARGET)

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean: libft_clean 
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean 
	rm -f $(TARGET)

re: fclean all

bonus:: CFLAGS += -D BONUS=1
bonus: re

rebonus: fclean bonus

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re bonus rebonus

