# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 21:02:06 by merlich           #+#    #+#              #
#    Updated: 2022/01/21 22:57:00 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

# srcs / objs / .d files

SRCS	=	main.c ft_draw.c fdf_utils.c ft_atoi.c \
			ft_read_file.c ft_hex_atoi.c ft_split.c ft_strtrim.c \
			get_next_line.c get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

D_FILES	=	${SRCS:.c=.d}

# compiler

CLANG	=	clang

CFlAGS	=	-Wall -Wextra -Werror -MD -D BUFFER_SIZE=1024

RM		=	rm -rf

# directories

SRCSDIR	=	./src/

# rules

%.o:	${SRCSDIR}%.c 
	$(CLANG) $(CFlAGS) -Imlx -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
	$(CLANG) ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

-include ${D_FILES}

clean:
	${RM} ${OBJS} ${D_FILES}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
