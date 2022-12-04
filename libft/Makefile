NAME = libft.a

SRC = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr\
ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr\
ft_substr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum\
ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc ft_strdup\
ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_itoa ft_split\
is_digit is_sign nbr_cmp abs_vl ft_putstr ft_strcmp\

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\

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
			@echo "$(GREEN)Libft compiled $(MAGENTA)daddy UwU!$(DEFAULT)"

clean:
			@$(RM)	$(SRC:=.o)
			@echo "$(BLUE)objects awe cweean UwU!$(DEFAULT)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)Evewithing is cweean!$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)I cweeaned and rebuilt evewithing for u daddy UwU!$(DEFAULT)"

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
