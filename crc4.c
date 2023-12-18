#include<stdio.h>
#include<string.h>
#define N strlen(genpoly)
char message[28],cs[28],cs1[28],genpoly[]="11001";
int a,e,c;
int main(){
    printf("\n enter the data");
    scanf("%s", message);
printf("\n");
printf("the generating polynomial is %s ", genpoly);
a=strlen(message);
for(e=a;e<a+N-1;e++)
    message[e]='0';//12,13,14,15=0;

    printf("\n the new message is %s", message);
    printf("\n");
     for(e=0;e<N;e++)
        cs[e]=message[e];// always check from here
      //  printf("\n%s",cs);
    // printf("\n%c", cs[0]);
do{
 //   printf("\nhello");//c=4
   // printf("\n%d and %c", e,cs[0]);
    if(cs[0]=='1')
for(c = 0;c<N; c++)
 // printf("\n%s",cs);
    cs[c] = (( cs[c] == genpoly[c])?'0':'1');
  //  printf("\n%s",cs);
   //cs[c]=cs[c]<<1;
 for(c=0;c<N-1;c++)
       cs[c]=cs[c+1];
        cs[c]=message[e++];
       
    }while(e<=a+N-1);//e=5 to 16 12bits
 printf("\nChecksum is : %s",cs);
    for(e=a;e<a+N-1;e++)
       message[e]=cs[e-a];
    printf("\nFinal codeword is : %s",message);
cs1[e]=message[e];
for(e=0;e<N;e++)
        cs1[e]=message[e];
        do{
               if(cs1[0]=='1')
for(c = 0;c<N; c++)
 // printf("\n%s",cs);
    cs1[c] = (( cs1[c] == genpoly[c])?'0':'1');
    for(c=0;c<N-1;c++)
       cs1[c]=cs1[c+1];
        cs1[c]=message[e++];
         }while(e<=a+N-1);
         printf("\nChecksum is : %s",cs1);
    for(e=a;e<a+N-1;e++)
       message[e]=cs1[e-a];
   printf("\nFinal codeword is : %s",message);
   // printf("\n%c",message[4]);
printf("\n");
    printf("\nTest error detection 0(yes) 1(no)? : ");
      scanf("%d",&e);
    if(e==0)
    {
        do{
            printf("\nEnter the position where error is to be inserted : ");
            scanf("%d",&e);
        }while(e==0 || e>a+N-1);
        message[e-1]=(message[e-1]=='0')?'1':'0';
        printf("\n");
        printf("\nError data : %s\n",message);
    }
    for(e=0;e<N;e++)
        cs[e]=message[e];
    do{
        if(cs[0]=='1')
    for(c = 0;c < N; c++){
    cs[c] = (( cs[c] == genpoly[c])?'0':'1');
    }
    for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=message[e++];
    }while(e<=a+N-1);
    for(e=0;(e<N-1) && (cs[e]!='1');e++);
        if(e<N-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
            printf("\n----------------------------------------\n");
        

    return 0;
    }


