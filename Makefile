NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Werror -Wextra

SRC_PATH    = src/
OBJ_PATH    = obj/
INC_PATH    = includes/
LIBFT_PATH  = libft/

INCS        = -I $(INC_PATH) -I $(LIBFT_PATH)
LIBFT       = $(LIBFT_PATH)libft.a

SRC = parsing.c main.c \
      swap.c push.c rotate.c reverse_rotate.c \
      ft_sort.c ft_utils.c sort_small.c space.c \
	ft_outils.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)    
 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
