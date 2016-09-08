#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 10:17:09 by niccheva          #+#    #+#              #
#    Updated: 2016/09/08 14:33:22 by llapillo         ###   ########.fr        #
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
#LIBJSON			=	libraries/libjson/

INCLUDES		=	-I./includes/
INCLUDES		+=	-I../../includes/
INCLUDES		+=	-I../../$(LIBFT)includes/
INCLUDES		+=	-I../../$(LIBLIST)includes/
INCLUDES		+=	-I../../$(LIBREADLINE)includes/
INCLUDES		+=	-I../../$(LIBJSON)/includes/

LIBRARIES		=	-L../../build/$(LIBFT) -lft
LIBRARIES		+=	-L../../build/$(LIBLIST) -llist
LIBRARIES		+=	-L../../build/$(LIBREADLINE) -lreadline
#LIBRARIES		+=	-L../../build/$(LIBJSON) -ljson

SRCSHDIR		=	../../sources/

CDPATH			=	builtins/cd/
ECHOPATH		=	builtins/echo/
ENVPATH			=	builtins/env/
EXITPATH		=	builtins/exit/
SETENVPATH		=	builtins/setenv/
UNSETENVPATH	=	builtins/unsetenv/

CD				=	$(CDPATH)builtin_cd.c

ECHO			=	$(ECHOPATH)builtin_echo.c

ENV				=	$(ENVPATH)builtin_env.c

EXIT			=	$(EXITPATH)builtin_exit.c

SETENV			=	$(SETENVPATH)builtin_setenv.c
SETENV			+=	$(SETENVPATH)builtin_setenv_add_key.c
SETENV			+=	$(SETENVPATH)builtin_setenv_add_value.c

UNSETENV		=	$(UNSETENVPATH)builtin_unsetenv.c

#BUILTINS		=	$(CD)
#BUILTINS		+=	$(ECHO)
#BUILTINS		+=	$(ENV)
#BUILTINS		+=	$(EXIT)
BUILTINS		=	$(SETENV)
#BUILTINS		+=	$(UNSETENV)


SRCSH			=	$(BUILTINS)

SOURCES			=	main.c
SOURCES			+=	cd.c
SOURCES			+=	echo.c
SOURCES			+=	env.c
SOURCES			+=	exit.c
SOURCES			+=	setenv.c
SOURCES			+=	unsetenv.c

OBJECTS			=	$(patsubst %.c, $(DOBJECTS)%.o, $(SOURCES))

OBJSH			=	$(patsubst %.c, $(DOBJECTS)%.o, $(SRCSH))

DEPS			=	$(patsubst %.c, $(DOBJECTS)%.d, $(SOURCES))

DEPENDS			=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJSH)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)

-include $(OBJECTS:.o=.d)

$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(DOBJECTS)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

$(DOBJECTS)%.o: $(SRCSHDIR)%.c
	@mkdir -p $(DOBJECTS)$(CDPATH)
	@mkdir -p $(DOBJECTS)$(ECHOPATH)
	@mkdir -p $(DOBJECTS)$(ENVPATH)
	@mkdir -p $(DOBJECTS)$(EXITPATH)
	@mkdir -p $(DOBJECTS)$(SETENVPATH)
	@mkdir -p $(DOBJECTS)$(UNSETENVPATH)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(DOBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all makelib clean fclean re
