# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    enable_rights.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/02 23:00:04 by niccheva          #+#    #+#              #
#    Updated: 2016/07/02 23:02:47 by niccheva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

for p in `git submodule status | sed -e "s/^[+\ ][^\ ]*\ //" -e s/\ .*$//`; do
	chmod -R u+w $p;
done
