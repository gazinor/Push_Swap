#-------------  Variables  ---------------#

NAME	=	push_swap

CC		=	gcc

CFLAGS  =	-Wall -Wextra -Werror

DEBUG	=	-g3 -fsanitize=address

HEADER_P = 	./includes
HEADER_N =	push_swap.h
HEADER   =	$(addprefix $(HEADER_P)/,$(HEADER_N))

SRC_PATH =	./srcs
SRC_NAME =	utils.c \
			list_functions.c \
			ft_atoi.c \
			algo.c \
			algo_utils.c \
			algo_utils2.c \
			parsing.c \
			push_swap.c

SRC      =	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

DEP  = $(OBJ:%.o=%.d)

OBJ_PATH =	./.objs
OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ      =	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#----------------  Rules  ----------------#

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

-include $(DEP)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -MMD -I$(HEADER_P) -o $@ -c $<
	@printf "\e[1;30mTrying to compile : \e[1;37m./%-51s\e[1;0m" "$<"
	@printf "\e[32mcheck\e[1;0m\n"

d	:	$(OBJ)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o debug


save : fclean
	git add .
	git commit -m "$m"
	git push

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf debug

re : fclean all
