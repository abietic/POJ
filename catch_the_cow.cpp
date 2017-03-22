#include <stdio.h>
#include <queue>
#define maxlen 100000
int cal(int N,int K)
{
	if(N == K)
	{
		return 0;
	}
	if(N > K)
	{
		return N-K;
	}
	int Time[2*maxlen] = {0};
	Time[N] = 0;
	std::queue<int> list;
	list.push(N);
	int n;
	for(;;)
	{
		n = list.front();
		list.pop();
		if(n == K)
		{
			return Time[n];
		}
		if(n+1 <= 2*maxlen&& n+1 >= 0&& Time[n+1] == 0)
		{
			Time[n+1] = Time[n]+1;
			list.push(n+1);
		}
		if(n*2 <= 2*maxlen&& n*2 >= 0&& Time[2*n] == 0)
		{
			Time[n*2] = Time[n]+1;
			list.push(2*n);
		}
		if(n-1 >= 0&& Time[n-1] == 0)
		{
			Time[n-1] = Time[n]+1;
			list.push(n-1);
		}
	}
}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	printf("%d\n",cal(N,K));
	return 0;
}
