#!/bin/bash

echo -n "SRC	=" > Makefile
bol=0
for i in "$@"
do
	if [ $bol -eq 0 ]
	then
		bol=$(($bol + 1))
	else
		echo -n "	" >> Makefile
	fi
	echo "	$i.cpp \\" >> Makefile
done
echo "		main.cpp" >> Makefile

echo "" >> Makefile
echo 'OBJ	=	$(SRC:.cpp=.o)' >> Makefile

echo "Enter the name of the program: "
read NAME

echo "" >> Makefile
echo "NAME	=	$NAME" >> Makefile
echo "CC	=	g++" >> Makefile
echo "CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I. -g -fsanitize=address" >> Makefile
echo "" >> Makefile

echo 'all:	$(NAME)' >> Makefile
echo "" >> Makefile
echo '$(NAME):	$(OBJ)' >> Makefile
echo '	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)' >> Makefile
echo '' >> Makefile
echo '%.o:	%.cpp' >> Makefile
echo '	$(CC) $(CFLAGS) -c $< -o $@' >> Makefile
echo 'clean:' >> Makefile
echo '	rm -rf $(OBJ)' >> Makefile
echo "" >> Makefile
echo 'fclean:	clean' >> Makefile
echo '	rm -rf $(NAME)' >> Makefile
echo "" >> Makefile
echo "re:	fclean all" >> Makefile
echo "" >> Makefile
echo '.PHONY:	all clean fclean re' >> Makefile
