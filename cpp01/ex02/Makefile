# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 22:20:19 by michang           #+#    #+#              #
#    Updated: 2024/03/11 20:03:04 by michang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= c++
FLAG	:= -Wall -Wextra -Werror -std=c++98

DIR		:= ./
BASE	:= main
SRC		:= $(addprefix $(DIR), $(addsuffix .cpp, $(BASE)))
OBJ		:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME	:= HITHISISBRAIN

all		: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(FLAG) $^ -o $@
	@echo "\033[32;1m\n🚀 [SUCCESS] Everything has been compiled successfully! ✨\033[m"

%.o		: %.cpp
	@$(CC) $(FLAG) -I$(dir $<) -c $< -o $@
	@echo "\033[34;1m🎲 [OK] $< is compiled.\033[m"

clean	:
	@rm -f $(OBJ)
	@echo "\033[35;1m🧹 [CLEAN] Object files have been removed!\033[m"

fclean	: clean
	@rm -f $(NAME)
	@echo "\033[35;1m🧹 [FCLEAN] Executable files have been fully removed!\033[m"

re		: fclean all

.PHONY	: all clean fclean re
