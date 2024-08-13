# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:03:11 by inazaria          #+#    #+#              #
#    Updated: 2024/08/14 00:30:53 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>

SRC_DIR		= ./src/
BUILD_DIR	= ./build/

MOVES_SRC_DIR			= moves/
MOVES_SRC_FILES_NAMES	= push.c
MOVES_SRC_FILES_NAMES	+= push_no_print.c
MOVES_SRC_FILES_NAMES	+= rotate.c	
MOVES_SRC_FILES_NAMES	+= rotate_no_print.c	
MOVES_SRC_FILES_NAMES	+= reverse_rotate.c
MOVES_SRC_FILES_NAMES	+= reverse_rotate_no_print.c
MOVES_SRC_FILES_NAMES	+= swap.c
MOVES_SRC_FILES_NAMES	+= swap_no_print.c
MOVES_SRC_FILES = $(addprefix $(MOVES_SRC_DIR), $(MOVES_SRC_FILES_NAMES))

RADIX_SRC_DIR			= radix_sort/
RADIX_SRC_FILES_NAMES	= radix_sort.c
RADIX_SRC_FILES_NAMES	+= stack_utils.c
RADIX_SRC_FILES_NAMES	+= utils.c
RADIX_SRC_FILES			= $(addprefix $(RADIX_SRC_DIR), $(RADIX_SRC_FILES_NAMES))

SRC_FILES_NAMES	= $(RADIX_SRC_FILES)
SRC_FILES_NAMES	+= $(MOVES_SRC_FILES)

# Full path to .c files
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_FILES_NAMES))

# .o files for compialtion
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

# .d files for header and source dependency
DEP_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.d, $(SRC_FILES))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

CHECKER     = checker
NAME        = push_swap
CC          = clang
INCLUDE     = ./include/
CFLAGS      = -Wall -Wextra -Werror -g3 -I $(INCLUDE) -MMD -MP
MKDIR		= mkdir -p
ECHO		= echo -e


BLUE		= $(shell echo -e "\033[34m") 
YELLOW		= $(shell echo -e "\033[33m")
GREEN		= $(shell echo -e "\033[32m")
END			= $(shell echo -e "\033[0m")


libft :
	@$(MAKE) --no-print-directory -C ./libft


$(BUILD_DIR)%.o : $(SRC_DIR)%.c | libft
	@$(MKDIR) $(dir $@)
	@echo -e "$(BLUE)[CMP] Compiling $< ...$(END)" 
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP_FILES) build/push_swap.d build/checker.d

all : $(NAME)

	
$(NAME): $(OBJ_FILES)
	@echo -e "$(BROWN)[BLD] Building push_swap executable...$(NC)"
	@$(CC) $(CFLAGS) -c src/push_swap.c -o build/push_swap.o
	@$(CC) $(CFLAGS) $^ build/push_swap.o  libft/libft.a -o $(NAME)
	@echo -e "$(GREEN)[BLD] Executable built successfully.$(NC)"

$(CHECKER) : $(OBJ_FILES)
	@echo -e "$(BROWN)[BLD] Building checker executable...$(NC)"
	@$(CC) $(CFLAGS) -c src/checker.c -o build/checker.o
	@$(CC) $(CFLAGS) $^ builf/checker.o libft/libft.a -o $(CHECKER)
	@echo -e "$(GREEN)[BLD] Executable built successfully.$(NC)"

fclean : 
	@echo -e "$(YELLOW)[CLN] Deleting push_swap obj files...$(END)"
	@$(RM) $(OBJ_FILES) build/push_swap.[od] build/checker.[od]
	@echo -e "$(YELLOW)[CLN] Deleting push_swap dependency files...$(END)"
	@$(RM) $(DEP_FILES)  
	@echo -e "$(YELLOW)[CLN] Deleting push_swap...$(END)"
	@$(RM) $(NAME)
	@echo -e "$(YELLOW)[CLN] Deleting checker...$(END)"
	@$(RM) $(CHECKER)
	@echo -e "$(YELLOW)[CLN] Deleting libft obj files...$(END)"
	@echo -e "$(YELLOW)[CLN] Deleting libft.a...$(END)"
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo -e "$(GREEN)[CLN] Deleted all files !$(END)"

clean :
	@echo -e "$(YELLOW)[CLN] Deleting push_swap object files...$(END)"
	@$(RM) $(OBJ_FILES) build/push_swap.[od] build/checker.[od] 
	@echo -e "$(YELLOW)[CLN] Deleting push_swap dependency files...$(END)"
	@$(RM) $(DEP_FILES)  
	@echo -e "$(YELLOW)[CLN] Deleting libft obj files...$(END)"
	@$(MAKE) --no-print-directory -C ./libft clean
	@echo -e "$(GREEN)[CLN] Deleted all obj files !$(END)"

re : fclean all

.DEFAULT_GOAL=all
.PHONY: all clean fclean re libft
