//看了评论区知道了要判断重边 ， 最后看经过的路的权是否有0 ， 有0则不连通（不知道对不对）
#include <iostream>
#include <vector>
//----------------------------------------
using namespace std;
//----------------------------------------
struct edge
{
    int power;
    edge()
    {
        power = 0;
    }
};
//----------------------------------------
int main()
{
    int N , M;
    cin >> N >> M;
    vector < vector<edge> > head(N);
    for (int i = 0 ; i < N ; i++)
    {
        vector<edge> temp(N);
        head[i] = temp;
    }
    for (int i = 0 ; i < M ; i++)
    {
        int A , B , C;
        cin >> A >> B >> C;
        if (C > head[A - 1][B - 1].power)
        {
            head[A - 1][B - 1].power = C;
            head[B - 1][A - 1].power = C;//每次都忘记是无向边而忘记写这句然后懵逼
        }
    }
    const int n = N;
    int ver[n] , marked[n] , lowcost[n];
    for (int i = 1 ; i < n ; i++)
    {
        ver[i] = 0;
        marked[i] = 0;
        lowcost[i] = head[0][i].power;
    }
    ver[0] = -1;
    marked[0] = 1;
    lowcost[0] = 0;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int ldist = 0;
        int u;
        for (int j = 0 ; j < n ; j++)
        {
            if (lowcost[j] > ldist && marked[j] == 0)
            {
                u = j;
                ldist = lowcost[j];
            }
        }
        marked[u] = 1;
        for (int j = 0 ; j < n ; j++)
        {
            if (head[u][j].power > lowcost[j] && marked[j] == 0)
            {
                lowcost[j] = head[u][j].power;
                ver[j] = u;
                //cout << endl;
                //cout << u + 1 << " " << j + 1 << " " << lowcost[j] << endl;
            }
        }
    }
    bool all_connected = true;
    int sum = 0;
    for (int i = 1 ; i < n ; i++)
    {
        if (lowcost[i] <= 0)
        {
            all_connected = false;
            break;
        }
        sum += lowcost[i];
    }
    /*for (int i =0 ; i < n ; i++)
    {
        cout << ver[i] + 1 << " ";
    }
    cout << endl;
    cout << head[2][1].power << endl;*/
    if (!all_connected)
    {
        cout << -1;
    }
    else
    {
        cout << sum;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
