/* Daemon main thread*/

#include "daemon_header.h"
extern struct sockaddr_in sAddr;


int CreateDaemon(void)
{
    pid_t pid;
    int nRet = 0, Status = 0;
    int Sockfd, Clientfd, nLen = sizeof(sAddr);
    char strBuffer[BUFFER_SZ] = { '\0' };
    char *pBuffer = "Hello from Server";
    FILE *fp = NULL;

    pid = fork();
    if(pid == ERR_VAL)
    {
	return ERR_VAL;
    }
    if(pid > 0)
    {
	exit(0);
    }
    else
    {
	/* Child process */
	nRet = setsid();
	if(nRet == ERR_VAL)
	{
            return ERR_VAL;
	}
	nRet = chdir("/");
	if(nRet == ERR_VAL)
	{
            return ERR_VAL;
	}
	close(0);
	close(1);
	close(2);
        Status = CreateSocket(&Sockfd);
        if(Status != SUCCESS)
        {
	    return ERR_VAL;
        }
	fp = fopen("ClientLog.txt","w+");
	while(1)
        {

	    fprintf(fp, "Waiting for Client connection\n");
	    fflush(fp);
            Clientfd = accept(Sockfd, (struct sockaddr *)&sAddr, (socklen_t *)&nLen);
            if(Clientfd < 0)
            {
                return ERR_VAL;
            }
	    fprintf(fp, "Client Sock Fd is %d\n",Clientfd);
	    fflush(fp);
	    /* Read buf from client and
	     * send Hello message to client */
            read(Clientfd, strBuffer, BUFFER_SZ);
            send(Clientfd, pBuffer, strlen(pBuffer), 0);
        }
        return Status;
    }
}
int main(int argc, char *argv[])
{
    int Status = 0;

    Status = CreateDaemon();
    if(Status != SUCCESS)
    {
	return ERR_VAL;
    }
    return Status;
}
