FLAGS=-Wall -Werror -Wextra

NAME = lemin
SRC_FILES = $(shell find src -name "*.c")
DONE = @printf "\x1B[32mDone!\x1B[37m\n"
LIBRARY = -L./lib/libft -lft
INCLUDES = -I./includes
RPAD = 45

all: lemin

lemin: ./libft/libft.a ./includes/libft.h visualise
	@printf "%-$(RPAD)s" "Compiling lemin executable. "
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBRARY) $(SRC_FILES) ./main.c -o $(NAME)
	$(DONE)

./libft/libft.a:
	@printf "%-$(RPAD)s" "Compiling libft library. "
	@$(MAKE) -s -C lib/libft
	@$(MAKE) -s -C lib/libft clean
	@printf "\x1B[32mDone!\x1B[37m\n"

./includes/libft.h:
	@printf "%-$(RPAD)s" "Copying libf.h to includes. "
	@cp ./lib/libft/libft.h ./includes/
	@printf "\x1B[32mDone!\x1B[37m\n"

visualise:
	@$(MAKE) -s -C visualiser

clean:
	@$(RM) lemin

fclean: clean
	@printf "Performing clean build. \n"
	@$(RM) ./libft/libft.a
	@$(RM) ./visualiser/visual

re: fclean all