#ifndef UTIL_H_
#define UTIL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/dir.h>
#include<signal.h>

static int eflag=0;
void parse(char*,char**);
void execute(char**);
void sigint();                                 // Handler in case SIGINT occurs


#endif


