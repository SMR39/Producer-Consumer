/***********************************************************************************************
SGP ASSIGNMENT 1

cons.c

A simple program to demonstrate Producer Consumer Scheme between 2 Independent processes using
named pipes.

Authors : Shashi & Ishan

*************************************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>


#define BUFF_MAX 1024


void main()
{

    int fd;
    int res;
    char buff[BUFF_MAX];
    char * myfifo1 = "/tmp/myfifo1";


    //unlink(myfifo1);


    fd = open(myfifo1, O_RDONLY);  // open pipe in read mode

    if(fd == -1)
    {
        perror("open");
        exit(1);
    }


    while((res = read(fd, buff, BUFF_MAX)) != 0)
    {
        if(res==-1)
        {
            perror("read");
            break;
        }

        //end of line character
        else
        {
            printf("you have entered : %s\n",buff);

            if(strncmp(buff,"quit",4) == 0) 								// exit when user enter 'quit' in lowercase
            {
                printf("exiting... \n\n");
                close(fd);
                unlink(myfifo1);
                printf("fifo is deleted\n");
                exit(0);
            }
        }
    }



}
