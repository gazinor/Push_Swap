#-------------  Variables  ---------------#

NAME	=	push_swap

CC		=	gcc

CFLAGS  =	-O3 -g3 -Wall -Wextra -Werror -I$(HEADER_P)

DEBUG	=	-g3 -fsanitize=address

HEADER_P = 	./includes
HEADER_N =	push_swap.h
HEADER   =	$(addprefix $(HEADER_P)/,$(HEADER_N))

SRC_PATH =	./srcs
SRC_TMP :=	utils.c \
			list_functions.c \
			erase_list_functions.c \
			ft_atoi.c \
			algo.c \
			algo_utils.c \
			algo_utils2.c \
			parsing.c \
			push_swap.c \
			sets.c \
			gets.c \
			sorted.c \
			more_than_a_hundred.c \
			more_than_a_hundred_utils.c \
			short_list.c \
			math_functions.c \
			checks_before_instruction.c \
			instructions.c \
			exec.c \
			moves.c \
			target_rots.c \
			gnl.c \
			gnl_utils.c \
			gnl_utils2.c \
			gnl_utils3.c

CHECKER_NAME	=	Checker
TMP				=	checker.c
CHECKER_SRC		=	$(SRC_TMP) $(TMP)
CHECKER_OBJS	=	$(CHECKER_SRC:%.c=$(OBJ_PATH)/%.o)

SRC_NAME =	$(SRC_TMP) main.c
SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

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
	@$(CC) $(CFLAGS) -MMD -o $@ -c $<
	@printf "\e[1;30mTrying to compile : \e[1;37m./%-51s\e[1;0m" "$<"
	@printf "\e[32mcheck\e[1;0m\n"

d	:	$(OBJ)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o debug

tester : check
	@bash checkers/tester.sh $(noa)

check : re $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME)

save : fclean
	git add .
	git commit -m "$m"
	git push

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf debug
	@rm -rf $(CHECKER_NAME)

re : fclean all
