# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwong <bwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 21:21:54 by bwong             #+#    #+#              #
#    Updated: 2023/04/15 16:17:13 by vgeorgak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------------------------------------#
#                                 COLORS                                    #
#---------------------------------------------------------------------------#

GREEN = \033[38;5;82m
BLUE = \033[34m
YELLOW = \e[0;33m
RED	= \033[31;1m
PURPLE = \033[38;5;165m
TURTUR = \033[38;5;39m
RESET = \033[0m

#---------------------------------------------------------------------------#
#                                 VARS                                      #
#---------------------------------------------------------------------------#

NAME			= minishell
LIBFT			= libft.a

CC 				= gcc
CFLAGS 				= -Wall -Wextra -Werror -g
CINC 			= -I $(INCLUDE_PATH)
CREAD			= -lreadline

LIBFT_PATH 		= ./libft/
SRCS_PATH 		= ./src/
OBJS_PATH		= ./minishell_objects/
INCLUDE_PATH 	= ./include/

#---------------------------------------------------------------------------#
#                                 SRCS                                      #
#---------------------------------------------------------------------------#

SRCS			= main.c init_tool.c builtin.c builtin_utils.c ft_cd.c ft_echo.c ft_env.c\
				ft_exit.c ft_export.c ft_export_two.c ft_pwd.c ft_unset.c\
				cmd_utils.c cmd.c exec_child.c execution.c\
				hash.c key_search.c add_back_hash.c\
				get_key.c get_value.c insert_hash.c\
				expansion.c expansion_two.c expansion_tools.c heredoc.c\
				token_utils.c token.c setup_path.c\
				check_path.c create_path_list.c get_cmd_path.c\
				pid.c signal.c signal_two.c\
 				define.c error.c free.c free_two.c free_three.c pipe.c WYSIWYG.c\
				if_builtin.c if_command_valid.c if_double_operator.c\
				if_expandable.c if_fork_needed.c\
				if_grammar_valid.c if_identifier_valid.c if_in_quotes.c\
				if_pipe_valid.c if_quotes_valid.c if_redir_valid.c\
				if_redir.c if_valid_token.c if_no_meta.c
				

VPATH 			:= $(SRCS_PATH)\
				$(SRCS_PATH)builtins\
				$(SRCS_PATH)init\
				$(SRCS_PATH)cmd\
				$(SRCS_PATH)execution\
				$(SRCS_PATH)hash\
				$(SRCS_PATH)parsing\
				$(SRCS_PATH)signal\
				$(SRCS_PATH)path\
				$(SRCS_PATH)signals\
				$(SRCS_PATH)utils\
				$(SRCS_PATH)what_if\

OBJS			=	$(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

$(OBJS_PATH)%.o: %.c
				@printf "${GREEN}"
				$(CC) $(CFLAGS) $(CINC) -c $< -o $@
				

#---------------------------------------------------------------------------#
#                                 RULES                                     #
#---------------------------------------------------------------------------#

all :	dir	$(NAME)
			@printf "$(PURPLE)"
			@echo ${BANNER}
	

dir :
	@mkdir -p ${OBJS_PATH}

$(NAME)	:	$(OBJS)
			@echo "${GREEN}---------------\nFlags used for compilation -Wall -Wextra -Werror.\n-------------${RESET}"
			@sleep 0.5
			@echo "$(BLUE)---------------\nObject files generated!\n--------------------$(RESET)"
			@sleep 0.5
			@echo "$(YELLOW)---------------\nCompiling libft...\n-----------------$(RESET)"
			@sleep 0.5
			$(MAKE) -s -C $(LIBFT_PATH) $(LIBFT)
			$(CC) $(CFLAGS) $(CINC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft $(CREAD)
			@printf "$(RED)\n\n\nWelcome to \n\n\n$(RESET)"
			@sleep 0.7

#----------------------------------------------------------------------------
# Uncomment only if user has sudo rights
#install:
#			sudo apt-get install libreadline-dev
#			echo"$(GREEN)Readline ready!$(RESET)"
#----------------------------------------------------------------------------

# To use valgrind with readline suppresions, "make ignore" first.
ignore:
	@echo ${IGNORE} > .ignore_readline
	@echo "$(YELLOW)-----------------\n.ignore_readline is succesfully generated.\n----------------------$(RESET)"

# If .ignore_readline is created, the suppressions can be used
leaks:
	@valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./minishell #--suppressions=.ignore_readline  

clean:
			make -s -C $(LIBFT_PATH) clean
			rm -rf $(OBJS_PATH)
			rm -rf .ignore_readline
			@echo "${YELLOW}--------- \nFiles cleared.\n---------- ${RESET}"

fclean:		clean
			make -s -C $(LIBFT_PATH) fclean
			rm -rf $(NAME)
			@echo "${TURTUR}--------- \nName cleared.\n---------- ${RESET}"


re:			fclean all

#---------------------------------------------------------------------------#
#                                 TARGETS                                   #
#---------------------------------------------------------------------------#

.SILENT: ${NAME} ${OBJS} clean fclean
.PHONY:		all clean fclean re ignore leaks 

#---------------------------------------------------------------------------#
#                              BANNER/IGNORE                                #
#---------------------------------------------------------------------------#

BANNER :=\
     "      💀        💀                        ";\
echo "█▀▄▀█ ▄█    ▄   ▄█    ▄▄▄▄▄    ▄  █ ▄███▄   █    █     ";\
echo "█ █ █ ██     █  ██   █     ▀▄ █   █ █▀   ▀  █    █     ";\
echo "█ ▄ █ ██ ██   █ ██ ▄  ▀▀▀▀▄   ██▀▀█ ██▄▄    █    █     ";\
echo "█   █ ▐█ █ █  █ ▐█  ▀▄▄▄▄▀    █   █ █▄   ▄▀ ███▄ ███▄  ";\
echo "   █   ▐ █  █ █  ▐               █  ▀███▀       ▀    ▀ ";\
echo "  ▀      █   ██                 ▀                      ";\
echo "                                                       ";\

IGNORE:= {'\n''\t'ignore_libreadline_conditional_jump_errors'\n''\t'Memcheck:Leak'\n''\t'...'\n''\t'obj:*/libreadline.so.*'\n'} 
