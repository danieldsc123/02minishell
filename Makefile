# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:38:18 by aperez-b          #+#    #+#              #
#    Updated: 2025/04/10 17:54:45 by daniel-da        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

# Properties for MacOS
CDEBUG = #-fsanitize=address
CHECKER = tests/checker_Mac
ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS = valgrind --leak-check=full --track-fds=yes --trace-children=yes -s -q 
endif

# Make variables
CFLAGS = -Wall -Wextra -Werror -MD -g3 
CPPFLAGS = -I inc -I libft/inc -I ~/.brew/opt/readline/include \
	-I /usr/local/opt/readline/include
LDFLAGS = -L ~/.brew/opt/readline/lib -L /usr/local/opt/readline/lib
LDLIBS = -lreadline
RM = rm -f
CC = gcc
PRINTF = printf
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIBFT = libft/bin/libft.a
BIN = minishell
NAME = $(BIN_DIR)/$(BIN)
LIBFT_DIR = libft
LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)

SRC = main.c builtins.c ft_strtrim_all.c exec.c			\
	  fill_node.c get_params.c ft_cmdtrim.c				\
	  expand.c heredoc.c error.c env.c custom_cmd.c		\
	  get_next_line.c get_next_line_utils.c prompt.c	\
	  ft_cmdsubsplit.c signal.c parse_args.c get_cmd.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) | $(BIN_DIR)
	@$(CC) $(LDFLAGS) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) $(LDLIBS) -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(CDEBUG) -c $< -o $@

$(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR) $(BIN_DIR)
	@$(MAKE) all -C libft

compare: all
	@cd tests && ./compare.sh && cd ..

test: all
	@cd tests && ./test.sh && cd ..

run: all
	@$(LEAKS)./$(NAME)

clean: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)Cleaning up object files...$(DEFAULT)\n"
	@$(MAKE) clean -C libft
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	$(RM) $(LIBFT)
	@$(PRINTF) "$(CYAN)Removed $(LIBFT)$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc
	@$(MAKE) norminette -C libft


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

re: fclean all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d

.PHONY: all clean fclean norminette test compare run git re
