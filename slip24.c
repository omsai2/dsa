#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
char name[20];
int age;
}emp[10];
int readfile(struct employee a[])
{
int i=0;
FILE*fp;
if((fp=fopen("emp.txt","r"))!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s%d",&a[i].name,&a[i].age);
i++;
}
}
}
return i-1;
void InsertionSort(struct employee a[],int n)
{
int i,j;
struct employee key;
for(i=1; i<n; i++)
{
key=a[i];
for(j=i-1; j>=0; j--)
{
if(strcmp(a[j].name,key.name)>0)
{
a[j+1]=a[j];
}
else
break;
}
a[j+1]=key;
}
}
void writefile(struct employee a[],int n)
{
int i=0;
FILE*fp;
if((fp=fopen("insertionsort.txt","w"))!=NULL)
{
for(i=0;i<n;i++)
{
fprintf(fp,"%s %d\n",a[i].name,a[i].age);
}
}
}
int main()
{
int n;
n=readfile(emp);
if(n==-1)
printf("File Not Found");
else
{
InsertionSort(emp,n);
writefile(emp,n);
printf("File Sorted");
}
}
