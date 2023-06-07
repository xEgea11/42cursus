NAME = pipex

FILES = test.c 
OBJS = $(FILES.c=.o)

LIB = libft/libft.a

CFLAGS = -Wall -Werror -Wextra 

$(NAME) : $(FILES) $(LIB)
	$(CC)  $(CFLAGS) $(FILES) $(LIB) -o $(NAME) 

$(LIB) :
	make -sC libft/



.PHONY : all clean fclean re

all: $(NAME)

clean : 
	rm -f *.o 
fclean: clean
	rm -f $(NAME)

re : fclean all 