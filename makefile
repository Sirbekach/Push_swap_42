# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 15:13:44 by ybekach           #+#    #+#              #
#    Updated: 2024/09/15 12:58:05 by ybekach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC =  ft_sorting.c push_operation.c read_arguments.c rrotate_operation.c parsing_tools.c\
  	 list_utils.c rotate_operation.c swap_operation.c sort_more.c sort_list_utils.c\

OBJ = $(SRC:.c=.o)

MAIN = main.c \

MAIN_OBJ = $(MAIN:.c=.o)

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a


$(NAME): $(OBJ) $(MAIN_OBJ)
	@echo "\n===============Compiling Libft=================\n"
	make -C libft
	@echo "\n===============LIBFT SUCCESS!!==================\n" 
	@echo "\n===============Compiling ft_printf==============\n" 
	make -C ft_printf
	@echo "\n===============FT_PRINTF SUCCESS!!================\n" 
	@echo "\n===============Compiling push_swap================\n" 
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\n===============PUSH_SWAP SUCCES===================\n" 

all: $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	@echo "\n==============Objects Cleaned=================\n" 

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)
	@echo "\n================EXE Cleaned=====================\n" 

re:	fclean all

.PHONY: clean 