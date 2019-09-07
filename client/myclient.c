#include "mylib.h"

int main(int argc,char **argv)
{
	int sock1,PORT,n;
	char buffer[MAXLINE+1];
	struct sockaddr_in svraddr;

	if(argc<4)
	{    
		printf("plz provide <IP Address> and <PORT Number>");
		exit(1);
	}

	bzero(&svraddr,sizeof(svraddr));

	sock1=Socket(AF_INET,SOCK_STREAM,0);

	PORT=atoi(argv[2]);

	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(PORT);
  
	Inet_pton(AF_INET,argv[1],&svraddr.sin_addr);

	Connect(sock1,(SA *)&svraddr,sizeof(svraddr));

	FILE *myfile = fopen(argv[3],"w");
	printf("x");
	while(1)
    {
    	printf("xx") ;
        ssize_t data_in_byte = Recv(sock1, buffer, sizeof(buffer), 0);
   
        if (data_in_byte == 0) 
        	break;

        if (fwrite(buffer, 1, data_in_byte, myfile) != (size_t)data_in_byte)
        {
            printf("fwrite");
            break;
        }

        printf("Received %i bytes from network...\n", (int)data_in_byte);
    }
    
    fclose(myfile);

	Close(sock1);
	return 0;
}