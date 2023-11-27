Slip7_2 : Write a program that checks whether a string of characters is palindrome or not.
The function should use a stack library (cststack.h) of stack of characters using a static
implementation of the stack

Solution :

Header File : cststack.h

#include<stdio.h>
char s[20];
int top;
void init()
{
 top=-1;
}
int isempty()
{ if(top==-1)
 return 1;
 else return 0;
}
int isfull()
{ if(top==19)
 return 1;
 else
 return 0;
}
void push(char data)
{
 if(isfull()==1)
 printf("\nStack is full ");
 else
 { top++;
 s[top]=data;
 }
}
char pop()
{ char data;
 if(isempty()==1)
 printf("\nStack is empty ");
 else
 { data=s[top];
 top--;
 return data;
 }
}
int peek()
{ return s[top];
}

Program File :

#include<stdio.h>
#include"cststack.h"
 void main()
{
 char str[20];
 int count=0,i;
 char ch;
 printf("enter string");
 scanf("%s",str);
 init();
 for(i=0;i<=str[i]!='\0';i++)
 {
 push(str[i]);
 }
 for (i=0;i<=strlen(str)/2;i++)
 {
 ch = pop();
 if(ch!=str[i])
 {
 count++;
 break;
 }
 }
 if(count==0)
 {
 printf("The string is palindrome");  }
 else
 {
 printf("The string is not palindrome");  }

}
