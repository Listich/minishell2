##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## bsls
##


NAME = mysh

SRC = main.c\
	my_str_to_word_array.c\
	complexe_command.c\
	alpha_numeric.c\
	pipe_command.c\
	isbuilding.c\
	get_env.c\
	setenv.c\
	redirection.c\
	my_unsetenv.c\
	allocate.c\
	implementation_cd.c\
	remove_space.c\
	my_signal.c

OBJ = $(SRC:.c=.o)

CFLAGS +=  -g3 -Wall -Wextra

all: $(NAME)

clean:
		find . -type f -name '*~' -delete
		find . -type f -name '#*#' -delete
		find . -type f -name '*.o' -delete

fclean: clean
		rm -f $(NAME)
		rm -f a.out

re: fclean all

$(NAME) : $(OBJ)
			make -C lib/
			gcc -o $(NAME) $(OBJ) -L./ -lmy

.PHONY : all re fclean clean
