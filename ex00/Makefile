# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 09:02:49 by jrinna            #+#    #+#              #
#    Updated: 2022/10/11 12:56:49 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

LST_SRC := main.cpp
LST_INC := main.hpp
LST_OBJ := ${LST_SRC:.cpp=.o}

DIR_SRC := source
DIR_INC := include
DIR_OBJ := .object

SRC := ${addprefix ${DIR_SRC}/,${LST_SRC}}
INC := ${addprefix ${DIR_INC}/,${LST_INC}}
OBJ := ${addprefix ${DIR_OBJ}/,${LST_OBJ}}

CC := c++ -std=c++98
CFLAGS := -Wall -Wextra -Werror #-fsanitize=address -g3
NAME := convertor_3000

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${DIR_OBJ}/%.o : ${DIR_SRC}/%.cpp ${INC} Makefile | ${DIR_OBJ}
	${CC} ${CFLAGS} -c $< -o $@ -I ${DIR_INC}

${DIR_OBJ} :
	mkdir -p ${DIR_OBJ}

clean :
	rm -rf ${DIR_OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all re clean fclean
