FLAGS=-Wall -Werror -Wextra -g

NAME = visual
SRC_FILES = $(shell find src -name "*.c")
DONE = @printf "\x1B[32mDone!\x1B[37m\n"
INCLUDES = -I./includes -I../lib/libft
RPAD = 45
LIBRARY = -L./lib -lSDL2 -lSDL2_gfx -lSDL2_image -L../lib/libft -lft

all: visual

visual:
	@printf "%-$(RPAD)s" "Compiling visual executable. "
	@$(CC) $(FLAGS) $(SRC_FILES) $(INCLUDES) $(LIBRARY) ./main.c -o visual
	$(DONE)

	@printf "%-$(RPAD)s" "Updating dylib paths in visual executable. "
	@install_name_tool -change /usr/local/opt/sdl2_image/lib/libSDL2_image-2.0.0.dylib @executable_path/lib/libSDL2_image-2.0.0.dylib visual
	@install_name_tool -change /usr/local/opt/sdl2/lib/libSDL2-2.0.0.dylib @executable_path/lib/libSDL2-2.0.0.dylib visual
	@install_name_tool -change /usr/local/opt/sdl2/lib/libSDL2-2.0.0.dylib @executable_path/lib/libSDL2-2.0.0.dylib visual
	$(DONE)

clean:
	@$(RM) $(NAME)

fclean: clean
	@printf "Performing clean build. \n"

re: fclean all