# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibault <thibault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 03:34:03 by thibault          #+#    #+#              #
#    Updated: 2023/11/24 16:16:21 by thibault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
SOURCES		=	.
OBJECTS		=	./bin
INCLUDES	=	

SRCS		=	

OBJS		=	$(addprefix ${OBJECTS}/, $(SRCS:.cpp=.o))

CC			=	g++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address -fsanitize=undefined
CINCLUDES	=	

BLACK		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;35m"
BLUE		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"

TOTAL_OBJS := $(words $(OBJS))
COMPILED_OBJS := 0

${OBJECTS}/%.o: ${SOURCES}/%.cpp
	@mkdir -p $(dir $@)
	@$(call print_progress, $(TOTAL_OBJS), $(COMPILED_OBJS))
	@$(CC) $(CFLAGS) -o $@ -c $< $(CINCLUDES)
	@$(eval COMPILED_OBJS=$(shell echo "$(COMPILED_OBJS)+1" | bc))

all: ${NAME}

${NAME}: ${OBJS} ${OBJECTS}/${NAME}.o
	@echo $(GREEN)"\n● Compilation of ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} ${CINCLUDES} -o ${NAME} ${OBJS} ${OBJECTS}/${NAME}.o

clean:
	@echo ${RED}"● Deletion of binary files (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Deletion of executables and libraries..."$(EOC)
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re