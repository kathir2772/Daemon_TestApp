/* Create socket */

#include "daemon_header.h"

int CreateLogFile(void)
{
    FILE *fp = NULL;
    fp = fopen ("LogNew.txt", "w+");
    while (1)
    {
        sleep(1);
        fprintf(fp, "Logging info...\n");
        fflush(fp);
    }
}
struct sockaddr_in sAddr;

int CreateSocket(int *Sockfd)
{
    int Status = 0, nRet = 0;
    int opt = 1;
   
    *Sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(Sockfd <= 0)
    {
	return ERR_VAL;
    }

    if(setsockopt(*Sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
       &opt, sizeof(opt)))
    {
	return ERR_VAL;
    }

    sAddr.sin_family = AF_INET;
    sAddr.sin_addr.s_addr = INADDR_ANY;
    sAddr.sin_port = htons( PORT );
    nRet = bind(*Sockfd, (struct sockaddr *)&sAddr, sizeof(sAddr));
    if(nRet < 0)
    {
        return ERR_VAL;
    }

    if(listen(*Sockfd, 3) < 0)
    {
	return ERR_VAL;
    }

    return Status;

}
