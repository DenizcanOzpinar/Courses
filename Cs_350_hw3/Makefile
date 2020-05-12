default: 
	gcc -o server server.c -pthread -I.
	gcc -o client client.c
	gcc -o echo_server echo_server.c
	gcc -o echo_client echo_client.c
clean:
	rm -f server
	rm -f client
	rm -f echo_server
	rm -f echo_client
