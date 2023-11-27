Slip 11_2: Implement a priority queue library (PriorityQ.h) of integers using a static implementation of the queue and implement the below two operations. 1) Add an element with its priority into the queue. 2) Delete an element from queue according to its priority.

Solution :
Header File : PriorityQ.h
#include<stdio.h>
int Q[20];
int f,R;
void init()
{
 f=R=-1;
}
int isempty()
{
 if(f==R)
 return 1;
 else
 return 0;
}
int isfull()
{
 if(R==19)
 return 1;
 else return 0;
}
void Add(int no)
{ int i;
 if(isfull()==1)
 printf("Queue is Full ");
 else
 {
 for(i=R;i>f;i--)
 { if(no<Q[i])
 Q[i+1]=Q[i];
 else
 break;
 }
 Q[i+1]=no;
 R++;
 }
}
int Delete()
{ int no;
 if(isempty()==1)
 printf("Queue is empty ");
 else
 {
 f++;
 no=Q[f];
 }
 return no;
}
void display()
{
 int i;
 for(i=f+1;i<=R;i++)
 { printf("%d ",Q[i]);
 }
}

Program File :

#include<stdio.h>
#include "PriorityQ.h"
main()
{
int n,ch;
 init();
 do
 {
 printf("\n\n1.Add \n2.Delete \n3.Display \n0.EXit");  printf("\nEnter choice ");
 scanf("%d",&ch);
 switch(ch)
 { case 1:printf("\nEnter element ");  scanf("%d",&n);
 Add(n);
 break;
 case 2:if(isempty()==1)
 printf("\nQueue is empty ");  else
 printf("deleted elemet =%d ",Delete());
 break;
 case 3:display();
 break;
 case 0:break;
 default:printf("\nInvalid choice ");  }
 }while(ch!=0);
}