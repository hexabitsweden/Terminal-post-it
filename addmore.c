#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#define red   "\033[0;31m"        
#define cyan  "\033[1;36m"      
#define green "\033[0;32m"     
#define blue  "\033[9;34m"  
#define yellow "\e[1;33m" 
#define black  "\033[9;34m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"
#define bred  "\e[0;30;41m" 
#define bgreen "\e[0;30;42m"
#define byellow "\e[0;30;43m"
#define none   "\033[0m" 
#define pink   "\e[1;30;31m"
#define bblue  "\e[46m"
#define bpurple  "\e[45m"
#define menucol "\e[0;30;43m"
/* This should be built in to tnotes.c or imported instead */
char str[150];
int i;
char str2[150];
int i2;
char path[80];
char note[100];
char fname[100];
char fname2[100];
typedef char * string;
char tester[10];
char inpt[20];
char text[200];
char text2[200];
 int  main(argc, argv)
 
   int argc; char **argv;
      {

       strcpy(fname, argv[1]);
       i2 = strlen(fname)-1;

       if( fname[ i2 ] == '\n') 
          fname[i2] = '\0';  

    FILE *fp;
    fp = fopen(fname, "a");
    printf("Enter text: ");
    fgets(str, 150, stdin);
    i = strlen(str)-1;

    if( str[ i ] == '\n') 
       str[i] = '\0';

    printf("%sOk wrote:%s %s\"%s to your note!\"%s\n",blue, none, yellow, str, none);
    fprintf(fp,"%s", str);
    fclose(fp);
   }


