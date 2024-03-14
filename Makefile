NAME = CPiscineTester
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./modules/src
INCLUDE = ./modules/include
OBJDIR = ./modules/obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INLCUDE)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all