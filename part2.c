/***********************************************************************************************
SGP ASSIGNMENT 1

part2.c

A simple program to demonstrate FORK EXEC & WAIT System Calls


Authors : Shashi & Ishan

*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main ()
{
    printf ("the exec program process ID is %d\n", (int) getpid ());
    exit(0);
}
