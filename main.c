#include"util.h"

int main(int argc, char **argv){
char *name;
if(argv[0][0]=='.' && argv[0][1]=='/')
    name = argv[0]+2;
else
    name = argv[0];
if(argc>2){
    printf("Usage: %s [batchfile]\n",name);
}
else if(argc==2){
FILE* fp = fopen(argv[1],"r");
if(fp==NULL){
    fprintf(stderr,"%s: %s: No such file or directory\n",name,argv[1]);
}
else {
    char *str = (char*) malloc(80*sizeof(char));
    char  *args[64];
    while (fscanf(fp,"%s",str)!=EOF){
        if(!strcmp(str,"quit")) exit(1);
        parse(str,args);
        execute(args);
    }
    free(str);
    }
}
else {
    char pathname[PATH_MAX];
    if (!getwd(pathname)){
        printf("Error getting path\n");
        exit(0);
    }
    int count,i;
    for( i=0;pathname[i]!='\0';i++)
    if(pathname[i]=='/') count=i;
    for(i=count+1;pathname[i]!='\0';i++) pathname[i-count-1]=pathname[i];
    pathname[i-count-1]=pathname[i];
    char *user,*hostname;
    user=getenv("USER");
    hostname=getenv("HOSTNAME");
    char* str;
    char  *n;
    signal(SIGINT,&sigint);
    char  *args[64];
    while(1){
        str = (char*) malloc(80*sizeof(char));
        printf("[%s@%s %s] # ",user,hostname,pathname);
        gets(str);	
        if(!strcmp(str,"quit")) break;
        parse(str,args);
	execute(args);
        free(str);
    }
}
return 0;
}
