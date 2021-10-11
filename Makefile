NAME		= push_swap

NAME_BON	= checker

LIBA		= Libft/

lib			= libft.a

FOLDER		= ./

SRC			= \
calculate_moves.c \
cmd_p.c \
cmd_r.c \
cmd_rr.c \
cmd_s.c \
final_rotate_a.c \
main.c \
psarr2lst.c \
pslstadd_back.c \
pslstadd_front.c \
pslstclear.c \
pslstext.c \
pslstnew.c \
push_a_with_least_moves.c \
push_b_all_except_min_med_max.c \
push_swap.c \
sort3.c \

FOLDER_BON	= ./

SRC_BON		= \
cmd_p.c \
cmd_r.c \
cmd_rr.c \
cmd_s.c \
main.c \
parse_cmds_bonus.c \
psarr2lst.c \
pslstadd_back.c \
pslstadd_front.c \
pslstclear.c \
pslstext.c \
pslstnew.c \
push_swap_bonus.c \

INCLUDES	= ./

HDR			= \
push_swap.h \

HDR_BON		= \
push_swap_bonus.h \

SRCS		= $(addprefix $(FOLDER), $(SRC))

SRCS_BON	= $(addprefix $(FOLDER_BON), $(SRC_BON))

HDRS		= $(addprefix $(INCLUDES), $(HDR))

HDRS_BON	= $(addprefix $(INCLUDES), $(HDR_BON))

OBJS		= $(SRCS:%.c=%.o)

OBJS_BON	= $(SRCS_BON:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM      	= rm -f

BON			= bonus_on

%.o:		%.c Makefile $(HDRS) $(HDRS_BON)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all:		libft $(NAME)

libft:
			make -C $(LIBA) -f Makefile

$(NAME):	$(LIBA)$(lib) $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBA)$(lib) -I $(INCLUDES)
#			$(RM) $(BON)

bonus:		libft_bonus $(BON)

libft_bonus:
			make bonus -C $(LIBA)

$(BON):		$(LIBA)$(lib) $(OBJS_BON)
			$(CC) $(CFLAGS) -o $(NAME_BON) $(OBJS_BON) $(LIBA)$(lib) -I $(INCLUDES)
			touch $(BON)

clean:		libft_clean local_clean

libft_clean:
			make clean -C $(LIBA)

local_clean:
			$(RM) $(OBJS) $(OBJS_BON)

fclean:		local_clean
			make fclean -C $(LIBA)
			$(RM) $(NAME) $(NAME_BON) $(BON)

re:			fclean all

.PHONY:		all clean fclean re libft bonus libft_bonus libft_clean local_clean
