#include <stdio.h>
#include "postman.h"
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/file.h>
#include <strings.h>
#define bufsize 1024
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
#define bgreen "\e[0;37;42m"
#define bgreenb "\e[0;30;42m"
#define byellow "\e[0;30;43m"
#define none   "\033[0m"
#define pink   "\e[1;30;31m"
#define bblue  "\e[0;30;46m"
#define bpurple  "\e[0;30;45m"
#define menucol "\e[0;30;43m"
#define bwhite "\e[0;31;47m"
#define white  "\033[0;37m"
#define MAX 81
#define men    "menu"
#define SIZE 256
/*****************************************
 *      *
 *            *
 *               *
 *  *
 *           *
 * *
 ****************************************/
char tt;
char tname[60];
char tname2[60];
typedef char * string;
char files[50];
string lister[40];
char bcolor[6];
char bcolors[10];
char file[8];
char cmd[SIZE];
char namn[10];
char name[100];
char ftype[]=".txt";
char note[]="notes/";
int ant;
char cc;
int colums;
int tvt;
FILE *fp;

int makeBars(int ant, string bcolors) {
  tvt = 0;
  while (tvt != ant) {
    printf("%s-------%s", bcolors, none);
    tvt++;
    if (tvt == ant) {
      printf("\n");
    }
  }
  return 1;
}

int  menu() {
  system("clear");
  printf("\n");
  printf(" %s o             o %s   %s o               o \n%s %s    T-notes      %s   %s  5.Mark as Done   \n%s",bgreenb, none, byellow, none, bgreenb, none, byellow, none);
  printf(" %s        BETA     %s   %s  6.Read Old msg   \n%s %s                 %s   %s  7.Backup/Restore \n%s",bgreenb, none, byellow, none, bgreenb, none, byellow, none);
  printf(" %s                 %s   %s                   %s\n",bgreenb, none, byellow, none);
  printf("\n");
  printf("       %s o                o %s %s o            o %s\n       %s  1.List/Read       %s %s   8.FlatDB     %s\n       %s  2.Create New      %s %s   0.Delete     %s\n       %s  3.Append to note  %s %s   4.Help       %s \n", bred, none, bpurple, none, bred, none, bpurple, none, bred, none, bpurple, none, bred, none, bpurple, none);
  printf("       %s  9.Archive Note    %s %s           %s o      o %s\n", bred, none, bpurple, bgreenb, none);
  printf("       %s                    %s %s           %s          %s\n", bred, none, bpurple, bgreenb, none);
  printf(" %s             Daniel Jendinger 2012    %s%s          %s\n", white, none,  bgreenb, none);
  printf("%s                                       %s%s          %s\n", white, none, bgreenb, none);
  /*makePostmini(2, bpurple);*/
  inpt();
  return 0;
}

int readGet()
{
  /*system("./testIncoming"); */
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  strcpy(fname,"./notes/PARSE.TXT");

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
    return 1;
  }

  printf("\n");
  int tick=0;
  int tick2=0;
  int lwait=0;
  char wt;
  char *tcols=byellow;
  char string1[200];
  char *p;
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {
      tick++;
      tick2++;
      lwait++;

      p = strchr(tok, '_');

      while (p != NULL) {
        /*  printf ("found at %d\n",p - str + 1); */
        tok[p - tok]=' ';
        p = strchr(p + 1, '_');
      }

      if (tick2==3)
      {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      if(lwait==20)
      {
        printf("%s MORE:(enter) %s\n",yellow, none);
        wt=getchar();
        wt=getchar();
        lwait=0;
      }


      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n");
    makeBars(9, yellow);
    printf("Chose Note: ");
    scanf("%i",&noter);

    if(noter=='\0')
      menu();
    char t;
    strcpy(tname,lister[noter]);

    p = strchr(tname, ' ');
    /* Put the '_' back in filename */
    while (p != NULL) {
      tname[p - tname]='_';
      p = strchr(p + 1, ' ');
    }
    readNote(tname);
  }
  return 0;
}

int main (int argc, char const *argv[])
{

  system("clear");
  menu();
}



/*     test(file)
       {
       makeNewNote();
       makePostmini(2, namn, bred);
       return;
       }
       */
int makeNewNote()
{   /* Fungerar perfekt */
  system("./gettxt");
  scanf("%c", &tt);
  scanf("%c", &tt);
  tt=0;
  menu();
  return 0;
}

int makePostmini(int colums, string namn, string bcolors) {
  tvt = 1;

  while (tvt != colums) {
    printf("%s   %s\n", bcolors, none);
    tvt++;
    if (tvt==2) {
      printf("%s   %s >%s Reading:%s %s%s %s\n", bcolors, none, yellow, none, cyan, namn, none);

    }
    if (tvt == colums) {

    }
  }
  return 0;
}

