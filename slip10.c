slip 10_2 : Read the data from the file “employee.txt” and sort on names in alphabetical order (use strcmp) using bubble sort and selection sort.

Solution :Using Bubble sort

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
 char name[20];
 int age;
}emp[10];
int readfile(struct employee a[10])
{
 int i=0;
 FILE*fp;
 if((fp=fopen("empl.txt","r"))!=NULL)
 {
 while(!feof(fp))
 {
 fscanf(fp,"%s%d",a[i].name ,&a[i].age);  i++;
 }
 }
 return i-1;
}
void writefile(struct employee a[],int n)
{
 int i;
 FILE *fp;
 if((fp=fopen("bsort.txt","w"))!=NULL)
 {
 for(i=0;i<n;i++)
 {
 fprintf(fp,"%s %d \n",a[i].name ,a[i].age);  }
 }
}
void bubblesort(struct employee a[],int n)
{
 int i,j;
 struct employee temp;
 for(i=0;i<n-1;i++)
 {
 for(j=0;j<n-1;j++)
 {
 if(strcmp(a[j].name,a[j+1].name)>0)  {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
 }
 }
}
main()
{
 int n;
 n=readfile(emp);
 if(n==-1)
 printf("File is not found");
 else
 {
 bubblesort(emp,n);
 writefile(emp,n);
 printf("File is found");
 }

}