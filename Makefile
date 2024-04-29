# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 21:59:03 by yoishi            #+#    #+#              #
#    Updated: 2024/04/29 17:43:30 by yoishi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NORMAL = ft_printf.c\
	src/ft_parse_args.c\
	src/put/ft_putstr.c\
	src/put/ft_putstrl.c\
	src/put/ft_putcharl.c\
	src/put/ft_putchar.c\
	src/put/ft_putnbr.c\
	src/conv/ft_put_conv.c\
	src/conv/ft_put_percent.c\
	src/conv/ft_put_c.c\
	src/conv/ft_put_s.c\
	src/conv/ft_put_p.c\
	src/conv/ft_put_i.c\
	src/conv/ft_put_u.c\
	src/conv/ft_put_x.c\
	src/utils/ft_get_digits.c
SRCS_BONUS = $(SRCS_NORMAL)

OBJS_NORMAL = $(SRCS_NORMAL:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

INCLUDES = include

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

ifdef IS_BONUS
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_NORMAL)
endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS) 
	@make -C $(LIBFT_PATH) all
	cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)make done$(DEF_COLOR)"

all: ${NAME}
	@echo "$(GREEN)make all done$(DEF_COLOR)"

bonus: 
	@make IS_BONUS=1 $(NAME)
	@echo "$(GREEN)make bonus done$(DEF_COLOR)"

clean:
	$(RM) $(OBJS_NORMAL) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean
	@echo "$(MAGENTA)make clean done$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "$(MAGENTA)make fclean done$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)make re done$(DEF_COLOR)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS_BONUS) $(INCLUDES)

# ==========FOR TESTER==========
printf:
	cc -Wno-format ../test/main.c  -o ../test/printf
ft_printf:
	cc -Wno-format ../test/main.c libftprintf.a -D FT_PRINTF -o ../test/ft_printf
test_clean:
	rm -f ../test/printf ../test/ft_printf
# ==========FOR TESTER==========

.PHONY: all clean fclean re bonus norm test_clean printf ft_printf
