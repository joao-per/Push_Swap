# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:24:44 by joao-per          #+#    #+#              #
#    Updated: 2023/01/25 13:24:44 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atol ft_isdigit ft_neg_to_pos ft_putstr ft_strcmp ft_strlen is_sign

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
AR	= ar rcs

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:		$(NAME)

$(NAME): $(SRC:=.o)
			@$(AR) $(NAME) $(SRC:=.o)
			@echo "$(GREEN)Libft compiled $(MAGENTA)UwU!$(DEFAULT)"

bonus:		$(BONUS:=.o)
			@$(AR) $(NAME) $(BONUS:=.o)
			@echo "$(GREEN)Bonus compiled$(DEFAULT)"

clean:
			@$(RM)	$(SRC:=.o) $(BONUS:=.o)
			@echo "$(BLUE)objects awe cweean UwU!$(DEFAULT)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Evewithing is cweean!$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)I cweeaned and rebuilt evewithing for u daddy UwU!$(DEFAULT)"

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
