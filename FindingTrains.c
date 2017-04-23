#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
   int  i,count=0,temp=0;
   char Time[10],stCode[5];
   printf("Enter Time:");
   scanf("%s",&Time);
   printf("Enter Station:");
   scanf("%s",stCode);
   FILE *fp;
   char str[7000],arr[50];
   char *p,*c;
   fp = fopen("D:\\Train.txt", "r");
   if(fp == NULL)
   {
      perror("Error opening file");
      return(-1);
   }
   while(fgets(str,sizeof str, fp)!=NULL )
   {
        p=strstr(str,stCode);
        if(strstr(str,stCode))
        break;
   }
   int x = strlen(Time);
  // printf("%d",x);
   //printf("%s",p);
   for(i=10;i<strlen(p);i++){
   if(p[i]==':' || p[i]=='k'){
        count++;
    if(x==5&&isdigit(p[i-2])){
        if(Time[0]==p[i-2] && Time[1]==p[i-1] && Time[3]==p[i+1] && Time[4]<=p[i+2]){
            printf("%c""%c"":""%c""%c",p[i-2],p[i-1],p[i+1],p[i+2]);
            break;
        }
        else if(Time[0]==p[i-2] && Time[1]==p[i-1] && Time[3]<p[i+1]){
            printf("%c""%c"":""%c""%c",p[i-2],p[i-1],p[i+1],p[i+2]);
            break;
        }
        else if(Time[0]==p[i-2] && Time[1]<p[i-1]){
            printf("%c""%c"":""%c""%c",p[i-2],p[i-1],p[i+1],p[i+2]);
            break;
        }
        else if(Time[0]<p[i-2]){
            printf("%c""%c"":""%c""%c",p[i-2],p[i-1],p[i+1],p[i+2]);
            break;
        }
    }
    else if(x==4){
         if(Time[0]==p[i-1] && Time[2]==p[i+1] && Time[3]<=p[i+2]){
            printf("%c"":""%c""%c",p[i-1],p[i+1],p[i+2]);
            break;
        }
        else if(Time[0]==p[i-1] && Time[2]<p[i+1]){
            printf("%c"":""%c""%c",p[i-1],p[i+1],p[i+2]);
            break;
        }
        else if(Time[0]<p[i-1]){
            printf("%c"":""%c""%c",p[i-1],p[i+1],p[i+2]);
            break;
        }
    }
   }
   }
   printf("\n");
   fclose(fp);
   count -=1;
   fp = fopen("D:\\Train.txt", "r");
   int j;
   char strForm[100] = "Train";
   while(fgets(str,sizeof str, fp)!=NULL )
   {
        c=strstr(str,strForm);
        if(str,strForm)
            break;
   }
   temp = 15 + count*6;
   printf("%c""%c""%c""%c""%c",c[temp],c[temp+1],c[temp+2],c[temp+3],c[temp+4]);
   fclose(fp);

}
