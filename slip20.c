#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next,*prev;
};
struct node *f;
void create()
{
struct node *s;
int i,n;
printf("enter how many nodes");
scanf("%d",&n);
f=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&f->data);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node*)malloc(sizeof(struct node));
s=s->next;
printf("enter data");
scanf("%d",&s->data);
}
s->next=f;
}
void display()
{
struct node *s;
printf("\nCircular linked list is::");
s=f;
do
{
printf("%d->",s->data);
s=s->next;
}
while(s!=f);
}
void append()
{
struct node *nw,*s;
int n,i;
printf("\nenter how many new nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
nw=(struct node*)malloc(sizeof(struct node));
printf("\nenter new node of data");
scanf("%d",&nw->data);
s=f;
do
{
s=s->next;
}while(s->next!=f);
}
}
main()
{
s->next=nw;
nw->next=f;
create();
display();
append();
display();
}
