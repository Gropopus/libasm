# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 11:22:21 by user42            #+#    #+#              #
#    Updated: 2021/03/31 14:38:38 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE=\e[1;33m
GREEN=\e[1;32m
RED=\e[1;31m
NC=\e[0m

SRCS		=	./srcs/ft__strlen.s\
			./srcs/ft__strcpy.s\
			./srcs/ft__strcmp.s\
			./srcs/ft__strdup.s\
			./srcs/ft__read.s\
			./srcs/ft__write.s\

CC		=	clang

NASM		=	nasm

ASMFLAG		=	-f elf64

CFLAG		= 	-Wall -Wextra -Werror

OBJS		=	${SRCS:.s=.o}

NAME		=	libasm.a

RM		=	rm -rf

.s.o:	
	@echo "${ORANGE}"
	@${NASM} ${ASMFLAG} $< -o ${<:.s=.o}
	@echo "${<:.s=.o} ${GREEN}	[ OK ]${NC}"

${NAME}:	${OBJS}	
		@ar -rc libasm.a ${OBJS}
		@echo "${GREEN}"
		ranlib ${NAME}
		@echo "${NC}"

all:		${NAME}

clean:		
		@${RM} ${OBJS}
		@echo "${RED}*.o files deleted${GREEN}	[ ok ]${NC}"

fclean:		clean
		@${RM} ${NAME}
		@echo "${RED}libasm.a  deleted	${GREEN}[ ok ]${NC}"

re:		fclean all

.PHONY:		all clean fclean re
