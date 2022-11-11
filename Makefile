all: server client

bonus: server client

server:
ifeq (bonus,$(MAKECMDGOALS))
	gcc -Wall -Wextra -Werror server_bonus.c utils_bonus.c -o server
else
	gcc -Wall -Wextra -Werror server.c utils.c -o server
endif

client:
ifeq (bonus,$(MAKECMDGOALS))
	gcc -Wall -Wextra -Werror client_bonus.c utils_bonus.c -o client
else
	gcc -Wall -Wextra -Werror client.c utils.c -o client
endif

clean:
	rm -rf server client

fclean: clean

re: fclean all

.PHONY: all re clean fclean bonus