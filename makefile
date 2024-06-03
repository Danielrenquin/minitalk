# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenquin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:38:26 by drenquin          #+#    #+#              #
#    Updated: 2024/06/03 17:39:08 by drenquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#	Makefile variables
################################################################################

CC		=	clang
FLAGWS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	/bin/rm -f

################################################################################
#	Compilation Client/Serveur "Mandatory"
################################################################################

OBJS_DIR	=	./


C_NAME		=	client
C_OBJS		=	$(addprefix $(OBJS_DIR), $(C_FILES:.c=.o))

C_FILES		=	client.c \


S_NAME		=	server
S_OBJS		=	$(addprefix $(OBJS_DIR), $(S_FILES:.c=.o))

S_FILES		=	server.c \

################################################################################
#	Compilation Libft
################################################################################

LIBFT_DIR	=	./lib/libft

################################################################################
#	Compilation printf
################################################################################

PRINTF_DIR	=	./lib/ftprintf

################################################################################
#	Lib
################################################################################

LIB		=	-L$(LIBFT_DIR) -lft \
			-L$(PRINTF_DIR) -lftprintf \
			
################################################################################
#	Colors
################################################################################

NO_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m
RED = \033[0;31m

################################################################################
#	Rules
################################################################################

all:	$(LIBFT_DIR)/libft.a \
		$(PRINTF_DIR)/libftprintf.a \
		$(C_NAME) \
		$(S_NAME)

$(C_NAME): $(C_OBJS)
	@$(CC) $(FLAGWS) -o $(C_NAME) $(C_OBJS) $(LIB)
	@echo "$(GREEN)$(C_NAME) compiled!$(NO_COLOR)"

$(S_NAME): $(S_OBJS)
	@$(CC) $(FLAGWS) -o $(S_NAME) $(S_OBJS) $(LIB)
	@echo "$(GREEN)$(S_NAME) compiled!$(NO_COLOR)"
	@echo "$(RED)READY TO LAUNCH$(NO_COLOR)"

%.o: %.c
	@$(CC) $(FLAGWS) -c -o $@ $<
	@echo "$(YELLOW)Compiling: $< $(NO_COLOR)"

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -sC $(LIBFT_DIR)
	
$(PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -sC $(PRINTF_DIR)

clean:
	@$(RM) $(C_OBJS) $(S_OBJS)
	@echo "$(BLUE)object files cleaned!$(NO_COLOR)"
	@echo ""

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	@$(RM) $(C_NAME) $(S_NAME)
	@echo "$(CYAN)all executable files cleaned!$(NO_COLOR)"
	@echo ""

re: fclean all
	@echo "$(GREEN)all RE compiled!$(NO_COLOR)"

.PHONY: all clean fclean re

