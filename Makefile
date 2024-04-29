# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:03:11 by inazaria          #+#    #+#              #
#    Updated: 2024/04/29 13:56:50 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOVES_SRC_FILES       = $(wildcard src/moves/*.c)
RADIX_SORT_SRC_FILES  = $(wildcard src/radix_sort/*.c)

SRC_FILES   = $(RADIX_SORT_SRC_FILES)
SRC_FILES   += $(MOVES_SRC_FILES)

OBJ_FILES   = $(SRC_FILES:.c=.o)

CHECKER     = checker
NAME        = push_swap
CC          = gcc
INCLUDE     = ./include/
CFLAGS      = -Wall -Wextra -Werror -g3 -I $(INCLUDE) -Wno-unknown-warning-option
RM          = rm -f


BLUE		= $(shell echo -e "\033[34m") 
YELLOW		= $(shell echo -e "\033[33m")
GREEN		= $(shell echo -e "\033[32m")
END			= $(shell echo -e "\033[0m")

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@
 
all : $(NAME)

libft :
	@$(MAKE) --no-print-directory -C ./libft

	
$(NAME): libft $(OBJ_FILES)
	@echo "$(YELLOW)Compiling push_swap...$(END)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) src/push_swap.c -o $(NAME) libft/libft.a
	@echo "$(GREEN)Compiled push_swap ! $(END)"

$(CHECKER) : libft $(OBJ_FILES)
	@echo "$(YELLOW)Compiling checker...$(END)"
	@$(CC) $(CFLAGS) $(OBJ_FILES)  src/checker.c -o $(CHECKER) libft/libft.a
	@echo "$(GREEN)Compiled checker ! $(END)"

fclean : 
	@echo "$(YELLOW)Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES) src/push_swap.o src/checker.o
	@echo "$(YELLOW)Deleting push_swap...$(END)"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Deleting checker...$(END)"
	@$(RM) $(CHECKER)
	@echo "$(YELLOW) Deleting libft obj files...$(END)"
	@echo "$(YELLOW)Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "$(GREEN)Deleted all files !$(END)"

clean :
	@echo "$(YELLOW)Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES) src/push_swap.o src/checker.o
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@$(MAKE) --no-print-directory -C ./libft clean
	@echo "$(GREEN)Deleted all obj files !$(END)"

re : fclean all

.PHONY: all clean fclean re libft
