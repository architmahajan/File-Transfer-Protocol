#include "mylib.h"

//-----------------------------------------------------------------------------------------

int Socket(int family, int type, int protocol)
{
	int n;

	n=socket(family,type,protocol);

	if (n < 0)
	{
		printf("socket error");
		exit(1);
	}
	return(n);
}

//------------------------------------------------------------------------------------------

void Inet_pton(int family,const char *strptr,void *addrptr)
{
	int	n;

	n=inet_pton(family,strptr,addrptr);

	if (n<=0)
	{
		printf("inet_pton error for %s", strptr);
		exit(1);
	}
}

//--------------------------------------------------------------------------------------------

void Connect(int fd,const struct sockaddr *sa,socklen_t salen)
{
	int n;
	n=connect(fd,sa,salen);
	if(n<0)
	{
		printf("connect error");
		exit(1);
	}
}

//--------------------------------------------------------------------------------------------

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t	n;

	n=read(fd,ptr,nbytes);

	if (n<0)
	{
		printf("read error");
		exit(1);
	}
	return(n);
}

//---------------------------------------------------------------------------------------------

void Close(int fd)
{
	int n;

	n=close(fd);

	if(n== -1)
	{
		printf("close error");
		exit(1);
	}
}

//----------------------------------------------------------------------------------------------

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	int n;
	n=bind(fd,sa,salen);
	if (n< 0)
	{
		printf("bind error");
		exit(1);
	}
}

//----------------------------------------------------------------------------------------------

void Listen(int fd, int backlog)
{
	char *ptr;

		/*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
	{
		printf("listen error");
		exit(1);
	}
}

//---------------------------------------------------------------------------------------------

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int	n;
	n=accept(fd,sa,salenptr);
	if (n< 0)
	{
		printf("accept error");
		exit(1);
	}
	return(n);
}

//----------------------------------------------------------------------------------------------

void Write(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
	{
		printf("write error");
		exit(1);
	}
}

//----------------------------------------------------------------------------------------------

void Send(int fd, const void *ptr, size_t nbytes, int flags)
{
	if (send(fd, ptr, nbytes, flags) != (ssize_t)nbytes)
	{
		printf("send error");
		exit(1);
	}
}

//----------------------------------------------------------------------------------------------

ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags)
{
	ssize_t	n;

	if ( (n = recv(fd, ptr, nbytes, flags)) < 0)
	{
		printf("recv error");
		exit(1);
	}
	return n;
}