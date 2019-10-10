SOURCES= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
			ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
			ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c\
			ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
			ft_strnequ.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
			ft_lstiter.c ft_lstmap.c ft_strtol.c ft_isspace.c ft_strndup.c\
			ft_strnlen.c ht_new_item.c ht_new.c ht_del_item.c ht_del_hash_table.c\
			ht_hash.c ft_lpow.c ft_is_prime.c ft_find_next_prime.c ft_lstrev.c\
			ft_lstfind.c ft_memswap.c ft_putnstr.c ft_putnstr_fd.c

OBJECTS= $(addsuffix .o, $(basename $(SOURCES)))

NAME = libft.a

all: $(NAME)

$(NAME): $(SOURCES)
	gcc -Wall -Wextra -Werror -c $(SOURCES)
	ar rcs libft.a $(OBJECTS)

clean:
	rm -f *.o

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY : all clean fclean re
