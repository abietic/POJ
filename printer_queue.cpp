#include <stdio.h>
#include <queue>
struct Data
{
	int pri;
	bool is;
};
int cal()
{
	int length,target;
	scanf("%d%d",&length,&target);
	std::queue<Data> list;
	Data a,b;
	int priority[9] = {0};
	for(int i = 0;i<length;i++)
	{
		a.is = false;
		scanf("%d",&(a.pri));
		++priority[9-a.pri];
		if(i == target)
		{
			a.is = true;
		}
		list.push(a);
	}
	int count = 0;
	for(int j = 0;j<=9;j++)
	{
		while(priority[j])
		{
			b = list.front();
			if(b.pri<(9-j))
			{
				list.pop();
				list.push(b);
			}
			else
			{
				list.pop();
				priority[j]--;
				count++;
				if(b.is)
				{
					return count;
				}
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int times[n];
	for(int i = 0;i<n;i++)
	{
		times[i] = cal();
	}
	for(int j = 0;j<n;j++)
	{
		printf("%d\n",times[j]);
	}
	return 0;
}
