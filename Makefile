# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jestevao <jestevao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 19:24:04 by jestevao          #+#    #+#              #
#    Updated: 2023/12/19 11:14:57 by jestevao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = /bin/rm -f

INCS_DIR    = ./includes
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

BUILD_DIR   = build
SRC_DIR     = ./srcs
SRCS        = 	ft_printf.c \
					ft_format_tools.c \
					ft_convert_cdsxp.c \
					ft_convert_utype.c \
					ft_special_format.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus


test: re
	@$(CC) $(CFLAGS) main.c -L. -lftprintf -L$(LIBFT_DIR) -lft -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@./runner.out

testmem: re
	@$(CC) $(CFLAGS) main.c -L. -lftprintf -L$(LIBFT_DIR) -lft -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./runner.out

.PHONY: all clean fclean re bonus test testmem
