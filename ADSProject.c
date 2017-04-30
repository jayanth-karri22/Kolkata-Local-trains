#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char Time[50];

int Whichtrain(int ini, int Fin){
    if (ini>17 && ini<35){
        printf("No  such train exists!!\n");
        exit(0);
    }
    if(ini<17){
            if(ini>Fin)
                return 1;
            else return 2;
    }
    else if(ini == 17 && Fin <17){
            return 1;
        }
        else if(ini<35){
            if(Fin>ini)
                return 3;
            else return 4;
        }
        else if(ini==38 &&Fin<35 ){
                    return 4;}
            else if(Fin>ini && Fin<35)
                    return 5;
                else if (ini>=35){
                        return 5;
                }
                    else return 6;
            return 0;
}
int pathFunc(char str1[], char str2[], int *end){
    char st[5];
    int n,ini=0,Fin=0,route;
    FILE *fin1,*fin2;
    fin1 = fopen("stations.txt","r");
    fin2 = fopen("stations.txt","r");
    if( !fin1){
        perror("Could not find the file!\n");
        exit(0);
    }
    if( !fin2){
        perror("Could not find the file!\n");
        exit(0);
    }
    while( fin1!= NULL){
        fscanf(fin1,"%s%d",st,&n);
        if(strcmp(str1,st)==0){
            ini=n;
            break;
        }
    }
    if( ini==0){
         printf("No such station exists...!\n");
            exit(0);
    }
    while( fin2!= NULL){
        fscanf(fin2,"%s%d",st,&n);
        if(strcmp(str2,st)==0){
            Fin=n;
            break;
        }
   }
    if( Fin==0){
         printf("No such station exists...!\n");
            exit(0);
    }
    route=Whichtrain(ini,Fin);
    fclose(fin1);
    fclose(fin1);
    *end = Fin;
    if (route==1 || route==2){
        if(Fin>17)
            *end=17;
    }
    else if(route==3 || route==4){
        if(Fin<18){
            *end = 17;
        }
        else if( Fin>38 || Fin==35|| Fin==36|| Fin==37){
            *end = 38;
        }
        else if (route ==4 && Fin>17 && Fin<33){
                *end = 17;
            }
    }
        else if(Fin<38 && Fin!=35 && Fin!=36 && Fin!=37)
            *end = 38;
    return route;
}
int timeReturn( char endStation[], int l, int count){
    char *t, str[1024];
    FILE *fp;
    switch(l){
        case 1:
            fp = fopen("1.txt", "r");
            break;

        case 2:
            fp = fopen("2.txt", "r");
            break;

        case 3:
            fp = fopen("3.txt", "r");
            break;

        case 4:
            fp = fopen("4.txt", "r");
            break;

        case 5:
            fp = fopen("5.txt", "r");
            break;

        case 6:
            fp = fopen("6.txt", "r");
            break;
        }
   while(fgets(str,sizeof str, fp)!=NULL )
   {
        t = strstr(str,endStation);
        if(t)
            break;
   }
   int count1 = 0, i=0;
   for(i=0;i<strlen(t);i++){
        if(t[i]==':' || t[i]=='k'){
            count1++;
            if(count1 == count+1){
                if(t[i] == 107){
                    printf("Train Won't Stop,Time for next available train is! \n-->");
                    return -1;
                    }
                else if(isdigit(t[i-2])){
                    Time[0]=t[i-2];Time[1]=t[i-1];Time[2]=t[i];Time[3]=t[i+1];Time[4]=t[i+2];
                    printf("%s",Time);
                    return 0;
                    }
                else{
                    Time[0]=t[i-1];Time[1]=t[i];Time[2]=t[i+1];Time[3]=t[i+2];
                    printf("%s",Time);
                    return 0;
                    }
            }
        }
   }

    fclose(fp);
    return 0;
}
int trainReturn(char stCode[], char Time[], int l,char endStation[]){
   int  i,temp=0,j=-1;
    FILE *fp,*fp1;
   char str[1024],arr[50];
   char *p,*c;
   while(j==-1){
   int count=0;
   switch(l){
        case 1:
            fp = fopen("1.txt", "r");
            fp1 = fopen("1.txt", "r");
            break;

        case 2:
            fp = fopen("2.txt", "r");
            fp1 = fopen("2.txt", "r");
            break;

        case 3:
            fp = fopen("3.txt", "r");
            fp1 = fopen("3.txt", "r");
            break;

        case 4:
            fp = fopen("4.txt", "r");
            fp1 = fopen("4.txt", "r");
            break;

        case 5:
            fp = fopen("5.txt", "r");
            fp1 = fopen("5.txt", "r");
            break;

        case 6:
            fp = fopen("6.txt", "r");
            fp1 = fopen("6.txt", "r");
            break;
        default:
            perror("No such File\n");
        }

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
   for(i=0;i<strlen(p);i++){
   if(p[i]==':' || p[i]=='k'){
        count++;
    if(x==5&&isdigit(p[i-2])){
        if(Time[0]==p[i-2] && Time[1]==p[i-1] && Time[3]==p[i+1] && Time[4]<=p[i+2]){
            Time[0]=p[i-2];Time[1]=p[i-1];Time[2]=':';Time[3]=p[i+1];Time[4]=p[i+2];
            printf("%s - Train arrival time",Time);
            break;
        }
        else if(Time[0]==p[i-2] && Time[1]==p[i-1] && Time[3]<p[i+1]){
            Time[0]=p[i-2];Time[1]=p[i-1];Time[2]=':';Time[3]=p[i+1];Time[4]=p[i+2];
            printf("%s  - Train arrival time",Time);
            break;
        }
        else if(Time[0]==p[i-2] && Time[1]<p[i-1]){
            Time[0]=p[i-2];Time[1]=p[i-1];Time[2]=':';Time[3]=p[i+1];Time[4]=p[i+2];
            printf("%s  - Train arrival time",Time);
            break;
        }
        else if(Time[0]<p[i-2]){
            Time[0]=p[i-2];Time[1]=p[i-1];Time[2]=':';Time[3]=p[i+1];Time[4]=p[i+2];
            printf("%s  - Train arrival time",Time);
            break;
        }
    }
    else if(x==4){
         if(Time[0]==p[i-1] && Time[2]==p[i+1] && Time[3]<=p[i+2]){
            Time[0]=p[i-1];Time[1]=':';Time[2]=p[i+1];Time[3]=p[i+2];
            printf("%s  - Train arrival time",Time);
            break;
        }
        else if(Time[0]==p[i-1] && Time[2]<p[i+1]){
            Time[0]=p[i-1];Time[1]=':';Time[2]=p[i+1];Time[3]=p[i+2];
            printf("%s  - Train arrival time",Time);
            break;
        }
        else if(Time[0]<p[i-1]){
            Time[0]=p[i-1];Time[1]=':';Time[2]=p[i+1];Time[3]=p[i+2];
            printf("%s - Train arrival time",Time);
            break;
        }
        else if(Time[0]=='9'){
            strcpy(Time,("10:00"));
            x = strlen(Time);
            i=0;
        }
    }
   }
   }
   if(i==strlen(p)){
    printf("No more Trains Left For the day\n");
    printf("Trains for the next day");
    strcpy(Time,("0:00"));
   }
   printf("\n");
   fclose(fp);
   count -=1;
   char strForm[100] = "Train";
   while(fgets(str,sizeof str, fp1)!=NULL )
   {
        c=strstr(str,strForm);
        if(str,strForm)
            break;
   }
   temp = 13 + count*6;
   j=timeReturn(endStation,l,count);
    if(j==-1)
    {
        if(strlen(Time)==5){
            Time[4]++;
        }
        else{
            Time[3]++;
        }
    }
   }
  printf(" %c""%c""%c""%c""%c ",c[temp],c[temp+1],c[temp+2],c[temp+3],c[temp+4]);
   fclose(fp1);
   return 0;
}

