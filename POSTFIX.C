#include<math.h>
#include<stdio.h>
#include<conio.h>
int pos = -1;
int push (int [],int);
int pop(int [],int * );
int isoperator(char);
int calculate(int ,int ,char);
main()
{
	int s[100];
	int i=0,n1,n2,res,r;
	char postfix[100],ch;

	printf("Enter the postfix expression:");
	gets(postfix);
	while (postfix[i]!='\0')
	{
		ch = postfix[i];
		if(isoperator(ch)==0)
		{
			r = push(s,ch-48);
		}
		else
		{
			r = pop(s,&n2);
			r = pop(s,&n1);
			res = calculate(n1,n2,ch);
			r = push(s,res);
		}
		i++;
	}
	r = pop(s,&res);
	printf("Result:%d",res);
	getch();
}
int push(int s[],int n)
{
	if (pos==99)
	{
		return(0);
	}
	else
	{
		pos++;
		s[pos]=n;
		return(1);
	}
}
int pop(int s[],int *n)
{
	if (pos == -1)
	{
		return(0);
	}
	else
	{
		*n = s[pos];
		pos--;
		return(1);
	}
}
int isoperator(char ch)
{
	if (ch == '+'||ch == '-'||ch == '*'||ch == '/'||ch=='$')
	{
		return(1);
	}
	else{
		return(0);
	}
}
int calculate(int n1,int n2,char oper)
{
	int res;
	switch(oper)
	{
		case '+':
			res = n1+n2;
			break;
		case '-':
			res = n1- n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
		case '$':
			res = pow(n1,n2);
			break;
	}
	return(res);
}
