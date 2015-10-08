/***********************************************************************************************
SGP ASSIGNMENT 1

prod.c

A simple program to demonstrate Producer Consumer Scheme between 2 Independent processes using
named pipes.

type 'quit' after entering the text to exit the program.

please run prod.c before cons.c 

Authors : Shashi & Ishan

*************************************************************************************************/


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_MAX 1024

void main()
{
    int fd;
    int res;
    char * myfifo1 = "/tmp/myfifo1";

    char buffer[BUFF_MAX];

    res =  mknod(myfifo1, S_IFIFO | 0666, 0);   // create a named pipe


    if(res == -1)
    {
        perror("mkfifo");
        exit(1);
    }


    fd = open(myfifo1, O_WRONLY);               // open fifo in write mode

    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    else
    {
        printf("please enter the text\n");

        while(fgets(buffer, BUFF_MAX, stdin))
        {

            res = write(fd, buffer, BUFF_MAX);

            if(res == -1)
            {
                perror("write");
                exit(1);
            }

            sleep(2);

            if(strncmp(buffer,"quit",4) == 0)
            {
                printf("exiting... \n\n");
                close(fd);
                exit(0);

            }
        }




    }
}
