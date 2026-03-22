#include "tcp_sockets.h"

void panic(const char *str)
{
	perror(str);
	exit(-1);
}

int connect_to_server(char *ip,int port)
{
	int sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sock_fd < 0)
	{
		panic("socket ");
	}

	// filling in the server's IP and Port number
	struct sockaddr_in sin;
	memset(&sin,0,sizeof(sin));

	sin.sin_family      = AF_INET;
	sin.sin_port        = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);


	int status = connect(sock_fd,(const struct sockaddr *)&sin,sizeof(sin));
	if(status < 0)
	{
		//printf("%d status : %d  sock_fd\n",status,sock_fd);
		//panic("connect ");
	}

	//printf("%d status : %d  sock_fd\n",status,sock_fd);
	close(sock_fd);
	return status; // we have connected to the server
}

void tcp_scan_range(char *ip,int start,int end)
{
	for(int i = start; i < end; i++)
	{
		int status = connect_to_server(ip,i);
		if(status == 0)
		{
			printf("port %d opened\n",i);
		}
	}

}

void tcp_scan(char *ip,int proc)
{
	int pids[proc];
	int start  = 0;
	int offset = 50;

	for (int ii = 0; ii < 10000; ii += proc * offset)
	{
		start = ii;
		for(int i = 0; i < proc; i++)
		{
			int pid = fork();
			if(pid == 0)
			{
				tcp_scan_range(ip,start,start + offset);
				exit(0);
			}

			pids[i] = pid;
			start += offset;
		}
	}

	
	for(int i = 0; i< proc; i++)
	{
		waitpid(pids[i],NULL,0);
	}
}


int main(int argc,char **argv)
{
	tcp_scan(argv[1],30);
	return 0;
}
