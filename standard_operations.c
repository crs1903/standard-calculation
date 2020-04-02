#include<stdio.h>
#include<stdint.h>

typedef long long unsigned int uint64;

unsigned int bits(uint64);
uint64 add(uint64,uint64,unsigned int);
uint64 multi(uint64, uint64);
uint64 div(uint64, uint64,uint64 *);
uint64 mod(uint64,uint64);
uint64 gcd(uint64,uint64);

int main()
{
	uint64 a,b;
	printf("Any two unsigned int:\n");
	scanf("%lld%lld",&a,&b);
	printf("\n\n");
	printf("add  : %llu\n",add(a,b,0));
	printf("subs : %lld\n",add(a,b,1));
	printf("mult : %llu\n",multi(a,b));
	printf("div  : %llu\n",div(a,b,NULL));
	printf("mod  : %llu\n",mod(a,b));
	printf("gcd  : %llu\n",gcd(a,b));
	
}

unsigned int bits(uint64 n)
{
	unsigned int b=0;
	while(n)
	{
		b++;
		n>>=1;
	}
	return b;
}

uint64 add(uint64 m,uint64 n,unsigned int c)
{
	unsigned int i=1,a,b,ic=c==1?1:0;
	uint64 s,sum=0;
	for(i=0;i<8*sizeof(uint64);i++)
	{	
		a=(m>>i)&1;
		b=((n>>i)&1)^ic;
	
		s=a^b^c;
		c=(a&b)|((a^b)&c);
		
		sum=sum|(s<<i);
	}
	return sum;
}
uint64 multi(uint64 m, uint64 n)
{
	uint64 mult=0;
	while(n)
	{
		if(n&1==1)
			mult=add(mult,m,0);
		m<<=1;
		n>>=1;
	}
	return mult;
}
uint64 div(uint64 m, uint64 n,uint64 *remainder)
{
	uint64 q=0,r=m,x=n,i;
	unsigned int a=bits(m),b=bits(n);
	if(n==0)
		return -1;	
	if(m<n)
		return 0;
	while(r>=n)
	{
		x=n;
		a=bits(x);
		b=bits(r);
		int k=b-a;
		x<<=k;
		
		if(r<x)
		{
			x>>=1;
			k--;
		}
		q=q|(1<<k);	
		r=add(r,x,1);	
	}
	if(remainder!=NULL)
		*remainder=r;
	return q;
}
uint64 mod(uint64 a,uint64 b)
{
	uint64 r;
	div(a,b,&r);
	return r;
}
uint64 gcd(uint64 m,uint64 n)
{
	uint64 t;
	while(n)
	{
		t=mod(m,n);
		m=n;
		n=t;
	}
	return m;
}





