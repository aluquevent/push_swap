CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
SRC_DIR = src
INCLUDES_DIR = includes
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	best_move.c		cost.c \
			list_free.c		list_struct.c \
			list_utils.c	operations_core.c \
			operations_do.c	operations_do_rotate.c \
			ops_counter.c	position_utils.c \
			push_initial.c	main.c \
			small_sort.c	sort.c \
			turkish_sort.c	validation.c \
			init.c			validation_utils.c \
			operations_do_rotate_both.c

# Add complete route
SRC_WITH_PATH = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

#Generate object names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_WITH_PATH))

#Dependencias
DEP_FILES = $(OBJ_FILES:.o=.d)

HEADERS =	includes/operations.h	includes/push_swap.h \
			includes/list.h			includes/sorting.h

#Executable name
EXEC = push_swap

#Bonus files
BONUS_OBJ = \
			obj/checker_bonus.o \
			obj/validation.o \
			obj/validation_utils.o \
			obj/operations_core.o \
			obj/list_utils.o \
			obj/init.o \
			obj/list_struct.o \
			obj/list_free.o

CHECKER = checker

#Main Rule
all: directories libft_make $(EXEC)

#Create objects dir
directories:
	@echo "📂 Creating objects directory..."
	@mkdir -p $(OBJ_DIR)

#Compile libft
libft_make:
	@echo "📚 Compiling libft library..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
#Compile exec
$(EXEC): $(OBJ_FILES) $(LIBFT)
	@echo "❗ Creating executable file..."
	@$(CC) $(CFLAGS) -g -o $@ $^ -L$(LIBFT_DIR) -lft

#Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -MD -c $< -o $@
	@echo "🔧 Compiling $@..."

bonus: all $(BONUS_OBJ) $(LIBFT)
	@echo "⭐ Compiling bonus Checker..."
	@$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJ) $(LIBFT)
#Clean generated files
clean:
	@echo "🧹 Cleaning libft and push_swap object files..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -f $(EXEC)
	@rm -f $(CHECKER)

re: fclean all
	@echo "🤖 Push_swap project rebuilt !!!"

.PHONY: all clean fclean re directories libft_make bonus

#Include generated dependency files
-include $(DEP_FILES)
