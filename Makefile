# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:39:37 by joao-per          #+#    #+#              #
#    Updated: 2023/03/01 17:07:30 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variáveis

NAME		= push_swap
LIBFT		= libft
CC			= gcc
CFLAGS		= -g
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

SRC_FILES	=	index_and_pos.c input.c main.c op1.c op2.c sorts.c stacks.c utils.c cost.c


OBJ		= $(SRC_FILES:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME) 

$(NAME):
	@echo "$(YELLOW)Compiling:"
	make -C $(LIBFT)
	@echo "$(MAGENTA)Compiling:"
	$(CC) $(CFLAGS) $(SRC_FILES) libft/libft.a -o $(NAME)
	@echo "$(GREEN)Push_swap compilled!$(DEFAULT)"

clean:
			@make clean -C $(LIBFT)

fclean:
			@make fclean -C $(LIBFT)
			@$(RM) -f $(NAME)

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap! $(RED)\nI'm your slave$(DEFAULT)"

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000