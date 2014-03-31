#include"util.h"

void execute(char **args)
{
pid_t child,c;
if ((child=fork())==0){
    if (execvp(*args, args) < 0){
    printf("%s: command not found...\n",*args);
    exit(1);
}
}
else{
    int cstatus;
    c = wait(&cstatus); /* Wait for child to complete. */
}
return;
}

void parse(char *str, char **argv)
{
while(*str!='\0'){
    while(*str==' '||*str=='\t'||*str=='\n')
        *str++='\0';
    *argv++=str;
    while(*str!='\0'&& *str!=' ' && *str!='\t' && *str!='\n')
        str++;
}
*argv = '\0';
}


void sigint(){}
