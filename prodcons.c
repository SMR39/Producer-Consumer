/***********************************************************************************************
SGP ASSIGNMENT 1

prodcons.c

A simple program to demonstrate Producer Consumer Scheme between 2 processes i.e parent and child
using pipes.

type 'quit' after entering the text to exit the program.

Authors : Shashi & Ishan

*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUF 200


void main()

{
    pid_t pid;
    int mypipefd[2]; 											  // initializing pipe with two fd to read and write.
    int ret;	
    char buf[BUF], buf2[BUF] ;

    ret = pipe(mypipefd);  									         // create a pipe
    if (ret == -1)
    {
        perror("pipe failed");
        exit(1);
    }

    pid = fork();
    if(pid == 0)
    {
        /*child process*/

        close(mypipefd[0]);

        printf ("\nPlease enter a line of text, max %d characters\n\n", sizeof(buf));

        while(fgets(buf, sizeof(buf), stdin)) 								// check if any input from keyboard and store in buff
        {
            write (mypipefd[1], buf, sizeof(buf)); 							// write  to mypipe[1] from buff
            sleep(2);
            if(strncmp(buf,"quit",4) == 0) 								// exit when user enter 'quit' in lowercase
            {
                printf("exiting... \n\n");
                exit(0);
            }
        }
    }
    else if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else
    {
        /*parent process*/

        close(mypipefd[1]);
        while(read(mypipefd[0], buf2, sizeof(buf2))) 						      // read from mypipe[0] and store in buf2
        {
            printf("\nyou have entered : %s\n",buf2 );
        }
    }


}