int appendNote()
{
  char danne[40];
  char danne2[40];
  char *p;
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  strcpy(fname,"./notes/PARSE.TXT");
  char *tcols=byellow;
  char string1[100];
  int tick=0;
  int tick2=0;

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
    return 1;
  }
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {
      p = strchr(tok, '_');

      while (p != NULL) {
        /*  printf ("found at %d\n",p - str + 1); */
        tok[p - tok]=' ';
        p = strchr(p + 1, '_');
      }
      tick++;
      tick2++;

      if (tick2==2) {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n");
    makeBars(5, yellow);
    printf("Append to Note: ");
    scanf("%i",&noter);
    char t;
    strcpy(tname,lister[noter]);
    p = strchr(tname, ' ');
    /* Put the '_' back in filename */
    while (p != NULL) {
      tname[p - tname]='_';
      p = strchr(p + 1, ' ');
    }
    strcpy(danne,"./APPEND2 ");
    strcpy(danne2,tname);
    strcat(danne,danne2);
    system(danne);
    printf(" %s OK, text added! %s\n", cyan, none);
    scanf("%c", &tt);
    scanf("%c", &tt);
    tt=0;
    menu();
  }
  return 0;
}

int makePostit(int colums, char* bcolors) {
  tvt = 1;
  printf("%s        %s\n", bcolors, none);
  while (tvt != colums) {
    printf("%s        %s\n", bcolors, none);
    tvt++;
    if (tvt == colums) {
      printf("\n");
    }
  }
  return 0;
}

char listdir(char files)
{
  DIR *dp;
  char *tmp;
  struct dirent *ep;
  dp = opendir ("./notes/");
  if (dp != NULL)
  {
    while (ep == readdir (dp))
      puts (ep->d_name);
    (void) closedir (dp);
  }
  else
  perror ("Couldn't open the directory");
  return 0;
}



void notedb()
{
  system("vim notes.db");
  menu();
}

void archiveNote()
{
  /*system("cp -Rn * ../notetrash");*/
  char del1[40];
  char del2[40];
  char del3[40];
  char danne[40];
  char danne2[40];
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  strcpy(fname,"./notes/PARSE.TXT");
  int tick=0;
  int tick2=0;
  char *p;
  char *tcols=byellow;
  char string1[100];

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
  }
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {
      p = strchr(tok, '_');
      while (p != NULL) {
        /*  printf ("found at %d\n",p - str + 1); */
        tok[p - tok]=' ';
        p = strchr(p + 1, '_');
      }
      tick++;
      tick2++;

      if (tick2==2) {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n    %s  Archive Mode. 0=cancel%s\n", bpurple, none);
    makeBars(7, yellow);
    printf("Chose Note: ");
    scanf("%i",&noter);

    if (noter==0)
    {
      menu();
    }

    char t;
    strcpy(tname,lister[noter]);
    p = strchr(tname, ' ');
    /* Put the '_' back in filename */
    while (p != NULL) {
      tname[p - tname]='_';
      p = strchr(p + 1, ' ');
    }
    strcpy(danne,"rm ");
    strcpy(del1,"./delindex.sh ");
    strcpy(del2,tname);
    strcpy(danne2,tname);
    strcat(danne,danne2);
    strcat(del1,del2);
    /*   system(danne); */
    system(del1);
    printf(" %s  OK, ARCHIVED  %s\n", bgreen, none);
    scanf("%c", &tt);
    scanf("%c", &tt);
    tt=0;
    menu();
  }
}

void killNote()
{
  /*system("cp -Rn * ../notetrash");*/
  char dele1[40];
  char dele2[40];
  char dele3[40];
  char dannee[40];
  char dannee2[40];
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  strcpy(fname,"./notes/PARSE.TXT");
  int tick=0;
  int tick2=0;
  char *p;
  char *tcols=byellow;
  char string1[100];

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
  }
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {
      p = strchr(tok, '_');
      while (p != NULL) {
        /*  printf ("found at %d\n",p - str + 1); */
        tok[p - tok]=' ';
        p = strchr(p + 1, '_');
      }
      tick++;
      tick2++;

      if (tick2==2) {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n    %s  Warning! Delete Mode. 0=cancel%s\n", bwhite, none);
    makeBars(7, yellow);
    printf("Chose Note: ");
    scanf("%i",&noter);

    if (noter==0)
    {
      menu();
    }

    char t;
    strcpy(tname2,lister[noter]);
    p = strchr(tname2, ' ');
    /* Put the '_' back in filename */
    while (p != NULL) {
      tname2[p - tname2]='_';
      p = strchr(p + 1, ' ');
    }
    strcpy(dannee,"rm ");
    strcpy(dele1,"./kill_index.sh ");
    strcpy(dele2,tname2);
    strcpy(dannee2,tname2);
    strcat(dannee,dannee2);
    strcat(dele1,dele2);
    /*   system(danne); */
    system(dele1);
    printf(" %s  OK, DELETED  %s\n", bgreen, none);
    scanf("%c", &tt);
    scanf("%c", &tt);
    tt=0;
    menu();
  }
}


