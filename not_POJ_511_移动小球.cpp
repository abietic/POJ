#include <iostream>
//----------------------------------------
using namespace std;
//----------------------------------------
void move_left(int L[] , int R[] , int x , int y);
void move_right(int L[] , int R[] , int x , int y);
void judge(int L[] , int R[] , int which , int m);
//----------------------------------------
int main()
{
    int n , N , M;
    cin >> n;
    for ( ; n > 0 ; n--)
    {
        cin >> N >> M;
        const int MAXN = N;
        int L[MAXN] , R[MAXN];
        for (int i = 0 ; i < MAXN ; i++)//初始化静态跳舞链
        {
            R[i] = i + 1;
            L[i] = i - 1;
            if (i == 0)
            {
                L[i] = MAXN - 1;
            }
            if (i == MAXN - 1)
            {
                R[i] = 0;
            }
        }
        for (int i = 0 ; i < M ; i++)//录入改变顺序的操作
        {
            int x , y;
            char s;
            cin >> s >> x >> y;
            switch (s)
            {
                case 'A' : move_left(L , R , x - 1 , y - 1);break;//把编号为x的小球移动到编号为y的小球左边
                case 'B' : move_right(L , R , x - 1 , y - 1);break;//把编号为x的小球移动到编号为y的小球右边
                case 'Q' : judge(L , R , x , y - 1);break;//Q 1 m为询问编号为m的小球右边的球号     Q 0 m为询问编号为m的小球左边的球号
            }
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
void move_left(int L[] , int R[] , int x , int y)
{
    R[L[x]] = R[x];
    L[R[x]] = L[x];
    R[x] = y;
    L[x] = L[y];
    R[L[y]] = x;
    L[y] = x;
}
//----------------------------------------
void move_right(int L[] , int R[] , int x , int y)
{
    R[L[x]] = R[x];
    L[R[x]] = L[x];
    L[x] = y;
    R[x] = R[y];
    L[R[y]] = x;
    R[y] = x;
}
//----------------------------------------
void judge(int L[] , int R[] , int which , int m)
{
    if (which == 0)
    {
        cout << L[m] + 1 <<endl;
    }
    if (which == 1)
    {
        cout << R[m] + 1 <<endl;
    }
}
//----------------------------------------
