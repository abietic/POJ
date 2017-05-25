#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//----------------------------------------
using namespace std;
//----------------------------------------
struct node
{
    int degree;
    bool exist;
    int x[2];
    int y[2];
    vector<int> adj;
    node()
    {
        degree = 0;
        exist = false;
    }
};
//----------------------------------------
char output[30];
int total;
//----------------------------------------
void dfs(node aovnet[] , int cur);
//----------------------------------------
int main()
{
    int h , w;
    while (scanf("%d%d" , &h , &w) != EOF)
    {
        node aovnet[26];
        char wallmap[40][40] = {0};
        char line[40] = {0};
        //读入图片
        //看行列始末
        total = 0;
        for (int i = 0 ; i < h ; i++)
        {
            scanf("%s" , wallmap[i]);
            for (int j = 0 ; j < w ; j++)
            {
                if (wallmap[i][j] != '.')
                {
                    int t = wallmap[i][j] - 'A';
                    if (!aovnet[t].exist)
                    {
                        aovnet[t].exist = true;
                        total++;
                        aovnet[t].x[0] = j;
                        aovnet[t].x[1] = j;
                        aovnet[t].y[0] = i;
                        aovnet[t].y[1] = i;
                    }
                    else
                    {
                        aovnet[t].x[0] = min(aovnet[t].x[0] , j);
                        aovnet[t].x[1] = max(aovnet[t].x[1] , j);
                        aovnet[t].y[0] = min(aovnet[t].y[0] , i);
                        aovnet[t].y[1] = max(aovnet[t].y[1] , i);
                    }
                }
            }
        }
        //判断拓扑序列
        for (int i = 0 ; i < 26 ; i++)
        {
            if (!aovnet[i].exist)
            {
                continue;
            }
            for (int p = aovnet[i].x[0] ; p <= aovnet[i].x[1] ; p++)
            {
                for (int q = aovnet[i].y[0] ; q <= aovnet[i].y[1] ; q++)
                {
                    if (p < aovnet[i].x[1] && p > aovnet[i].x[0] && q == aovnet[i].y[0] + 1)//※只计算了边框被覆盖的所有字母，由于题中说不会完全覆盖一个边，所以不会有漏掉的情况
                    {
                        q = aovnet[i].y[1];
                    }
                    int current = wallmap[q][p] - 'A';
                    if (current == i)
                    {
                        continue;
                    }
                    aovnet[i].adj.push_back(current);//※要倒序建立拓扑序列
                    aovnet[current].degree++;
                }
            }
        }
        ///DFS输出
        dfs(aovnet , 0);
    }
    return 0;
}
//----------------------------------------
void dfs(node aovnet[] , int cur)
{
    if (cur == total)
    {
        output[cur] = '\0';
        cout << output << endl;
        return;
    }
    for (int i = 0 ; i < 26 ;i++)
    {
        if (!aovnet[i].exist)
        {
            continue;
        }
        if (aovnet[i].degree != 0)
        {
            continue;
        }
        aovnet[i].degree--;
        for (int j = 0 ; j < aovnet[i].adj.size() ; j++)
        {
            aovnet[ aovnet[i].adj[j] ].degree--;
        }
        output[cur] = 'A' + i;
        dfs(aovnet , cur + 1);
        aovnet[i].degree++;
        for (int j = 0 ; j < aovnet[i].adj.size() ; j++)
        {
            aovnet[ aovnet[i].adj[j] ].degree++;
        }
    }
}
//----------------------------------------
