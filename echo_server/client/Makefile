# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:15:59 by seoyoo            #+#    #+#              #
#    Updated: 2023/05/28 21:19:08 by seoyoo           ###   ########.fr        #
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

# Variables

NAME		= client
DBNAME		= $(NAME)_debug

SRC_DIR		= src
INC_DIR		= include
OBJ_DIR		= obj
TEST_DIR	= test
BIN_DIR		= bin

CXX			= c++
# W_FLAGS		= -Wall -Wextra -Werror
W_FLAGS		= 
VER_FLAGS	= -std=c++98
INC_FLAGS	= -I$(INC_DIR) -I$(SRC_DIR)
CXXFLAGS	= -c $(W_FLAGS) $(VER_FLAGS) $(INC_FLAGS)
LDFLAGS		= 
DBGFLAGS	= -g3 $(VER_FLAGS) $(INC_FLAGS)
TESTFLAGS	= $(W_FLAGS) $(VER_FLAGS) $(INC_FLAGS)

SRCS	= $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# **************************************************************************** #

# Rules

# Main target
all : make_directories $(BIN_DIR)/$(NAME)

# Compilation
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Linking 
$(BIN_DIR)/$(NAME) : $(OBJS)
	$(CXX) -o $@ $^
	@echo "$(Blue)\n[ Compile finished!! ]\n$(Color_Off)"

make_directories : 
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(BIN_DIR)

debug : $(BIN_DIR)/$(DBNAME)

$(BIN_DIR)/$(DBNAME) : $(SRCS)
	@mkdir -p $(@D)
	$(CXX) $(DBGFLAGS) -o $(BIN_DIR)/$(DBNAME) $^
	@echo "$(Blue)\n[ LETS START DEBUGGING! ]\n$(Color_Off)"

re : fclean all

# 'make run' will recompile and execute executable file with given arguments
#   add arguments if you need
BIN_ARGS = 

run : re
	./$(BIN_DIR)/$(NAME) $(BIN_ARGS)

# Rule for module test!
server : 

module : $(BIN_DIR)/$(MODULE_NAME)

$(BIN_DIR)/$(MODULE_NAME) : $(MODULE_TEST_SRCS)
	$(CXX) $(TESTFLAGS) -o $@ $^



.PHONY : all make_directories clean fclean debug re run
