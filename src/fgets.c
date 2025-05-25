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

typedef char * string;
char str[450];
int i;
char str2[450];
int i2;
char path[80];
char note[100];
char fname[100];
char fname2[100];
char *spacerg=";            ";
char *spacerb=":            ";
char *spacer2="                       ";
char *spacer="            ";
int cols;
char tcols[8];
char redc;

void writeIndex(char *fname)
{
  char danne[40];
  char danne2[40];
  strcpy(danne,"./APPEND ");
  strcpy(danne2,fname);
  strcat(danne,danne2);
  system(danne);

}

int main (int argc, char const *argv[])

{
  printf("Note Name: ");
  fgets(note, 80, stdin);
  strcpy(fname,note);
  i2 = strlen(fname)-1;

  if( fname[ i2 ] == '\n')
    fname[i2] = '\0';

  char *p;

  p = strchr(fname, ' ');

  while (p != NULL) {
    fname[p - fname]='_';
    p = strchr(p + 1, ' ');
  }


  char fullname[20];
  strcpy(fullname,"./notes/");
  strcat(fullname, fname);
  printf("Fullname: %s", fullname);


  FILE *fp;
  fp = fopen(fullname, "a");
  printf("For background color: type: Red=\"r\", Green=\"g\" or Blue=\"b\" (none=Yellow)\n");
  printf("Enter text: ");
  fgets(str, 450, stdin);
  i = strlen(str)-1;

  if( str[ i ] == '\n')
    str[i] = '\0';

  printf("%sOk wrote:%s %s\"%s to your note!\"%s\n",blue, none, yellow, str, none);
  fprintf(fp,"%s%s%s", str, spacer2, spacer2);
  fclose(fp);

  writeIndex(fname);
}




