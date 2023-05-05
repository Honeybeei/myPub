# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:15:59 by seoyoo            #+#    #+#              #
#    Updated: 2023/04/30 22:07:31 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME	= tests
DBNAME	= $(NAME)_debug

# compiler
CPP			= c++
DEBUG_FLAGS	= -g3

CFLAGS		= -Wall -Wextra -Werror
VERFLAGS	= -std=c++98

# basic directories
SRC_DIR		= ./src/
INC_DIR		= ./inc/
OBJ_DIR		= ./obj/
TEST_DIR	= ./test/

# include header file
INC_FLAGS	= -I $(INC_DIR)

# flags and options
COMPILE_FLAGS	= $(CPP) $(CFLAGS) $(VERFLAGS) $(INC_FLAGS)
LINKING_FLAGS	= $(CPP) $(CFLAGS) $(VERFLAGS) $(INC_FLAGS)
DEBUG_MODE_FLGS	= $(CPP) $(CFLAGS) $(VERFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS)

# **************************************************************************** #

# actions
FILE_NAMES	= \
			main \
			Bureaucrat \
			Form

# add-suf/prefix
SRCS	= $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(FILE_NAMES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE_NAMES)))

# main rules
all : mkobjdir $(NAME)

# linking
$(NAME) : $(OBJS)
	$(LINKING_FLAGS) -o $@ $^
	@echo "$(Blue)\n[ Compile finished!! ]\n$(Color_Off)"

# compiling
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(COMPILE_FLAGS) -o $@ -c $<

mkobjdir :
	@mkdir -p $(OBJ_DIR)

debug : $(SRCS)
	$(DEBUG_MODE_FLGS) -o $(DBNAME) $^

debug_clean :
	rm -f $(DBNAME)
	rm -rf $(DBNAME).dSYM

clean :
	rm -rf $(OBJ_DIR)

fclean : clean debug_clean
	rm -f $(NAME)

re : fclean all

ree : clean all

run : ree
	@./$(NAME)

.PHONY : all mkobjdir debug debug_clean clean fclean re ree run
