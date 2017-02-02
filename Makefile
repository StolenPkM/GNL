# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 23:38:55 by pabonnin          #+#    #+#              #
#    Updated: 2017/01/30 15:11:31 by pabonnin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =          gcc $(FLAGS)
FLAGS =       -Wall -Wextra -Werror
NAME =        libft.a
INCLUDES =    ./includes/*.h
SRCS =        ./sources/ft_*.c\
			  ./sources/get_next_line.h
		
OBJS=$(SRCS:.c=.o)

C_NO="\033[00m"
C_OK="\033[32m"
C_GOOD="\033[32m"
C_ERROR="\033[31m"
C_WARN="\033[31m"

SUCCESS=$(C_GOOD)SUCCESS$(C_NO)
OK=$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc  $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
