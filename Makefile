
NAME = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror 
SRCMAIN =src/push_swap.c $(SRCS)
SRCS =	src/ft_splitarg.c src/ft_stackinit.c src/operations.c src/sorting.c src/bigsort.c src/biggi.c src/biggi2.c\
	
OBJS = $(SRCMAIN:.c=.o) 
DEPS = $(SRCMAIN:.c=.d)

SRCBONUS = 	src/checker.c $(SRCS)

OBJBONUS = $(SRCBONUS:.c=.o)
DEPBONUS = $(SRCBONUS:.c=.d)

RM = rm -f

PS = libs/push_swap.h
LIBFT_DIR = libs/MyLibft
LIBFT =  libs/MyLibft/libft.a
LIBS = $(PS) $(LIBFT)
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(PS) Makefile
	@$(CC) $(CFLAGS) -MMD -g -I./ -c $< -o $@

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $@
	@echo "$(GREEN)push_swap compiled$(NC)"

$(NAME)::
	@echo -n

bonus:
	@$(MAKE) -C $(LIBFT_DIR) 
	@$(MAKE) $(BONUS)

$(BONUS):: $(OBJBONUS)
	@$(CC) $(OBJBONUS) $(LIBFT) -o $@
	@echo "$(GREEN)checker compiled$(NC)"
	
$(BONUS)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJBONUS) $(DEPBONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(BONUS) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(DEPBONUS)
