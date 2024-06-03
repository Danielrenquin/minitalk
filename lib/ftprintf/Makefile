SRC =	ft_cspdiuxX.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsigned.c ft_hexa.c ft_hexaup.c ft_ptr.c \

OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs
all: ${NAME}
#%.o: %.c
#	${CC} ${CFLAGS} -c -o $@ $< 
${NAME}: ${OBJ} 
	${LIBC} ${NAME} ${OBJ}
clean:
	${RM} ${OBJ}
fclean: clean
	${RM} ${NAME}
re: fclean all
	
.PHONY : ${NAME} all clean fclean re

