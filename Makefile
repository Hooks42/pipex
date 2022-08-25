# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:47:28 by ceatgie           #+#    #+#              #
#    Updated: 2022/08/25 16:11:10 by ceatgie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	main.c\
			Libft/ft_putendl_fd.c\
			Libft/ft_split.c\
			Libft/ft_strchr.c\
			Libft/ft_strdup.c\
			Libft/ft_strjoin_free.c\
			Libft/ft_strjoin.c\
			Libft/ft_strlen.c\
			Libft/ft_strncmp.c\
			Pipex/ft_child_process.c\
			Pipex/ft_open_file.c\
			Pipex/ft_parent_process.c\
			Pipex/ft_pipex_core.c\
			Pipex/pipex.c\
			Utils/ft_execute.c\
			Utils/ft_free.c\
			Utils/ft_get_path.c\


OBJS= $(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re