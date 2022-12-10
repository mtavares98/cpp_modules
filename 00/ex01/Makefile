SRC	= PhoneBook.cpp \
	  Contact.cpp \
	  main.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= phone

CC	= g++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -I.

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
