# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:03:11 by inazaria          #+#    #+#              #
#    Updated: 2024/04/16 03:36:30 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOVESET_SRC_FILES     = $(wildcard src/moveset/*.c)
STACK_SRC_FILES       = $(wildcard src/stack/*.c)
HELPERS_SRC_FILES     = $(wildcard src/helper/*.c)
STUPID_SORT_SRC_FILES = $(wildcard src/stupid_sort/*.c)
SMART_SORT_SRC_FILES  = $(wildcard src/smart_sort/*.c)

SRC_FILES   = $(STACK_SRC_FILES)
SRC_FILES   += $(HELPERS_SRC_FILES)
SRC_FILES   += $(MOVESET_SRC_FILES)
SRC_FILES   += $(STUPID_SORT_SRC_FILES)
SRC_FILES   += $(SMART_SORT_SRC_FILES)

OBJ_FILES   = $(SRC_FILES:.c=.o)

NAME        = push_swap
CHECKER     = checker
CC          = gcc
BUFFER_SIZE = 1024
INCLUDE     = ./include/
CFLAGS      = -Wall -Wextra -Werror -g3 -I $(INCLUDE) -D BUFFER_SIZE=$(BUFFER_SIZE) -Wno-unknown-warning-option
ifeq ($(shell ls /usr/local/bin/egypt | wc -l ), 1)
	CFLAGS += -fdump-rtl-expand
endif
RM          = rm -f


BLUE		= $(shell echo -e "\033[34m") 
YELLOW		= $(shell echo -e "\033[33m")
GREEN		= $(shell echo -e "\033[32m")
END			= $(shell echo -e "\033[0m")

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@
 
all : $(NAME) checker call_graph

call_graph: libft $(OBJ_FILES)
ifeq ($(shell ls /usr/local/bin/egypt | wc -l ), 1)
	@echo "$(YELLOW)Creating call graph...$(END)"
	@egypt push_swap*.expand src/smart_sort/*.expand src/stack/*.expand | dot -Gsize=11,8.5 -Tpdf -o callgrpah_push_swap.pdf
	@echo "$(GREEN)Created call graph !$(END)"
endif

libft :
	@$(MAKE) --no-print-directory -C ./libft

	
$(NAME): libft $(OBJ_FILES)
	@echo "$(YELLOW)Compiling push_swap...$(END)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) src/push_swap.c -o $(NAME) libft/libft.a
	@echo "$(GREEN)Compiled push_swap ! $(END)"


checker: libft $(OBJ_FILES)
	@echo "$(YELLOW)Compiling checker...$(END)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) src/checker.c -o $(CHECKER) libft/libft.a
	@echo "$(GREEN)Compiled checker ! $(END)"

fclean : 
	@echo "$(YELLOW)Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES) src/push_swap.o src/checker.o
	@echo "$(YELLOW)Deleting push_swap...$(END)"
	@$(RM) $(NAME)rm 
	@echo "$(YELLOW)Deleting checker...$(END)"
	@$(RM) $(CHECKER)
	@echo "$(YELLOW)Deleting .rtl files...$(END)"
	@$(RM) */*/*.expand
	@$(RM) */*.expand
	@$(RM) *.expand
	@echo "$(YELLOW)Deleting call graph...$(END)"
	@$(RM) callgrpah_push_swap.pdf
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@echo "$(YELLOW)Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "$(GREEN)Deleted all files !$(END)"

clean :
	@echo "$(YELLOW)Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES) src/push_swap.o src/checker.o
	@echo "$(YELLOW)Deleting .rtl files...$(END)"
	@$(RM) */*/*.expand
	@$(RM) */*.expand
	@$(RM) *.expand
	@echo "$(YELLOW)Deleting call graph...$(END)"
	@$(RM) callgrpah_push_swap.pdf
	@echo "$(YELLOW)Deleting libft obj files...$(END)"
	@$(MAKE) --no-print-directory -C ./libft clean
	@echo "$(GREEN)Deleted all obj files !$(END)"

re : fclean all

.PHONY: all clean fclean re libft
