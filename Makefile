##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME_EXE = my_paint

SRC_GC = 		$(wildcard lib/malloc_checks/*.c)

SRC_CSFML = 	$(wildcard lib/CSFML/*.c)

SRC_C_LIB = 	$(wildcard lib/C_LIB/*.c)

SRC_C_FOLDERS = $(wildcard src/init/*.c) $(wildcard src/error_handling/*.c)

SRC_C = 		$(wildcard src/*.c) $(wildcard src/buttons/*.c) \
				$(wildcard src/file_gui/*.c)

SRC = 			$(SRC_GC) $(SRC_CSFML) $(SRC_C_LIB) $(SRC_C_FOLDERS) $(SRC_C)

OBJ	=			$(SRC:.c=.o)

CFLAGS = 		$(I_FLAGS) $(CSFML_FLAGS) -Wall -Wextra -lm

CSFML_FLAGS = 	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

I_FLAGS = 		-I./include/ -g

all: 			$(NAME_EXE)

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME_EXE)

$(NAME_EXE):	$(OBJ)
				gcc $(OBJ) -o $(NAME_EXE) $(CFLAGS)

debug: 			fclean
				gcc $(SRC) -g -o $(NAME_EXE) $(CFLAGS)

re: 			fclean all