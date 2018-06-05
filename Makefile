# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anesteru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 15:37:28 by anesteru          #+#    #+#              #
#    Updated: 2018/01/05 15:37:34 by anesteru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC_FILES	=	ft_printf.c \
				put_csid.c \
				put_base.c \
				parse_flags.c \
				put_unic.c \
				put_unistr.c \
				flager_c.c \
				flager_for_di.c \
				chek_my_mod.c \
				unsignum.c \
				flager_point.c \
				colors.c \
				flager_for_base_two.c \

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

INC_DIR		=	./includes/
SRC_DIR		=	./src/
OBJ_DIR		= 	./object_files/

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mMISSION COMPLETE\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\033[33mObjects and libftprintf.a are removed\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mFT_PRINTF is removed\033[0m"

re: fclean all

.PHONY: all clean fclean re
