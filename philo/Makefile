# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:34:29 by user42            #+#    #+#              #
#    Updated: 2022/07/28 12:55:19 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCLUDE	=	ft_philo.h
I_INC	=	-I.

PHILO_S	=	error philosophers lib init_master

SRCS	=	$(addprefix ft_, $(addsuffix .c, $(PHILO_S)))

OBJS	=	$(addprefix ft_, $(addsuffix .o, $(PHILO_S)))

CFLAGS	=	-Wall -Wextra -Werror 
# F_THREAD=	-lpthread -D_REENTRANT
F_THREAD=	

CC		=	gcc

all		:	$(NAME)

%.o		:	%.c $(INCLUDE)
			$(CC) $(CFLAGS) $(F_THREAD) $(I_INC) -c -o $@ $<

lib		:
			make -C $(D_LIBFT)

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(F_THREAD) $(I_INC) $(OBJS) -o $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re