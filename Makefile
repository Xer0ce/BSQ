##
## EPITECH PROJECT, 2022
## makefile
## File description:
## compiler librairie
##

RED = '\033[0;31m'
GREEN = '\033[0;32m'
WHITE = '\033[0;37m'
BLUE = '\033[0;34m'
YELLOW = '\033[0;33m'

SRC		=	    ./src/main.c \
				./src/bsq.c \
				./src/resolver.c \
				./src/generator_map.c \

OBJ		= 		$(SRC:.c=.o)

NAME	= 		libmy.a

NAMEBIN =		bsq

CFLAGS  = 		-I ./include/ -W -Wall -Wextra

NOPRINT = 	--no-print-directory

%.o: %.c
		@gcc -c $< -o $@ $(CFLAGS)

$(NAMEBIN):		$(OBJ)
		@echo -e $(BLUE)'         All:'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@make $(NOPRINT) -C ./lib/
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@echo -e $(RED)'    ['$(YELLOW)'BUILDING BSQ'$(RED)']'$(WHITE)
		@gcc -g3 $(OBJ) -o $(NAMEBIN) -L. $(NAME)
		@echo -e $(RED)'       ['$(YELLOW)'FINISH'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

all:			$(NAMEBIN)

clean:
		@echo -e $(BLUE)'        Clean:'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@rm -f $(OBJ)
		@echo -e $(RED)'      ['$(YELLOW)'REMOVE .o'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

fclean:     clean
		@echo -e $(BLUE)'     Force Clean:'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@echo -e $(RED)'     ['$(YELLOW)'REMOVE BSQ'$(RED)']'$(WHITE)
		@rm -f $(NAME)
		@rm -f $(NAMEBIN)
		@echo -e $(RED)'       ['$(YELLOW)'FINISH'$(RED)']'$(WHITE)
		@echo -e $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)
		@make fclean $(NOPRINT) -C ./lib/
		@echo -e  $(RED)'['$(YELLOW)'--------------------'$(RED)']'$(WHITE)

re:			fclean all

.PHONY : all clean fclean re
