#include<stdio.h>
#include<stdlib.h>
#include<unistd>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
	int fd[2],fd1[2],Pn;
	pid_t p1;
	pipe(fd);
	char buffer[100];
	pipe(fd1);
	p1=fork();
	if(p1>0)
	{
		close(fd[0]);
		printf("parent process\n");
		write(1,"Please enter message you want to send to\n",34);
		n=read(0,buffer,sizeof(buffer));
		write(fd[1],buffer,n);
		wait(NULL);
		close(fd1[1]);
		n=read(fd1[0],buffer,n);
		printf("parent process\nreceived message from child process is %s",buffer);
	}
	else
	{
		close(fd[1]);
		n=read(fd[0],buffer,100);
		printf("child process\nreceived message is %s\n",buffer);
		for(int i=0;buffer[i]!='\0';i++)
		{
			if(buffer[i]>='a'&&buffer[i]<='z')
			{
				buffer[i]=buffer[i]-32;
			}
			else if(buffer[i]>='A'&&buffer[i]<='Z')
			{
				buffer[i]=buffer[i]+32;
			}
		}
		close(fd1[0]);
		printf("sending modified message again back to parent process\n");
		write(fd1[1],buffer,n);
	}
}

