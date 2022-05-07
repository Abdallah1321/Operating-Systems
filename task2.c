#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char str[100];
	int fd[2];
	int return_value;

	return_value = pipe(fd);

	if (return_value < 0){
		printf("Error creating pipe");
		exit(1);
	}

	printf("enter String: ");
	fgets(str, 100, stdin);	
	write(fd[1],str,strlen(str));
	printf("\npid is %d for sending message through pipe",getpid());
	printf("\n\nThe message in pipe is: %s\n",str);	
	for(int i=0;i<strlen(str);i++)
		{
		if((int)str[i]>=65 && (int)str[i]<=90)
			{
				str[i]=(int)str[i]+32;
			
			}
		else if((int)str[i]>=97 && (int)str[i]<=122)
			{
				str[i]=(int)str[i]-32;
			
			}
		}
	close(fd[0]);
	read(fd[0],str,strlen(str));
	printf("pid is %d for reading in pipe ",getpid());
	printf("\n\nreading from the file: %s\n",str);
	
}