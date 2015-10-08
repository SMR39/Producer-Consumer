/***********************************************************************************************
SGP ASSIGNMENT 1

part1.c

A simple program to demonstrate FORK EXEC & WAIT System Calls


Authors : Shashi & Ishan

*************************************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{
    pid_t child_pid,wpid;

    int child_status;

    printf ("the main program process ID is %d\n", (int) getpid ());

    child_pid = fork ();

    if (child_pid == 0)
    {
        execl("/home/SMR/Desktop/part2","part2",0);

        perror("execl() failure!\n\n");

        printf ("this is the child process, with id %d\n", (int) getpid ());    // should not print this if exec is succesfull
    }
    else if (child_pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    else
    {
        printf ("this is the parent process, with id %d\n", (int) getpid ());

        printf ("the child’s process ID is %d\n", (int) child_pid);

        wpid = wait(&child_status);                                             // returns the identifier of terminated process to wpid and stores the status in pointer argument

        if (WIFEXITED(child_status))                                            //checks for normal exit

            printf("Child %d terminated with exit status --> %d\n",
                   wpid, WEXITSTATUS(child_status));                            // prints process id and exit status

        else
            printf("Child %d terminate abnormally\n", wpid);
    }


    return 0;
}