void readNote(string tname){
  system("clear");
  printf("\n");
  printf(" %s o             o %s   %s o               o \n%s %s    T-notes      %s   %s  5.Mark as Done   \n%s",bgreenb, none, byellow, none, bgreenb, none, byellow, none);
  printf(" %s        BETA     %s   %s  6.Read Old msg   \n%s %s                 %s   %s  7.Backup/Restore \n%s",bgreenb, none, byellow, none, bgreenb, none, byellow, none);
  printf(" %s                 %s   %s                   %s\n",bgreenb, none, byellow, none);
  printf("\n");
  printf("       %s o                o %s %s o            o %s\n       %s  1.List/Read       %s %s   8.Long       %s\n       %s  2.Create New      %s %s   0.In Logs    %s\n       %s  3.Append to note  %s %s                %s \n", bred, none, bpurple, none, bred, none, bpurple, none, bred, none, bpurple, none, bred, none, bpurple, none);
  printf("       %s  4.Delete Note     %s %s           %s o      o %s\n", bred, none, bpurple, bgreenb, none);
  printf("       %s                    %s %s           %s          %s\n", bred, none, bpurple, bgreenb, none);
  printf(" %s             Daniel Jendinger 2012    %s%s          %s\n", white, none,  bgreenb, none);
  printf("%s                                       %s%s          %s\n", white, none, bgreenb, none);

  FILE* fpd;
  char *tcol=byellow;
  char buf[bufsize], *tok, fname[15];
  char rr='r';
  char gg='g';
  char bl='b';
  char yy='y';
  int metr=0;
  if ((fpd = fopen(tname,"rt")) == '\0')
  {
    fprintf(stderr,"%sError opening file: %s%s\n",red, none, tname);
    scanf("%c", &tt);
    scanf("%c", &tt);
    menu();
  }

  int tick=0;
  char tjo[9];
  strcat(tjo,tname);
  tjo[0]=' ';
  makePostmini(2, tjo, byellow);
  printf("%s-", yellow);
  makeBars(7, yellow);

  FILE *fp = fopen("r","r");
  int c , nc, nlines;
  nlines = 0 ;
  nc = 0;
  fp = fopen( tname, "r" );
  if ( fp == NULL )
  {
    printf("Cannot open %s for reading \n", tname );
  }
  c = getc( fp ) ;

  while (  c != EOF )
  {
    nlines++ ;
    nc++ ;
    metr++;
    if (c==rr && metr==1)
    {
      tcol=bred;
      c=' ';
    }
    if (c==bl && metr==1)
    {
      tcol=bblue;
      c=' ';
    }
    if (c==yy && metr==1)
    {
      tcol=byellow;
      c=' ';
    }
    if (c==gg && metr==1)
    {
      tcol=bgreenb;
      c=' ';
    }
    if (c==',' || nc==49) {
      if (c==',' && nc!=49) {
        while (nc!=49) {
          c=' ';
          printf("%s ", tcol);
          nc++;
        }
      }
      printf("%s  %s\n", tcol, none);
      nc=0;
    }
    else {
      printf("%s%c%s", tcol, c, none);
      c = getc ( fp );
    }
  }
  if ( c==EOF && nc!=49 ) {
    while ( nc!=50) {
      printf("%s ", tcol);
      nc++;
    }
  }
  printf("%s\n", none);
  fclose( fp );
  scanf("%c", &tt);
  scanf("%c", &tt);
  tt=0;
  menu();
}

void markDone()
{
  char danne[40];
  char danne2[40];
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  char *tcols=byellow;
  char string1[100];
  strcpy(fname,"./notes/PARSE.TXT");

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
  }

  printf("\n");
  int tick=0;
  int tick2=0;
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {

      tick++;
      tick2++;

      if (tick2==2) {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n");
    makeBars(5, yellow);
    printf("Mark Note: ");
    scanf("%i",&noter);
    char t;
    strcpy(tname,lister[noter]);
    strcpy(danne,"./MARKDONE ");
    strcpy(danne2,tname);
    strcat(danne,danne2);
    system(danne);
    printf(" %s OK, Marked as DONE.. %s\n", bgreen, none);
    scanf("%c", &tt);
    scanf("%c", &tt);
    tt=0;
    menu();
  }
}

