SHELL		=	/bin/bash

NAME		=	so_long
BNAME		=	so_long_bonus
INC			=	inc
HEADER		=	-I inc
LIBFT		=	lib/libft/
FT_PRINTF	=	lib/ft_printf/
MINILIBX	=	./lib/mlx/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -f
MINILIBXCC	=	-I mlx -L ./lib/mlx/ -lmlx
OPENGL		=	-framework OpenGL -framework AppKit

SL_DIR		=	so_long/
MAND_FILES	=	so_long check_limits map_validation window window_fill keyhook
BONUS_DIR	=	bonus/
BONUS_FILES	=	check_limits_bonus map_validation_bonus so_long_bonus utils_bonus window_bonus window_fill_bonus keyhook_bonus

SRC_FILES	=	$(addprefix $(SL_DIR), $(MAND_FILES))
SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

BSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
BOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

OBJF		=	.cache_exists

all:			$(NAME)

$(NAME):		$(OBJ) $(OBJF)
				@make -C $(LIBFT)
				@cp lib/libft/libft.a .
				@make -C $(FT_PRINTF)
				@cp lib/ft_printf/libftprintf.a .
				@make -s -C $(MINILIBX)
				@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a libftprintf.a $(MINILIBXCC) $(OPENGL) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)$(SL_DIR)
				@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
				@touch $(OBJF)

clean:
				@$(RM) -r $(OBJ_DIR)
				@make clean -C $(LIBFT)
				@$(RM) $(OBJF)
				@make clean -C $(MINILIBX)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) libft.a
				@$(RM) $(LIBFT)/libft.a
				@$(RM) -rf *.dSYM
				@find . -name ".DS_Store" -delete

bonus:			$(BNAME)

$(BNAME):		$(BOBJ)
				@make -C $(LIBFT)
				@cp lib/libft/libft.a .
				@make -C $(FT_PRINTF)
				@cp lib/ft_printf/libftprintf.a .
				@make -s -C $(MINILIBX)
				@$(CC) $(CFLAGS) $(BSRC) $(HEADER) libft.a libftprintf.a $(MINILIBXCC) $(OPENGL) -o $(BNAME)

re:				fclean all

.PHONY:			all clean fclean re
