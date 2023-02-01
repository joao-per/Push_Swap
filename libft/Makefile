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

SRC = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
ft_substr ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr \
ft_strrchr ft_strdup ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_strchr\
ft_tolower ft_toupper \
ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
ft_atoi ft_bzero ft_calloc ft_split ft_itoa \

BONUS = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstnew \
ft_lstlast ft_lstiter ft_lstsize ft_lstmap \

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

OBJSF		=	.cache_exists

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
