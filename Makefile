# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:15:05 by ltimsit-          #+#    #+#              #
#    Updated: 2019/06/10 11:26:17 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	@gcc $(WFLAG) $(CSRCS) $(INCLUDE)
#	@gcc -o $(NAME) $(OSRCS) $(LIBFT) 
#	make -C libft

NAME = libftprintf.a
WFLAG = -c -Wall -Werror -Wextra 
#-Wall -Werror -Wextra
LIBFT = libft/libft.a
INCLUDE = -I include
CC = gcc $(INCLUDE)
LIBFTSRCS = ft_atoi ft_putnstr_fd ft_strcat ft_strdup ft_strlen ft_strndup\
				ft_strnew ft_memalloc ft_memcpy ft_strcpy ft_strnlen\
				ft_strtol ft_bzero ft_isspace ft_memdel ft_strncmp
LIBFTC = $(addprefix libft/, $(LIBFTSRCS))
LIBFTO = $(addsuffix .o, $(LIBFTC))
LIBFTA = libft/libft.a
SRCS = init ft_strjoin_free_order pf_str get_info check_attributs_w_p \
	   pf_char pf_utoabase pf_itoa pf_itoa_check doubletoa2 doubletoa3 \
	   va_fct va_fct2 va_fct3 get_color\
	   tab_fcts doubletoa_operations doubletoa_utils percent get_binary \
	   double_exeption double_round get_type
CSRCS = $(addsuffix .c, $(SRCS)) 
OSRCS = $(addsuffix .o, $(SRCS) $(LIBFTC)) 

all : $(NAME)

$(NAME) : $(OSRCS) Makefile include/ft_printf.h include/libft.h
	make -C libft
	gcc $(WFLAG) $(INCLUDE) $(CSRCS) 
	ar rc $(NAME) $(OSRCS) $(LIBFTO)
	ranlib $(NAME)

clean : 
	@rm -rf $(OSRCS)
	make clean -C libft

fclean : clean 
	@rm -rf $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : re clean fclean all
