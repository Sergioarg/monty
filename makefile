
build:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o monty
	@echo "Buliding..."

run:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o monty
	@echo "Runing..."
	@./monty test; rm -f monty

valgrind-q:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o monty
	@valgrind --quiet --leak-check=full --track-origins=yes ./monty test; rm -f monty
#	--trace-children=

valgrind:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o monty
	@valgrind --leak-check=full --track-origins=yes ./monty test ; rm -f monty

gdb:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o monty
	@gdb ./monty; rm -f monty

gdb-c:
	@gcc -g -Wall -Werror -Wextra -pedantic *.c -o monty
	@gdb ./monty; rm -f monty

file="bytecodes/00.m"
utest:
	@gcc -Wall -Werror -Wextra -pedantic *.c -o monty
	@echo "Test -> $(file)"
	@./monty $(file)
