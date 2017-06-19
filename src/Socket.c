#include "Socket.h"
#include "basic_data.h"
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void set_socket_statue(int fd, int blocking)
{
	int flags = fcntl(fd, F_GETFL, 0);
	if (flags < 0)
		return;
	flags = blocking == 1 ? (flags&~O_NONBLOCK) : (flags|O_NONBLOCK);
	fcntl(fd, F_SETFL, flags);
}

void init_socket2(t_Connection *connection){
	if (bind(connection->fd, (const struct sockaddr *)&connection->s_in, sizeof(connection->s_in)) == -1)
	{
		print(2, "Can not bind socket\n");
		close(connection->fd);
		exit(1);
	}
	if (listen(connection->fd, 10) == -1)
	{
		print(2, "Can not listen on server\n");
		close(connection->fd);
		exit(1);
	}
}

bool send_message(int fd, char *msg)
{
	if (send(fd, msg, strlen(msg), MSG_DONTWAIT | MSG_NOSIGNAL) == -1)
		return(false);
	return(true);
}

void basic_init_socket(t_Connection *socket)
{
	socket->port = -1;
}

void init_socket(t_Connection *connection)
{
	connection->protocole = getprotobyname("TCP");
	if (!connection->protocole)
	{
		print(2, "Can not initialize TCP\n");
		exit(1);
	}
	connection->fd = socket(AF_INET, SOCK_STREAM, connection->protocole->p_proto);

	if (connection->fd == -1)
	{
		print(2, "Can not initialize socket\n");
		exit(1);
	}
	if (connection->port == -1)
		connection->port = 6666;
	connection->s_in.sin_family = AF_INET;
    connection->s_in.sin_port = htons(connection->port);
    connection->s_in.sin_addr.s_addr = INADDR_ANY;
	init_socket2(connection);
	printf("Server start with port: %d\n", connection->port);
}