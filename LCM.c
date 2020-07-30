#include<stdio.h>
int main()
{
	int m,n,a,b,t,q,s;
	printf("Enter two integers\n");
	scanf("%u%u",&m,&n);
	a=m;
	b=n;
	while(b!=0)
	{
		q=a/b;
		t=a-q*b;
		a=b;
		b=t;
	}
	s=m*n;
	s=s/a;
	printf("lcm = %u\n",s);	



}
