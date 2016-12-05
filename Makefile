#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/09 10:17:09 by niccheva          #+#    #+#              #
#    Updated: 2016/12/05 11:33:18 by llapillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	42sh

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

DSOURCES		=	./sources/

DOBJECTS		=	objects/

BUILD			=	$(PWD)/build

LIBFT			=	libraries/libft/
LIBLIST			=	libraries/liblist/
LIBREADLINE		=	libraries/libreadline/
LIBJSON			=	libraries/libjson/
LIBOPTION		=	libraries/liboption/

INCLUDES		=	-I./includes/
INCLUDES		+=	-I$(LIBFT)includes/
INCLUDES		+=	-I$(LIBLIST)includes/
INCLUDES		+=	-I$(LIBREADLINE)includes/
INCLUDES		+=	-I$(LIBJSON)includes/
INCLUDES		+=	-I$(LIBOPTION)includes/

LIBRARIES		=	-L$(BUILD)/$(LIBFT) -lft
LIBRARIES		+=	-L$(BUILD)/$(LIBLIST) -llist
LIBRARIES		+=	-L$(BUILD)/$(LIBREADLINE) -lreadline
LIBRARIES		+=	-L$(BUILD)/$(LIBOPTION) -loption
#LIBRARIES		+=	-L$(BUILD)/$(LIBJSON) -ljson

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
BUILTINS		=	$(EXIT)
BUILTINS		+=	$(SETENV)
BUILTINS		+=	$(UNSETENV)

SOURCES			=	$(BUILTINS)
SOURCES			+=	main.c
SOURCES			+=	sh_quit.c
SOURCES			+=	fd_create_file.c
SOURCES			+=	fd_append_file.c
SOURCES			+=	fd_openread_file.c

OBJECTS			=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.o, $(SOURCES))

DEPS			=	$(patsubst %.c, $(BUILD)/$(DOBJECTS)%.d, $(SOURCES))

DEPENDS			=	-MT $@ -MD -MP -MF $(subst .o,.d,$@)

all: makelib $(BUILD)/$(NAME)

clone_submodules:
	@git submodule init
	@git submodule update
	@./libraries/disable_rights.sh

update_submodules: clone_submodules
	@./libraries/enable_rights.sh
	@git submodule update --remote
	@./libraries/disable_rights.sh

makelib: clone_submodules
	make BUILD=$(BUILD)/$(LIBFT) -C $(LIBFT)
	make BUILD=$(BUILD)/$(LIBLIST) -C $(LIBLIST)
	make BUILD=$(BUILD)/$(LIBREADLINE) -C $(LIBREADLINE)
	make BUILD=$(BUILD)/$(LIBOPTION) -C $(LIBOPTION)
#	make BUILD=$(BUILD)/$(LIBJSON) -C $(LIBJSON)

$(BUILD)/$(NAME): $(OBJECTS)
	@echo "\n\033[0;32m$(NAME) compiled:\t\033[0;m\c"
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBRARIES)
	@ln -sf $@ $(NAME)

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

cleanlib:
	@make BUILD=$(BUILD)/libft -C $(LIBFT) fclean
	@make BUILD=$(BUILD)/liblist -C $(LIBLIST) fclean
	@make BUILD=$(BUILD)/libreadline -C $(LIBREADLINE) fclean
	@make BUILD=$(BUILD)/libjson -C $(LIBJSON) fclean
	@make BUILD=$(BUILD)/libjson -C $(LIBOPTION) fclean

all_clean: fclean cleanlib
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all makelib clean fclean cleanlib all_clean re
