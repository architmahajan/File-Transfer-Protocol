#include "mylib.h"

int main(int argc,char **argv)
{
	int sock1,sock2,PORT;
	char buffer[MAXLINE+1];
	struct sockaddr_in svraddr;

	if(argc<3)
	{
		printf("plz provide <PORT Number>");
		exit(1);
	}

	bzero(&svraddr,sizeof(svraddr));

	sock1=Socket(AF_INET,SOCK_STREAM,0);

	PORT=atoi(argv[1]);

	svraddr.sin_family=AF_INET;
	svraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	svraddr.sin_port=htons(PORT);

	Bind(sock1,(SA *)&svraddr,sizeof(svraddr));

	Listen(sock1,MAXLINE);

	sock2=Accept(sock1,(SA *)NULL,NULL);
          
	FILE *myfile = fopen(argv[2],"r");
	printf("f") ;
	while(1)
    {
    	printf("ff");
        ssize_t data_in_byte = fread(buffer, 1, sizeof(buffer), myfile);
        if ( data_in_byte <= 0)
        	break;
        
        Send(sock2, buffer, data_in_byte , 0);

        printf("sending %i bytes to network...\n", (int)data_in_byte);
    }
    fclose(myfile);
	Close(sock1);
	return 0;
}