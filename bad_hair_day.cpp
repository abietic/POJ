//逆向思考每头牛被看见的次数，通过排序位置确定被看见次数
#include<stdio.h>
#define maxN 80003
int main()
{
	int a[maxN];
	int N;
	unsigned long sum = 0;
	scanf("%d",&N);
	int top = 0;
	int x;
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&x);
		while(top>0&&a[top]<=x)
		{
			top--;
		}
		sum+=top;
		a[++top] = x;
	}
	printf("%u\n",sum);
	return 0;
}
