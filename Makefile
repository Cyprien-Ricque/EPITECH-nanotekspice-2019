##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.cpp	\
		src/nts.cpp	\
		src/simulate.cpp	\
		src/component_factory.cpp	\
		src/nts_error.cpp	\
		src/parser.cpp	\
		src/Input.cpp	\
		src/Output.cpp	\
		src/true.cpp	\
		src/false.cpp	\
		src/Clock.cpp	\
		src/2716.cpp	\
        src/4001.cpp	\
        src/4008.cpp	\
        src/4011.cpp	\
        src/4013.cpp	\
        src/4017.cpp	\
        src/4030.cpp	\
        src/4040.cpp	\
        src/4069.cpp	\
        src/4071.cpp	\
        src/4081.cpp	\
        src/4094.cpp	\
        src/4514.cpp	\
        src/4801.cpp

SRC_TEST	=	src/nts.cpp	\
                src/simulate.cpp	\
                src/component_factory.cpp	\
                src/nts_error.cpp	\
                src/parser.cpp	\
                src/Input.cpp	\
                src/Output.cpp	\
                src/true.cpp	\
                src/false.cpp	\
                src/Clock.cpp	\
                src/2716.cpp	\
                src/4001.cpp	\
                src/4008.cpp	\
               	src/4011.cpp	\
				src/4013.cpp	\
				src/4017.cpp	\
				src/4030.cpp	\
				src/4040.cpp	\
				src/4069.cpp	\
				src/4071.cpp	\
				src/4081.cpp	\
				src/4094.cpp	\
				src/4514.cpp	\
				src/4801.cpp	\
				tests/main_test.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-W -Wall -Wextra -I include

NAME	=	nanotekspice

all:	$(NAME)

debug:	CPPFLAGS += -g
debug:	all

debugre:	CPPFLAGS += -g
debugre:	re

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

tests_run:
	g++ $(SRC_TEST) -o tests_run -lgtest -lgtest_main -lpthread --coverage -I include
	./tests_run

re:	fclean all
