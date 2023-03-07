# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:39:37 by joao-per          #+#    #+#              #
#    Updated: 2023/03/07 10:55:54 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variáveis

NAME		= push_swap
BONUS_NAME	= checker
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# Cores

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	index_and_pos.c input.c op1.c op2.c sorts.c stacks.c utils.c cost.c main.c libft/libft.a
BONUS_FILES	=	index_and_pos.c input.c op1.c op2.c sorts.c stacks.c utils.c cost.c libft/libft.a bonus/checker.c bonus/opb.c bonus/opb2.c
GNL			=	GNL/get_next_line_utils.c GNL/get_next_line.c


OBJ		= $(SRC_FILES:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME) 

$(NAME):
	@echo "$(YELLOW)Compiling Libft:"
	make -C $(LIBFT)
	@echo "$(MAGENTA)Compiling:"
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)
	@echo "$(GREEN)Push_swap compilled!$(DEFAULT)"

bonus: all $(BONUS_NAME)

$(BONUS_NAME):
	@echo "$(CYAN)Compiling Bonus:"
	$(CC) $(CFLAGS) $(BONUS_FILES) $(GNL) -o $(BONUS_NAME)
	
clean:
			@make clean -C $(LIBFT)

fclean:
			@make fclean -C $(LIBFT)
			@$(RM) -f $(NAME)
			@$(RM) -f $(BONUS_NAME)

re:			fclean all bonus
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap! $(RED)\nI'm your slave$(DEFAULT)"


test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l


.PHONY: all bonus clean fclean re test100 test500