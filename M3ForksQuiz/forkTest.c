#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    int i;
    pid_t p;
    int value;

    for(i=0; i<4; i++){
        p = fork();
        if(p == 0){
            printf("%ld: child process to %ld parent process \n", (long)getpid(), (long)getppid());
            exit(i);
        }
    }
    if (p > 0){
        while((p = waitpid(-1, &value, 0)) != -1){
            printf("%ld: My child process %ld exited(%ld)\n", (long)getpid(), p, WEXITSTATUS(value));
        }
    }
    return 0;

} 
