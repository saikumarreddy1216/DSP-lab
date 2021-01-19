#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *link;
};
struct node *head;
void push(char item)
{
		struct node *p=(struct node*) malloc(sizeof(struct node));
	    p->data=item;
		p->link=head;
		head=p;	
}
char pop()
{
	if(head->data!='$')
	{
	char ch=head->data; 
    head=head->link;
	return ch;
    }
    else printf("no elements in stack");
}
int get_precedence(char c)
{
	if(c=='%') return 4;
	else if(c=='*'||c=='/') return 3;
	else if(c=='+'||c=='-') return 2;
	else return 1;
}
void postfix(char *s,int length)
{
	for (int i=0;i<length;i++)
	{
		if(s[i]==' ') ;
		else if(s[i]>='0' && s[i]<='9')
		{
			char ch='0';
			int a=(int)s[i++]-(int)ch;
			//i++;
			while((s[i]>='0' && s[i]<='9'))
			{
				a=a*10+((int)s[i++]-(int)ch);
				//i++;
			}
			i--;
			printf("%d ",a);
		}
		else if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
		{
		    printf("%c ",s[i]);
		}
		else if(s[i]=='(')
		{
			push(s[i]);
		}
		else if(s[i]==')')
		{
			char a;
			while(1)
			{
				char a=pop();
				if(a!='(') printf("%c ",a);
				else break;
			}
		}
		else
		{
			if(get_precedence(s[i])>get_precedence(head->data)) push(s[i]);	
			else
			{
				while(get_precedence(s[i])<=get_precedence(head->data)) printf("%c ",pop());
				push(s[i]);
			}
		}
	}
	while(head->data!='$') printf("%c ",pop());
}
int main()
{
	char s[1000];
	scanf("%[^\n]%*c",s);
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(!(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='('||s[i]==')'||s[i]==' '||(s[i]>='0'&&s[i]<='9')||(s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')))
		{
			printf("Invalid");
			return 0;
		}
	}
	int str_len=0;
	for(i=0;s[i]!='\0';i++) str_len++;
	head=(struct node*) malloc(sizeof(struct node));
	head->data='$'; //initialising head just like stack top=-1 ;
	head->link=NULL;
	postfix(s,str_len);
	return 0;
}