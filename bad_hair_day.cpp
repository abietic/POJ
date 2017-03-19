#include<stdio.h>
#define maxN 80000
int main()
{
	int a[maxN];
	int N;
	unsigned long sum = 0;
	scanf("%d",&N);
	int top = 0;
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	while(top != (N-1))
	{
	for(int j = top+1;j<N;j++)
	{
		if(a[top] > a[j])
		{
			++sum;
		}
		else
		{
			break;
		}
	}
	++top;
	}
	printf("%u\n",sum);
	return 0;
}
