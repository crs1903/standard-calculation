#include<stdio.h>
#include<stdlib.h>


unsigned int bits(long unsigned int n)
{
	unsigned int b=0;
	while(n)
	{
		b++;
		n>>=1;
	}
	return b;
}
long long unsigned int add(unsigned long long int m,unsigned long long n)
{
	unsigned int i=1,s,a,b,c=0,sum=0;
	
	for(i=0;i<8*sizeof(unsigned long long int);i++,count++)
	{	
		a=(m>>i)&1;
		b=(n>>i)&1;
	
		s=a^b^c;
		c=(a&b)|((a^b)&c);
		
		sum=sum|(s<<i);
	}
	return sum;
}
long long unsigned int mult(long long unsigned int m,long long unsigned int n)
{
	if(m==1)
		return n;
	
	if(n==1)
		return m;
	
	if(m==0||n==0)
		return 0;

	unsigned int a=bits(m),b=bits(n),t=a>b?a:b;
	long long unsigned int m1,m2,n1,n2,p,q;
	a=t>>1;
	m1=m>>a;
	n1=n>>a;
	m2=m^(m1<<a);
	n2=n^(n1<<a);
	p=add(m1,m2);
	q=add(n1,n2);
	long long unsigned int x=mult(m1,n1),y=mult(m2,n2),z=mult(p,q),u;
	u=add(add(z,-x),-y);	
	return add(add(x<<(a<<1),u<<a),y);
}
int main()
{
	unsigned int a,b;
	printf("Enter any two number:\n");
	scanf("%d%d",&a,&b);
	printf("\nThe multiplication is:\n %d * %d = %lld\n",a,b,mult(a,b));
		
}
