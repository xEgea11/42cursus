NAME = libftprintf.a

SRC_FILE = src/
INCLUDE = include/

FILES = ft_printf.c  ft_printf_utils.c ft_hex.c

SRC = $(addprefix $(SRC_FILE), $(FILES) )

OBJS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS) 
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	@gcc $(CFLAGS) -c $(SRC) 

.PHONY : all clean fclean re

all : $(NAME)

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all