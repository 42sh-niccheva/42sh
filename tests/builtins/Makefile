#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 10:17:09 by niccheva          #+#    #+#              #
#    Updated: 2016/07/01 17:01:58 by llapillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	test_builtins

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

DSOURCES		=	./sources/

DOBJECTS		=	./objects/

LIBFT			=	libraries/libft/
LIBLIST			=	libraries/liblist/
LIBREADLINE		=	libraries/libreadline/
LIBJSON			=	libraries/libjson/

INCLUDES		=	-I./includes/
INCLUDES		+=	-I../../includes/
INCLUDES		+=	-I../../$(LIBFT)includes/
INCLUDES		+=	-I../../$(LIBLIST)includes/
INCLUDES		+=	-I../../$(LIBREADLINE)includes/
INCLUDES		+=	-I../../$(LIBJSON)/includes/

LIBRARIES		=	-L../../build/$(LIBFT) -lft
LIBRARIES		+=	-L../../build/$(LIBLIST) -llist
LIBRARIES		+=	-L../../build/$(LIBREADLINE) -lreadline
LIBRARIES		+=	-L../../build/$(LIBJSON) -ljson

SOURCES			=	main.c
SOURCES			+=	cd.c
SOURCES			+=	echo.c
SOURCES			+=	env.c
SOURCES			+=	exit.c
SOURCES			+=	setenv.c
SOURCES			+=	unsetenv.c

OBJECTS			=	$(patsubst %.c, $(DOBJECTS)%.o, $(SOURCES))

DEPS			=	$(patsubst %.c, $(DOBJECTS)%.d, $(SOURCES))

DEPENDS			=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)

-include $(OBJECTS:.o=.d)

$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(DOBJECTS)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(DOBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
