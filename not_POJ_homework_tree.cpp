#include <iostream>
#include <cstdio>
#include <stack>
//----------------------------------------
int get_depth(int n , int treemap[101][101]);
//----------------------------------------
int get_wide(int n , int treemap[101][101]);
//----------------------------------------
int get_dist(int n , int treemap[101][101] , int u , int v);
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
	FILE *in , *out;
	in = fopen("tree.in" , "r");
	out = fopen("tree.out" , "w");
	//----------------------------------------
	int n , u , v;
	int treemap[101][101] = {0};
	fscanf(in , "%d" , &n);
	for (int i = 0 ; i < n - 1 ; i++)
	{
		fscanf(in , "%d%d" , &u , &v);
		treemap[u][v] = 1;
		treemap[v][u] = 2;
	}
	fscanf(in , "%d%d" , &u , &v);
	int wide = 0;
	int depth = 0;
	int dist = 0;
	wide = get_wide(n , treemap);
	depth = get_depth(n , treemap);
	dist = get_dist(n , treemap , u , v);
	fprintf(out , "%d\n%d\n%d" , depth , wide , dist);
	//----------------------------------------
	fclose(in);
	fclose(out);
    return 0;
}
//----------------------------------------
int get_depth(int n , int treemap[101][101])
{
    stack<int> former , later;
    int d = 0;
    int temp;
    former.push(1);
    int i;
    while (true)
    {
        if (former.empty() && later.empty())
        {
            break;
        }
        if (former.empty())
        {
            d++;
            while (!later.empty())
            {
                temp = later.top();
                later.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i] == 1)
                    {
                        former.push(i);
                    }
                }
            }
            continue;
        }
        if (later.empty())
        {
            d++;
            while (!former.empty())
            {
                temp = former.top();
                former.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i] == 1)
                    {
                        later.push(i);
                    }
                }
            }
            continue;
        }
    }
	return d;
}
//----------------------------------------
int get_wide(int n , int treemap[101][101])
{
    int coun_max = 1 , coun;
    stack<int> former , later;
    int temp;
    former.push(1);
    int i;
    while (true)
    {
        if (former.empty() && later.empty())
        {
            break;
        }
        if (former.empty())
        {
            coun = later.size();
            if (coun > coun_max)
            {
                coun_max = coun;
            }
            while (!later.empty())
            {
                temp = later.top();
                later.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i] == 1)
                    {
                        former.push(i);
                    }
                }
            }
        }
        if (later.empty())
        {
            coun = former.size();
            if (coun > coun_max)
            {
                coun_max = coun;
            }
            while (!former.empty())
            {
                temp = former.top();
                former.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i] == 1)
                    {
                        later.push(i);
                    }
                }
            }
        }
    }
	return coun_max;
}
//----------------------------------------
int get_dist(int n , int treemap[101][101] , int u , int v)
{
    int prev1  = 0, prev2 = 0;
    int after1 = u , after2 = v;
    int coun1 = 0 , coun2 = 0;
    int path1[100] = {u};
    int path2[100] = {v};
    int i;
    if (u == 1)
    {
        while(prev2 != 1 && after2 != 1)
        {
                for (i = 1 ; i <= n ; i++)
                {
                    if (treemap[after2][i] == 2)
                    {
                        prev2 = i;
                        path2[coun2 + 1] = i;
                        after2 = i;
                        coun2++;
                        break;
                    }
                }
        }
        return coun2;
    }
    if (v == 1)
    {
        while(prev1 != 1 && after1 != 1 )
        {
            for (i = 1 ; i <= n ; i++)
            {
                if (treemap[after1][i] == 2)
                {
                    prev1 = i;
                    path1[coun1 + 1] = i;
                    after1 = i;
                    coun1++;
                    break;
                }
            }
        }
        return 2 * coun1;
    }
    while(prev1 != 1 && after1 != 1 )
    {
        for (i = 1 ; i <= n ; i++)
        {
            if (treemap[after1][i] == 2)
            {
                prev1 = i;
                path1[coun1 + 1] = i;
                after1 = i;
                coun1++;
                break;
            }
        }
    }
    while(prev2 != 1 && after2 != 1)
    {
        for (i = 1 ; i <= n ; i++)
        {
            if (treemap[after2][i] == 2)
            {
                prev2 = i;
                path2[coun2 + 1] = i;
                after2 = i;
                coun2++;
                break;
            }
        }
    }
    for ( ; path1[coun1 + 1] == path2[coun2 + 1] ; coun1-- , coun2--)
    {
        if (path1[coun1] != path2[coun2])
            break;
    }
    coun1++;
    coun2++;
    printf("%d %d\n" , coun1 ,coun2);
	return coun1 * 2 + coun2;
}
//----------------------------------------
