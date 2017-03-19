//逆向思考每头牛被看见的次数，通过排序位置确定被看见次数
//每次碰见大到足够隔断前面较小数的视野时用它将较小的数替换掉，就可以保留并计算出下一头牛会被前面几头牛看到
//看不出哪里是栈模拟
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
