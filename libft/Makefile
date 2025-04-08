NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

ROOT_DIR = $(shell pwd)
OBJ_DIR = $(shell pwd)/obj/
LIBFT_DIR = $(ROOT_DIR)/libft/
PRINTF_DIR = $(ROOT_DIR)/ft_printf/
GNL_DIR = $(ROOT_DIR)/gnl/
INCLUDES = -I$(ROOT_DIR)/includes/

# Files
LIBFT_SRCS =	ft_atoi.c			ft_memcpy.c \
      			ft_memchr.c			ft_strrchr.c \
				ft_strdup.c			ft_striteri.c \
				ft_substr.c			ft_bzero.c \
				ft_memmove.c		ft_strjoin.c \
				ft_tolower.c		ft_calloc.c \
				ft_memset.c			ft_strlcat.c \
				ft_toupper.c		ft_isalnum.c \
				ft_putchar_fd.c		ft_strlcpy.c \
				ft_isalpha.c		ft_putendl_fd.c \
				ft_strlen.c			ft_isascii.c \
				ft_putnbr_fd.c		ft_strmapi.c \
				ft_isdigit.c		ft_putstr_fd.c \
				ft_strncmp.c		ft_isprint.c \
				ft_split.c			ft_strnstr.c \
				ft_itoa.c			ft_memcmp.c \
				ft_strchr.c			ft_strtrim.c \
				ft_lstnew.c			ft_lstadd_front.c \
				ft_lstlast.c		ft_lstclear.c \
				ft_lstdelone.c		ft_lstsize.c \
				ft_lstmap.c			ft_lstiter.c \
				ft_lstadd_back.c	ft_itoa_base.c \
				ft_uitoa.c

PRINTF_SRCS =	ft_printf.c	formatters.c \
				handlers.c	handlers2.c	\
				parsers.c	printers.c

GNL_SRCS =		get_next_line.c

LIBFT_SRCS_PATH = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))
PRINTF_SRCS_PATH = $(addprefix $(PRINTF_DIR)src/, $(PRINTF_SRCS))
GNL_SRCS_PATH = $(addprefix $(GNL_DIR), $(GNL_SRCS))

ALL_SRC = $(LIBFT_SRCS_PATH) $(PRINTF_SRCS_PATH) $(GNL_SRCS_PATH)

#Generate object file names
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(OBJ_DIR)libft_%.o)
PRINTF_OBJS = $(PRINTF_SRCS:%.c=$(OBJ_DIR)printf_%.o)
GNL_OBJS = $(GNL_SRCS:%.c=$(OBJ_DIR)gnl_%.o)
ALL_OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

# Main rules
all: $(NAME)

$(NAME): libft printf gnl
	@echo "✅ Library $(NAME) created successfully."

libft: $(LIBFT_OBJS)
	@echo "✅ libft part compiled successfully"

printf: $(PRINTF_OBJS)
	@echo "✅ printf part compiled successfully"

gnl: $(GNL_OBJS)
	@echo "✅ get_next_line part compiled successfully"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#Compile libft source files
$(OBJ_DIR)libft_%.o: $(LIBFT_DIR)%.c Makefile includes/libft.h | $(OBJ_DIR)
	@echo "🔧 Compiling $(@F:libft_%.o=%.c)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(AR) $(NAME) $@

#Compile printf source files
$(OBJ_DIR)printf_%.o: $(PRINTF_DIR)src/%.c Makefile includes/ft_printf.h | $(OBJ_DIR)
	@echo "🔧 Compiling $(@F:printf_%.o=%.c)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(AR) $(NAME) $@

#Compile get_next_line source files
$(OBJ_DIR)gnl_%.o: $(GNL_DIR)%.c Makefile includes/get_next_line.h | $(OBJ_DIR)
	@echo "🔧 Compiling $(@F:gnl_%.o=%.c)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(AR) $(NAME) $@

clean:
	@echo "🧹 Removing object files at libft..."
	@$(RM) -r $(OBJ_DIR)
	@echo "✅ Object files removed."

fclean: clean
	@echo "🗑️ Removing library..."
	@$(RM) $(NAME)
	@echo "✅ Cleanup complete."

re: fclean all
	@echo "🎉 Full recompilation complete."

.PHONY: all clean fclean re libft printf gnl
	