void showLog()
{
 /* system("./testIncoming"); */
  FILE* fpd;
  char buf[bufsize], *tok, fname[18];
  strcpy(fname, "./notes/inlog.txt");
  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"%sNo external messages... %s\n",red, none);
    scanf("%c", &tt);
    scanf("%c", &tt);
    menu();
  }
  printf("\n");
  int tick=0;
  makePostmini(2, fname, bred);
  makeBars(5, yellow);

  FILE *fp = fopen("r","r");
  int c , nc, nlines;
  nlines = 0 ;
  nc = 0;
  fp = fopen( fname, "r" );
  if ( fp == NULL )
  {
    printf("Cannot open %s for reading \n", fname );
  }
  c = getc( fp ) ;
  printf("     %s   Messages log  %s\n", bpurple, none);

  while (  c != EOF )
  {
    char end='#';
    nlines++ ;
    nc++ ;
    if ( c==end ) {
      c=' ';
      printf("\n");
    }
    if ( c=='-' ) {
      printf("%s%c%s", cyan, c, none);
      c=' ';
    }
    printf("%s%c%s", yellow, c, none);
    c = getc ( fp );
  }
  fclose( fp );
  char t;
  printf("      %s Press ENTER ..%s ", bgreen ,none);
  scanf("%c", &t);
  scanf("%c", &t);
  menu();
}

void oneline(char* tcol)
{
  printf("%s              %s\n", tcol, none);
}

void readOLD()
{
 /* system("./testIncoming"); */
  char *p;
  FILE* fpd;
  char buf[bufsize], *tok, fname[22];
  strcpy(fname,"./notes/PARSE_DEL.TXT");

  if ((fpd = fopen(fname,"rt")) == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",fname);
  }

  printf("\n");
  int tick=0;
  int tick2=0;
  int lwait=0;
  char wt;
  char *tcols=byellow;
  char string1[100];
  while(fgets(buf, bufsize, fpd) != NULL)
  {
    for(tok = strtok(buf," \n");tok;tok=strtok(0," \n"))
    {

      p = strchr(tok, '_');

      while (p != NULL) {
        /*  printf ("found at %d\n",p - str + 1); */
        tok[p - tok]=' ';
        p = strchr(p + 1, '_');
      }
      tick++;
      tick2++;
      lwait++;

      if (tick2==2)
      {
        printf("\n\n");
        tick2=0;
      }
      strcpy(string1,tok);

      if(string1[0]=='r')
      {
        string1[0]=' ';
        tcols=bred;
      }
      if(string1[0]=='g')
      {
        string1[0]=' ';
        tcols=bgreenb;
      }
      if(string1[0]=='b')
      {
        string1[0]=' ';
        tcols=bblue;
      }
      if(string1[0]=='y')
      {
        string1[0]=' ';
        tcols=byellow;
      }
      if(lwait==20)
      {
        printf("%s MORE:(enter) %s\n",yellow, none);
        wt=getchar();
        wt=getchar();
        lwait=0;
      }


      printf(" %s %s %s(%i)%s%s ", tcols, none, white, tick, none, string1);
      lister[tick] = tok;
    }
    fclose(fpd);
    int noter;
    printf("\n");
    makeBars(7, yellow);
    printf("Chose Note: ");
    scanf("%i",&noter);

    if (noter==0)
    {
      menu();
    }

    char t;
    strcpy(tname,lister[noter]);
    p = strchr(tname, ' ');
    /* Put the '_' back in filename */
    while (p != NULL) {
      tname[p - tname]='_';
      p = strchr(p + 1, ' ');
    }
    readNote(tname);
  }
}

void inpt ()
{
  printf("  %s CMD %s%s>>>%s", menucol, none, yellow, none);
  scanf("%c", &cc);
  switch( cc )
  {
    case '1':
      readGet();
      break;

    case '2':
      makeNewNote();
      break;

    case '3':
      appendNote();
      break;

    case '9':
      archiveNote();
      break;

    case '5':
      markDone();
      break;

    case '6':
      readOLD();
      break;

    case '8':
      notedb();
      break;

    case '0':
      /*   showLog(); */
      killNote();
      break;

    default :
      menu();
      break;
  }
  makeBars(5, yellow);
  /*test(namn);*/
  makeBars(5, yellow);
  readGet();
}

