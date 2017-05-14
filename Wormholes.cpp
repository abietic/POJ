//在题目中我没有读出已经固定了起点是1的说法。
//但在本题确实是起点为1算是AC的。
//AC得莫名奇妙。
#include <iostream>
//----------------------------------------
using namespace std;
//----------------------------------------
const int INF = 147483647;
//----------------------------------------
int main()
{
    int F,N,M,W;
    int from , to , cost;
    cin >> F;
    for (int i = 0 ; i < F ; i++)
    {
        cin >> N >> M >> W;
        int farmmap[510][510] = {0};
        bool isring = false;
        for (int j = 0 ; j < M ; j ++)
        {
            cin >> from >> to >> cost;
            if (farmmap[from - 1][to - 1] > cost || farmmap[from - 1][to - 1] == 0)
            {
                farmmap[from - 1][to - 1] = cost;
            }
            if (farmmap[to - 1][from - 1] > cost || farmmap[to - 1][from - 1] == 0)
            {
                farmmap[to - 1][from - 1] = cost;
            }
        }
        for (int j = 0 ; j <W ; j++)
        {            cin >> from >> to >> cost;
            if (farmmap[from - 1][to - 1] > -cost)
            {
                farmmap[from - 1][to - 1] = -cost;
            }
        }
        //for (int j = 0 ; j < N ; j++)
        //{
            int dist[510];
            for (int p = 0 ; p < N ; p++)
            {
                dist[p] = INF;
            }
            dist[0] = 0; //原来写的是dist[j] = 0;
            int coun = 0;
            bool relaxed;
            while (true)
            {
                relaxed = false;
                for (int p = 0 ; p < N ; p++)
                {
                    for (int q = 0 ; q < N ; q++)
                    {
                        if (dist[p] + farmmap[p][q] < dist[q] && farmmap[p][q] != 0)
                        {
                            dist[q] = dist[p] + farmmap[p][q];
                            relaxed = true;
                        }
                    }
                }
                if (!relaxed)
                {
                    break;
                }
                coun++;
                if (coun > N + 1)
                {
                    isring = true;
                    break;
                }
                if (dist[0] < 0)///////////////////////////////////////////不加这个的话，我的bellmanFord程序就TLE
                {
                    break;
                }
            }
        //}
        /*for (int p = 0 ; p < N ; p++)
        {
            for (int q = 0 ; q < N ; q++)
            {
                cout << farmmap[p][q] << " ";
            }
            cout << endl;
        }*/
        if (isring || dist[0] < 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
