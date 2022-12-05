# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:39:37 by joao-per          #+#    #+#              #
#    Updated: 2022/12/05 12:23:50 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variáveis

NAME		= push_swap
OUTPUT		= checker
GNLFILE		= getnl
LIBFT		= libft
SRC_DIR		= src/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

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

SRC_FILES	=	start_stack.c input_checker.c main.c move_counter.c moves.c self_esteem.c position.c push.c rotate.c reverse_rotate.c sort.c stacks.c swap.c utils.c
GNS			=	gnl/get_next_line

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		= $(SRC_FILES:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME) 

$(NAME):
	@echo "$(YELLOW)Compiling:"
	make -C $(LIBFT)
	@echo "$(MAGENTA)Compiling:"
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)
	@echo "$(GREEN)Push_swap compiled!$(DEFAULT)"
bonus:	$(OUTPUT)
$(OUTPUT):
			@echo "$(YELLOW)Compiling:"
			make -C $(LIBFT)
			@echo "$(MAGENTA)Compiling BONUS:"
			gcc src/checker.c libft/libft.a src/input_checker.c src/move_counter.c src/moves.c src/position.c src/push.c src/reverse_rotate.c src/rotate.c src/self_esteem.c src/sort.c src/stacks.c src/start_stack.c src/swap.c src/utils.c src/abs_vl.c src/checker_utils.c gnl/get_next_line.c libft/is_sign.c libft/ft_atoi.c libft/ft_strdup.c libft/nbr_cmp.c libft/is_digit.c libft/ft_strlen.c -o $(OUTPUT)
clean:
			@make clean -C $(LIBFT)

fclean:
			@make fclean -C $(LIBFT)
			@$(RM) -f $(NAME)
			@$(RM) -f $(OUTPUT)

re:			fclean all bonus
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap! $(RED)\nI'm your slave$(DEFAULT)"
			@echo "I also did your bonus btw"

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

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

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

#gcc checker.c ../libft/libft.a input_checker.c move_counter.c moves.c position.c push.c reverse_rotate.c rotate.c self_esteem.c sort.c stacks.c start_stack.c swap.c utils.c abs_vl.c checker_utils.c ../gnl/get_next_line.c ../libft/is_sign.c ../libft/ft_atoi.c ../libft/ft_strdup.c ../libft/nbr_cmp.c ../libft/is_digit.c ../libft/ft_strlen.c -o checker

.PHONY: all clean fclean bonus re test2 test3 test5 test100 test500 test1000