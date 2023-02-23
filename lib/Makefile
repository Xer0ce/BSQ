##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

RED = '\033[0;31m'
GREEN = '\033[0;32m'
WHITE = '\033[0;37m'
BLUE = '\033[0;34m'
YELLOW = '\033[0;33m'

SRC =	my_putstr.c \
		str_to_word_array.c \
		my_putchar.c \
		my_strlen.c \
		my_atoi.c \
		my_strcat.c \
		my_strcpy.c \

OBJ = 	$(SRC:.c=.o)

HEADER =	my.h

NAME =		libmy.a

%.o: %.c
	@gcc -c $< -o $@ $(CFLAGS)

$(NAME):	$(OBJ)
	@echo -e $(RED)'  ['$(YELLOW)'BUILDING LIBRARY'$(RED)']'$(WHITE)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@cp my.h ../include
	@rm $(NAME)
	@echo -e $(RED)'       ['$(YELLOW)'FINISH'$(RED)']'$(WHITE)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f libmy.a
	@echo -e $(RED)'   ['$(YELLOW)'REMOVE LIBRARY'$(RED)']'$(WHITE)

re: fclean all

.PHONY : all clean fclean re
