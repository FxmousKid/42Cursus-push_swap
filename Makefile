# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:03:11 by inazaria          #+#    #+#              #
#    Updated: 2024/04/10 02:37:56 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOVESET_SRC_FILES = $(wildcard src/moveset/*.c)
STACK_SRC_FILES   = $(wildcard src/stack/*.c)
HELPERS_SRC_FILES = $(wildcard src/helper/*.c)

SRC_FILES   = $(MOVESET_SRC_FILES) $(STACK_SRC_FILES) $(HELPERS_SRC_FILES)
SRC_FILES   += src/main.c

OBJ_FILES   = $(SRC_FILES:.c=.o)

NAME        = push_swap
CC          = cc
BUFFER_SIZE = 1024
INCLUDE     = ./include/
CFLAGS      = -Wall -Wextra -Werror -g3 -I $(INCLUDE) -D BUFFER_SIZE=$(BUFFER_SIZE)
RM          = rm -f


ERASE		= $(shell echo -e "\033[2K\r")
BLUE		= $(shell echo -e "\033[34m") 
YELLOW		= $(shell echo -e "\033[33m")
GREEN		= $(shell echo -e "\033[32m")
END			= $(shell echo -e "\033[0m")


.c.o :
	@echo "$(YELLOW)Compiling obj files...$(END)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled obj files !$(END)"
 
all : $(NAME)

libft :
	@$(MAKE) --no-print-directory -C ./libft

	
$(NAME): libft $(OBJ_FILES)
	@echo "$(ERASE)$(YELLOW)Compiling push_swap...$(END)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) libft/libft.a
	@echo "$(ERASE)$(GREEN)Compiled push_swap ! $(END)"

fclean : 
	@echo "$(ERASE)$(YELLOW)Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES)
	@echo "$(ERASE)$(YELLOW)Deleting push_swap...$(END)"
	@$(RM) $(NAME)
	@echo "$(ERASE)$(YELLOW)Deleting libft obj files...$(END)"
	@echo "$(ERASE)$(YELLOW)Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "$(ERASE)$(GREEN)Deleted all files !$(END)"

clean :
	@echo "$(ERASE)$(YELLOW)Deleting push_swap obj files...$(END)"
	$(RM) $(OBJ_FILES)
	@echo "$(ERASE)$(YELLOW)Deleting libft obj files...$(END)"
	$(MAKE) --no-print-directory -C ./libft clean
	@echo "$(ERASE)$(GREEN)Deleted all obj files !$(END)"

re : fclean all

.PHONY: all clean fclean re libft
