#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


void  execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
     }
}

int  main(void)
{
     char  cmd[1024];             /* the input line                 */
     char  *arg[64];              /* the command line argument      */

     while (1) {                   /* repeat until done ....         */
          printf("Shell -> ");     /*   display a prompt             */
          gets(cmd);              /*   read in the command line     */
          printf("\n");int i=0;
         // parse(line, argv);
          arg[i++]=strtok(cmd," ");
        while(arg[i-1]!=NULL)
        {arg[i++]=strtok(NULL," ");}        /*   parse the line               */
          if (strcmp(arg[0], "exit") == 0)  /* is it an "exit"?     */
               exit(0);            /*   exit if it is                */
          execute(arg);           /* otherwise, execute the command */
     }
}
