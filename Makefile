##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile that compiles a lib and more
##

CC 	=	gcc

SRC	=	lib/my_printf.c	\
		lib/my_put_nbr.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/str_to_array.c	\
		lib/my_strlen.c	\
		lib/my_str_cmp.c \
		lib/my_strcat.c	\
		lib/my_cut_startstr.c	\
		lib/cut_after_space.c	\
		lib/cutspace.c	\
		lib/my_strncmp.c	\
		lib/strcmp_custom.c	\
		lib/good_args_setenv.c	\
		lib/my_tab_strlen.c	\
		lib/my_str_cpy.c	\
		lib/replace_space_egal.c	\
		init_struct.c	\
		unsetenv.c	\
		my_exec.c	\
		path_execve.c	\
		conditions.c	\
		cd.c	\
		env.c	\
		main.c	\
		terminal.c	\
		getpwd.c	\

NAME    =   mysh

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Wno-unused-parameter -Wno-int-conversion

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
