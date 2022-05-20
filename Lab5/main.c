#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>


int run = 1;
int count;
char buf[256];


void sigHandler(int code) {
    switch (code)
    {
    case 2:
        printf("Caught SIGINT\n");
        break;
    case 3:
        printf("Caught SIGQUIT\n");
        break;
    case 15:
        printf("Caught SIGTERM\n");
        break;
    default:
        break;
    }
    run=0;
}


int main(int args, char* argv[])
{
    signal(SIGINT, sigHandler);
    signal(SIGQUIT, sigHandler);
    signal(SIGTERM, sigHandler);

    if (argv[1] == NULL)
    {
        count=0;
    }
    else
    {
        count = atoi(argv[1]);
    }

    while (run == 1)
    {
        printf("%d\n", count);
        sleep(5);
        count++;
    }   

    sprintf(buf, "%d", count);
    argv[1] = strdup(buf);
    
    pid_t pid = fork();
 
    if (pid == -1) {
        printf("Unable to fork\n");
    } else if (pid > 0) {
        printf("I am parent %d\n", getpid());
        printf("Child is %d\n", pid);
        printf("End\n");
    } else {
        // we are the child            
        printf("//////////\nI am child %d of %d\n", getpid(), getppid());
        if (execv("main",argv) == -1) {
            printf("Unable to exec\n");
        }
    }
    return 0;
}