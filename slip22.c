#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city
{
char name[20];
int code;
}ct[10];
int readFile(struct city a[])
{
int i=0;
FILE *fp;
if((fp=fopen("city.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",&a[i].name,&a[i].code);
i++;
}
}
return i-1;
}
void sentinelsearch(struct city a[10],int n,int sr)
{
int i,cnt=0;
a[n]=sr;
while(strcmp(sr,a[i].name)!=0)
{
i++;
}
if(i<n)
printf("city is found and STD code is %d
else
printf("city is not found ");
",a[i].code);
}
main()
{
int n;
char sr[20];
n=readFile(ct);
if(n==-1)
printf("File not found ");
else
{
printf("Enter city name to search");
scanf("%s",sr);
SentinelSearch(ct,n,sr);
}
}
