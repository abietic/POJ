#include <stdio.h>
#define maxlen 1000
int main()
{
	int N;
	int a[maxlen],b[maxlen+1]={0},c[maxlen+1];
	scanf("%d",&N);
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	int topa = N-1;
	int topb = 0;
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
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;		
}
