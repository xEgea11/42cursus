NAME = fractol.out

FILES = main.c mandelbrot.c print_utils.c
OBJS = $(FILES.c=.o);
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
LIB = ./MLX42
LINK =  -ldl -lglfw -pthread -lm $(LIB)/libmlx42.a -L "/Users/regea-go/.brew/opt/glfw/lib/"

	
$(NAME) : 
	make -sC $(LIB)
	$(CC) $(FILES) $(LINK) -o $(NAME)


.PHONY : all clean fclean re exec libmlx

all : $(NAME)

clean :
	@rm -f fractol.out
	@echo "Ejecutable eliminado"

fclean : clean

re : fclean all 

exec : re
	@echo "Ejecutando programa..."
	@./fractol.out mandelbrot