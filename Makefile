##
## EPITECH PROJECT, 2019
## makefile
## File description:
## return
##

SRC =	main.c							\
		src/my_principal.c				\
		src/my_pressed.c				\
		src/my_first_round_map.c		\
		src/my_perline_noise.c			\
		src/my_second_round.c			\
		src/draw_buttons.c				\
		src/make_mountains.c			\

NAME = my_world

FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all: $(SRC)
	gcc -o $(NAME) $(SRC) $(FLAGS)

val: $(SRC)
	gcc -o $(NAME) $(SRC) $(FLAGS) -g

clean:
		@rm -f vgcore*

fclean: clean
		@rm -f $(NAME)

re: fclean all
