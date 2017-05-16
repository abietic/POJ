//最小生成树问题 ， 稠密图运用prim算法。
#include <iostream>
#include <vector>
//----------------------------------------
using namespace std;
//----------------------------------------
struct edge
{
	int power;
	bool donebefore;
};
struct country
{
	int x;
	int y;
};
//----------------------------------------
int main()
{
	int N , M;
	cin >> N;
	const int n = N;
	country cou[n];
	for (int i = 0 ; i < n ; i++)
	{
		cin >> cou[i].x >> cou[i].y;
	}
	vector< vector<edge> > head(N);
	for (int i = 0 ; i < n ; i++)
	{
		vector<edge> temp(n);
		int nowcountry = i;
		for (int j = 0 ; j < n ; j++)
		{
			if (j == nowcountry)
			{
				edge tt;
				tt.power = -1;
				tt.donebefore = true;
				temp[j] = tt;
			}
			else
			{
				edge tt;
				tt.power = (cou[nowcountry].x - cou[j].x) * (cou[nowcountry].x - cou[j].x) + (cou[nowcountry].y - cou[j].y) * (cou[nowcountry].y - cou[j].y);
				tt.donebefore = false;
				temp[j] = tt;
			}
		}
		head[i] = temp;
	}
	cin >> M;
	for (int i = 0 ; i < M ; i++)
	{
		int from , to;
		cin >> from >> to;
		head[from - 1][to - 1].power = 0;
		head[from - 1][to - 1].donebefore = true;
		head[to - 1][from - 1].power = 0;//忘记是无向边忘了写这两句 ， 懵逼了一阵。
		head[to - 1][from - 1].donebefore = true;
		//cout << head[from - 1][to - 1].power << endl;
	}
	cout << endl;
	const int INF = 210000000;
	int lowcost[n];
	int ver[n];
	int marked[n];
	for (int i = 1  ; i < n ; i++)
	{
		lowcost[i] = head[0][i].power;
		ver[i] = 0;
		marked[i] = 0;
	}
	marked[0] = 1;
	lowcost[0] = 0;
	ver[0] = -1;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		int ldist = INF;
		int u;
		for (int j = 0 ; j < n ; j++)
		{
			if (lowcost[j] < ldist && marked[j] == 0)
			{
				ldist = lowcost[j];
				u = j;
			}
		}
		marked[u] = 1;
		for (int p = 0 ; p < n ; p++)
		{
			if (p == u)
			{
				continue;
			}
			if (head[u][p].power < lowcost[p] && marked[p] == 0)
			{
				lowcost[p] = head[u][p].power;
				ver[p] = u;
			}
		}
	}
	for (int i = 0 ; i < n ; i++)
	{
		if (ver[i] != -1)
		{
			if (!head[ver[i]][i].donebefore)
			{
				cout << ver[i] + 1 << " " << i + 1 << endl;
			}
		}
	}
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
//虽然还没有完全掌握最小生成树 ， 不过还是有点小激动。
