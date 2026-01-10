COMMON_SRC = src/parsing.c  src/ft_outils.c \
      src/swap.c src/push.c src/rotate.c src/reverse_rotate.c \
      src/ft_sort.c src/ft_utils.c  src/space.c \

BONUS_SRC =  checker_bonus/checker_bonus.c\
	      checker_bonus/checker_utile1_bonus.c checker_bonus/checker_utile_bonus.c

SRC = src/main.c src/sort_small.c 

BONUS_OBJS = $(BONUS_SRC:.c=.o)

OBJS = $(SRC:.c=.o)

COMMOB_OBJS = $(COMMON_SRC:.c=.o)

BONUS = checker

LIBFT = libft/libft.a

LIBFT_PATH = libft/

CC = cc

FLAGS = -Wall -Wextra -Werror -I./includes

NAME = push_swap

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJS) $(COMMOB_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) $(COMMOB_OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(COMMOB_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(COMMOB_OBJS) $(LIBFT) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(COMMOB_OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(BONUS) $(NAME) 
	make fclean -C $(LIBFT_PATH)

re: fclean all


.PHONY: all bonus clean fclean re
	
