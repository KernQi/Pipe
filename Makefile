CFLAGS = -g -Wall -Werror

tester:
	clang $(CFLAGS) -o list_tester linked_list.c list_tester.c

clean:
	rm -f list_tester