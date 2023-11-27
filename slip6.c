Slip 6_2 : Implement a queue library (dyqueue.h) of integers using a dynamic (linked list)
implementation of the queue and implement init, enqueue, dequeue, isempty, peek
operations. 

Solution :
Header File : dyqueue.h
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *f,*r;
void init()
{
 f=NULL;
 r=NULL;
}
int isempty()
{
 if(f==NULL)
 return 1;
 else
 return 0;
}
void enqueue()
{
 struct node*nw;
 int n;
 nw=(struct node*)malloc(sizeof(struct node));
 nw->data=n;
 nw->next=NULL; 
 if(f==NULL)
 {
 f=nw;
 r=nw;
 }
 else
 {
 r->next=nw;
 r=r->next;
 }
}
int dequeue()
{
 int n;
 struct node *temp;
 if(isempty()==1)
 printf("queue is empty");
 else
 {
 temp=f;
 f=f->next;
 n=temp->data;
 free(temp);
 }
}
int peek()
{
 return f->data;
}

Program File :

#include<stdio.h>
#include"dyqueue.h"
main()
{
 int ch,no;
 init();
 do
 {
 printf("\n1.enqueue \n2.dequeue \n3.peek \n0.exit");  printf("enter choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:printf("enter data:");
 scanf("%d",&no);
 enqueue(no);
 break;
 case 2:if(isempty()==1)
 printf("\n queue is empty");  else
 printf("dequeue element=%d",dequeue());  break;
 case 3:printf("top element =%d",peek());
break;
 case 0:break;
 }
 }while(ch!=0);
} 
