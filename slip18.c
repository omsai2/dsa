#include<stdio.h>
#include<stdlib.h>
struct node
{
int coeff,exp;
struct node *next;
};
struct node* create(struct node *f)
{
int i,n;
struct node *s;
printf("\nEnter no of terms ");
scanf("%d",&n);
printf("Enter term in descending order of power ");
f=(struct node *)malloc(sizeof(struct node));
printf("\n Enter coeff ");
scanf("%d",&f->coeff);
printf("\n Enter power ");
scanf("%d",&f->exp);
s=f;
for(i=1;i<n;i++)
{
s->next=(struct node *)malloc(sizeof(struct node));
s=s->next;
printf("\n Enter coeff ");
scanf("%d",&s->coeff);
printf("\n Enter power ");
scanf("%d",&s->exp);
}
s->next=NULL;
return f;
}
void display(struct node *f)
{
struct node *s;
for(s=f;s!=NULL;s=s->next)
{
}
printf("%dx^%d ->",s->coeff,s->exp);
}
int length(struct node *p)
{
int len=0;
struct node *s;
for(s=p;s!=NULL;s=s->next)
{
len++;
}
return len;
}
struct node* Mult(struct node *p1,struct node *p2)
{
struct node *t1,*t2,*t3=NULL,*nw;
struct node *p3;
for(t1=p1;t1!=NULL;t1=t1->next)
{
for(t2=p2;t2!=NULL;t2=t2->next)
{
nw=(struct node*)malloc(sizeof(struct node));
nw->next=NULL;
nw->coeff=t1->coeff*t2->coeff;
nw->exp=t1->exp+t2->exp;
if(t3==NULL)
{
p3=nw;
t3=nw;
}
else
{
t3->next=nw;
t3=t3->next;
}
}
}
return p3;
}
main()
{
struct node *p1=NULL,*p2=NULL,*p3=NULL;
p1=create(p1);
p2=create(p2);
printf("\n 1st Polynomial is : ");
display(p1);
printf("\n 2nd Polynomial is : ");
display(p2);
p3=Mult(p1,p2);
printf("\n Multiplication of 2 Polynomial is ");
display(p3);
}
