Slip 3_2 : Write a C program to evaluate postfix expression.

Solution :

#include<stdio.h>
#include<string.h>
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
void postfix_eval(char str[20])
{ int i,op1,op2,val;
 for(i=0;str[i]!='\0';i++)
 { switch(str[i])
 {
 case '+': op2=pop();
 op1=pop();
 push(op1+op2);  break;
 case '-': op2=pop();
 op1=pop();
 push(op1-op2);  break;
 case '*': op2=pop();
 op1=pop();
 push(op1*op2);  break;
 case '/': op2=pop();
 op1=pop();
 push(op1/op2);  break;
 default:printf("Enter value of %c ",str[i]);  scanf("%d",&val);
 push(val);

 }
 }
 printf("Ans =%d ",pop());
} 
main()
{ char str[20];
 printf("Enter postfix string ");
 scanf("%s",str);
 postfix_eval(str);
}
