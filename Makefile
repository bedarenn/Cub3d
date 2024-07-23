# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 13:24:32 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/23 15:23:12 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################### NAME #####################################
NAME := cub3D
NAME_BONUS := cub3D_bonus

WATI_HDRS := libwati.h
WATI_NAME := libwati.a
WATI_RULES := wati-

MLX_HDRS := mlx.h
MLX_INT := mlx_int.h
MLX_NAME := libmlx.a
MLX_RULES := mlx-

EXT_RULES := ext-

################################### COMPILER ###################################
# CC := gcc -g --function-sections -Wl,--gc-sections -Wl,--print-gc-sections

CC := cc

################################# DIRECTORIES ##################################

DIR_OBJS := objs/
DIR_WATI := libwati/
DIR_MLX := minilibx-linux/
DIR_LIBS := libs/

DIR_SRCS := srcs/
DIR_SRCS_BONUS := srcs_bonus/
DIR_HDRS := hdrs/
DIR := \
	$(DIR_SRCS) \
	$(DIR_HDRS)

#################################### FILES #####################################

include $(DIR_SRCS)/sources.mk
include $(DIR_SRCS_BONUS)/sources.mk

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))
OBJS_BONUS = $(addprefix $(DIR_OBJS), $(SRCS_BONUS:%.c=%.o))

#################################### FLAGS #####################################
CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L$(DIR_LIBS) -lwati -lmlx -lXext -lX11 -lm -lz
IFLAGS := -I$(DIR_HDRS)

##################################### MAKE #####################################
MAKE := make --no-print-directory -C

#################################### RULES #####################################

all:
debug:
bonus:

$(NAME):
	@$(MAKE) $(DIR_SRCS) -j
	@printf "$(GREEN)compile $@                                         $(NC)\n"
	@$(CC) $(OBJS) $(LFLAGS) -o $@

$(NAME_BONUS):
	@$(MAKE) $(DIR_SRCS_BONUS) -j
	@printf "$(GREEN)compile $@                                         $(NC)\n"
	@$(CC) $(OBJS_BONUS) $(LFLAGS) -o $@

clean: $(EXT_RULES)clean
	@printf "$(RED)clean objs$(NC)\n"
	@rm -rf $(DIR_OBJS)

fclean: $(EXT_RULES)clean
	@printf "$(RED)clean $(NAME)$(NC)\n"
	@rm -rf $(DIR_OBJS)
	@rm -f $(NAME)

re: fclean all

all:	$(MLX_NAME) $(WATI_NAME) $(NAME)
bonus:	$(MLX_NAME) $(WATI_NAME) $(NAME_BONUS)
debug:	CFLAGS += -g
debug:	$(EXT_RULES)debug $(NAME)

dir: $(DIR)
	mkdir -p $^

################################# EXT_RULES ###################################

$(EXT_RULES)all: $(MLX_RULES)all $(WATI_RULES)all
$(EXT_RULES)debug: 	$(MLX_RULES)all $(WATI_RULES)debug
$(EXT_RULES)clean: $(MLX_RULES)clean $(WATI_RULES)fclean
$(EXT_RULES)re: $(MLX_RULES)re $(WATI_RULES)re
$(EXT_RULES)git: $(MLX_RULES)git $(WATI_RULES)git

################################# WATI_RULES ###################################

$(WATI_RULES)all: $(WATI_NAME)
$(WATI_NAME):
	@$(MAKE) $(DIR_WATI) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)
$(WATI_RULES)debug:
	@$(MAKE) $(DIR_WATI) debug -j
	@cp $(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)$(WATI_HDRS)
$(WATI_RULES)clean:
	@$(MAKE) $(DIR_WATI) clean
$(WATI_RULES)fclean:
	@$(MAKE) $(DIR_WATI) fclean
	@rm -f $(DIR_HDRS)$(WATI_HDRS) $(DIR_LIBS)$(WATI_NAME)
$(WATI_RULES)re:
	@$(MAKE) $(DIR_WATI) re
$(WATI_RULES)git:
	@printf "$(RED)clean $@ $(NC)\n"
	@rm -rf $(DIR_WATI).git

################################# MLX_RULES ###################################

$(MLX_RULES)all: $(MLX_NAME)
$(MLX_NAME):
	@$(MAKE) $(DIR_MLX) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_MLX)$(MLX_NAME) $(DIR_LIBS)
	@cp $(DIR_MLX)$(MLX_HDRS) $(DIR_HDRS)$(MLX_HDRS)
	@cp $(DIR_MLX)$(MLX_INT) $(DIR_HDRS)$(MLX_INT)
$(MLX_RULES)clean:
	@$(MAKE) $(DIR_MLX) clean
	@rm -f $(DIR_HDRS)$(MLX_HDRS) $(DIR_HDRS)$(MLX_INT) $(DIR_LIBS)$(WATI_NAME)
$(MLX_RULES)re:
	@$(MAKE) $(DIR_MLX) re
$(MLX_RULES)git:
	@printf "$(RED)clean $@$(NC)\n"
	@rm -rf $(DIR_MLX).git

#################################### PHONY #####################################
.PHONY: all clean fclean debug dir git

#################################### COLORS ####################################
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
