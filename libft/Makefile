# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:00:09 by inazaria          #+#    #+#              #
#    Updated: 2024/04/07 19:38:01 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
    

SRCS_LIBFT		=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_strrch.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c

SRCS = $(addprefix ./libft/, $(SRCS_LIBFT))

SRCS += ./get_next_line/get_next_line.c
SRCS += ./get_next_line/get_next_line_utils.c

SRCS += ./ft_printf/printf_utils/c_conversion.c
SRCS += ./ft_printf/printf_utils/d_and_i_conversions.c
SRCS += ./ft_printf/printf_utils/ft_putchar.c
SRCS += ./ft_printf/printf_utils/ft_putnbr.c
SRCS += ./ft_printf/printf_utils/ft_putstr.c
SRCS += ./ft_printf/printf_utils/length_of_num.c
SRCS += ./ft_printf/printf_utils/p_conversion.c
SRCS += ./ft_printf/printf_utils/s_conversion.c
SRCS += ./ft_printf/printf_utils/u_conversion.c
SRCS += ./ft_printf/printf_utils/x_and_X_conversions.c
SRCS += ./ft_printf/printf_utils/conversion_utils.c
SRCS += ./ft_printf/printf_utils/parsing_utils.c
SRCS += ./ft_printf/printf_utils/percent_conversion.c
SRCS += ./ft_printf/ft_printf.c

INC_DIR		= ./include/

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

BUFFER_SIZE     = 1024 
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I $(INC_DIR) -D BUFFER_SIZE=$(BUFFER_SIZE)

NAME			= libft.a

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
