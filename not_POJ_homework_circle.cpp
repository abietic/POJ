#include <iostream>
#include <cstdio>
//----------------------------------------
const int maxnum = 7100;
int father[maxnum] = {0};
int x[maxnum] = {0};
int y[maxnum] = {0};
int r[maxnum] = {0};
//----------------------------------------
//----------------------------------------
void merg(int i , int j);
//----------------------------------------
int find_father(int i);
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
    FILE *in , *out;
    in = fopen("circle.in" , "r");
    out = fopen("circle.out" , "w");
    //----------------------------------------
    int n;
    long long dist;
    long long sum_r;
    fscanf(in , "%d" , &n);
    const int N = n;
    for (int i = 0 ; i < N ; i++)
    {
        fscanf(in , "%d%d%d" , &x[i] , &y[i] , &r[i]);
        father[i] = i;
    }
    for (int j = 0 ; j < N ; j++)
    {
        for (int p = j + 1 ; p < N ; p++)
        {
            dist = (x[p] - x[j]) * (x[p] - x[j]) + (y[p] - y[j]) * (y[p] - y[j]);
            sum_r = r[p] + r[j];
            sum_r *= sum_r;
            if (sum_r - dist >= 0 )
            {
                merg(p , j);
            }
        }
    }
    n = 0;
    for (int m = 0 ; m < N ; m++)
    {
        if (father[m] == m)
        {
            ++n;
        }
    }
    fprintf(out , "%d" , n);
    //----------------------------------------
    fclose(in);
    fclose(out);
    return 0;
}
//----------------------------------------
int find_father(int i)
{
    while (i != father[i])
    {
        father[i] = father[father[i]];
        i = father[i];
    }
    return i;
}
//----------------------------------------
void merg(int i , int j)
{
    i = find_father(i);
    j = find_father(j);
    if (i != j)
    {
        father[i] = j;
    }
    return;
}
//----------------------------------------
