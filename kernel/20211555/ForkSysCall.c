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
    }
    else {
      wait(NULL);
      printf("parents process is working ...\n");
    }
    return 0;
}

