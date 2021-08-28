#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
      FILE *fp,*fp1;
      char ch,c1,c2,fname[100];
      int i,pos;

      fp=fopen("input.txt","r");
      if(fp==NULL)
      {
            printf("File does not exist..");
      }
      fseek(fp,0,SEEK_END);
      pos=ftell(fp);

      i=0;
      while(i<pos)
       {
            i++;
            fseek(fp,-i,SEEK_END);
            ch=fgetc(fp);
            printf("%c",ch);
      }

    printf("\nEnter the filename with extension: ");
    gets(fname);
    fp1 = fopen(fname, "w");
    fp=fopen("input.txt","r");
    c1=fgetc(fp);
     while(c1!=EOF)
           {
               fputc(c1,fp1);
               c1=fgetc(fp);
           }
    fclose(fp1);
    fp1=fopen(fname,"r");
    printf("new file contents are: ");
    c2=fgetc(fp1);
     while(c2!=EOF)
           {
               printf("%c",c2);
               c2=fgetc(fp1);
           }
    fclose(fp1);
    fclose(fp);
      return 0;
}
