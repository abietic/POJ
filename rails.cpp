//无法通过。。。wa
#include <stdio.h>
#define maxlen 1000
int judg(int N,int a[])
{
	int b[maxlen]={0},c[maxlen+1];
	int topa = N-1;
	int topb = -1;
	int topc = N;
	while(topc != 0)
	{
		while(topa != -1&&b[topb] != topc)
		{
			b[++topb] = a[topa--];
		}
		c[topc] = b[topb--];
		if(c[topc] == topc)
		{
			topc--;
		}
		else
		{
			return 0;
		}
	}
	return 1;		
}
int main()
{
	int a[maxlen];
	int bol[maxlen];
	int count = 0;
	int N;
	scanf("%d",&N);
	while(N)
{
	while(1)
	{
		scanf("%d",&a[0]);
		if(a[0] == 0)
		{
			break;
		}
		for(int i = 1;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		bol[count++] = judg(N,a);	
	}
	bol[count++] = 2;
	scanf("%d",&N);
}
    for(int j = 0;j<count;j++)
    {
    	if(bol[j] == 1)
    	{
    		printf("Yes\n");
		}
		else if(bol[j] == 0)
		{
			printf("No\n");
		}
		else if(bol[j] == 2)
		{
			printf("\n");
		}
	}
	return 0;
}
