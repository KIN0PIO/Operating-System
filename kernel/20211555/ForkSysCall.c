
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int forkSysCall(void)
{
    pid_t pid;
    /*fork a child process*/
 
    pid = fork();
    if (pid < 0){
      fprintf(stderr, "Fork Failed");
      return 1;
    }
    else if (pid == 0) {
      printf("child process is working ...\n");
      execlp("/bin/ls","ls",NULL);
      printf("Child process is done.\n");
    }
    else {
      printf("parents process is working ...\n");
      wait(NULL);
      printf("Parent process is done.\n");
    }
    return 0;
}

/*
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int forkSysCall(void) {
    pid_t pid;
    
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process is working ...\n");
        printf("Child process is done.\n");
    } else {
        // Parent process
        printf("Parent process is working ...\n");
        printf("Parent process is done.\n");
    }
    
    return 0;
}
*/

