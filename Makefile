#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 10:17:09 by niccheva          #+#    #+#              #
#    Updated: 2016/06/10 10:29:49 by niccheva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	42sh

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

DSOURCES		=	./sources/

DOBJECTS		=	./objects/

LIBFT			=	./libraries/libft/
LIBLIST			=	./libraries/liblist/
LIBREADLINE		=	./libraries/libreadline/
LIBYAML			=	./libraries/libyaml/

INCLUDES		=	-I./includes/
INCLUDES		+=	-I$(LIBFT)includes/
INCLUDES		+=	-I$(LIBLIST)includes/
INCLUDES		+=	-I$(LIBREADLINE)includes/
INCLUDES		+=	-I$(LIBYAML)includes/

LIBRARIES		=	-L$(LIBFT) -lft
LIBRARIES		+=	-L$(LIBLIST) -llist
LIBRARIES		+=	-L$(LIBREADLINE) -lreadline
LIBRARIES		+=	-L$(LIBYAML) -lyaml

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

UNSETENV		=	$(UNSETENVPATH)builtin_unsetenv.c

BUILTINS		=	$(CD)
BUILTINS		+=	$(ECHO)
BUILTINS		+=	$(ENV)
BUILTINS		+=	$(EXIT)
BUILTINS		+=	$(SETENV)
BUILTINS		+=	$(UNSETENV)

SOURCES			=	$(BUILTINS)

OBJECTS			=	$(patsubst %.c, $(DOBJECTS)%.o, $(SOURCES))

DEPS			=	$(patsubst %.c, $(DOBJECTS)%.d, $(SOURCES))

DEPENDS			=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: makelib $(NAME)

makelib:
#	./libraries/clone_libraries.sh
#	make -C $(LIBFT)
#	make -C $(LIBLIST)
#	make -C $(LIBREADLINE)
#	make -C $(LIBYAML)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)

-include $(OBJECTS:.o=.d)

$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(DOBJECTS)
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
