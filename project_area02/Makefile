# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:55:35 by seoyoo            #+#    #+#              #
#    Updated: 2023/11/24 16:19:29 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m			# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m			# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

NAME = Inception
USER_NAME = seoyoo
DB_LOCATION = /home/${USER_NAME}/data/db/
WP_LOCATION = /home/${USER_NAME}/data/wp/

all : $(NAME)

$(NAME) : 
	@echo "$(Blue)\n[ Docker-compose ----------------------------------------------------------- ]\n$(Color_Off)"
	@echo "$(Green)\n -- Create data directories\n$(Color_Off)"
	@sudo mkdir -p ${DB_LOCATION}
	@sudo mkdir -p ${WP_LOCATION}
	@sudo echo 127.0.0.1 ${USER_NAME}.42.fr >> /etc/hosts
	@sudo docker-compose -f ./srcs/docker-compose.yml up --build -d
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

up : 
	@echo "$(Blue)\n[ Docker-compose up -------------------------------------------------------- ]\n$(Color_Off)"
	@docker-compose -f ./srcs/docker-compose.yml up -d
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

down : 
	@echo "$(Blue)\n[ Docker-compose down ------------------------------------------------------ ]\n$(Color_Off)"
	@docker-compose -f ./srcs/docker-compose.yml down
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

stop : 
	@echo "$(Blue)\n[ Docker-compose stop ------------------------------------------------------ ]\n$(Color_Off)"
	@docker-compose -f ./srcs/docker-compose.yml stop
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

start : 
	@echo "$(Blue)\n[ Docker-compose start ----------------------------------------------------- ]\n$(Color_Off)"
	@docker-compose -f ./srcs/docker-compose.yml start
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

status : 
	@echo "$(Blue)\n[ Docker-compose status ---------------------------------------------------- ]\n$(Color_Off)"
	@echo "$(Green)\n[ Docker containers ]\n$(Color_Off)"
	@docker ps
	@echo "$(Green)\n[ Docker images ]\n$(Color_Off)"
	@docker images
	@echo "$(Green)\n[ Docker volumes ]\n$(Color_Off)"
	@docker volume ls
	@echo "$(Green)\n[ Docker networks ]\n$(Color_Off)"
	@docker network ls
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

re : down up

clean :
	@echo "$(Blue)\n[ Docker-compose clean ----------------------------------------------------- ]\n$(Color_Off)"
	@echo "$(Green)\n -- Delete all containers, images, volumes and networks\n$(Color_Off)"
	@sudo docker-compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

fclean : clean
	@echo "$(Blue)\n[ Docker-compose fclean ---------------------------------------------------- ]\n$(Color_Off)"
	@sudo rm -rf ${DB_LOCATION}
	@sudo rm -rf ${WP_LOCATION}
	@echo "$(Blue)\n[ -------------------------------------------------------------------------- ]\n$(Color_Off)"

.PHONY : all up down stop start status clean re