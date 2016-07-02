#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 10:17:09 by niccheva          #+#    #+#              #
#    Updated: 2016/07/02 22:09:25 by niccheva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	42sh

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

DSOURCES		=	./sources/

DOBJECTS		=	objects/

BUILD			=	./build

LIBFT			=	libraries/libft/
LIBLIST			=	libraries/liblist/
LIBREADLINE		=	libraries/libreadline/
LIBYAML			=	libraries/libyaml/

INCLUDES		=	-I./includes/
INCLUDES		+=	-I$(LIBFT)includes/
INCLUDES		+=	-I$(LIBLIST)includes/
INCLUDES		+=	-I$(LIBREADLINE)includes/
INCLUDES		+=	-I$(LIBYAML)includes/

LIBRARIES		=	-L$(BUILD)/$(LIBFT) -lft
LIBRARIES		+=	-L$(BUILD)/$(LIBLIST) -llist
LIBRARIES		+=	-L$(BUILD)/$(LIBREADLINE) -lreadline
LIBRARIES		+=	-L$(BUILD)/$(LIBYAML) -lyaml

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

OBJECTS			=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.o, $(SOURCES))

DEPS			=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.d, $(SOURCES))

DEPENDS			=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: makelib $(NAME)

makelib:
#	./libraries/clone_libraries.sh
#	make BUILD=$(BUILD)/libft -C $(LIBFT)
#	make BUILD=$(BUILD)/liblist -C $(LIBLIST)
#	make BUILD=$(BUILD)/libreadline -C $(LIBREADLINE)
#	make BUILD=$(BUILD)/libyaml -C $(LIBYAML)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(INCLUDES) $(LIBRARIES)
	@ln -sf $(BUILD)/$@ $@

-include $(OBJECTS:.o=.d)

$(BUILD)/$(DOBJECTS)%.o: $(DSOURCES)%.c
	@mkdir -p $(BUILD)/$(DOBJECTS)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(CDPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(ECHOPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(ENVPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(EXITPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(SETENVPATH)
	@mkdir -p $(BUILD)/$(DOBJECTS)$(UNSETENVPATH)
	@echo "\033[0;32m$< compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) $(DEPENDS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD)/$(DOBJECTS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BUILD)/$(NAME)
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all makelib clean fclean re
