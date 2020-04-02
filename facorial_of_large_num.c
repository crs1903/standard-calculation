#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct link_list
{
	char val;
	struct link_list *prev,*next;
};
typedef struct link_list LINK;

LINK* insert(LINK*,char);
void printlist(LINK*);
LINK* fact(int);
LINK* multi(LINK*,int);

int main()
{	
	int n;
	printf("Enter a number:\n");
	scanf("%d",&n);
	LINK* a=fact(n);
	printf("Factorial of %d is :\n",n);
	printlist(a);
	printf("\n");
}
LINK* multi(LINK *head,int m)
{	
	int c=0;
	LINK *p=head;
	do
	{	
		int k=(p->val)*m+c;
		p->val=k%10;
		c=k/10;
		p=p->next;
	}while(p!=head);
	while(c!=0)
	{
		head = insert(head,c%10);
		c=c/10;
	}
	return head;
}
LINK* fact(int n)
{	
	LINK *head=malloc(sizeof(head));
	head->val=1;
	head->next=head;
	head->prev=head;
	for(int j=2;j<=n;j++)
	{	
		head = multi(head,j);
	}
	return head;
}
void printlist(LINK* head)
{	LINK *p=head->prev;
	do
	{
		printf("%d",p->val);
		p=p->prev;
	}while(p!=head->prev);
	printf("\n");
}
LINK* insert(LINK *head,char n)
{	
	LINK *p=head,*new=(LINK*)malloc(sizeof(new));
	new->val=n;
	p=p->prev;
	
	new->prev=p;
	p->next=new;
	new->next=head;
	(head)->prev=new;
	return head;
}














