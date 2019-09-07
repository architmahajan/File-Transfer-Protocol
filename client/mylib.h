//Headers

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

//Variable



//Macros

#define	SA struct sockaddr
#define MAXLINE 1024*4

//Function

int Socket(int family,int type,int protocol);	             //Wrapper Function for socket()

void Inet_pton(int,const char *,void *);					 //Wrapper Function for inet_pton()

void Connect(int,const SA *,socklen_t);                      //Wrapper Function for connect()

ssize_t Read(int,void *,size_t);                             //Wrapper Function for read()

void Close(int);											 //Wrapper Function for close()

void Bind(int,const SA *,socklen_t);						 //Wrapper Function for bind()

void Listen(int,int);										 //Wrapper Function for listen()

int	Accept(int, SA *, socklen_t *);							 //Wrapper Function for accept()

void Write(int,void *,size_t);					 			 //Wrapper Function for write()

void Send(int fd, const void *ptr, size_t nbytes, int flags);//Wrapper Function for send()

ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags);   //Wrapper Function for recv()