distributerFunc( char stCode[], char stCodef[], char Time[]){
   int  i,count=0,temp=0,l,end=0,counter,dum1,j=-1;
   char str[10],est1[5];
   while(j==-1){
    int k=0;
   l=pathFunc( stCode, stCodef, &end);
   FILE *fin;
   fin = fopen("stations.txt","r");
   if( !fin){
        perror("Could not find the file!\n");
    }
    for( counter=0; counter<end; counter++)
        fgets(str,sizeof str, fin);
    char *endStation;
    while(isalpha(str[k])){
        endStation[k]=str[k];
        k++;
    }
    fclose(fin);
    trainReturn(stCode,Time,l,endStation);
   if (endStation[0]==stCodef[0]&&endStation[1]==stCodef[1]&&endStation[2]==stCodef[2]){
        j=0;
        printf("%s to %s\n",stCode,endStation);
        printf("done");
   }
   else { printf("%s to %s\n",stCode,endStation);
        stCode[0]=endStation[0];
        stCode[1]=endStation[1];
        if(isalpha(endStation[2]))
            stCode[2]=endStation[2];
        else stCode[2]='\0';
        j=-1;}
    }
   return 0;
}

int main(){
    int i,xo;
    char T[24];
    time_t t;
    t = time(&t);
    char* c_time_string;
    strcpy(T, ctime(&t));
	char stCodei[5],stCodef[5];
	printf("Please follow the following codes for respective stations: \n Barddhaman \t BWN \t Durgapur \t DGR \t RaniGanj \t RNG \n Asansol \t ASN \t Dhanbad \t DHN \t Bandel \t BDC \n DaltonGanj \t DTO \t Garhwa Road \t GHD \t Renukut \t RNQ \n Chopan \t CPU \t Guna \t\t GUN \t Barkakana \t BRK \n Singrauli \t SGR \t Beohari \t BEH \t Damoh \t\t DMO \n Saugor \t SGO \t Mungaoli \t MNV \t Ashok Nagar \t ASK \n Phusro \t PUS \t Katni Murwara \t KMZ \t Kolkata \t KOA \n Hooghly \t HYG \t Garifa \t GFA \t Naihati \t NHC \n Sealdah \t SDA \t Bidhan Nagar \t BNX \t Dum Dum \t DDJ \n Belgharia \t BLH \t Agarpara \t AGP \t Sodpur \t SEP \n Khardaha \t KDH \t Titagarh \t TGH \t Barrackpore \t BPC \n Palta \t\t PTF \t Ichhapur \t IPC \t Shyamnagar \t SNR \n Jagaddal \t JGD \t Kakinara \t KNR \t Halisahar \t HLR \n Kanchrapara \t KPA \t Kalyani \t KYI \t Howrah \t HWH \n Liluah \t LLH \t Belur \t\t BEQ \t Bally \t\t BLY \n Uttarpara \t UPA \t Hind Motor \t HMZ \t Konnagar \t KOG \n Rishra \t RIS \t Shrirampur \t SRP \t Seoraphuli \t SHE \n Baidyabati \t BBA \t Bhadreshwar \t BHR \t Mankundu \t MUU \n Chuchura \t CNS \t Chandan \t CGR \n ");
	printf("Enter the starting station :");
	scanf("%s",stCodei);
	printf("Enter the Destination station code: ");
	scanf("%s",stCodef);
    printf("Press 1 if you want to use the current time and 0 otherwise.");
    scanf("%d",&xo);
   if (xo==1){
        for(i=0;i<5;i++){
            Time[i]=T[11+i];
        }
   }
   else if (xo==0){
          printf("Enter date and time: ");
        scanf("%s",Time);
   }
  	distributerFunc(stCodei,stCodef,Time);
	printf("Have a happy journey!\n");
	return 0;
}

